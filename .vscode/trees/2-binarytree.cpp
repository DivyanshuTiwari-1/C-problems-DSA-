#include<iostream>
#include"binarytree.h"
#include<queue>
 
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

 int numnodes(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+numnodes(root->left)+numnodes(root->right);
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

bool isnodepre(binarytreenode<int>*root,int x){
    if (root==NULL){
        return false;
    }
    if( root->data==x){
        return true;
    }
    if(isnodepre(root->left,x)||isnodepre(root->right,x)){
        return true;
    }
    return false;

}

  binarytreenode<int>*mirrorimage(binarytreenode<int>*root){
    if(root==NULL){
        return NULL ;
    }
    binarytreenode<int>*leftchild=mirrorimage(root->left);
    binarytreenode<int>*rightchild=mirrorimage(root->right);
    root->left=rightchild;
    root->right=leftchild;
    return root;
}

void inorder(binarytreenode<int>*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(binarytreenode<int>*root){
    if(root==NULL){
        return ;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(binarytreenode<int>*root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
binarytreenode<int>*contructprehelper(int in[],int pr[],int ins,int ine,int prs,int pre){
     if(ins>ine){
        return NULL;
     }
     
     int rootdata=pr[prs];
    
     int rootind=-1;
     for(int i=ins;i<=ine;i++){
       
        if(in[i]==rootdata){
            rootind=i;
            break;
        }
        

     }
    int lins=ins;
    int line=rootind-1;
    int lprs=prs+1;
    int lpre=line-lins+lprs;
    int rins=rootind+1;
    int rine=ine;
    int rprs=lpre+1;
    int rpre=pre;
    binarytreenode<int>*root=new binarytreenode<int>(rootdata);
    binarytreenode<int>*leftchild=contructprehelper(in,pr,lins,line,lprs,lpre);
    binarytreenode<int>*rightchild=contructprehelper(in,pr,rins,rine,rprs,rpre);
    root->left=leftchild;
    root->right=rightchild;
    return root;

}



 binarytreenode<int>*construtpre(int n,int in[],int pr[]){
   binarytreenode<int>*root =contructprehelper(in,pr,0,n-1,0,n-1);
   return root;

 }
binarytreenode<int>*contructposthelper(int in[],int pr[],int ins,int ine,int prs,int pre){
     if(ins>ine){
        return NULL;
     }
     
     int rootdata=pr[pre];
    
     int rootind=-1;
     for(int i=ins;i<=ine;i++){
       
        if(in[i]==rootdata){
            rootind=i;
            break;
        }
        

     }
    int lins=ins;
    int line=rootind-1;
    int lprs=prs;
    int lpre=line-lins+lprs;
    int rins=rootind+1;
    int rine=ine;
    int rprs=lpre+1;
    int rpre=pre-1;
    binarytreenode<int>*root=new binarytreenode<int>(rootdata);
    binarytreenode<int>*leftchild=contructposthelper(in,pr,lins,line,lprs,lpre);
    binarytreenode<int>*rightchild=contructposthelper(in,pr,rins,rine,rprs,rpre);
    root->left=leftchild;
    root->right=rightchild;
    return root;

}



 binarytreenode<int>*construtpost(int n,int in[],int pr[]){
   binarytreenode<int>*root =contructposthelper(in,pr,0,n-1,0,n-1);
   return root;

 }
int diametr(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    int option1 =1+hightoftree(root->left)+hightoftree(root->right);
    int option2 =diametr(root->left);
    int option3=diametr(root->right);   //time com o (n*hight) because function is calling hight 
                                       // again and again for more clarity see notes or dry run .
    return max(option1,max(option2,option3));
}

pair<int,int>hightdiameter(binarytreenode<int>*root){
    if(root==NULL){
        pair<int,int>p;
        p.first=0;
        p.second=0;          // this is the alter native of above code here we have used the 
                            // inbuild pair class which return the both hight & dia in single call.

        return p;
    }
    pair<int,int>leftans=hightdiameter(root->left);
    pair<int,int>rightans=hightdiameter(root->right);
    int lh=leftans.first;
    int ld=leftans.second;
    int rh=rightans.first;
    int rd=rightans.second;
    int hight =1+max(lh,rh);
    int dia=max(lh+rh,max(ld,rd));
  pair<int,int>p;
        p.first=hight;
        p.second=dia;
        return p;

}

 // For std::pair
 
 pair<int,int> minAndMax(binarytreenode<int>* root) {
    if (root->left == NULL && root->right == NULL) {
        pair<int,int> p1;
        p1.first = root->data;
        p1.second = root->data;
        return p1;
    }

    pair<int,int> leftAns = minAndMax(root->left);
    pair<int,int> rightAns = minAndMax(root->right);
    int lmin = leftAns.first;
    int lmax = leftAns.second;
    int rmin = rightAns.first;
    int rmax = rightAns.second;

    int mini = min(root->data, min(lmin, rmin));
    int maxi = max(root->data, max(lmax, rmax));

    pair<int,int> p1;
    p1.first = mini;
    p1.second = maxi;
    return p1;
}


//1 2 3 4 5 6 7-1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

 /* binarytreenode<int>*root=new binarytreenode<int>(1);
    binarytreenode<int>*node1=new binarytreenode<int>(2);
    binarytreenode<int>*node2=new binarytreenode<int>(3);
    root->left=node1;
    root->right=node2;
*/
int main(){
 /* binarytreenode<int>*root=takeinputlw();
    printlevelwise(root);
    cout<<"numof nodes:"<<numnodes(root)<<endl;
    cout<<"hightoftree:"<<hightoftree(root)<<endl;
    cout<<isnodepre(root,10)<<endl;
  binarytreenode<int>*ans=mirrorimage(root);
    printlevelwise(ans);
    cout<<"inorder:";
    inorder(root);
    cout<<endl;
   cout<<"preorder:";
    preorder(root);
    cout<<endl;
   cout<<"postorder:";
    postorder(root);
    cout<<endl;*/
   int in[]={7,3,9,6,8,1,5,2,4};
   int pre[]={1,3,7,6,9,8,2,5,4};
   int post[]={7,9,8,6,3,5,4,2,1};
   binarytreenode<int>*root=construtpre(9,in,pre);
   binarytreenode<int>*root2=construtpost(9,in,post);
    printlevelwise(root);
  // cout<<"diametr "<<diametr(root1)<<endl;
   pair<int,int>p=hightdiameter(root);
   cout<<"hight:"<<p.first<<endl;
   cout<<"diameter:"<<p.second<<endl;

  pair<int,int>p1=minAndMax(root);
   cout<<"minimum:"<<p1.first<<endl;
   cout<<"maximum:"<<p1.second<<endl;




}