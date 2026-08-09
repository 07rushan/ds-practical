#include <iostream>
using namespace std;

void value(int x)
{
    x = 20;
    cout << "Inside Call by Value: " << x << endl;
}
void reference(int &x)
{
    x = 30;
    cout << "Inside Call by Reference: " << x << endl;
}

int main()
{
    int a = 10;
    int b = 10;

    cout << "Before Call by Value: " << a << endl;
    value(a);
    cout << "After Call by Value: " << a << endl;

    cout << endl;

    cout << "Before Call by Reference: " << b << endl;
    reference(b);
    cout << "After Call by Reference: " << b << endl;

    return 0;
}