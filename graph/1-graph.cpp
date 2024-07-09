#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;

void print(int **edge, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edge[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(edge, n, i, visited);
        }
    }
}

void printbfs(int **edge ,int n,int sv,bool *visited){
    
      queue<int>pendingque;
      pendingque.push(sv);
      visited[sv]=true;

   while(!pendingque.empty()){
          int currver=pendingque.front();
          cout<<currver<<endl;
          pendingque.pop();
          visited[currver]=true;
          for (int i=0;i<n;i++){
               if (i==currver){
                continue;
               }
               if (edge[currver][i]==1&& !visited[i]){
                pendingque.push(i);
               }

          }
   }
}
void dfs(int **edge,int n){
bool *visited=new bool [n];
    
    for (int i=0;i<n;i++){
        visited[i]=false;
    }
    for (int i=0;i<n;i++){
        if(!visited[i]){
            print(edge,n,i,visited);
        }
    }
   delete[] visited;
}



void bfs(int **edge,int n){
bool *visited=new bool [n];
    for (int i=0;i<n;i++){
        visited[i]=false;
    }
    for (int i=0;i<n;i++){
        if(!visited[i]){
            printbfs(edge,n,i,visited);
        }
    }
   delete[] visited;
}

bool haspathhelp(int ** edge ,int n,int sv,int e ,bool* visited){
   
    if (sv==e){
        return true;
    }
    if (edge[sv][e]==1){
        return true;

    }
    for (int i=0;i<n;i++){
        if (edge[sv][i]==1&& !visited[sv]){
               visited[sv]=true;
            return haspathhelp(edge,n,i,e ,visited);
            
        }
    }
    return false;


}
bool haspath(int **edge,int n,int sv ,int e ){
    bool *visited= new bool [n];
    for (int i=0;i<n;i++){
        visited[i]=false;
    }
    return haspathhelp(edge,n,sv,e,visited);
}

vector<int> printpathhelp(int **edge, int n, int sv, int e, bool *visited, vector<int> output) {
    if (sv == e) {
        output.push_back(sv);
        return output;
    }

    visited[sv] = true; // Move this line outside the loop

    for (int i = 0; i < n; i++) {
        if (edge[sv][i] == 1 && !visited[i]) {  // Fix the condition
            output.push_back(sv);
            vector<int> result = printpathhelp(edge, n, i, e, visited, output);
            
            // Check if a path is found
            if (!result.empty()) {
                return result;
            }
        }
    }

    // If no path is found, return an empty vector
    return vector<int>();
}

void printpath(int **edge, int n, int sv, int e) {
    vector<int> output;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    vector<int> ans = printpathhelp(edge, n, sv, e, visited, output);

    if (ans.empty()) {
        cout << "No path found";
        return;
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans.at(i) << " ";
    }
}
void printPathBFS(int **edge, int n, int sv, int e) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    queue<int> pendingQueue;
    unordered_map<int, int> output;
    pendingQueue.push(sv);
    output[sv] = -1;

    while (!pendingQueue.empty()) {
        int currVer = pendingQueue.front();
        pendingQueue.pop();

        for (int i = 0; i < n; i++) {
            if (edge[currVer][i] == 1 && !visited[i]) {
                pendingQueue.push(i);
                output[i] = currVer;
                visited[i] = true;

                if (i == e) {
                    int value = e;
                    while (value != -1) {
                        cout << value << " ";
                        value = output[value];
                    }
                    return;
                }
            }
        }
    }
}
void cheackisconnecteddfs(int **edge,int n,int sv,bool *visited){
     visited[sv]=true;
     for (int i=0;i<n;i++){
        if (i==sv){
            continue;
        }
       if (edge[sv][i]==1){
        if (visited[i]){
              continue;
        }
        cheackisconnecteddfs(edge,n,i,visited);
       }
     }
    


}

bool isconnected(int **edge,int n){
    bool *visited=new bool [n];
    for (int i=0;i<n;i++){
        visited[i]=false;
    }
    cheackisconnecteddfs(edge,n,0,visited);
    for (int i=0;i<n;i++){
        if (visited[i]==0){
            return false;
            
        }
    }
   return true;
}

vector<int>givecomponent(int **edge,int n,int sv, bool *visited,vector<int>khali){
    khali.push_back(sv);
    visited[sv]=true;

    for (int i=0;i<n;i++){
        if (i==sv){
            continue;
        }
        if (edge[sv][i]==1){
            if (visited[i]){
                continue;
            }
            vector<int>output=givecomponent(edge,n,i,visited,khali);
            return output;
        }
    }
    return khali;
}








vector<vector<int>>allconnectedcomponent(int **edge,int n){
    bool *visited=new bool [n];
    for (int i=0;i<n;i++){
        visited[i]=false;
    }
    vector<vector<int>>output;
    for (int i=0;i<n;i++){
        if (!visited[i]){
            vector<int>khali;
            vector<int>anderwala=givecomponent(edge,n,i,visited,khali);
            output.push_back(anderwala);
        }
    }
    return output;
}

int islandscomponent(int **edge,int n,int sv,bool *visited,int count){
       visited[sv]=true;
       
       for (int i=0;i<n;i++){
        if (i==sv){
            continue;
        }
        if (!visited[i]&&edge[sv][i]){
           int ans=islandscomponent(edge,n,i,visited,count); 
        }
        
       }
       count++;
       for (int i=0;i<n;i++){
        if (!visited[i]){
          int ans1= islandscomponent(edge,n,i,visited,count);
        }
       }
       return count;



}








int islandscomponentcount(int **edge ,int n){
    
    bool *visited=new bool[n];
    for (int i=0;i<n;i++){
        visited[i]=false;
    }
    return islandscomponent(edge,n,0,visited,0);


}

int largestpicehelp(int **cake,int n,int i,int j,int col,bool** visited){
     
     if (i<0||i>=n||j<0||j>=n){
        return 0;
     }
     if (cake[i][j]!=col){
        return 0;
     }
     
     if (visited[i][j]==true){
        return 0;
     }
     visited[i][j]=true;
     int count=0;
     
 
  count+= largestpicehelp(cake,n,i,j+1,1,visited);
  count+= largestpicehelp(cake,n,i,j-1,1,visited);
  count+= largestpicehelp(cake,n,i+1,j,1,visited);
  count+= largestpicehelp(cake,n,i-1,j,1,visited);

return count+1;




}

int largestpice(int **cake ,int n){
    bool **visited=new bool*[n];
    for (int i=0;i<n;i++){
        visited[i]=new bool [n];
        for (int j=0;j<n;j++){
            visited[i][j]=false;
        }
    }
  int  max=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (!visited[i][j]&&cake[i][j]==1){
                int ans=largestpicehelp(cake,n,i,j,1,visited);
                if (ans>=max){
                    max=ans;
                }
            }
        }
    }
   return max;
}


int threecycle(int **edge,int n){
    int count=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (edge[i][j]==1){
                for (int k=0;k<n;k++){
                    if (edge[j][k]==1&&edge[k][i]==1){
                        count++;
                    }
                }
            }
        }
    }
    return count/6;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
    // now we will ask where is edge
    for (int i = 0; i < e; i++)
    {
        int s, f;
        cin >> s >> f;
        edge[s][f] = 1;
        edge[f][s] = 1;
    }
//   int v1,v2;
//   cin>>v1>>v2;

//  cout<<haspath(edge,n,v1,v2)<<endl;
//  printpath(edge,n,v1,v2);
//  printPathBFS(edge,n,v1,v2);
//     return 0;
// cout<<isconnected(edge,n);
// vector<vector<int>>output=allconnectedcomponent(edge,n);
// for (int i=0;i<output.size();i++){
//     vector<int>temp=output[i];
//     for (int j=0;j<temp.size();j++){
//        cout<<temp.at(j)<<" ";
//     }
//     cout<<endl;
// }
// cout<<islandscomponentcount(edge,n);
// int n,m;
// cin>>n>>m;
//  char **word = new char *[n];
//  for (int i=0;i<n;i++){
//     word[i]=new char [m];
//     for (int j=0;j<m;j++){
//         cin>>word[i];
//     }

//  }
// //  cout<<ispresentword(word,n,m)<<endl;
// int n;
// cin>>n;
// int **pizza=new int* [n];
// for (int i=0;i<n;i++){
//     pizza[i]=new int [n];
//     for (int j=0;j<n;j++){
//         cin>>pizza[i][j];
//     }

// }

// cout<<largestpice(pizza,n);
cout<<threecycle(edge,n);


}