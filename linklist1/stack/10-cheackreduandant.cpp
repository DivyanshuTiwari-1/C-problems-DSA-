#include<iostream>
using namespace std;
#include<stack>

bool isredundant( string str){
int c=0;stack<char>s;
for( int i=0;i<str.length();i++){
   
     if( str[i]=='('){
    s.push(str[i]);
   }
   else if (str[i]==')'){
     while(s.top()!='('){
        s.pop();
        c++;
     }s.pop();
     
     if(str.length()==0){
      break;
     }
     c=0;
   }
   else  {
    s.push(str[i]);
    
   }
   
   }
if(c==0){
    return true;
}
else return false;

}

int main(){
    string str ="(a+(b+c)";
    cout<<isredundant(str);
}