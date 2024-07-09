#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
int countofpair(int a[],int n){
    unordered_map<int,int>seen;
    int cou=0;
    for (int i=0;i<n;i++){
         if( seen.count(-a[i])>0){
           cou++;
         }

         seen[a[i]]=true;
    }
    return cou;
}
int main(){
    int arr[5]={2,1,-2,2,4};
    cout<<countofpair(arr,5)<<endl;

}
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