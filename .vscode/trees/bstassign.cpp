#include <iostream>
#include "binarytree.h"
#include <queue>
#include <stack>
#include "bstclass.h"
using namespace std;

void printtree(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printtree(root->left);
    printtree(root->right);
}

binarytreenode<int> *takeinput()
{
    int rootdata;
    cout << "enter data";
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    binarytreenode<int> *root = new binarytreenode<int>(rootdata);
    binarytreenode<int> *leftchild = takeinput();
    binarytreenode<int> *rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}
binarytreenode<int> *takeinputlw()
{
    int rootdata;
    cout << "enter root data" << endl;
    cin >> rootdata;
    binarytreenode<int> *root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {

        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter left child data" << front->data << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            binarytreenode<int> *leftchild = new binarytreenode<int>(leftchilddata);
            front->left = leftchild;
            pendingnodes.push(leftchild);
        }

        cout << "enter right child data" << front->data << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            binarytreenode<int> *rightchild = new binarytreenode<int>(rightchilddata);
            front->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}
void printlevelwise(binarytreenode<int> *root)
{

    queue<binarytreenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pendingnodes.push(front->left);
        }
        else
        {
            cout << "L -1";
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingnodes.push(front->right);
        }
        else
        {
            cout << "R -1";
        }
        cout << endl;
    }
}

binarytreenode<int> *insertduplicate(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    binarytreenode<int> *newroot = new binarytreenode<int>(root->data);
    binarytreenode<int> *temp = root->left;
    newroot->left = temp;
    root->left = newroot;
    binarytreenode<int> *left = insertduplicate(newroot->left);
    binarytreenode<int> *right = insertduplicate(root->right);
    newroot->left = left;
    root->right = right;
    return root;
}

int main()
{
    binarytreenode<int> *root = takeinputlw();
    printlevelwise(root);
    binarytreenode<int> *root1=insertduplicate(root);
    printlevelwise(root1);
}