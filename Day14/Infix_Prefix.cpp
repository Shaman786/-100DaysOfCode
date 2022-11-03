// infix to prefix

#include <iostream>
#include <stack>

using namespace std;

int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s)
{
    stack<char> st;
    string res;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];
        else if(s[i] == ')')
            st.push(s[i]);
        else if(s[i] == '(')
        {
            while(!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else
        {
            while(!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string s;
    cout << "Enter the infix expression: ";
    cin >> s;
    cout << "Prefix expression: " << infixToPrefix(s);
    return 0;
}

// Algorithm:
// 1. Scan the infix expression from left to right.
// 2. If the scanned character is an operand, output it.
// 3. Else,
//     a. If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
//     b. Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
// 4. If the scanned character is an ‘(‘, push it to the stack.
// 5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis.
// 6. Repeat steps 2-6 until infix expression is scanned.
// 7. Print the output
// 8. Pop and output from the stack until it is not empty.

// Pseudocode
// 1. Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
// 2. Obtain the infix expression of the modified string obtained in step 1.
// 3. The prefix expression is the reverse of the string obtained in step 2.
