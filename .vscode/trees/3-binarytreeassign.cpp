#include<iostream>
#include"binarytree.h"
#include<queue>
#include<stack>
 
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
int hightoftree(binarytreenode<int>*root){
    if (root==NULL){
        return 0 ;
    }
    int ans=hightoftree(root->left);
    int ans1=hightoftree(root->right);
    if(ans>=ans1){
        return 1+ans;
    }
    else return 1+ans1;
}
int sumofnode(binarytreenode<int>*root){
    if(root==NULL){
      return 0;
    }
    return root->data +sumofnode(root->left)+sumofnode(root->right);

}
bool isbalanced(binarytreenode<int>*root){
    if(root==NULL){
        return true;
    }
    int a = hightoftree(root->left)-hightoftree(root->right);
    if(a==1||a==0||a==-1){
        bool b =isbalanced(root->left); // this  problem is similiar to diameter problem it
                                        //time com is o(n*h)due hight of tree is called again and again.
                                        //use pair class method 
        bool c=isbalanced(root->right);
       if(b&&c){
        return true;
       }
       return false;
    }
    return false;
}

/*pair<bool,int>hightbal(binarytreenode<int>*root){
    if(root==NULL){
         pair<bool,int>ans;
         ans.first=true;
         ans.second=0;
         return ans;
    }
    pair<bool,int>leftchild=hightbal(root->left);
    pair<bool,int>rightchild=hightbal(root->right);
    bool lb= leftchild.first;
    bool lh=leftchild.second;
    bool rb=rightchild.first;
    bool rh=rightchild.second;
     pair<bool,int>ans;
     int a =abs(lh-rh);
    if(lb&&rb){
          
        if(a<=1){
            
            ans.first=true;
        }
        else{
        ans.first=false;
        }
        ans.second=1+max(lh,rh);
        return ans;
    }
    
        ans.first=false;
        ans.second=1+max(lh,rh);
        return ans;
    



}*/
pair<bool, int> hightbal(binarytreenode<int>* root) {
    if (root == NULL) {
        pair<bool, int> ans;
        ans.first = true;
        ans.second = 0;
        return ans;
    }

    pair<bool, int> leftchild = hightbal(root->left);
    pair<bool, int> rightchild = hightbal(root->right);

    bool lb = leftchild.first;
    bool rb = rightchild.first;
    int lh = leftchild.second;
    int rh = rightchild.second;

    pair<bool, int> ans;

    if (lb && rb) {
        int a = abs(lh - rh);
        if (a <= 1) {
            ans.first = true;
            ans.second = 1 + max(lh, rh);
        } else {
            ans.first = false;
            ans.second = 1 + max(lh, rh);
        }
    } else {
        ans.first = false;
        ans.second = 1 + max(lh, rh);
    }

    return ans;
}

bool isbalnecedpair(binarytreenode<int>*root){
    if(root==NULL){
        return true;

    }
    pair<bool,int>ans=hightbal(root);
    return ans.first;
}


vector<binarytreenode<int>*>linkhead(binarytreenode<int>*root){
    vector<binarytreenode<int>*>output;
     queue<binarytreenode<int>*>pendingnodes;
     pendingnodes.push(root);
     pendingnodes.push(NULL);
     binarytreenode<int>*head=NULL;
     binarytreenode<int>*tail=NULL;
     
    while(pendingnodes.size()!=0){
        binarytreenode<int>*front=pendingnodes.front();
        pendingnodes.pop();

        if(front!=NULL){
          if(head==NULL&&tail==NULL){
            head=front;
            tail=front;
          }
          else if(head!=NULL){
          tail->next=front;
          tail=tail->next;
          } 
        if (front->left!=NULL){
         pendingnodes.push(front->left);
            
        }
        if(front->right!=NULL){
            pendingnodes.push(front->right);
        }
        
        }
        else{
        output.push_back(head);
        head=NULL;
        tail=NULL;
        
        if(!pendingnodes.empty()){
        pendingnodes.push(NULL);
        }
    }
}
return output;
}

 binarytreenode<int>*removeleaf(binarytreenode<int>*root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL){
      delete(root);
      return NULL;
        
    }
    else{
    binarytreenode<int>*leftchild=removeleaf(root->left);
    binarytreenode<int>*rightchild=removeleaf(root->right);
    root->left=leftchild;
    root->right=rightchild;
    
 }
 return root;
 }
 
void printzigzag(binarytreenode<int>* root) {
    if (root == nullptr) {
        return;
    }

    stack<binarytreenode<int>*> s1;
    stack<binarytreenode<int>*> s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            binarytreenode<int>*top= s1.top();
            s1.pop();
            cout << top->data << " ";
            if (top->left) {
                s2.push(top->left);
            }
            if (top->right) {
                s2.push(top->right);
            }
        }
      cout<<endl;

        while (!s2.empty()) {
           binarytreenode<int>*top= s2.top();
            s2.pop();
            cout << top->data << " ";
            if (top->right) {
                s1.push(top->right);
            }
            if (top->left) {
                s1.push(top->left);
            }
        }
       cout << endl;
    }
}
void nodeswithsibling(binarytreenode<int>*root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL&&root->right==NULL){
        cout<<root->left->data<<endl;
    }
    
    if(root->left==NULL&&root->right!=NULL){
        cout<<root->right->data<<endl;
    }
    nodeswithsibling(root->left);
    nodeswithsibling(root->right);
}

//1 2 3 4 5 6 7-1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
     binarytreenode<int>*root=takeinputlw();
    printlevelwise(root);
    cout<<sumofnode(root);
    cout<<isbalnecedpair(root)<<endl;
   // binarytreenode<int>*root1=removeleaf(root);
   // levelwise(root1);
   nodeswithsibling(root);
}