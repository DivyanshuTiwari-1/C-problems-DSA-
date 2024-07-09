#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int>arrinter(int arr1[],int arr2[], int n,int m){
  vector<int>output;
  unordered_map<int,int>seen;

 for(int i=0;i<n;i++){

  seen[arr1[i]]=true;
 }

 for(int i=0;i<m;i++){
  if(seen.count(arr2[i])>0 ){
    output.push_back(arr2[i]);
 }


}
return output;
}
int main(){
  int ar1[4]={2,6,1,2};
  int ar2[5]={1,2,3,4,2};
     vector<int>output=arrinter(ar1,ar2,4,5);
     for(int i=0;i<output.size();i++){
      cout<<output.at(i);
     }
return 0;
}