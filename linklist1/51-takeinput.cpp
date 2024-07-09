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
/*node *takeinput()
{

   int data;
   cin >> data;
   node *head = NULL;
   while (data != -1)
   {
       node *n1 = new node(data);
       if (head == NULL)
       {
           head = n1;
       }
       else
       {
           node *temp = head;
           while (temp->next!= NULL)
           {                                 //time complexity O(n ^2)
               temp = temp->next;
           }
           temp->next = n1;

       }

        cin >> data;
   }
   return head;
}*/
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

int ithdata(node *temp, int p)
{

    int count = 1;
    while (count < p)
    {
        temp = temp->next;
        count++;
    }
    return temp->data;
}

void print(node *temp)
{

    while (temp != NULL)
    { // for printing upto last nods use = temp1= NULL
      // last  node se pahle tak ke liye temp->next!= NULL
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    node *temp = takeinput();
    print(temp);
    cout << lengthlink(temp)<<endl;
    cout<<ithdata(temp,3)<<endl;
    return 0;
}