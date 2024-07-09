#include "trienode.h"
using namespace std;
class Trie
{
  Trienode *root;

public:
  Trie()
  {
    root = new Trienode('\0');
  }
  void insertword(Trienode *root, string word)
  {
    // base
    if (word.size() == 0)
    {
      root->isterminal = true;
      return;
    }
    // small calcu;ation
    int index = word[0] - 'a';
    Trienode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      child = new Trienode(word[0]);
      root->children[index] = child;
    }
    // recursive call

    insertword(child, word.substr(1));
  }

  void insertword(string word)
  {
    insertword(root, word);
  }

  bool searchword(Trienode *root, string word)
  {

    if (word.size() == 0)
    {
      root->isterminal = true;
      return true;
    }

    int index = word[0] - 'a';
    Trienode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }
    searchword(child, word.substr(1));
  }
  bool searchword(string word)
  {
    return searchword(root, word);
  }

  void removeword(Trienode *root, string word)
  {

    if (word.size() == 0)
    {
      root->isterminal = false;
      return;
    }
    // small calculation

    int index = word[0] - 'a';
    Trienode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return;
    }
    removeword(child, word.substr(1));

    if(child->isterminal==false){
      for(int i=0;i<26;i++){
        if(child->children[i]!=NULL){
          return ;
        }
        delete child;
        root->children[index]=NULL;
      }
    }
  }
   void removeword(string word){
    removeword(root,word);
   }









  
};
