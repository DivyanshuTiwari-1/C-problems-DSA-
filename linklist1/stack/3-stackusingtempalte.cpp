#include <iostream>
using namespace std;
template<typename T>
class stack
{
    T *arr;
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
    arr= new T [4];
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

    T top()
    {

        return arr[nextindex - 1];
    }
    T pop()
    {
        if (isempty()==1){
            cout<<"cant be delleted"<<endl;
        }
        
        nextindex--;
        return arr[nextindex];
        
    }
    void push(T data)
    {
        if (nextindex == capacity)
        { 
             T *nearr= new T [2*capacity];
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
    stack <char>s;
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);

    cout<<s.top()<<endl;
 
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
   
    cout<<s.pop()<<endl;

   cout<<s.size()<<endl;


 
}
