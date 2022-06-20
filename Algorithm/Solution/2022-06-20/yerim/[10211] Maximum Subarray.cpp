// [10211] Maximum Subarray
// dp, 브루트포스
// dp[i] = i번째 원소를 포함하면서 최대 합
#include <iostream>
using namespace std;

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}

int getMaximumSubarray(int n, int x[])
{
    int dp[1001];
    dp[0] = x[0];
    // 양수라고 무조건 더하면 안됨
    // x = |-3|2|5| 인 경우 -3+2+5 < 2+5
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + x[i], x[i]);
    }

    int max = dp[0];
    for(int i = 1; i < n; i++) {
        if(dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

void input()
{
    int t, n, x[1001];
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        cout << getMaximumSubarray(n, x) << '\n';
    }
}

int main(void)
{
    input();
}