// [17413] 단어 뒤집기2
// 구현, 문자열, 스택
#include <iostream>
#include <stack>
using namespace std;

stack<char> wordStack;

void printStack()
{
    while(!wordStack.empty()) {
        cout << wordStack.top();
        wordStack.pop();
    }
}

void go(string s)
{
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '<') {
            printStack();
            cout << s[i];
            while(s[i] != '>') {
                cout << s[++i];
            }
        }
        else if(s[i] == ' ') {  
            printStack();
            cout << s[i];
        }   
        else { // 소문자, 숫자
            wordStack.push(s[i]);
        }   
    }
    printStack();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[100005];
    cin.getline(s, 100005);
    go(s);
    return 0;
}