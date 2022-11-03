// Evaluation of prefix expression

#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s)
{
    stack<int> st;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    return st.top();
}

int main()
{
 string s;
    cin >> s;
    cout << prefixEvaluation(s) << endl;
    return 0;
}

// Algorithm:
// 1. Scan the expression from right to left.
// 2. If the scanned character is an operand, push it to the stack.
// 3. If the scanned character is an operator, pop two operands from the stack and apply it.
// 4. Repeat the above steps until end of prefix expression.

// Pseudocode
// 1. Create an empty stack to store operands (or values).
// 2. Scan the prefix expression and do following for every scanned element.
//     a. If the element is a number, push it into the stack
//     b. If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
// 3. When the expression is ended, the number in the stack is the final answer
