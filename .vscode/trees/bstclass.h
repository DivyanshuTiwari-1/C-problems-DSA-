#include<iostream>
using namespace std;
class bst{
  binarytreenode<int>*root;
  public:
  bst(){
    root=NULL;
  }
   ~bst(){
    delete root;
   }
private:
bool hasdata(int data,binarytreenode<int>*node){
    if(node==NULL){
        return false;
    }
    if(node->data==data){
        return true;
    }else if(root->data>data){
        return hasdata(data,root->left);
    }else{
        return hasdata(data,root->right);
    }

} public: 
   bool hasdata(int data){
    return hasdata(data,root);
   }
   private:
binarytreenode<int>*insertdata(int data,binarytreenode<int>*node){
   
    if(node==NULL){
         binarytreenode<int>*nnode=new binarytreenode<int>(data);
           return nnode;
    }
    if(node->data>data){
        binarytreenode<int>*left=insertdata(data,node->left);
        node->left=left;
       
    }
    else{
           binarytreenode<int>*right=insertdata(data,node->right);
        node->right=right;
      
    }
    return node;
}




  public:

  void insertdata(int data){
    binarytreenode<int>*root1=insertdata(data,root);
    root=root1;
  }
  private:
  binarytreenode<int>*deletenode(int data ,binarytreenode<int>*node){
    if(node==NULL){
        return NULL;
    }
   else if(node->data>data){
        binarytreenode<int>*left=deletenode(data,node->left);
        node->left=left;
    }else if(node->data<data){
         binarytreenode<int>*right=deletenode(data,node->left);
        node->right=right;
    }
    else{
        if(node->left==NULL&&node->right==NULL){
            delete node;
            return NULL;
        }
        if(node->left==NULL){
            binarytreenode<int>*temp=node->right;
            node->right=NULL;
            delete node;
            return temp;
        }
        if(node->right==NULL){
              binarytreenode<int>*temp=node->left;
            node->left=NULL;
            delete node;
            return temp;
        }else{
            binarytreenode<int>*minnode=node->right;
            while(minnode->left!=NULL){
                minnode=minnode->left;
            }
           int rightdata=minnode->data;
            node->data=rightdata;
            node->right=deletenode(rightdata,node->right);
            return node;
        }

    }

    

    

  }
  public:
  void deletenode(int data){
   binarytreenode<int>*root1=deletenode(data,root);
   root=root1;
  }
private:
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
public:
void printtree(){
    printtree(root);
}



};




