#include <stdio.h>
#include <string.h>

// bool 정의
typedef enum {false, true} bool;

// 입력 값의 최대 사이즈 지정
#define ARRAY_SIZE 200

// 입력 받은 수식이 저장되는 배열
char input[ARRAY_SIZE] = {0};

// 입력 받은 수식의 길이를 보관하는 변수
int inputLength = 0;

// 사칙 연산의 결과를 int형으로 반환하는 함수이다. 파라미터로 사칙연산 수식과, 그 수식의 길이를 받는다.
int fundamentalOperation(char localValue[ARRAY_SIZE], int localCount) {
    int  v[ARRAY_SIZE] = {0};   // 수를 저장하는 공간
    int  vIdx = 0;              // v배열에 들어가는 갯수를 계산하기 위한 변수
    char con[ARRAY_SIZE] = {0}; // 수식기호를 저장하는 공간
    int  conIdx = 0;            // con배열에 들어가는 갯수를 계산하기 위한 변수
    int  sqr = 0;               // 문자열 배열로 깨져있는 수를 조합하는 공간(이후 저장하는 공간으로 이동)
    bool hasDivMultip = false;  // 곱하기나 나누기를 가지고 있는지 확인하기 위한 변수

    for (int j = 0; j < localCount; j++) {
        if ('0' <= localValue[j] && localValue[j] <= '9') { // 숫자일 경우 sqr에 저장한다.
            sqr *= 10;  // 기존에 들어있던 sqr 값은 10을 곱하여 한칸 밀어주고
            // printf("1st%d\n", sqr);
            sqr += localValue[j] - '0'; // 새로운 숫자를 더해준다. 캐릭터형이기 때문에 '0'을 빼서 원래 값을 구한다.
            // printf("2nd%d\n", sqr);
        }
        else if (localValue[j] == '-' || localValue[j] == '+') { // - + 연산자일 경우
            v[vIdx] = sqr;      // 기존에 구한 숫자를 v배열에 추가하고,
            sqr = 0;            // sqr을 초기화한다.
            vIdx++;             // 배열의 크기를 계산하기 위한 vIdx는 1을 더해준다.
            
            if (hasDivMultip) { // 곱하기나 나누기를 가지고 있음을 확인한 상태라면
                int tmp = 0;
                if (con[conIdx-1] == '*') {
                    tmp = v[vIdx-2] * v[vIdx-1];
                }else if (con[conIdx-1] == '/') {
                    tmp = v[vIdx-2] / v[vIdx-1];
                }
                hasDivMultip = false;
                // 계산한 값들을 배열에서 제외해준다.
                con[conIdx-1] = 0;
                conIdx--;
                
                v[vIdx-1] = 0;
                v[vIdx-2] = 0;
                vIdx -= 2;
                
                v[vIdx] = tmp;
                vIdx ++;
            }
            
            con[conIdx] = localValue[j]; // 수식도 배열에 추가한다.
            // printf("con[%d] : %c\n", conIdx, con[conIdx]);
            conIdx++;
            
        }
        else if (localValue[j] == '*' || localValue[j] == '/') { // * / 연산자일 경우,
            v[vIdx] = sqr;      // 기존에 구한 숫자를 v배열에 추가하고,
            sqr = 0;            // sqr을 초기화한다.
            vIdx++;             // 배열의 크기를 계산하기 위한 vIdx는 1을 더해준다.
            
            if (hasDivMultip) { // 기존에 곱셈이나 나눗셈 수식을 받아둔게 있다면
                int tmp = 0;
                if (con[conIdx-1] == '*') {
                    tmp = v[vIdx-2] * v[vIdx-1];
                }else if (con[conIdx-1] == '/') {
                    tmp = v[vIdx-2] / v[vIdx-1];
                }
                con[conIdx-1] = 0;
                conIdx--;
                
                v[vIdx-1] = 0;
                v[vIdx-2] = 0;
                vIdx -= 2;
                
                v[vIdx] = tmp;
                vIdx ++;
            }
            
            con[conIdx] = localValue[j]; // 수식도 배열에 추가한다.
            conIdx++;
            
            hasDivMultip = true; // 곱하기나 나누기를 입력받았음을 표현해둔다.
        }
        if (j == localCount-1) { // 수식을 다 입력받은 상태로, 곱하기나 나누기를 입력 받은 상태라면
            v[vIdx] = sqr;      // 기존에 구한 숫자를 v배열에 추가하고,
            sqr = 0;            // sqr을 초기화한다.
            vIdx++;             // 배열의 크기를 계산하기 위한 vIdx는 1을 더해준다.
            
            if (hasDivMultip) {
                int tmp = 0;
                if (con[conIdx-1] == '*') {
                    tmp = v[vIdx-2] * v[vIdx-1];
                }
                else if (con[conIdx-1] == '/') {   //printf("나눗셈 계산 %d, %d", v[vIdx-2], v[vIdx-1]);
                    tmp = v[vIdx-2] / v[vIdx-1];
                }
                hasDivMultip = false;   // 계산한 값들을 배열에서 제외해준다.
                con[conIdx-1] = 0;
                conIdx--;
                
                v[vIdx-1] = 0;
                v[vIdx-2] = 0;
                vIdx -= 2;
                
                v[vIdx] = tmp;
                vIdx ++;
            }
        }
    }
    
    int result = v[0];
    for (int i =0; i < conIdx; i++) {
        if (con[i] == '+') {
            result += v[i+1];
        }else if (con[i] == '-') {
            result -= v[i+1];
        }
    }
    return result;
}

int main() {
    while(1) {
        printf("수식을 입력하세요. 종료를 원하시면 exit를 입력하세요.\n");
        printf("입력 : ");
        scanf("%s", input);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            // exit라는 값을 입력받았는지 확인하고, 입력받았으면 while문을 벗어난다.
            break;
        }
        else {
            // 입력한 수식의 길이를 알아낸다.
            for (int i = 0; i < ARRAY_SIZE; i++) {
                if (input[i] == 0) {    //NULL까지의 입력값
                    inputLength = i;
                    break;
                }
            }
            
            // 0~9와 *-+/()만 입력 가능하도록 필터링한다.
            bool hasUnknownCharacter = false;

            for (int i = 0; i < inputLength; i++) {
                if (!('0' <= input[i] && input[i] <= '9') &&
                    input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' ) {
                    hasUnknownCharacter = true; // 숫자와 괄호, 그리고 사칙연산 이외의 값을 입력받으면 hasUnknownCharacter을 true으로 변환
                }
            }

            if (hasUnknownCharacter == true) { // hasUnknownCharacter가 true일 경우(엉뚱한 값을 입력받았을 경우)
                printf("잘못된 입력 값이 있습니다.\n"); // 메시지 출력
            }
            // 남은 사칙연산을 수행
            int result = fundamentalOperation(input, inputLength);

            printf("결과는 %d입니다.\n", result); // 결과 출력
        }
        // 배열의 데이터를 0으로 초기화
        memset(&input[0], 0, sizeof(input));
        inputLength = 0;
    }
    printf("종료합니다.\n");
    
    return 0;
}