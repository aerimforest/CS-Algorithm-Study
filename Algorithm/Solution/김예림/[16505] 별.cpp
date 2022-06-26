// [16505] 별
// 구현
#include <iostream>
#include <cstring>
using namespace std;

int n;
char board[1100][1100];

void printStar() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void go(int size, int x, int y) {
    if(size == 1) {
        board[x][y] = '*';
        return;
    }
    
    int nextSize = size / 2; 
    go(nextSize, x, y); // 왼쪽 위
    go(nextSize, x + nextSize, y); // 오른쪽
    go(nextSize, x, y + nextSize); // 왼쪽 아래
}

void input() {
    cin >> n;
    n = 1 << n;
}

void solution() {
    go(n, 0, 0);
    printStar();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    memset(board, ' ', sizeof(board));
    solution();

    return 0;
}