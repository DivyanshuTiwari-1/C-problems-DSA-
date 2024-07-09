#include<iostream>
using namespace std;
#include<stack>

bool bracketcheack(string str){
    stack<char>s;
    for (int i=0;i<str.length();i++){
          if(str[i]=='{'||str[i]=='['||str[i]=='('){
            s.push(str[i]);
          }
        else if (str[i]=='}'||str[i]==']'||str[i]==')'){
            
          s.pop();
            
        }
        
    }
    if (s.empty()){
        return true;
    }
    return false;
}

int main(){
    
    string str="(((()))(";
   cout<< bracketcheack(str);

}