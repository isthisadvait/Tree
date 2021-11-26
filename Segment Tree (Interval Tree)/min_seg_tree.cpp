#include<bits/stdc++.h>
using namespace std;
vector<int>arr,tree;
void BuildTree(int nl,int nr,int v){
    if(nl==nr){
        tree[v]=arr[nl];
        return;
    }
    int mid=nl+(nr-nl)/2;
    BuildTree(nl,mid,2*v);
    BuildTree(mid+1,nr,2*v+1);
    tree[v]=min(tree[2*v],tree[2*v+1]);

}
void update(int nl,int nr,int v,int idx,int val){
    if(nl==nr){
        tree[v]=val;
        arr[idx]=val;
        return;
    }
    int mid=nl+(nr-nl)/2;
    if(mid<=idx) update(nl,mid,2*v,idx,val);
    else update(mid+1,nr,2*v+1,idx,val);
    tree[v]=min(tree[2*v],tree[2*v+1]);

}
int getmin(int nl,int nr,int v,int l,int r){
    if(l>r) return INT_MAX;
    if(l==nl && r==nr) return tree[v];
    int mid=nl+(nr-nl)/2;
    int ans1= getmin(nl,mid,2*v,l,min(mid,r));
    int ans2= getmin(mid+1,nr,2*v+1,max(l,mid+1),r);
    return min(ans1,ans2);

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
          cout<<(getmin(0,n-1,1,l,r))<<endl;
      }
  }
   return 0;
}
