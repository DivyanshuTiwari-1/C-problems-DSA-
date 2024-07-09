#include <iostream>
using namespace std;

template <typename T>
class node
{
  public:
  T data;
  node<T> *next;


  node(T data)
  {
    this->data = data;
    this->next = NULL;
  }
};
template <typename T>
class queueusingll
{

  node<T> *head;
  node<T> *tail;
  int size;

public:
  queueusingll()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }
  int getsize()
  {
    return size;
  }
  bool isempty()
  {
    return head == NULL;
  }
  void enqueue(T data)
  {
    if(head==NULL){
      node<T> *newnode = new node<T>(data);
      head=newnode;
      tail=newnode;
    }
    
    node<T> *newnode = new node<T>(data);

    tail->next = newnode;
    tail = newnode;
    size++;
  }
  T dequeue()
  {
    if (isempty())
    {
      cout << "queue is empty:" << endl;
      return 0;
    }
    node<T> *temp = head;
    head = head->next;
    T ans = temp->data;
    delete (temp);
    size--;
    return ans;
  }
  T front()
  {
    return head->data;
  }
};

int main(){
    queueusingll<int>q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;


    
}