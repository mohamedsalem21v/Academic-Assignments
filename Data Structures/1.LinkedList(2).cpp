#include <bits/stdc++.h>
#define sp " "
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void insertEnd(int val)
    {
        Node *newnode = new Node();
        newnode->data = val;
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newnode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << sp;
            temp = temp->next;
        }
        cout << endl;
    }

    void AddBefore(int value, int item)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (head == nullptr)
            return;

        if (head->data == item)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != item)
            temp = temp->next;

        if (temp->next == nullptr)
            return;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void Update(int position, int newvalue)
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            if (count == position)
            {
                temp->data = newvalue;
                return;
            }
            count++;
            temp = temp->next;
        }
    }

    void DelAt(int position)
    {
        if (head == nullptr)
            return;

        if (position == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr)
            return;

        Node *todel = temp->next;
        temp->next = todel->next;
        delete todel;
    }

    void DelAfter(int value)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != value)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr)
            return;

        Node *todel = temp->next;
        temp->next = todel->next;
        delete todel;
    }

    void InsertAtMiddle(int data, int position)
    {
        Node *new_node = new Node();
        new_node->data = data;

        if (head == nullptr && position == 0)
        {
            head = new_node;
            return;
        }

        if (position == 0)
        {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node *current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++)
            current = current->next;

        if (current == nullptr)
            return;

        new_node->next = current->next;
        current->next = new_node;
    }

    void DeleteAtMiddle(int target_node)
    {
        if (head == nullptr)
            return;

        if (head->data == target_node)
        {
            Node *del = head;
            head = head->next;
            delete del;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->data != target_node)
            current = current->next;

        if (current->next == nullptr)
            return;

        Node *del = current->next;
        current->next = del->next;
        delete del;
    }
};

int main()
{
    LinkedList ls;
    ls.insertEnd(1);
    ls.insertEnd(2);
    ls.insertEnd(3);
    ls.insertEnd(4);
    ls.insertEnd(5);

    ls.InsertAtMiddle(100, 2);
    ls.DeleteAtMiddle(3);
    ls.AddBefore(99, 3);
    ls.DelAfter(2);
    ls.DelAt(2);
    ls.Update(1, 500);

    ls.display();
    return 0;
}