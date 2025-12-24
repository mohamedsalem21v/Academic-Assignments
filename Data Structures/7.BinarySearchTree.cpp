#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
public:
    Node *root;
    Tree() { root = nullptr; }

private:
    Node *insert(Node *root, int val)
    {
        if (root == nullptr)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        return root;
    }

    Node *MinItem(Node *r)
    {
        if (r == nullptr)
            return nullptr;
        else if (r->left == nullptr)
            return r;
        else
            MinItem(r->left);
    }

    Node *MaxItem(Node *r)
    {
        if (r == nullptr)
            return nullptr;
        else if (r->right == nullptr)
            return r;
        else
            MaxItem(r->right);
    }

    Node *Delete(Node *node, int val)
    {
        if (node == nullptr)
            return nullptr;

        if (val < node->data)
            node->left = Delete(node->left, val);
        else if (val > node->data)
            node->right = Delete(node->right, val);
        else
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = MinItem(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
        return node;
    }

    void PreOrder(Node *r) // root->left->right
    {
        if (r == nullptr)
            return;
        cout << r->data << " ";
        PreOrder(r->left);
        PreOrder(r->right);
    }

    void InOrder(Node *r) // left->root->right
    {
        if (r == nullptr)
            return;
        InOrder(r->left);
        cout << r->data << " ";
        InOrder(r->right);
    }

    void PostOrder(Node *r) // left->right->root
    {
        if (r == nullptr)
            return;
        PostOrder(r->left);
        PostOrder(r->right);
        cout << r->data << " ";
    }

    int getSize(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + getSize(node->left) + getSize(node->right);
    }

    int getDepth(Node *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }

    void destroyTree(Node *node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    void insert(int val)
    {
        root = insert(root, val);
    }

    void Delete(int val)
    {
        root = Delete(root, val);
    }

    void printInorder()
    {
        InOrder(root);
        cout << endl;
    }

    void printPreorder()
    {
        PreOrder(root);
        cout << endl;
    }

    void printPostorder()
    {
        PostOrder(root);
        cout << endl;
    }

    int getSize()
    {
        return getSize(root);
    }

    int getDepth()
    {
        return getDepth(root);
    }

    int getMin()
    {
        if (root == nullptr)
            return -1;
        Node *current = root;
        while (current->left)
            current = current->left;
        return current->data;
    }

    int getMax()
    {
        if (!root)
            return -1;
        Node *current = root;
        while (current->right)
            current = current->right;
        return current->data;
    }

    ~Tree()
    {
        destroyTree(root);
    }
};

int main()
{
    Tree t;

    t.insert(50);
    t.insert(30);
    t.insert(20);
    t.insert(40);
    t.insert(70);
    t.insert(60);
    t.insert(80);

    cout << "Inorder: ";
    t.printInorder();

    cout << "Preorder: ";
    t.printPreorder();

    cout << "Postorder: ";
    t.printPostorder();

    cout << "Size: " << t.getSize() << endl;
    cout << "Depth: " << t.getDepth() << endl;
    cout << "Min: " << t.getMin() << endl;
    cout << "Max: " << t.getMax() << endl;

    cout << "Deleting 20" << endl;
    t.Delete(20);
    cout << "Inorder after delete: ";
    t.printInorder();

    return 0;
}