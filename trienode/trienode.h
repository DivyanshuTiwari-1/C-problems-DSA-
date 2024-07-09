#include<iostream>

class Trienode{
    public:
    char data;
    Trienode **children;
    bool isterminal ;

   Trienode(char data){
    this->data=data;
    children=new Trienode*[26];
    
    for(int i=0;i<26;i++){
        children[i]=NULL;

    }
    isterminal =false;

   }










};