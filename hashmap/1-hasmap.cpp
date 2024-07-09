#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

int maximumfrequancy(int a[],int size){
      
      unordered_map<int,int>seen;
      int max=1;
      for(int i=0;i<size;i++){
     
            seen[a[i]]++;
        
            
             if( max<seen[a[i]]){
                    max=seen[a[i]];
             }
        }
        

    
      

     return max; 
}




 int main(){
     int a[11]=  {1,2,2,3,4,1,43,4,5,6,7};
    cout<<maximumfrequancy(a,11);
 }




