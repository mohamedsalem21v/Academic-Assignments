#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class Doubly_List
{
public:
    Node *head;
    Doubly_List()
    {
        head = nullptr;
    }

    bool empty()
    {
        return (head == nullptr);
    }

    void addToHead(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (empty())
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void addToTail(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (empty())
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    int findNode(int value)
    {
        Node *temp = head;
        int position = 0;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1; // Not found
    }

    int deleteFromHead()
    {
        if (empty())
        {
            cout << "The linked list is empty." << endl;
            return -1;
        }
        Node *delptr = head;
        int val = delptr->data;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete delptr;
        return val;
    }

    int deleteFromTail()
    {
        if (empty())
        {
            cout << "The linked list is empty." << endl;
            return -1;
        }
        Node *temp = head;
        if (head->next == nullptr)
        {
            int val = head->data;
            delete head;
            head = nullptr;
            return val;
        }
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        int val = temp->data;
        temp->prev->next = nullptr;
        delete temp;
        return val;
    }

    void deleteNode(int value)
    {
        if (empty())
        {
            cout << "The linked list is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Not found." << endl;
            return;
        }
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        delete temp;
    }

    void reverse()
    {
        Node *current = head;
        Node *temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAfter(int target, int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        Node *temp = head;

        while (temp != nullptr && temp->data != target)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Item not found." << endl;
            delete newnode;
            return;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = newnode;
        temp->next = newnode;
    }

    ~Doubly_List()
    {
        Node *current = head;
        Node *nextNode;
        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    Doubly_List dll;

    return 0;
}