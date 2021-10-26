/* Implementation Of Max Binary Heap Using Array 

    Author - Raman
    
   */

#include<bits/stdc++.h>
using namespace std;

class Heap{
     private:
     vector<int>a;
     int sz,root,cap;
     public:
     Heap(){
         a.reserve(101);
         sz=0;
         root=1;
         cap=100;
     }
     int top(){    //peek the top element
         if(isEmpty()){
             cout<<"Empty Heap\n";
             return -1;
         }
         return a[root];
     }
     void pop(){     //delete the top element 
        int element=a[root];
        swap(a[root],a[sz--]);
        heapify(root);
     }

     void heapify(int node){ 
          int largest=node;
          if(leftChild(node)<=sz && a[leftChild(node)]>a[largest]) largest=leftChild(node);
          if(rightChild(node)<=sz &&a[rightChild(node)]>a[largest]) largest=rightChild(node);

          if(largest!=node){
              swap(a[largest],a[node]);
              heapify(largest);
          }
     }
     bool isEmpty(){
           return (sz==0);
     }
     void push(int data){
         if(sz==cap){
             cout<<"Heap Full";
             return;
         }
        
         int node=++sz;
         a[node]=data;
         while(node!=root){
             if(a[parent(node)]>a[node]) break;
             swap(a[node],a[parent(node)]);
             node=parent(node);
         }
     }
     int getSize(){
             return sz;
     }
     int parent(int node){
         return node/2;

     }
     int rightChild(int node){
         return 2*node+1;
     }
     int leftChild(int node){
         return 2*node;
     }

     void print(){
         for(int i=root;i<=sz;i++){
             cout<<a[i]<<" ";
         }
         cout<<endl;
     }
     int getCap(){
         return cap;
     }
};

int main(){
    Heap pq;
    
    pq.push(10);
    pq.push(12);
    pq.push(11);
    pq.push(-1);
    pq.push(3);
    pq.push(2);
    pq.push(1);
    pq.push(-15);
    cout<<pq.top()<<endl;
    cout<<pq.getSize()<<endl;
    pq.print();
    return 0;
}
