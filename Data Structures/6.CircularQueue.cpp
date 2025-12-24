#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

class CircularQueue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return front == (rear + 1) % MAX_SIZE;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else if (isEmpty())
        {
            front++;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int temp = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            throw "Queue is empty!\n";
        }
        else
            return arr[front];
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }

    int length()
    {
        if (isEmpty())
            return 0;
        if (rear >= front)
            return rear - front + 1;
        return MAX_SIZE - (front - rear - 1);
    }

    void enqueueN(int values[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            enqueue(values[i]);
        }
    }

    vector<int> dequeueN(int n)
    {
        vector<int> removed;
        for (int i = 0; i < n; i++)
        {
            if (isEmpty())
                break;
            removed.push_back(dequeue());
        }
        return removed;
    }

    int searchqueue(int value)
    {
        if (isEmpty())
            return -1;
        int index = front;
        int pos = 0;
        while (true)
        {
            if (arr[index] == value)
                return pos;
            if (index == rear)
                break;
            index = (index + 1) % MAX_SIZE;
            pos++;
        }
        return -1;
    }
};

int main()
{
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    cout << q.dequeue() << endl;
    q.print();
    int arr[] = {40, 50, 60};
    q.enqueueN(arr, 3);
    q.print();
    vector<int> removed = q.dequeueN(2);
    for (int val : removed)
        cout << val << " ";
    cout << endl;
    q.print();
    cout << "Length: " << q.length() << endl;
    cout << "Index of 50: " << q.searchqueue(50) << endl;
    cout << "Index of 100: " << q.searchqueue(100) << endl;
    return 0;
}