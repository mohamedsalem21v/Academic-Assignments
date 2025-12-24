#include <bits/stdc++.h>
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

class linked_stack
{
public:
    Node *top;
    linked_stack()
    {
        top = nullptr;
    }

    bool empty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = top;
        top = newnode;
    }

    void pop()
    {
        if (empty())
            return void(cout << "The stack is empty." << endl);
        Node *del = top;
        top = top->next;
        delete del;
    }

    void topEL()
    {
        if (empty())
            return void(cout << "The stack is empty." << endl);
        cout << top->data << endl;
    }
    
    void print()
    {
        Node *temp = top;
        while(temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int searchStack(int value)
    {
        Node *temp = top;
        int pos = 0;
        while (temp != nullptr)
        {
            if (temp->data == value)
                return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }
};

int main()
{
    linked_stack ls;
    ls.push(10);
    ls.push(20);
    ls.push(30);
    ls.print();
    return 0;
}