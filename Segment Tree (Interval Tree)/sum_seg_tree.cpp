/*
        Solving the problem of Range Sum Query with point Update .
     
        Solution By -Raman Mehta
      
  */


#include<bits/stdc++.h>
using namespace std;
vector<int>arr,tree;
void BuildTree(int nl,int nr, int ti){
    if(nl==nr){
        tree[ti]=arr[nl];
        return;

    }
    int mid=nl+(nr-nl)/2;
    BuildTree(nl,mid,2*ti);
    BuildTree(mid+1,nr,2*ti+1);
    tree[ti]=tree[2*ti]+tree[2*ti+1];

   
}
void update(int nl,int nr,int ti, int idx,int val){
   
    if(nl==nr){
        tree[ti]=val;
        arr[idx]=val;
       
        return;
    }
    int mid=nl+(nr-nl)/2;
    if(idx<=mid){
        update(nl,mid,2*ti,idx,val);
    }else{
        update(mid+1,nr,2*ti+1,idx,val);
    }
    tree[ti]=tree[2*ti]+tree[2*ti+1];
}
int sum(int nl,int nr,int ti,int l,int r){
          if(r<nl or l>nr) return 0;
          if(l==nl and r==nr) return tree[ti];
          int mid=nl+(nr-nl)/2;

          int ans1=sum(nl,mid,2*ti,l,min(r,mid));
          int ans2=sum(mid+1,nr,2*ti+1,max(l,mid+1),r);
          return ans1+ans2;

}
int main(){
  int n; cin>>n;
  arr.resize(n);
  tree.resize(4*(n+2));
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  BuildTree(0,n-1,1);

  int q;
  cin>>q;
  while(q--){
      int type;cin>>type;
      if(type==1){
          int idx,val; cin>>idx>>val;
          update(0,n-1,1,idx,val);

      }else{
          int l,r;cin>>l>>r;
          cout<<(sum(0,n-1,1,l,r))<<endl;
      }
  }
   return 0;
}
