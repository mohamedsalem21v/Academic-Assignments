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

class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void AddToHead(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (isEmpty())
        {
            head = newnode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            newnode->next = head;
            head = newnode;
            temp->next = head;
        }
    }

    void addToTail(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (isEmpty())
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void insertAfter(int data, int value)
    {
        if (isEmpty())
            return;
        Node *temp = head;
        while (temp->next != head && temp->data != data)
        {
            temp = temp->next;
        }
        if (temp->data == data)
        {
            Node *newnode = new Node();
            newnode->data = value;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    int findNode(int value)
    {
        if (isEmpty())
            return -1;
        Node *temp = head;
        int index = 1;
        while(temp->next != head)
        {
            if (temp->data == value)
                return index;
            temp = temp->next;
            index++;
        }
        if (temp->data == value)
            return index;
        return -1;
    }

    void deleteFromHead()
    {
        if (isEmpty())
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node *delNode = head;
        head = head->next;
        temp->next = head;
        delete delNode;
    }

    void deleteFromTail()
    {
        if (isEmpty())
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    void deleteNode(int value)
    {
        if (isEmpty())
            return;
        if (head->data == value)
        {
            deleteFromHead();
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp->next != head && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data == value)
        {
            prev->next = temp->next;
            delete temp;
        }
    }

    int countList()
    {
        int count = 0;
        if (isEmpty())
            return count;
        Node *temp = head;
        while(temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        count++;
        return count;
    }

    void printList()
    {
        if (isEmpty())
            return;
        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    ~CircularLinkedList()
    {
        if (isEmpty())
            return;
        Node *temp = head;
        Node *nextNode = nullptr;
        while (temp->next != head)
        {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete temp;
    }
};

int main()
{

    return 0;
}