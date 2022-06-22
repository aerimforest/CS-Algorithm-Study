// [1914] 하노이 탑
// 재귀
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
        
void hanoiTower(int num, int from, int by, int to)
{
    if(num == 1) {
        cout << from << " " << to << '\n';
    }
    else {
        hanoiTower(num - 1, from, to, by);
        cout << from << " " << to << '\n';
        hanoiTower(num - 1, by, from, to);
    }
}
        
int main(void)
{
    int n;
    cin >> n;
    string strN = to_string(pow(2, n));				
    strN = strN.substr(0, strN.find('.'));			
    strN[strN.length() - 1] -= 1; // 하노이 탑 원판 이동 횟수 = 2^n - 1			
    cout << strN << '\n';

    if(n <= 20) {
        hanoiTower(n, 1, 2, 3);
    }
        
    return 0;
}