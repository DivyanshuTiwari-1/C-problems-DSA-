#include<iostream>
#include<queue>
#include"treenode.h"
using namespace std;

void printtree(treenode<int>*root){
    if(root==NULL){
        return ;  //not the base case it is a edge case .base case is already taken into consideration 
                  //when i=0 that the size is zero of the children.
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
         cout<<root->children[i]->data<<",";//printing the children with the node.
    }cout<<endl;
       for(int i=0;i<root->children.size();i++){
         printtree(root->children[i]) ;//recursive calls
    }
}


treenode<int>*takeinput(){
    int rootdata;
    cout<<"enter the root data"<<endl;
    cin>>rootdata;
    treenode<int>*root=new treenode<int>(rootdata);
    int n;
    cout<<"enter the no of children"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>*child=takeinput();//base case if n=0 that means no child so it will return 
        root->children.push_back(child);
    }
    return root;
   v 
}

treenode<int>*takeinputlw(){
                                  //takeinputlevelwise
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode<int>*root=new treenode<int>(rootdata);
    queue<treenode<int>*>pendingnodes; //taking queue as the node which come first
                                        // will insert first.also taking queue types is treenode
                                        // as it will take nodes in which we can do further changes.

    
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        treenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
    int numchild;
    cout<<"enter the no of child of the"<<front->data<<endl;
    cin>>numchild;

    for(int i=0;i<numchild;i++){
         int childdata;
        cout<<"enter"<<i<<"th child of "<<front->data<<endl;
          cin>>childdata;
            treenode<int>*child=new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
    }
    }
    return root;
}
void printtreelw(treenode<int>*root){
   
  queue<treenode<int>*> pennode;
  pennode.push(root);
  while(pennode.size()!=0){
        treenode<int>*front=pennode.front();
        pennode.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            pennode.push(front->children[i]);
        }
        cout<<endl;
        

  }


}

int countnodes(treenode<int>*root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=countnodes(root->children[i]);
    }
    return ans;
}
 int summodes(treenode<int>*root)
 {
    int ans =root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=summodes(root->children[i]);
    }
    return ans;
}
int maximum(treenode<int>*root){
    int max=root->data;
    queue<treenode<int>*>pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size()!=0){
      treenode<int>*front=pendingnodes.front();
     pendingnodes.pop();
        if(max<front->data){
            max=front->data;
        }
    for(int i=0;i<front->children.size();i++){
    
            pendingnodes.push(front->children[i]);
        
    }

    } 
    return max;
}
int hightoftree(treenode<int>*root){

    if (root==NULL){
        return 0;
    }
    int max=0;
    for(int i=0;i<root->children.size();i++){
        int max1=hightoftree(root->children[i]);
        if(max<max1){
            max=max1;
        }
    }
    return 1+max;
}

void printatlevelK(treenode<int>*root,int k){
   if (root=NULL){
    return;
   }
    if(k==0){
        cout<<root->data;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printatlevelK(root->children[i],k-1);
    }
}
int countleaf(treenode<int>*root){
    if( root->children.size()==0){
        return 1;
    }
    int count =0;
    for(int i=0;i<root->children.size();i++){
        int p= countleaf(root->children[i]);
        count+=p;
    }
    return count;
}

void preorder(treenode<int>*root){
    if (root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    for(int i=0 ;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
void postorder(treenode<int>*root ){
 if (root==NULL){
        return ;
    }
    for(int i=0 ;i<root->children.size();i++){
        preorder(root->children[i]);
    }
    cout<<root->data<<" ";

}
bool searchnode(treenode<int>* root, int x) {
    if (root->data == x) {
        return true;
    }

    for (int i = 0; i < root->children.size(); i++) {
          bool p =searchnode(root->children[i], x);
          if(p){
            return true;
          }
    }
    return false;
}

int countgrtnodes(treenode<int>*root,int x){
    if (root==NULL){
        return -1;
    }
    int ans=0;
    if (root->data>=x){
       ans++;
    }
 for(int i=0;i<root->children.size();i++){
   int p=countgrtnodes(root->children[i],x);
   ans+=p;
 }
 return ans;
}









class Pair{
    public: 
    treenode<int>*node;
    int sum;
    Pair(treenode<int>*node){
        sum=node->data;
      for(int i=0;i<node->children.size();i++){
        
        sum=sum+node->children[i]->data;
    }
      
    }
};

treenode<int>*sumofchild(treenode<int>*root){
    Pair p(root);
    int maxsum=p.sum;
    treenode<int>*ans= root;
    for(int i=0;i<root->children.size();i++){
        Pair p1(root->children[i]);
        if(p1.sum>maxsum){
            ans= root->children[i];
            maxsum=p1.sum;
        }
    }
    return ans;
}
treenode<int>*nextlarger(treenode<int>*root,int x){

   treenode<int>*ans=NULL;
   if(root-> data>x){
    ans=root;
   }
   for(int i=0;i<root->children.size();i++){
       treenode<int>*temp= nextlarger(root->children[i],x);
       if(ans==NULL){
           ans=temp;
       }
      else if(temp->data>x&&temp->data<ans->data ){
         ans=temp;
       }
       
   }
return ans;



}

class pair1{
public :

treenode<int>*max;
treenode<int>*smax;

};
pair1 helper(treenode<int>*root){
   pair1 p;
    p.max=root;
    p.smax=NULL;

for(int i=0; i<root->children.size();i++)
{
    
    pair1 p1=helper(root->children[i]);

       if(p.smax==NULL&&p1.smax==NULL){
          if(p.max->data>=p1.max->data){
            p.smax=p1.max;
          }
          treenode<int>*temp=p.max;
          p.max=p1.max;
          p.smax=temp;
          
       }
       else if (p.smax!=NULL&&p.smax==NULL){
            if(p.max->data>p1.max->data){
                if(p1.max->data>p.smax->data){
                    p.smax=p1.max;
                }
            }
            treenode<int>*temp1=p.max;
             p.max=p1.max;
             if(temp1->data>p.smax->data){
                p.smax=temp1;
             }
       }
       else if(p.smax==NULL&&p1.smax!=NULL){
           if(p.max->data>p1.max->data){
            if(p1.max->data>p1.smax->data){
                p.smax=p1.max;
            }
            p.max=p1.smax;
           }
           treenode<int>*temp2=p.max;
           p.max=p1.max;
           if(temp2->data>p1.smax->data){
              p.smax=temp2;
           }
           p.smax=p1.smax;

       }
       else if
        (p.smax!=NULL&&p1.smax!=NULL){
           if(p.max->data>p1.max->data){
            if(p.smax->data<p1.max->data){
                p.smax=p1.max;
            }
            if (p.smax->data<p1.smax->data){
                p.smax=p1.smax;
            }
           }
           treenode<int>*temp3=p.max;
           p.max=p1.max;
           if(p.smax->data<temp3->data){
               p.smax=temp3;
           }
           if (p.smax->data<p1.smax->data){
            p.smax=p1.smax;
           }


       }
    }

  return p;
}

treenode<int>*secondmaxi(treenode<int>*root){
   
   return helper(root).smax;

  }

void replacewd(treenode<int>*root,int ans){
    root->data=ans;
   for(int i=0;i<root->children.size();i++){
        replacewd(root->children[i],ans+1);
   }
}
void replacewithdepth(treenode<int>*root){
    if(root==NULL){
        return;
    }
    
  replacewd(root,0);



}















int main(){
/*treenode<int>*root= new treenode<int>(1);
treenode<int>*node1= new treenode<int>(2);
treenode<int>*node2= new treenode<int>(3);  //basic
root->children.push_back(node1);
root->children.push_back(node2);
*/
treenode<int>*root =takeinputlw();
printtreelw(root);
cout<<"count"<<" "<<countnodes(root)<<endl;
cout<<"sum"<<" "<<summodes(root)<<endl;      // rather giving again and again the tree as below
cout<<"maximum"<<" "<<maximum(root)<<endl;  // 5 2 6 7 2 8 9 2 10 11 0 0 0 0   
cout<<"hight"<<""<<hightoftree(root)<<endl;
//printatlevelK(root,2);
cout<<"countleaf"<<" "<<countleaf(root)<<endl;
cout<<"preorder:";
preorder(root);
cout<<endl;
cout<<"postorder:";
postorder(root);
cout<<endl;
cout<<"searchnodes"<<" "<<searchnode(root,10)<<endl;
cout<<"countnodes"<<" "<<countgrtnodes(root,10)<<endl;
treenode<int>*ans1=sumofchild(root);
printtreelw(ans1);
  treenode<int>*ans2=nextlarger(root,7);
  printtree(ans2);
  /*treenode<int>*ans3=secondmaxi(root);
  cout<<"second maxi"<<endl;
  printtree(ans3);*/
  replacewithdepth(root);
  printtreelw(root);
}

