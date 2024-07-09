#include<iostream>
using namespace std;
#include<stack>
#include<queue>
/*void reversestack( stack<int> &s,stack<int> &s1){
    if(s.size()==0||s.size()==1){
          return;

    }
    int X=s.top();
    s.pop();
   reversestack(s,s1);
   while(!s.empty()){
    int x=s.top();
    s.pop();
    s1.push(x);

   }
   s.push(X);
  while(!s1.empty()){
    int x=s1.top();
    s1.pop();
    s.push(x);
   } 


}*/
void reversequeue(queue<int>&q){

    if(q.size()==0||q.size()==1){
        return;
    }
    int X=q.front();
    q.pop();
    reversequeue(q);
    q.push(X);




}
int main(){
    int n;
    cout<<"enter the size of queue"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>> arr[i];
    }
    
    
  /*  stack<int>s;
    for(int i=0;i<n;i++){
       s.push( arr[i]);
    }
  
    stack<int>s1;
   
   reversestack(s,s1);
   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
    
   }*/
    queue<int>q;
    for(int i=0;i<n;i++){
       q.push( arr[i]);
    }
    reversequeue(q);
   while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
    
   }
  
}