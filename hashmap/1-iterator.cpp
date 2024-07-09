/*

itretors

unoredre mao ,vector ,set sab ke pass apna ek iterator hota
jiska use kar ke ham apna kam chala sakte hai
isko is taraf se access kiya jata h
unoredered_map<string,int>::itertors it;

it=ourmap.begin();
it++;
it=ourmap.end() ye last nhi h last ke bad wala h






*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    unordered_map<string,int>ourmap;
    ourmap["abc"]=1;
    ourmap["abc1"]=2;
    ourmap["abc2"]=3;

    ourmap["abc3"]=4;
    ourmap["abc4"]=5;
       unordered_map<string,int>::iterator it=ourmap.begin();
       while(it!=ourmap.end() ){
        cout<<"key:"<<it->first<<" "<<"value:"<<it->second<<endl;;
        it++;
       }
       vector<int>out;
       out.push_back(2);
       out.push_back(21);
       out.push_back(22);
       out.push_back(23);
       out.push_back(24);
       out.push_back(25);
      vector<int>::iterator it1=out.begin();
      while(it1!=out.end()){
        cout<<*it1<<endl;
        it1++;
      }

}/*


hass function
   key->hf=>integres
   hf
   /     \
hass    |  compression function
code    !   address to interge
&address|e.g.=%prime number
collison:- when to wants key points to same location 
collison handling:-
1) closed addressing -> use a linklist to stroed key &value and 
the array will contain the head of the the ll
2) open adressing;-
find aLTERNATE PLACE
h_i(a)=hf(a)+f(i) but f(0)->0
1)linear proping:f(i)->
2)quarditcf(i)->
3) double hasingf(i)->i*h'(a);
seprate chaining:-

*/
