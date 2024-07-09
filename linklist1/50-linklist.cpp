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
 void print ( node * temp) {
    
    while (temp !=NULL)
    {                                  // for printing upto last nods use = temp1= NULL
                                       // last  node se pahle tak ke liye temp->next!= NULL 
        cout << temp->data << endl;
        temp = temp->next;
    }
 }

 void bubbleshort(int arr[], int n){
   for(int i=0;i<n;i++){
    for (int j=0;j<n-i;j++){
        if(arr[j]>arr[j+1]){
            int t =arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t;
        }
    }

   }

 }

int main()
{
    node n1(10);
    node *head = &n1;
    node *temp = head;
    node n2(20);
    node *n3 = new node(30);
    n1.next = n3;
    n3->next = &n2;
  // print (temp);
  int arr[] ={5,4,3,2,1};
  bubbleshort(arr,5);
  for(int i=0;i<5;i++){
    cout<<arr[i];
  }
    return 0;
}