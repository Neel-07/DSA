// C++ program to find length of the 
// longest valid substring
#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
    int n = str.length();

    // Create a stack
    stack<int> stk;

    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
        
        // If closing bracket, i.e.,str[i] = ')'
        else
        {
            
            // If the stack is not empty and on the top
            // that is and index of a open bracket then pop
            if (!stk.empty() and str[stk.top()] == '(')
                stk.pop();

            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else
                stk.push(i);
        }
    }

    // Initialize the result
    // 'last' is initialized
    // to calculate the distance
    int result = 0, last = n;


    while(!stk.empty())
    {
        int now = stk.top();
        stk.pop();

        // take the maximum in result
        result = max(result, last-now-1);

        // update the last index
        // with current index
        last = now;
    }

    // return the maximum of last and result
    return max(result, last);
}

// Driver code
int main()
{
    string str = "((()()";

    // Function call
    cout << findMaxLen(str) << endl;

    str = "()(()))))";

    // Function call
    cout << findMaxLen(str) << endl;

    return 0;
}
