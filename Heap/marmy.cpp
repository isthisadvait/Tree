/* Problem Link-https://www.codechef.com/problems/MARMY

    Solution By -Raman Mehta
*/


#include <iostream>
#include<queue>
#include<utility>
using namespace std;


int main() {
    long long n,k; cin>>n>>k;
    
    priority_queue< pair<long long,long long>> pq;

    int x,y;
    pair<long long,long long>temp;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        pq.push({t,-i});

    }
    while(k){
        temp=pq.top();
        pq.pop();
        int x=temp.first; 
        
        int y=temp.second;
        cout<<-y<<" ";
        x--;
        k--;
        if(x!=0) pq.push({x,y});


    }
    
   return 0;
}


