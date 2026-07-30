#include <iostream>
using namespace std;

// Traversal
void traversal(int arr[], int n)
{
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Insertion
void insertion(int arr[], int &n)
{
    int value, pos;
    cout << "Enter value and position: ";
    cin >> value >> pos;

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;
}

// Deletion
void deletion(int arr[], int &n)
{
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

// Search
void search(int arr[], int n)
{
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i << endl;
            return;
        }
    }

    cout << "Element not found." << endl;
}

int main()
{
    int arr[100];
    int n = 10;
    int choice;

    cout << "Enter 10 elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do
    {
        cout << "\n1. Traversal";
        cout << "\n2. Insertion";
        cout << "\n3. Deletion";
        cout << "\n4. Search";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            traversal(arr, n);
            break;

        case 2:
            insertion(arr, n);
            break;

        case 3:
            deletion(arr, n);
            break;

        case 4:
            search(arr, n);
            break;

        case 5:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}