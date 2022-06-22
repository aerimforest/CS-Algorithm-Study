// [2630] 색종이 만들기
// 분할 정복, 재귀
#include <iostream>
using namespace std;

int n, ans[2], colorPaper[130][130];

bool isAllColorSame(int x, int y, int length)
{
    for(int i = x; i < (x + length); i++) {
        for(int j = y; j < (y + length); j++) {
            if(colorPaper[i][j] != colorPaper[x][y]) {
                return false;
            }
        }
    }
    return true;
}

void divideAndQonquer(int x, int y, int length)
{
    if(isAllColorSame(x, y, length) == false) {
        divideAndQonquer(x, y, length/2);
        divideAndQonquer(x, y + length/2, length/2);
        divideAndQonquer(x + length/2, y, length/2);
        divideAndQonquer(x + length/2, y + length/2, length/2);
    }
    else {
        ans[colorPaper[x][y]]++;
    }
}

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> colorPaper[i][j];
        }
    }
}

void output()
{
    cout << ans[0] << '\n';
    cout << ans[1] << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    divideAndQonquer(0, 0, n);
    output();
}