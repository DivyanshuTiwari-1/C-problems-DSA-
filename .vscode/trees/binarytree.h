
using namespace std;
template<typename T>
class binarytreenode{
    public:
    T data;
    binarytreenode*left;
    binarytreenode*right;
    

    binarytreenode(T data){
        this->data=data;
        left= NULL;
        right=NULL;
      
    }
  ~binarytreenode(){
    delete left;
    delete right;
  }



};