// [1244] 스위치 켜고 끄기
// 구현, 시뮬레이션
#include <iostream>
#include <vector>
using namespace std;

int n, gender, studentNum, switchNum;
int switchState[101];
vector<pair<int, int> > studentVec;

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> switchState[i];
    }
    cin >> studentNum;
    for(int i = 0; i < studentNum; i++) {
        cin >> gender >> switchNum;
        studentVec.push_back(make_pair(gender, switchNum));
    }
}

void goBoy(int num)
{   
    for(int i = num; i <= n; i += num) {
        switchState[i] = (1 - switchState[i]);
    }
}

void goGirl(int num)
{
    switchState[num] = (1 - switchState[num]);
    for(int gap = 1; ; gap++) {
        if(num - gap <= 0 || num + gap > n) {
            break;
        }
        if(switchState[num - gap] != switchState[num + gap]) {
            break;
        }
        else {
            switchState[num - gap] = (1 - switchState[num - gap]);
            switchState[num + gap] = (1 - switchState[num + gap]);
        }

    }
}

void solution()
{
    for(int i = 0; i < studentNum; i++) {
        if(studentVec[i].first == 1) {
            goBoy(studentVec[i].second);
        }
        else {
            goGirl(studentVec[i].second);
        }
    }
}

void output()
{
    for(int i = 1; i <= n; i++) {
        cout << switchState[i] << " ";
        if(i % 20 == 0) {
            cout << '\n';
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();
    output();

    return 0;
}