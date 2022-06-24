// [14503] 로봇 청소기]
// 구현, 시뮬레이션
#include <iostream>
using namespace std;

bool visited[51][51];
int n, m, r, c, d, ans;
int map[51][51];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int nextR, nextC;

void input()
{
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}

int getNorthDir(int dir)
{
    switch(dir) {
    case 0:
        return 2;
        break;
    case 1:
        return 3;
    case 2:
        return 0;
    case 3:
        return 1;
    }
}

void startCleaning(int curR, int curC, int curD)
{
    // 1번
    if(visited[curR][curC] == false && map[curR][curC] == 0) {
        visited[curR][curC] = true;
        ans++;
    }   

    // 2번(동서남북 네 방향 중 이동 가능한 칸이 있는지 탐색)
    bool flag = true;
    for(int i = 0; i < 4; i++) {
        nextR = curR + dx[i];
        nextC = curC + dy[i];
        if(visited[nextR][nextC] == false && map[nextR][nextC] == 0) {
            flag = false;
            break;
        }
    }

    if(flag == true) {
        int southD = getNorthDir(curD);
        nextR = curR + dx[southD];
        nextC = curC + dy[southD];
        if(map[nextR][nextC] == 1) {
            cout << ans << '\n';
            exit(0);
        }
        startCleaning(nextR, nextC, curD);
    }
    else {
        int leftD = curD - 1;
        if(leftD < 0) leftD = 3;
        nextR = curR + dx[leftD];
        nextC = curC + dy[leftD];
        if(map[nextR][nextC] == 0 && visited[nextR][nextC] == false) {
            startCleaning(nextR, nextC, leftD);
        }
        else {
            startCleaning(curR, curC, leftD);
        }
    }
}

int main(void)
{
    input();
    startCleaning(r, c, d);  
    cout << ans << '\n';
    return 0;  
}