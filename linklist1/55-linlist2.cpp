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

node *returnmid(node *head)
{
    int len = lengthlink(head);
    node *slow = head;
    node *fast = head->next;
    if (len % 2 == 1)
    {
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    else
    {
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
}

node *mergeing(node *h1, node *h2)
{

    node *Fh = NULL;
    node *Ft = NULL;
    if (h1->data < h2->data)
    {
        Fh = h1;
        Ft = h1;
        h1 = h1->next;
    }
    else
    {
        Fh = h2;
        Ft = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {

        if (h1->data < h2->data)
        {
            Ft->next = h1;
            Ft = h1;
            h1 = h1->next;
        }
        else
        {
            Ft->next = h2;
            Ft = h2;
            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        Ft->next = h1;
    }
    else if (h2 != NULL)
    {
        Ft->next = h2;
    }
    return Fh;
}

node *mergeshort(node *head)
{

    if (head->next == NULL)
    {
        return head;
    }

    node *mid = returnmid(head);
    node *h2 = mid->next;
    mid->next = NULL;
    node *temp1 = mergeshort(head);
    node *temp2 = mergeshort(h2);
    node *temp3 = mergeing(temp1, temp2);
    return temp3;
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

/*class pair
{
public:
    node *head;
    node *tail;
};

pair reverse_link(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        pair ans;
        ans.head = head;
        ans.tail = head;
    }
    pair smallans = reverse_link(head->next);
    smallans.tail->next = head;
    head->next = NULL;

    pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}

node *reverse_link2(node *head)
{
    return reverse_link(head).head;
}
*/
node *reverseitrative( node* head){
    node* prev=NULL;
    node*c=head;
    node*n = head->next;
    while (c->next!=NULL){
        c->next=prev;
        prev=c;
        c=n;
        n=n->next;
    }
    c->next=prev;
  prev =c;
    return prev;
}
int main()
{
    node *head1 = takeinput();
    // node *head2 = takeinput();
        node *temp =reverseitrative(head1);
      print(temp);
}
