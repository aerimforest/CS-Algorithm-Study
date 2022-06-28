// [2757] 엑셀
// 구현, 수학, 문자열
#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
	int n, m;
    while(true) {
        char colNum[10] = {'0', };
        scanf("R%dC%d", &n, &m);
        if(n == 0 && m == 0) {
            break;
        }
        for(int i = 0; m > 0; i++) {
            m--; // 'A'에 나머지를 더해줄 것이기 때문에 시작 인덱스를 하나 줄여야 함 
            colNum[i] = ('A' + m%26);
            m /= 26;
        }
        for(int i = strlen(colNum) - 1; i >= 0; i--) {
            printf("%c", colNum[i]);
        }
        printf("%d\n", n);
        getchar();
    }

	return 0;
}