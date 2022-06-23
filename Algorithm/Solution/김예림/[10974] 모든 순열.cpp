// [10974] 모든 순열
// 브루트포스, 백트래킹
#include <iostream>
using namespace std;

bool visited[8];
int n, arr[8], tmpArr[8];

void dfs(int idx, int depth)
{
    if(depth == n) {
        for(int i = 0; i < n; i++) {
            cout << tmpArr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == false && i != idx) {
            visited[i] = true;
            tmpArr[depth] = arr[i];
            dfs(i, depth + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        arr[i] = i+1;
    }
    dfs(-1, 0);
}