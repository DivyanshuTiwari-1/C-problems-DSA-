#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(node *temp)
{

    while (temp != NULL)
    { // for printing upto last nods use = temp1= NULL
      // last  node se pahle tak ke liye temp->next!= NULL
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node *takeinput()
{

    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *n1 = new node(data);
        if (head == NULL)
        { // now tail doing thje constant work by moving only
          // one steo ahead ;
          // so it is a good way as time complexity is o ( n)
            head = n1;
            tail = n1;
        }
        else
        {
            tail->next = n1;
            tail = n1;
        }

        cin >> data;
    }
    return head;
}

int lengthrecursively(node *head)
{

    if (head == NULL)
    {
        return 0;
    }
    else if (head->next == NULL)
    {

        return 1;
    }
    return 1 + lengthrecursively(head->next);
}

node *insertnode(node *head, int data, int i)
{

    if (head == NULL)
    {
        return head;
    }
    else if (i == 0)
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }
    node *temp = insertnode(head->next, data, i - 1);
    head->next = temp;
    return head;
}

node *deletenode(node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    else if (pos == 0)
    {
        node *temp = head->next;
        free(head);
        return temp;
    }
    node *temp = deletenode(head->next, pos - 1);
    head->next = temp;
    return head;
}

int main()
{
    node *head = takeinput();
    print(head);
    cout << endl;
    cout << lengthrecursively(head);
    // node *temp =insertnode(head,24,3);
    // print(temp);
    cout << endl;
    node *temp1 = deletenode(head, 3);
    // print(temp);
    print(temp1);
}