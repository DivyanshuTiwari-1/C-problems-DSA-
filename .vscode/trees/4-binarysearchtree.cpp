#include<iostream>
#include"binarytree.h"
#include<queue>
#include<stack>
#include"bstclass.h"
using namespace std;


void printtree(binarytreenode<int>*root){
   if (root==NULL){
    return;
   }
   
    cout<<root->data<<":";
   if(root->left!=NULL){
      cout<<"L"<<root->left->data;
   }
   if(root->right!=NULL){
      cout<<"R"<<root->right->data;
   }
   cout<<endl;
   printtree(root->left);
   printtree(root->right);

}

binarytreenode<int>*takeinput(){
    int rootdata;
    cout<<"enter data";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
   binarytreenode<int>*root=new binarytreenode<int>(rootdata);
   binarytreenode<int>*leftchild=takeinput();
   binarytreenode<int>*rightchild=takeinput();
   root->left=leftchild;
   root->right=rightchild;
   return root;


}
binarytreenode<int>*takeinputlw(){
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    binarytreenode<int>*root=new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
    
        binarytreenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<front->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
       binarytreenode<int>*leftchild=new binarytreenode<int>(leftchilddata);
       front->left=leftchild;
       pendingnodes.push(leftchild);
        }
    
        cout<<"enter right child data"<<front->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
       binarytreenode<int>*rightchild=new binarytreenode<int>(rightchilddata);
       front->right=rightchild;
       pendingnodes.push(rightchild);
    }
    
}
return root;
}
void printlevelwise(binarytreenode<int>*root){
    
     queue<binarytreenode<int>*>pendingnodes;
     pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        binarytreenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<":";
        if (front->left!=NULL){
            cout<<"L"<<front->left->data;
            pendingnodes.push(front->left);
            
        }
        else{
            cout<<"L -1";
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data;
            pendingnodes.push(front->right);
        }
        else{
            cout<<"R -1";
        }
        cout<<endl;
    }
}

binarytreenode<int>*searchnodesbst(binarytreenode<int>*root,int x){
    if(root==NULL){
        return NULL;
    }
    if(root->data==x){
        return root;
    }
   else if(root->data<x){
     return searchnodesbst(root->right,x);
    }
    else if(root->data>x){
    return searchnodesbst(root->left,x);
    }


}
void printInRange(binarytreenode<int>* root, int k1, int k2) {
    if (root == NULL) {
        return;
    }
     
    if (k1 <= root->data && root->data <= k2) {
        cout << root->data << " ";
    }
    if(k1<root->data){
        printInRange(root->left, k1, k2);
        
    }
    if(k2>root->data){
        printInRange(root->right, k1, k2);
    }
}
int mini(binarytreenode<int>*root){
    if(root==NULL){
        return INT16_MAX;
    }
    return min(root->data,min(mini(root->left),mini(root->right)));
}
int maxi(binarytreenode<int>*root){
    if(root==NULL){
        return INT16_MIN;
    }
    return max(root->data,max(maxi(root->left),maxi(root->right)));

}


//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
bool isbst(binarytreenode<int>*root){
    if(root==NULL){
        return true;
    }
    int leftmax=maxi(root->left);// the timecomplexityof this methodis o(n*hight);
    int rightmin=mini(root->right);
    bool output =(root->data>leftmax)&&(root->data<rightmin)&&isbst(root->left)&&isbst(root->right);
    return output;
}
// now we can make class and object like diameter question

class Isbstretrun {
    public:
    bool isbst;
    int maximum;
    int minimum;
};

Isbstretrun isbst2(binarytreenode<int>*root){
    if(root==NULL){
        Isbstretrun output;
        output.isbst=true;
        output.maximum=INT16_MIN;
        output.minimum=INT16_MAX;
        return output;
    }
Isbstretrun left= isbst2(root->left);
Isbstretrun right=isbst2(root->right);
int maximum=max(root->data,max(left.maximum,right.maximum));
int minmum=min(root->data,min(left.minimum,right.minimum));
bool isbst1=(root->data>left.maximum)&&(root->data<=right.minimum)&&(left.isbst)&&(right.isbst);
Isbstretrun output;
output.isbst=isbst1;
output.maximum=maximum;
output.minimum=minmum;
return output;

}
binarytreenode<int>*consturctbst(int arr[],int m,int n){
    if(m>n){
        return NULL;
    }
    int mid=(m+n)/2;
    binarytreenode<int>*root=new binarytreenode<int>(arr[mid]);
    binarytreenode<int>*left=consturctbst(arr,m,mid-1);
    binarytreenode<int>*right=consturctbst(arr,mid+1,n);
    root->left=left;
    root->right=right;
    return root;
}

binarytreenode<int>*helper(int arr[],int n){
    if(n==0){
        return NULL;
    }
    binarytreenode<int>*root=consturctbst(arr,0,n-1);
    return root;
}
void preorder(binarytreenode<int>*root){
    if(root==NULL){
        return ;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
class node
{
public:
    int data;
    node *next;

    node(int data)
    {

        this->data = data;
        this->next = NULL;
    }
};
void print(node *temp)
{

    while (temp != NULL)
    { // for printing upto last nods use = temp1= NULL
      // last  node se pahle tak ke liye temp->next!= NULL
        cout << temp->data << endl;
        temp = temp->next;
    }
}
 pair<node*,node*>sortedlink(binarytreenode<int>*root){
    if(root==NULL){
         pair<node*,node*> p1;
        p1.first=NULL;
        p1.second=NULL;
        return p1;
    }
     pair<node*,node*>pl=sortedlink(root->left);
      pair<node*,node*>pr=sortedlink(root->right);
      node*head=new node(root->data);
      if(pl.first==NULL&&pl.second==NULL){
        pair<node*,node*>ans;
        ans.first=head;
        ans.second=head;
        return ans;
      }
      else{
      pl.second->next=head;
        head->next=pr.first;
      }
      pair<node*,node*>out;
      out.first=pl.first;
      out.second=pr.second;
      return out;
    
 }
  vector<int>*roottonodepath(binarytreenode<int>*root,int data){
    if(root==NULL){
        return NULL;
    }
    
    
    if(root->data==data){
        vector<int>*output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>*left=roottonodepath(root->left,data);
    if(left!=NULL){
        left->push_back(root->data);
        return left;
    }
    vector<int>*right=roottonodepath(root->right,data);
    if(right!=NULL){
        
        right->push_back(root->data);
        return right;
    }else{
        return NULL;
    }
    
  }
 void bsttoarry(binarytreenode<int>*root,int arr[]){
    static int pos=0;
    if(root==NULL){
        return ;
    }
     
    bsttoarry(root->left,arr);
    arr[pos++]=root->data;
    bsttoarry(root->right,arr);
 }
int numnodes(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+numnodes(root->left)+numnodes(root->right);
 }


void printpairsum(binarytreenode<int>*root,int sum){
    if(root==NULL){
        return ;
    }
    // also this method is better than brut force methodd as it complete the work in o(nlogn)
int arr[20];
int p=numnodes(root);
bsttoarry(root,arr);
int i=0, j=p-1;// we traverse the arry and find the sum of two elment whoose sum is 
              // given sum so we can do the following as we did in quick short 
while(i<j){
    if(arr[i]+arr[j]==sum){
        cout<<arr[i]<<" "<<arr[j]<<endl;
        i++;
        j--;
    }
    else if(arr[i]+arr[j]<sum){
        i++;
    }
    else{
        j--;
    }
}




}
binarytreenode<int>*lca(binarytreenode<int>*root ,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1|| root->data==n2){
        return root;
    }
    binarytreenode<int>*a=lca(root->left,n1,n2);
    binarytreenode<int>*b=lca(root->right,n1,n2);
    if(a==NULL&&b==NULL){
        return NULL;
    }
    else if(a==NULL&&b!=NULL){
        return b;
    }
    else if(a!=NULL&&b==NULL){
        return a;
    }
    else{
        return root;
    }


}

class largestbst{
  public:
   bool isbst;
  int minimum;
  int maximum;
 
  int hight;
};
largestbst largbs(binarytreenode<int>*root){
    if(root==NULL){
        largestbst output;
        output.isbst=true;
        output.maximum=INT16_MIN;
        output.minimum=INT16_MAX;
        output.hight=0; 
        return output;
    }
largestbst left= largbs(root->left);
largestbst right=largbs(root->right);
int maximum=max(root->data,max(left.maximum,right.maximum));
int minmum=min(root->data,min(left.minimum,right.minimum));
bool isbst1=(root->data>left.maximum)&&(root->data<=right.minimum)&&(left.isbst)&&(right.isbst);

largestbst output;
output.isbst=isbst1;
output.maximum=maximum;
output.minimum=minmum;


if(left.isbst&&right.isbst){
 output.hight=(max(left.hight,right.hight)+1);
}
else{
 output.hight=max(left.hight,right.hight);
}
return output;

}

int replacewithgre(binarytreenode<int>*root,int sum){

    if(root==NULL){
        return 0;
    }
    
    int rightsum=replacewithgre(root->right,sum);
     
    
    sum+=root->data+rightsum;
    root->data=sum;
    
     int leftsum=replacewithgre(root->left,root->data);
    
    return sum;
}
binarytreenode<int>*changewithsum(binarytreenode<int>*root){
    if(root==NULL){
        return NULL;
    }
    int temp=replacewithgre(root,0);
    return root;
}
void printroottopath(binarytreenode<int>* root, int k, vector<int>& path) {
    if (root == NULL) {
        return;
    }
    
    path.push_back(root->data);
    k = k - root->data;

    if (!root->left && !root->right) {
        if (k == 0) {
            for (int i : path) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    
    printroottopath(root->left, k, path);
    printroottopath(root->right, k, path);

    // Backtrack: Remove the last element from the path
    path.pop_back();
}

void printtopathhelp(binarytreenode<int>* root) {
    vector<int> v;
    printroottopath(root, 10, v);
}

pair<vector<int>,int>longestpathtoleaf(binarytreenode<int>*root){

    if(root==NULL){
        pair<vector<int>,int> p1;
       
       p1.second=0;
       return p1;
    }
    pair<vector<int>,int> left=longestpathtoleaf(root->left);
    pair<vector<int>,int> right=longestpathtoleaf(root->right);
    pair<vector<int>,int>output;
    if(left.second>right.second){
        left.first.push_back(root->data);
        output.first=left.first;
    }
     else{
        right.first.push_back(root->data);
        output.first=right.first;

     }
     
     output.second=1+max(left.second,right.second);


    return output;

}
binarytreenode<int>*removeleaf(binarytreenode<int>*root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL){
        delete root;
        return NULL;
    }
    binarytreenode<int>*left=removeleaf(root->left);
    binarytreenode<int>*right=removeleaf(root->right);
    root->left=left;
    root->right=right;
    return root;
}



//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

int main(){
  binarytreenode<int>*root=takeinputlw();
   printlevelwise(root);
 /*  printtopathhelp(root);

//printInRange(root,6,10);
//cout<<isbst(root);
Isbstretrun output=isbst2(root);
cout<<output.isbst<<endl;
int arr[]={1,2,3,4,5,6,7};
binarytreenode<int>*root1=helper(arr,7);
preorder(root1);*/
/*pair<node*,node*>output=sortedlink(root);
node*head=output.first;
print(head);
vector<int>*ans=roottonodepath(root,6);
for(int i=0;i<ans->size();i++){
    cout<<ans->at(i)<<" ";
}
binarytreenode<int>*ans=maxim(root);
printtree(ans);
/*
bst b;
b.insertdata(10);
b.insertdata(5);
b.insertdata(20);
b.insertdata(7);
b.insertdata(15);
b.insertdata(3);
b.printtree();
b.deletenode(10);
b.printtree();

printpairsum(root,7);
/*binarytreenode<int>*insi=lca(root,12,78);
cout<<insi->data;
largestbst output=largbs(root);
cout<<output.isbst<<endl;
cout<<output.hight<<endl;
binarytreenode<int>*root3=changewithsum(root);

printlevelwise(root3);
pair<vector<int>,int>output=longestpathtoleaf(root);
for(int i=0;i<output.second;i++){
cout<<output.first.back();
  output.first.pop_back();  
}
cout<<output.second;
*/
binarytreenode<int>*root1=removeleaf(root);
printlevelwise(root1);
}

