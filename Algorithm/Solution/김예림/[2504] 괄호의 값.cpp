// [2504] 괄호의 값
// 구현, 스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string str)
{
    stack<char> st;
    int multiple, ans = 0;
    st.push(str[0]);
    multiple = (str[0] == '(') ? 2 : 3; 

    for(int i = 1; i < str.size(); i++) {
        if(str[i] == '(') {
            multiple *= 2;
            st.push(str[i]);
        }
        else if(str[i] == ')') {
            multiple /= 2;
            if(str[i-1] == '(') {
                ans += multiple * 2;
            }
            if(st.empty()) return 0;
            else if(st.top() == '(') {
                st.pop();
            }
        }
        else if(str[i] == '[') {
            multiple *= 3;
            st.push(str[i]);
        }
        else {
            multiple /= 3;
            if(str[i-1] == '[') {
                ans += multiple * 3;
            }
            if(st.empty()) return 0;
            else if(st.top() == '[') {
                st.pop();
            }
        }
    }
    if(!st.empty()) {
        return 0;
    }
    else {
        return ans;
    }
}

int main(void)
{
    string str;
    cin >> str;
    cout << solution(str) << '\n';
}