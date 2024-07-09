#include<iostream>
using namespace std;
#include<cstring>

 int main(){
  char input1[100]="abcd",input2[100]="acvd" ;
 /*cin>>input1;
  cin>>input2;
 /* int len =strlen(input);// for calculating length of string 
  cout<<len<<endl;
*/

//cout<<strcmp(input1,input2);//for comparing two string

strcpy(input1,input2);//for copy the string
cout<<input1;
strncpy(input1,input2,3);//for copying first n charcter

cout<<strncpy;

return 0;
}
