// [1388] 바닥 장식
// 브루트포스
#include <iostream>
#include <cstdio>
using namespace std;

int n, m, ans;
int dx[2] = {0, 1}, dy[2] = {1, 0}; // 오른쪽: 0, 아래: 1
char design[51][51];
bool visited[51][51];

void solution(int x, int y)
{
    int dir, end;
    dir = (design[x][y] == '-') ? 0 : 1;

    int nx, ny;
    while(true) {
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(nx >= n || ny >= m) {
            break;
        }
        if(design[nx][ny] == design[x][y] && visited[nx][ny] == false) {
            visited[nx][ny] = true;
            x = nx; y = ny;
            continue;
        }
        else if(design[nx][ny] != design[x][y]) {
            break;
        }
    }
    ans++;
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> design[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == false) {
                visited[i][j] = true;
                solution(i, j);   
            }   
        }
    }
    cout << ans << '\n';
}