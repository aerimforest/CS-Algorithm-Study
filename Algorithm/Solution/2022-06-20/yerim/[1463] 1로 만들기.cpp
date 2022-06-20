// [1463] 1로 만들기
// dp[i] = i를 만드는데 필요한 최소 연산
#include <iostream>
using namespace std;

int n, dp[1000001];

void input()
{
    cin >> n;
}

int min(int a, int b)
{
    if(a < b) return a;
    else return b;
}

int go()
{
    dp[1] = 0; dp[2] = 1; dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 3 == 0) {
            dp[i] = min(dp[i/3] + 1, dp[i]);
        }
        if(i % 2 == 0) {
            dp[i] = min(dp[i/2] + 1, dp[i]);
        }
    }
    return dp[n];
}

int main(void)
{
    input();
    cout << go() << '\n';

    return 0;
}