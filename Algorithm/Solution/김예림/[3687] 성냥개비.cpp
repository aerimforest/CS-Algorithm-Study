// [3687] 성냥개비
// dp, 그리디
#include <iostream>
using namespace std;

int num[8] = {0, 9, 1, 7, 4, 2, 0, 8};
long long dp[101];

long long getMinNum(int match)
{
    if(match <= 7) {
        return dp[match];
    }

    for(int i = 8; i <= match; i++) {
        dp[i] = dp[i - 2] * 10 + num[2];

        for(int j = 3; j <= 7; j++) {
            dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
        }
    }
    return dp[match];
}

string getMaxNum(int match)
{
    string maxNum = "";
    if(match % 2 == 0) {
        for(int i = 0; i < match/2; i++) {
            maxNum += '1';
        }
    }
    else {
        maxNum += '7';
        for(int i = 0; i < match/2 - 1; i++) {
            maxNum += '1';
        }
    }
    return maxNum;
}

void solution(int match)
{   
    cout << getMinNum(match) << " ";
    cout << getMaxNum(match) << '\n';
}

void input()
{
    int t, match;
    cin >> t;
    while(t--) {
        cin >> match;
        solution(match);
    }
}

void init()
{
    for(int i = 1; i <= 7; i++) {
        dp[i] = num[i];
    }
    dp[6] = 6;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    input();
    return 0;
}