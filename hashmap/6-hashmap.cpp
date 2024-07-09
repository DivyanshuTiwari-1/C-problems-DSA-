#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int countofkdifferanceinarr(int a[],int n,int k){
    unordered_map<int,bool>seen1;
    unordered_map<int,int>seen;

    for( int i=0;i<n;i++){
        seen1[a[i]]=true;
        seen[a[i]]=0;
    }
    int c=0;
    

    for (int i=0;i<n;i++){
       if(seen1.count(a[i])>0){
        
          seen[a[i]]++;

          
       }

    }
    for (int i=0;i<n;i++){
        if (seen.count(a[i]+k)>0 ||seen.count(a[i]-k)>0 ){
            c+=(seen.count(a[i])*(seen.count(a[i]+k)+seen.count(a[i]-k)));
            seen[a[i]]=0;
            seen[a[i]+k]=0;
            seen[a[i]-k]=0;
        } 
    }
    return c;

}
int main(){
    int arr[]={4,4,4,4};
    cout<<countofkdifferanceinarr(arr,4,0);


    }
