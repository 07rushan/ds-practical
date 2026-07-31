#include <iostream>
#include <stack>
using namespace std;

int calculate(char op, int p1, int p2)
{
    switch(op)
    {
        case '+':
            return p2 + p1;

        case '-':
            return p2 - p1;

        case '*':
            return p2 * p1;

        case '/':
            return p2 / p1;

        case '%':
            return p2 % p1;

        default:
            cout << "Invalid Operator!";
            return 0;
    }
}

int main()
{
    char post[50];
    stack<int> s;

    cout << "Enter Postfix Expression: ";
    cin >> post;

    for(int i = 0; post[i] != '\0'; i++)
    {
        if(isdigit(post[i]))
        {
            s.push(post[i] - '0');
        }
        else
        {
            int p1 = s.top();
            s.pop();

            int p2 = s.top();
            s.pop();

            int result = calculate(post[i], p1, p2);
            s.push(result);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}