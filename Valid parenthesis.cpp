#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        if (matching.find(c) == matching.end()) {
            st.push(c);  // If it's an opening bracket, push it to the stack
        } else {
            if (st.empty() || st.top() != matching[c]) {
                return false;  // If no matching opening bracket, it's invalid
            }
            st.pop();  // Pop the matching opening bracket
        }
    }

    return st.empty();  // The stack should be empty if all brackets are matched
}

int main() {
    string s = "()[]{}";
    cout << "Is valid: " << (isValid(s) ? "true" : "false") << endl;
    return 0;
}
