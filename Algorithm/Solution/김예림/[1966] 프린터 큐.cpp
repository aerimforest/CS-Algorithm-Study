// [1966] 프린터 큐
// https://www.acmicpc.net/problem/1966
// 구현, 시뮬레이션, 큐
#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, int> > q;
priority_queue<int> pq; // 기본; 내림차순 정렬

void startPrintQ(int n, int m)
{
    int cnt = 0;
    while (!q.empty()) {
        int initialIdx = q.front().first;
        int curImportance = q.front().second;
        int maxImportance = pq.top();
        q.pop();
        if (curImportance == maxImportance) {
            pq.pop();
            cnt++;
            if (initialIdx == m) {
                cout << cnt << '\n';
                break;
            }
        }
        else {
            q.push(make_pair(initialIdx, curImportance));
        }
    }
}

void initialization()
{
    while(!pq.empty()) pq.pop();
    /** 중요!! 내가 원하는 인덱스를 찾으면 바로 출력하기 때문에 
        미처 출력되지 못한 원소가 남아있을 수 있음 **/
    while(!q.empty()) q.pop(); 
}

int main() {
    int t, n, m, num;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        initialization();
        for (int i = 0; i < n; i++) {
            cin >> num;
            pq.push(num);
            q.push(make_pair(i, num));
        }
        startPrintQ(n, m);
    }
    return 0;
}