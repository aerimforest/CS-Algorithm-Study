// [4963] 섬의 개수
// dfs
#include <iostream>
#include <cstring>
using namespace std;

int w, h, map[51][51];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y)
{
    map[x][y] = 0;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > h || ny < 0 || ny > w) {
            continue;
        }
        if(map[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

void solution()
{
    int islandNum = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 1) {
                dfs(i, j);
                islandNum++;
            }
        }
    }
    cout << islandNum << '\n';
}

void input()
{
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) {
            break;
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        solution();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}