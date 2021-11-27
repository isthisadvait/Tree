/*
        Problem Link -https://www.hackerearth.com/practice/data-structures/
        advanced-data-structures/segment-trees/practice-problems/algorithm/
        shivam-and-expensive-birthday-gift-da58b2f0/

        Solution BY-Raman Mehta


*/

#include<bits/stdc++.h>
using namespace std;

vector<int>arr,tree;



void update(int nl,int nr,int v,int idx,int type){
    if(nl==nr){
        if(type==1){
            arr[idx]++;tree[v]++;return;
        }else{
            if(arr[idx]==0) return;
            arr[idx]--;
            tree[v]--;
            return;
        }
        
    }

    int mid=nl+(nr-nl)/2;
    if(idx<=mid) update(nl,mid,2*v,idx,type);
    else update(mid+1,nr,2*v+1,idx,type);
    tree[v]=tree[2*v]+tree[2*v+1];

}
int NumOfOnes(int nl,int nr,int v,int l,int r){
     if(l>r) return 0;
    if((l==nl) && (r==nr)) return tree[v];

    int mid=nl+(nr-nl)/2;
    int ans1= NumOfOnes(nl,mid,2*v,l,min(mid,r));

    int ans2= NumOfOnes(mid+1,nr,2*v+1,max(l,mid+1),r);

    return ans1+ans2;

}
int main(){
  int n,q; cin>>n>>q;
  arr.resize(n,0);
  tree.resize(4*n,0);

  while(q--){
      int type;cin>>type;
      if(type==1){
          int idx,val; cin>>idx;
          idx--;

          update(0,n-1,1,idx,type);

      }else if(type==2){
          int idx; cin>>idx;
          idx--;

          update(0,n-1,1,idx,type);


      }
      else{
          int l,r;cin>>l>>r;
          l--;
          r--;
          cout<<(NumOfOnes(0,n-1,1,l,r))<<endl;


      }
  }
  
   return 0;
}
