
#include<vector>
using namespace std;


class priortiyqueue{
 vector<int>pq;
public:
priortiyqueue(){

}
bool isempty(){
    return pq.size()==0;
}

int getsize(){
    return pq.size();
}

int getmin(){
    if(isempty()){
        return 0;
    }
    return pq[0];
}

void insertelement(int data){
    pq.push_back(data);

   int childindex=pq.size()-1;
   while(childindex>0){
   int parentIndex=(childindex-1)/2;
   if(pq[childindex]<pq[parentIndex]){
    int temp=pq[childindex];
    pq[childindex]=pq[parentIndex];
    pq[parentIndex]=temp;
   }
   else{
    break;
   }
   childindex=parentIndex;
   }
}
int removemin() {
    if (isempty()) {
        // Handle the case when the priority queue is empty
        // You might want to throw an exception or return a special value
        // Here, I'm assuming returning -1 as a special value for an empty queue
        return -1;
    }

    int temp = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();

    int parentIndex = 0;
    int childindex1 = (2 * parentIndex + 1);

    while (childindex1 < pq.size()) {
        int childindex2 = (2 * parentIndex + 2);
        if (childindex2 >= pq.size() || pq[childindex1] <= pq[childindex2]) {
            if (pq[parentIndex] <= pq[childindex1]) {
                break;
            } else {
                int temp1 = pq[parentIndex];
                pq[parentIndex] = pq[childindex1];
                pq[childindex1] = temp1;
                parentIndex = childindex1;
            }
        } else {
            if (pq[parentIndex] <= pq[childindex2]) {
                break;
            } else {
                int temp2 = pq[parentIndex];
                pq[parentIndex] = pq[childindex2];
                pq[childindex2] = temp2;
                parentIndex = childindex2;
            }
        }

        childindex1 = (2 * parentIndex + 1);
    }

    return temp;
}
};