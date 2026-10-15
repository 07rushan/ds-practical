#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

node *first = NULL;

node *create_node(int x)
{
    node *t;
    t = new node;
    t->info = x;
    t->next = NULL;
    return t;
}

void insert_first(int x)
{
    node *t;
    t = create_node(x);

    if (first == NULL)
        first = t;
    else
    {
        t->next = first;
        first = t;
    }
}

void insert_last(int x)
{
    node *t, *p;
    t = create_node(x);

    if (first == NULL)
        first = t;
    else
    {
        p = first;

        while (p->next != NULL)
            p = p->next;

        p->next = t;
    }
}

void insert_after(int x, int key)
{
    node *t, *p;
    p = first;

    while (p != NULL && p->info != key)
        p = p->next;

    if (p == NULL)
        cout << "Node not found";
    else
    {
        t = create_node(x);
        t->next = p->next;
        p->next = t;
    }
}

void delete_first()
{
    node *t;

    if (first == NULL)
        return;

    t = first;
    first = first->next;
    delete t;
}

void delete_last()
{
    node *t, *p;

    if (first == NULL)
        return;

    if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        t = first;

        while (t->next != NULL)
        {
            p = t;
            t = t->next;
        }

        p->next = NULL;
        delete t;
    }
}

void delete_after(int key)
{
    node *t, *p;
    t = first;

    while (t != NULL && t->info != key)
        t = t->next;

    if (t == NULL || t->next == NULL)
        cout << "Node not found or no next node";
    else
    {
        p = t->next;
        t->next = p->next;
        delete p;
    }
}

void display()
{
    node *t;
    t = first;

    if (t == NULL)
        cout << "List is empty";

    while (t != NULL)
    {
        cout << t->info << " ";
        t = t->next;
    }

    cout << endl;
}

int main()
{
    int ch, x, key;

    do
    {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After Given Node";
        cout << "\n4. Delete First Node";
        cout << "\n5. Delete Last Node";
        cout << "\n6. Delete Node After Given Node";
        cout << "\n7. Display";
        cout << "\n8. Exit";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch (ch)
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
                cout << "Enter value: ";
                cin >> x;
                cout << "Enter node value: ";
                cin >> key;
                insert_after(x, key);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                cout << "Enter node value: ";
                cin >> key;
                delete_after(key);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (ch != 8);

    return 0;
}