#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void addToHead(int value)
    {
        Node *p = new Node;
        p->data = value;
        p->next = head;
        head = p;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    void print()
    {
        Node *curr = head;
        if (isEmpty())
            cout << "List is Empty\n";
        else
        {
            while (curr != NULL)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
    }
    // The assignment
    int getCount()
    {
        Node *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    int getMax()
    {
        Node *temp = head;
        int mx = INT32_MIN;
        while (temp != nullptr)
        {
            if (temp->data > mx)
                mx = temp->data;
            temp = temp->next;
        }
        return mx;
    }
    int getMin()
    {
        Node *temp = head;
        int mn = INT32_MAX;
        while (temp != nullptr)
        {
            if (temp->data < mn)
                mn = temp->data;
            temp = temp->next;
        }
        return mn;
    }
    int findNode(int key)
    {
        Node *temp = head;
        int pos = 1;
        while (temp != nullptr)
        {
            if (temp->data == key)
                return pos;
            pos++;
            temp = temp->next;
        }
        return -1;
    }
    ~LinkedList()
    {
        Node *current = head;
        while (current != NULL)
        {
            head = head->next;
            delete current; /// delete 0x10
            current = head;
        }
    }
};

int main()
{
    LinkedList l;

    l.addToHead(3);
    l.addToHead(4);
    l.addToHead(5);
    // cout << l.findNode(1) << endl;
    l.print();

    return 0;
}
