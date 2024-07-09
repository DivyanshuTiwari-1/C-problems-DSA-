#include"trie.h"
#include<iostream>
using namespace std;

int main(){
    Trie t;
    t.insertword("and");

    t.insertword("are");
    cout<<t.searchword("a")<<endl;

    t.removeword("and");
    cout<<t.searchword("and")<<endl;

}