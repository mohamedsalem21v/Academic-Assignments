#include <bits/stdc++.h>
using namespace std;
int max_size = 100;

class StackUsingArray
{
public:
    int top;
    int items[100];
    StackUsingArray()
    {
        top = -1;
    }

    bool empty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (top == max_size - 1)
        {
            cout << "The stack is full." << endl;
            return;
        }
        items[++top] = value;
    }

    void pop()
    {
        if (empty())
        {
            cout << "The stack is empty." << endl;
            return;
        }
        top--;
    }

    void topEL()
    {
        if (empty())
            return void(cout << "The stack is empty." << endl);
        cout << items[top] << endl;
    }   

    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    int searchStack(int value)
    {
        int pos = -1;
        for (int i = top; i >= 0; i--)
        {
            if (items[i] == value)
            {
                pos = top - i;
                break;
            }
        }
        return pos;
    }

};

int main()
{
    StackUsingArray stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();
    stack.topEL();
    
    return 0;
}