#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int *ptr;

    cout << "Enter 5 elements:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    ptr = &arr[4];

    cout << "Array elements in reverse order:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << *ptr << " ";
        ptr--;
    }

    return 0;
}