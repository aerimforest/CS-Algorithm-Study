// [20291] 파일 정리
// 문자열, 정렬, 맵
#include <iostream>
#include <map>
using namespace std;

map<string, int> m;

void categorizeExtension(string extension)
{
    if(m.find(extension) != m.end()) {
        m[extension]++;
    }
    else {
        m.insert(make_pair(extension, 1));
    }
}

void input()
{
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        categorizeExtension(s.substr(s.find(".")+1));
    }
}

void output()
{
    map<string, int>::iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++) {
        cout << iter -> first << " " << iter -> second << '\n';
    }
}

int main(void)
{
    input();
    output();
}