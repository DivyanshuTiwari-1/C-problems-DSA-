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
int lengthlink(node *temp)
{

    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int indexnode(node *head, int data, int pos)
{
    if (head == NULL)
    {
        int i = -(lengthlink(head) + 1);
        return i;
    }
    else if (head->data == data)
    {
        return pos;
    }
    else
    {

        return indexnode(head->next, data, pos + 1);
    }
}
int index_node(node *head, int data)
{
    return indexnode(head, data, 0);
}

node *evenafterodd(node *head)
{
    node *oh = NULL;
    node *ot = NULL;
    node *eh = NULL;
    node *et = NULL;
    while (head != NULL)
    {

        if ((head->data) % 2 == 1)
        {
            if (oh == NULL)
            {
                oh = head;
                ot = head;
            }
            else
            {
                ot->next = head;
                ot = ot->next;
            }
            head = head->next;
        }
        else
        {
            if (eh == NULL)
            {
                eh = head;
                et = head;
            }
            else
            {
                et->next = head;
                et = et->next;
            }
            head = head->next;
        }
    }
    if (oh == NULL)
    {
        et->next = NULL;
    }
    else if (eh == NULL)
    {
        ot->next = NULL;
    }
    else
    {
        ot->next = NULL;
        et->next = NULL;
    }
    et->next = oh;
    return eh;
}
node *everynnodes(node *head, int m, int n)
{
    node *t1 = head;
    node *t2 = NULL;
    int c;
    while (t1 != NULL)
    {
        for (c = 1; c <= m && t1 != NULL; c++)
        {
            t1 = t1->next;
        }
        if (t1 == NULL)
        {
            return t1;
        }
        t2 = t1->next;
        for (c = 1; c <= n && t2 != NULL; c++)
        {
            node *temp = t2;
            t2 = t2->next;
            free(temp);
        }
        t1->next = t2;
    }
}

void swaapll(node *head, int i, int j)
{

    node *temp1 = head;
    node *temp2 = head;
    node *temp3 = head;
    int a = 0;
    while (a < i - 1)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        a++;
    }
    temp2 = temp2->next;
    a = 0;
    while (a < j)
    {
        temp3 = temp3->next;
        a++;
    }
    temp1->next = temp3;
    temp2->next = temp3->next;
    temp3->next = temp2;
}

node *reverselink(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *smallans = reverselink(head->next);
    node *temp = smallans;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallans;
}

node *bubblesort(node *head)
{

    int l = lengthlink(head);
    node*h1=head;
    node*h2=head->next;
    int swap=0;
    for (int i = 0; i < l; i++)
    {      for(int j=0;j<l-i;j++){

            if(h1->data>h2->data){
                node* temp=h2->next;
               h2->next=h1;
               h1->next=temp;
               h2=h1->next;
               swap=1;
            }
            else{
               
                
            }
          



    }  if(swap==0){
            break;
         }
          
    
    
    }
    return head;
}

int main()
{
    node *head1 = takeinput();
    node *temp = bubblesort(head1);
    print(temp);
}