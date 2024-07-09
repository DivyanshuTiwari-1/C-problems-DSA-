#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int nextindex;
    int capacity;

public:
  /*  stack(int totalsize)
    {
        arr = new int[totalsize];
        nextindex = 0;  rather wrrting it we can use dynamic allocation .
        capacity = totalsize;
    }*/

stack (){
    arr= new int [4];
    nextindex=0;
    capacity=4;
}
    int size()
    {
        return nextindex;
    }

    bool isempty()
    { if (nextindex==0){
        return true ;
    }
      return false;
    }

    int top()
    {

        return arr[nextindex - 1];
    }
    int pop()
    {
        if (isempty()==1){
            cout<<"cant be delleted"<<endl;
        }
        
        nextindex--;
        return arr[nextindex];
        
    }
    void push(int data)
    {
        if (nextindex == capacity)
        { 
             int *nearr= new int [2*capacity];
             for( int i=0;i<capacity;i++){
                nearr[i]=arr[i];

             }
             delete [] arr;
             arr=nearr;
             capacity*=2;
        }
        arr[nextindex] = data;
        nextindex++;
    }
};

int main (){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout<<s.top()<<endl;
 
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
   
    cout<<s.pop()<<endl;

   cout<<s.size()<<endl;


 
}
