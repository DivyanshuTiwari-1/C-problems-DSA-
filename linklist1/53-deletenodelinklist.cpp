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

node *deletenode(node *head, int pos)
{

    node *temp = head;
    node *prev = NULL;
    int count = 0;

    if (pos < 0)
    {

        cout << "can not be  delated";
        return head;
    }

    while (count < pos - 1)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

int index(node *head, int data)
{

    node *temp = head;
    int count = 0;
    while (temp->data != -1)
    {
        if (temp->data == data)
        {
            return count;
            break;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}

node *appandtolast(node *head, int pos)
{
    node *head1 = NULL;
    node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    head1 = temp->next;
    ;
    temp->next = NULL;
    node *temp2 = head1;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = head;
    return head1;
}
node *removedupli(node *head)
{
    node *t1 = head;
    node *t2 = head->next;

    if (t1 == NULL || t2 == NULL)
    {
        return t1;
    }
    while(t2!=NULL){
    if (t1->data != t2->data)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    else if (t2->data = t1->data)
    {
        node *temp = t2;
        t2 = t2->next;
        delete (temp);
    }
    t1->next = t2;
}
    return head;
}

void printreverse(node* head){
    if( head==NULL){
        return;
    }
    printreverse(head->next);
    cout<<head->data<<" ";
}







int main()
{
    node *head = takeinput();
    print(head);
    cout << endl;
  //  node *temp = removedupli(head);
  //  print(temp);
  printreverse(head);
}