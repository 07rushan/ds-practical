#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

node *first = NULL, *last = NULL;

void insert_first(int x)
{
    node *temp = new node;
    temp->info = x;

    if (first == NULL)
    {
        first = last = temp;
        last->next = first;
    }
    else
    {
        temp->next = first;
        first = temp;
        last->next = first;
    }

    cout << "Inserted " << x << " at beginning.\n";
}
void insert_last(int x)
{
    node *temp = new node;
    temp->info = x;

    if (first == NULL)
    {
        first = last = temp;
        last->next = first;
    }
    else
    {
        last->next = temp;
        last = temp;
        last->next = first;
    }

    cout << "Inserted " << x << " at end.\n";
}
void insert_after(int pos, int x)
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    node *y = first;
    int c = 1;

    while (c < pos && y != last)
    {
        y = y->next;
        c++;
    }

    node *temp = new node;
    temp->info = x;

    temp->next = y->next;
    y->next = temp;

    if (y == last)
        last = temp;

    cout << "Inserted " << x << " after position " << pos << ".\n";
}
void delete_first()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    node *temp = first;

    if (first == last)
    {
        first = last = NULL;
    }
    else
    {
        first = first->next;
        last->next = first;
    }

    cout << "Deleted first node: " << temp->info << endl;
    delete temp;
}
void delete_last()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    node *temp = first;

    if (first == last)
    {
        cout << "Deleted last node: " << last->info << endl;
        delete last;
        first = last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }

        node *del = last;
        last = temp;
        last->next = first;

        cout << "Deleted last node: " << del->info << endl;
        delete del;
    }
}
void delete_after(int pos)
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    node *y = first;
    int c = 1;

    while (c < pos && y != last)
    {
        y = y->next;
        c++;
    }

    if (y->next == first)
    {
        cout << "No node to delete.\n";
        return;
    }

    node *del = y->next;
    y->next = del->next;

    if (del == last)
        last = y;

    cout << "Deleted node: " << del->info << endl;
    delete del;
}
void display()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    node *temp = first;

    cout << "Circular Linked List: ";

    do
    {
        cout << temp->info << " -> ";
        temp = temp->next;
    }
    while (temp != first);

    cout << "(back to first)" << endl;
}
int main()
{
    int choice, x, pos;

    while (1)
    {
        cout << "\n--- Singly Circular Linked List ---\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert After Position\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete After Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            insert_first(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            insert_last(x);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> x;
            insert_after(pos, x);
            break;

        case 4:
            delete_first();
            break;

        case 5:
            delete_last();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            delete_after(pos);
            break;

        case 7:
            display();
            break;

        case 8:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}