#include<iostream>
using namespace std;

/*class node{
    public:
   
    int data;
    node*next;
    
    node(int data){
        this->data =data;
        this->next=NULL;
    }
};

class stackll {
    node*head;
    int size;
public:
    stackll(){
        head=NULL;
        size=0;
    }
    int getsize(){
        return size;
    }
    
    bool isempty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
    void push(int data){
        node*newnode=new node(data);
        if(head==NULL){
            head=newnode;
            size++;
        }
        else {
            newnode->next=head;
            head=newnode;
            size++;
        }
        
    }
    int top(){
        if(isempty()){
            return 0;
        }
        return head->data;
    }
    int pop(){
         if(isempty()){
            return 0;
        }
        else {
          int t=head->data;
          head=head->next;
             size--;  
         return t;

    }
    }
    };

int main(){
    stackll s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.getsize()<<endl;


}*/
template<typename T>
class node{
    public:
   
    T data;
    node<T>*next;
    
    node(T data){
        this->data =data;
        this->next=NULL;
    }
};
template<typename T>
class stackll {
    node<T>*head;
    int size;
public:
    stackll(){
        head=NULL;
        size=0;
    }
    int getsize(){
        return size;
    }
    
    bool isempty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
    void push(T data){
        node<T>*newnode=new node<T>(data);
        if(head==NULL){
            head=newnode;
            size++;
        }
        else {
            newnode->next=head;
            head=newnode;
            size++;
        }
        
    }
    T top(){
        if(isempty()){
            return 0;
        }
        return head->data;
    }
    T pop(){
         if(isempty()){
            return 0;
        }
        else {
          T t=head->data;
          head=head->next;
             size--;  
         return t;

    }
    }
    };

int main(){
    stackll <double>s;
    s.push(10.1);
    s.push(20.2);
    s.push(30.3);
    s.push(40.4);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.getsize()<<endl;


}