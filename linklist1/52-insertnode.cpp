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
void print(node *temp)
{

    while (temp != NULL)
    { // for printing upto last nods use = temp1= NULL
      // last  node se pahle tak ke liye temp->next!= NULL
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

node *insertnode(node *head, int data, int pos)
{

    node *temp = head;
    int count = 1;
    node *newnode = new node(data);
    if ( pos<=0){
        cout<<"cannot inserted";
        return head;
    }
else if ( pos==1){
     newnode->next =head;
     return newnode;
 }
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

int main()
{ 
    node *head = takeinput();
    print (head);
    node *temp =insertnode(head,25,1);
    print(temp);
}
