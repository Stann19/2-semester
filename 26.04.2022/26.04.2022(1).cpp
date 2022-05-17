#include <iostream>
using namespace std;

struct BinaryTree {
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

void osnov(BinaryTree* &root, int a) {
    if (root == nullptr) {
        root = new BinaryTree;
        root->data = a;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (a > root->data) {
        osnov(root->right, a);
    }
    else {
        osnov(root->left, a);
    }
}

void del(BinaryTree* &root)
{
    if (root != nullptr)
    {
        del(root->left);
        del(root->right);
        delete root;
    }
}

void output(BinaryTree* &root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << "(";
        output(root->left);
        cout << root->data;
        output(root->right);
        cout << ")";
    }
}

int main()
{
    int a;
    cin >> a;
    BinaryTree* root = NULL;
    while (a != 0)
    {
        osnov(root, a);
        cin >> a;
    }
    output(root);
    del(root);
}

