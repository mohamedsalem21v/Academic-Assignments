#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
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

    void push(char value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = top;
        top = newnode;
    }

    char peek()
    {
        if (empty())
        {
            cout << "The stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    void pop()
    {
        if (empty())
            return void(cout << "The stack is empty." << endl);
        Node *del = top;
        top = top->next;
        delete del;
    }

    void print()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

string reverse(string st)
{
    string a = "";
    linked_stack stk;
    for (int i = 0; i < st.size(); i++)
    {
        stk.push(st[i]);
    }
    while (!stk.empty())
    {
        a += stk.peek();
        stk.pop();
    }
    return a;
}

bool checkBalance_1(string s)
{
    linked_stack st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (!st.empty())
        {
            if ((st.peek() == '(' and s[i] == ')') or (st.peek() == '{' and s[i] == '}') or (st.peek() == '[' and s[i] == ']'))
                st.pop();
            else
                st.push(s[i]);
        }
        else
            st.push(s[i]);
    }
    if (st.empty())
        return true;
    return false;
}

bool checkBalance_2(string s)
{
    linked_stack st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            if ((st.peek() == '(' and s[i] == ')') or (st.peek() == '{' and s[i] == '}') or (st.peek() == '[' and s[i] == ']'))
                st.pop();
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
}

int priority(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' or op == '/')
        return 2;
    else if (op == '+' or op == '-')
        return 1;
    else
        return 0;
}

string infix_to_postfix(string inf)
{
    linked_stack s;
    string postfix = "";
    for (int i = 0; i < inf.size(); i++)
    {
        if (isdigit(inf[i]))
        {
            string num = "";
            while (i < inf.size() and isdigit(inf[i]))
            {
                num += inf[i];
                i++;
            }
            i--;
            postfix += num + ' ';
        }
        else if (inf[i] == '(')
        {
            s.push(inf[i]);
        }

        else if (inf[i] == ')')
        {
            while (!s.empty() && s.peek() != '(')
            {
                postfix += s.peek();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() and priority(s.peek()) >= priority(inf[i]))
            {
                postfix += s.peek();
                s.pop();
            }
            s.push(inf[i]);
        }
    }
    while (!s.empty())
    {
        postfix += s.peek();
        s.pop();
    }
    return postfix;
}

int evalExpression(string post)
{
    linked_stack s;
    for (int i = 0; i < post.size(); i++)
    {
        if (isspace(post[i]))
            continue;
        if (isdigit(post[i]))
        {
            int num = 0;
            while (i < post.size() and isdigit(post[i]))
            {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            i--;
            s.push(num);
        }
        else
        {
            int second = s.peek();
            s.pop();
            int first = s.peek();
            s.pop();
            switch (post[i])
            {
            case '+':
                s.push(first + second);
                break;
            case '-':
                s.push(first - second);
                break;
            case '*':
                s.push(first * second);
                break;
            case '/':
                s.push(first / second);
                break;
            case '^':
                s.push(pow(first, second));
                break;
            }
        }
    }
    return s.peek();
}

int searchStack(linked_stack st, int value)
{
    int pos = 0;
    while (!st.empty() and st.peek() != value)
    {
        st.pop();
        pos++;
    }
    return (st.peek() == value ? pos : -1);
}

bool isPalindrome(string s)
{
    linked_stack st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
            return false;
        if (s[i] != st.peek())
            return false;
        st.pop();
    }
    return true;
}

string decToBin(int n)
{
    if (n == 0)
        return "0";
    linked_stack st;
    while (n > 0)
    {
        st.push(n % 2 + '0');
        n /= 2;
    }
    string bin = "";
    while (!st.empty())
    {
        bin += st.peek();
        st.pop();
    }
    return bin;
}

int main()
{

    string st = "Hello, World!";
    cout << reverse(st) << endl;

    string s = "(())(())";
    if (checkBalance_1(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    if (checkBalance_2(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    string inf = "(3+4)+8/2*((6+4)*2)";
    cout << infix_to_postfix(inf) << endl;

    string post = "3 4 + 8 2 / 6 4 + 2 * *";
    cout << evalExpression(post) << endl;

    
    int value = 4;
    linked_stack stck;
    stck.push(1);
    stck.push(2);
    stck.push(3);
    stck.push(4);
    stck.push(5);
    int pos = searchStack(stck, value);
    if (pos != -1)
        cout << "Position: " << pos << endl;
    else
        cout << "not found" << endl;


    string palin = "abba";
    if (isPalindrome(palin))
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;


    int n = 10;
    cout << decToBin(n) << endl;

    return 0;
}