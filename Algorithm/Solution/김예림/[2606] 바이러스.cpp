// [2606] 바이러스
// bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[101];
vector<int> connectedVec[101];

int getVirusComputer()
{
    int ans = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < connectedVec[cur].size(); i++) {
            int next = connectedVec[cur][i];
            if(visited[next] == false) {
                visited[next] = true;
                q.push(next);
                ans++;
            }        
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, connectedPair, a, b;
    cin >> n >> connectedPair;
    for(int i = 0; i < connectedPair; i++) {
        cin >> a >> b;
        connectedVec[a].push_back(b);
        connectedVec[b].push_back(a);
    } 
    cout << getVirusComputer() << '\n';
}