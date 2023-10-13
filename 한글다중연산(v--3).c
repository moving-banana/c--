#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "title.c"
#include "explain.c"

#define HANGUL_SIZE 3
#define HANGUL_NUM_MAX 9

#define MAX_STRINGS 100
#define MAX_STRING_LENGTH 100
#define MAX_OPERATORS 100

int minus = false;       //한글계산기 음수값 컨트롤
int won = false;         //"원"입력시
int looptimes = 0;       //루프 컨트롤 변수
char kors[HANGUL_NUM_MAX][HANGUL_SIZE + 1] = { "일","이","삼","사","오","육","칠","팔","구" };

int resultsSize = 0;
char Inpstore[MAX_STRINGS][MAX_STRINGS] = {0};
char Inpres[MAX_STRINGS][MAX_STRINGS] = {0};

void StartFunc();
void chooseMod();

// ESC키 입력시 동작 함수
bool EscPressed() {
    int putEsc = 0;
    while ((putEsc = getchar()) != '\n' && putEsc != EOF) {
        if (putEsc == 27) {  // 27은 ESC 키의 ASCII 코드입니다
            return true;
        }
    }
    return false;
}

// 터미널을 새로 그려주는 함수
void clearScreen() {
    printf("\033[H\033[J"); // ANSI 이스케이프 시퀀스로 화면 지우기
}

// 사칙 연산의 결과를 반환하는 함수이다. 파라미터로 연산 전체의str과, 그 str의 길이를 받는다.
int Operation(char AcceptNumstr[MAX_STRINGS], int AcceptNumstrLen) {
    int  numArr[MAX_STRINGS] = {0};   // 수를 저장하는 공간
    int  numArrIdx = 0;              // numArr배열에 들어가는 갯수를 계산하기 위한 변수
    char oper[MAX_STRINGS] = {0}; // 수식기호를 저장하는 공간
    int  operIdx = 0;            // oper배열에 들어가는 갯수를 계산하기 위한 변수
    int  stack = 0;               // 문자열 배열로 깨져있는 수를 조합하는 공간(이후 저장하는 공간으로 이동)
    bool hasDivMultip = false;  // 곱하기나 나누기를 가지고 있는지 확인하기 위한 변수

    for (int InputIdx = 0; InputIdx < AcceptNumstrLen; InputIdx++) {
        if ('0' <= AcceptNumstr[InputIdx] && AcceptNumstr[InputIdx] <= '9') { // 숫자일 경우 stack에 저장한다.
            stack *= 10;  // 기존에 들어있던 stack 값은 10을 곱하여 한칸 밀어주고
            // printf("1st%d\n", stack);
            stack += AcceptNumstr[InputIdx] - '0'; // 새로운 숫자를 더해준다. 캐릭터형이기 때문에 '0'을 빼서 원래 값을 구한다.
            // printf("2nd%d\n", stack);
        }
        else if (AcceptNumstr[InputIdx] == '-' || AcceptNumstr[InputIdx] == '+') { // - + 연산자일 경우
            numArr[numArrIdx] = stack;      // 기존에 구한 숫자를 numArr배열에 추가하고,
            stack = 0;            // stack을 초기화한다.
            numArrIdx++;             // 배열의 크기를 계산하기 위한 numArrIdx는 1을 더해준다.
            
            if (hasDivMultip) { // 곱하기나 나누기를 가지고 있음을 확인한 상태라면
                int DivMulResult = 0;
                if (oper[operIdx-1] == '*') {
                    DivMulResult = numArr[numArrIdx-2] * numArr[numArrIdx-1];
                }else if (oper[operIdx-1] == '/') {
                    DivMulResult = numArr[numArrIdx-2] / numArr[numArrIdx-1];
                }
                hasDivMultip = false;
                // 계산한 값들을 배열에서 제외해준다.
                oper[operIdx-1] = 0;
                operIdx--;
                
                numArr[numArrIdx-1] = 0;
                numArr[numArrIdx-2] = 0;
                numArrIdx -= 2;
                
                numArr[numArrIdx] = DivMulResult;
                numArrIdx ++;
            }
            
            oper[operIdx] = AcceptNumstr[InputIdx]; // 수식도 배열에 추가한다.
            // printf("oper[%d] : %c\n", operIdx, oper[operIdx]);
            operIdx++;
            
        }
        else if (AcceptNumstr[InputIdx] == '*' || AcceptNumstr[InputIdx] == '/') { // * / 연산자일 경우,
            numArr[numArrIdx] = stack;      // 기존에 구한 숫자를 numArr배열에 추가하고,
            stack = 0;            // stack을 초기화한다.
            numArrIdx++;             // 배열의 크기를 계산하기 위한 numArrIdx는 1을 더해준다.
            
            if (hasDivMultip) { // 기존에 곱셈이나 나눗셈 수식을 받아둔게 있다면
                int DivMulResult = 0;
                if (oper[operIdx-1] == '*') {
                    DivMulResult = numArr[numArrIdx-2] * numArr[numArrIdx-1];
                }else if (oper[operIdx-1] == '/') {
                    DivMulResult = numArr[numArrIdx-2] / numArr[numArrIdx-1];
                }
                oper[operIdx-1] = 0;
                operIdx--;
                
                numArr[numArrIdx-1] = 0;
                numArr[numArrIdx-2] = 0;
                numArrIdx -= 2;
                
                numArr[numArrIdx] = DivMulResult;
                numArrIdx ++;
            }
            
            oper[operIdx] = AcceptNumstr[InputIdx]; // 수식도 배열에 추가한다.
            operIdx++;
            
            hasDivMultip = true; // 곱하기나 나누기를 입력받았음을 표현해둔다.
        }
        if (InputIdx == AcceptNumstrLen-1) { // 수식을 다 입력받은 상태로, 곱하기나 나누기를 입력 받은 상태라면
            numArr[numArrIdx] = stack;      // 기존에 구한 숫자를 numArr배열에 추가하고,
            stack = 0;            // stack을 초기화한다.
            numArrIdx++;             // 배열의 크기를 계산하기 위한 numArrIdx는 1을 더해준다.
            
            if (hasDivMultip) {
                int DivMulResult = 0;
                if (oper[operIdx-1] == '*') {
                    DivMulResult = numArr[numArrIdx-2] * numArr[numArrIdx-1];
                }
                else if (oper[operIdx-1] == '/') {   //printf("나눗셈 계산 %d, %d", numArr[numArrIdx-2], numArr[numArrIdx-1]);
                    DivMulResult = numArr[numArrIdx-2] / numArr[numArrIdx-1];
                }
                hasDivMultip = false;   // 계산한 값들을 배열에서 제외해준다.
                oper[operIdx-1] = 0;
                operIdx--;
                
                numArr[numArrIdx-1] = 0;
                numArr[numArrIdx-2] = 0;
                numArrIdx -= 2;
                
                numArr[numArrIdx] = DivMulResult;
                numArrIdx ++;
            }
        }
    }
    
    int result = numArr[0];
    for (int numArrIdx =0; numArrIdx < operIdx; numArrIdx++) {
        if (oper[numArrIdx] == '+') {
            result += numArr[numArrIdx+1];
        }else if (oper[numArrIdx] == '-') {
            result -= numArr[numArrIdx+1];
        }
    }
    return result;
}

//입력받은 한글을 정수로 변환
int KorToNum(const char* inputStr) {       
    int retValue = 0;   //리턴값을 저장
    int sLen = strlen(inputStr);         //입력받은 스트링의 길이
    int checkKorIdx = 0, idx2 = 0;
    int digit = 0, unit = 0;      //digit=각자리의 정수  unit=십,백,천,만 의 자리

    for (checkKorIdx = 0; checkKorIdx < sLen; checkKorIdx += HANGUL_SIZE) {            //입력받은 스트링과 unit을 비교하여 해당값 저장
        if (strncmp(inputStr + checkKorIdx, "만", HANGUL_SIZE) == 0) {
            unit = 10000;
        }
        else if (strncmp(inputStr + checkKorIdx, "천", HANGUL_SIZE) == 0) {
            unit = 1000;
        }
        else if (strncmp(inputStr + checkKorIdx, "백", HANGUL_SIZE) == 0) {
            unit = 100;
        }
        else if (strncmp(inputStr + checkKorIdx, "십", HANGUL_SIZE) == 0) {
            unit = 10;
        }
        else {           //단위가아닌 각자리의 정수일때 (10미만의 수)
            for (idx2 = 0; idx2 < HANGUL_NUM_MAX; idx2 ++) {
                if (strncmp(inputStr + checkKorIdx, kors[idx2], HANGUL_SIZE) == 0) {
                    digit = idx2 + 1;
                    break;
                }
            }
        }

        if (unit >= 10) {        //단위값을 가르킬때 (10이상의 수)
            digit = (digit == 0 ? 1 : digit);
            retValue += digit * unit;
            digit = 0;
            unit = 0;
        }

        if(strcmp(inputStr + checkKorIdx, "원") == 0){
            won = true;
        }
    }

    retValue += digit;

    return retValue;
}

//문자열로저장된 수를 한글문자열로 변환
void NumToKor(const char* inputStr) {
    char unitKor[HANGUL_NUM_MAX+1][HANGUL_SIZE + 1] = { "", "십", "백", "천" , "만" , "십" , "백" , "천" , "억" , "십"};
    int checkNumIdx = 0, idx2 = 0;

    int tmpIdx = 0;        //일시적으로 인덱스값을 저장
    int ctrl = 0;       //if문 조절해주는 변수

    printf("연산결과는 : ");
    printf("\033[1m"); //굵은글자
    printf("\033[4m"); // 밑줄 글자로 출력
    if(minus == true){  //음수값일때 앞에 - 를 붙여주자
        printf("-");
        minus=false;
    }

    for (checkNumIdx = 0; checkNumIdx < strlen(inputStr); checkNumIdx++) {
        if (inputStr[checkNumIdx] == '0') {
            if(strlen(inputStr) - checkNumIdx - 1 == 8) {
                if (ctrl != 0) printf("억");
                ctrl = 0;
            }
            else if (strlen(inputStr) - checkNumIdx - 1 == 4) {      //십만 이상일때 checkNumIdx=1의값이 0이면
                if (ctrl != 0) printf("만");
                ctrl = 0;
            }
            continue;
        }

        //문자열로 저장된 str을 int형으로 변환후 0에 해당하는 ascii코드값(문자0 = 48)을 빼준다
        tmpIdx = inputStr[checkNumIdx] - 48;
        ctrl += 1;
        printf("%s%s", kors[tmpIdx - 1], unitKor[strlen(inputStr) - checkNumIdx - 1]);   //나머지자리 
    }

    if(won == true){
        printf("원");
        won = false;
    }
    printf("\033[0m");
    printf("\n");
}

// 문자열을 분리하고 저장하는 함수, stirings엔 한글 문자열을 지정해줄거라 2중배열로 설정
// *countOper 변수는 splitString 함수 내에서 문자열과 연산자가 몇번 분리되었는지를 나타내는 값(=연산기호의 개수)
void splitString(char *input, char strings[MAX_STRINGS][MAX_STRING_LENGTH], char operators[MAX_OPERATORS], int *countOper) {
    int operatorIndex = 0;
    // 연산자 복사
    for(int inputIdx=0; inputIdx<strlen(input); inputIdx++){
        if(input[inputIdx] == '+' || input[inputIdx] == '-' || input[inputIdx] == '*' || input[inputIdx] == '/'){
            operators[operatorIndex++] = input[inputIdx];
            // printf("operator%d : %c\n", operatorIndex, operators[operatorIndex - 1]);
        }
    }
    bool hasUnknownCharacter = false;

    for (int inputIdx = 0; inputIdx < strlen(input); inputIdx++) {
        if (!(!('0' <= input[inputIdx] && input[inputIdx] <= '9')) &&
            input[inputIdx] != '+' && input[inputIdx] != '-' && input[inputIdx] != '*' && input[inputIdx] != '/' ) {
            hasUnknownCharacter = true; // 숫자와 사칙연산 이외의 값을 입력받으면 hasUnknownCharacter을 true으로 변환
        }
    }

    if (hasUnknownCharacter == true) { // hasUnknownCharacter가 true일 경우(엉뚱한 값을 입력받았을 경우)
        printf("잘못된 입력 값이 있습니다.\n"); // 메시지 출력
        StartFunc();
    }
    printf("\n");

    char *token = strtok(input, "+-*/");    //토큰에 연산기호를 기점으로 문자열들 저장
    *countOper = 0;

    // token이 NULL이 아니고, *countOper가 MAX_STRINGS - 1보다 작을때
    while (token != NULL) {

        // 문자열 복사
        strcpy(strings[*countOper], token);

        (*countOper)++;
        token = strtok(NULL, "+-*/");
    }
}

//띄어쓰기 입력시 문자열 처리
void removeSpaces(char* input) {
    int count = 0;
    for (int spaceIdx = 0; input[spaceIdx]; spaceIdx++) {
        if (input[spaceIdx] != ' ') {
            input[count++] = input[spaceIdx];
        }
    }
    input[count] = '\0';
}

// 입력한 스트링과 결과값을 계속 저장하는 함수
void storeInpRes(const char *input, const char *show) {
    if (resultsSize < MAX_STRINGS) {
        strncpy(Inpstore[resultsSize], input, MAX_STRING_LENGTH - 1);
        Inpstore[resultsSize][MAX_STRING_LENGTH - 1] = '\0'; // 문자열 끝에 NULL 추가
        strncpy(Inpres[resultsSize], show, MAX_STRING_LENGTH - 1);
        Inpres[resultsSize][MAX_STRING_LENGTH - 1] = '\0'; // 문자열 끝에 NULL 추가
        resultsSize++;
    } else {
        printf("결과를 더 이상 저장할 수 없습니다.\n");
    }
}

// 저장된값들을 출력해주는 함수
void printStore() {
    printf("저장된 결과값들\n");
    if (resultsSize == 0) {
        printf("저장된 결과값이 없습니다.\n");
    } else {
        for (int printIdx = 0; printIdx < resultsSize; printIdx++) {
            printf("%d번째\n", printIdx+1);
            printf("입력한 수식 : %s\n", Inpstore[printIdx]);
            NumToKor(Inpres[printIdx]);
        }
    }
    printf("(이전 단계로 돌아가려면 esc 키를 누르세요)\n");
    if (EscPressed()) {
        chooseMod();
    }
}

void StartFunc() {
    char input[MAX_STRINGS] = {0};
    char strings[MAX_STRINGS][MAX_STRING_LENGTH] = {0}; //input의 str을 저장하는 배열
    char operators[MAX_OPERATORS] = {0}; //input의 연산기호를 저장하는 배열
    int numbers[MAX_STRINGS] = {0}; // 변환한 숫자를 저장할 배열 선언
    int countOper = 0;
    char NewInput[MAX_STRINGS] = {0}; //변환된 숫자와 연산기호를 다시 문자열로 저장할 배열
    int NewInputLength = 0;

    while (1) {
        printf("수식을 입력하세요 (예: 이천삼백사십오+이천삼백사십오-육백사십...)\n");
        printf("입력 ▶ ");
        fgets(input, sizeof(input), stdin);

        // 입력 문자열에서 줄 바꿈 문자를 제거
        input[strcspn(input, "\n")] = '\0';

        // 입력 문자에서 스페이스바 제거
        removeSpaces(input);

        // 문자열 분리
        splitString(input, strings, operators, &countOper);

        //분리된 문자열 숫자로 변환
        for (int stringsIdx = 0; stringsIdx < countOper; stringsIdx++) {
            numbers[stringsIdx] = KorToNum(strings[stringsIdx]); // KorToNum 함수를 호출하여 문자열을 숫자로 변환
            // printf("input : %s\n", strings[i]);
        }

        // 변환된 숫자와 연산자를 순서대로 NewInput에 저장
        for (int NewInputIdx = 0; NewInputIdx < countOper; NewInputIdx++) {
            NewInputLength += snprintf(NewInput + NewInputLength, MAX_STRINGS - NewInputLength, "%d", numbers[NewInputIdx]);
            NewInput[NewInputLength++] = operators[NewInputIdx];
        }
        NewInput[NewInputLength] = '\0'; //NULL값을 집어넣어 문자열을 완성
        // printf("변환된 입력값: %s\n", NewInput);

        char show[MAX_STRINGS] = { 0 };
        int result = Operation(NewInput, NewInputLength);

        if( result < 0 ){
            result = -result;
            minus = true;
        }

        
        sprintf(show, "%d", result);
        storeInpRes(NewInput,show); // 결과를 배열에 추가
        NumToKor(show);

        //초기화
        memset(input, 0, sizeof(input));
        memset(strings, 0, sizeof(strings));
        memset(operators, 0, sizeof(operators));
        memset(numbers, 0, sizeof(numbers));
        memset(NewInput, 0, sizeof(NewInput));
        NewInputLength = 0;
        
        printf("(이전단계롤 돌아가려면 esc키를 누르세요)\n");
        printf("(계속진행하려면 아무키나 입력하세요)\n");
        if (EscPressed()) {
            chooseMod();
            break;
        }
    }
}

// option선택자
void chooseMod(){
    char choose = 0;
	bool flag = true;
    while(flag == true){
        printf("\n");
        printf("\033[1m\n");
        printf("OPTION 선택!\n\n");
        printf("\033[0m");
        printf(" 바로시작!!        ▶ 1 입력\n");
        printf(" 저장값 보기!!     ▶ 2 입력\n");
        printf(" 설명보기!!        ▶ 3 입력\n");
        printf(" 프로그램 종료!!   ▶ 4 입력\n\n");
        if(looptimes == 0){
            printf("(처음 사용하신다면 설명을 먼저 보시길 추천드립니다!)\n\n");
            looptimes++;
        }
        printf("입력 ▶ ");
        scanf("%s", &choose);
        getchar();

        if (choose == '1') {
            clearScreen();
            printf("\033[1m\n"); //굵은글자
            printf("한글 계산기!!\n");
            printf("\033[0m");
            StartFunc();
            flag = false;
            break;
        }
        else if (choose == '2'){
            clearScreen();
            printStore();
            if (EscPressed()) {
                chooseMod();
            }
        }
        else if (choose == '3') {
            clearScreen();
            explain();
            if (EscPressed()) {
                chooseMod();
            }
            else {
                printf("다시 입력하세요!!!\n");
            }
            flag = false;
        }
        else if (choose == '4'){
            printf("프로그램을 종료합니다!\n");
            printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
            printf("3초후 종료!!\n");
            printf("\n");
            sleep(1);
            printf("2초후 종료!!\n");
            printf("\n");
            sleep(1);
            printf("1초후 종료!!\n");
            printf("\n");
            sleep(1);
            system("clear");
            exit(0);
        }
        else {
            printf("다시 입력하세요!!!\n");
            flag = true;
        }
    }
}

int main(){
    system("clear");
    title();
    chooseMod();
    return 0;
}