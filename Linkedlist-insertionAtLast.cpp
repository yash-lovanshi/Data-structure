
#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* start = NULL;

void createNode()
{
    int val;
    cout << "Enter value to insert: ";
    cin >> val;

    node* newnode = new node;

    newnode->data = val;
    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        node* ptr = start;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

void display()
{
    node* ptr = start;

    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int n;

    cout << "Number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        createNode();
    }

    cout << "Existing Linked List: ";
    display();

    cout << "\nNow inserting a new value at last\n";
    createNode();

    cout << "After insertion at last: ";
    display();

    cout << "\nFreeing memory...\n";

    node* ptr = start;

    while (ptr != NULL)
    {
        node* nextnode = ptr->next;
        delete ptr;
        ptr = nextnode;
    }

    start = NULL;

    cout << "All nodes freed";

    return 0;
}
