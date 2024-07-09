#include <iostream>
#include<string.h>
using namespace std;

void returncodes(string s, string output[])
{

    if (s.length() == 0)
    {
        return;
    }
    char c1 = (s[0] - 48) + 96;
    returncodes(s.substr(1), output + c1);
    int d = (s[0]-48)*10 +(s[1]-48);
    if (d >= 10 && d <= 26)
    {
        char c2 = d + 96;
        returncodes(s.substr(1),output+c2);
    }
}
int getanswer(string s,string output[]){

 string out =" ";
returncodes(s,out);
for(int i=0;i<out.size();i++){
    output[i]=out[i];
}
int x= out.size();
return x;


}



int main()
{
    string s;
    cin >> s;
    string output[100];
    int count = getanswer(s,output);

   for (int i=0;i<5;i++){
    cout<<output[i]<<endl;
   }
  

    return 0;
}