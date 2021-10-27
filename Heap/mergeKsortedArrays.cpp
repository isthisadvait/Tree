/* Merge K sorted Arrays 
            Author - Raman Mehta
*/

#include <bits/stdc++.h>
using namespace std;



vector<int> mergeKArrays(vector<vector<int> > arr)
{
         vector<int> output;
        
         priority_queue<pair<int,pair<int,int>>>pq;
         for (int i = 0; i < arr.size(); i++)
                pq.push({ -arr[i][0], { i, 0 } });
    
         while (pq.empty() == false) {
                pair<int,pair<int,int>> curr = pq.top();
                pq.pop();
                int i = curr.second.first;
                int j = curr.second.second;
      
               output.push_back(-curr.first);
               if (j + 1 < arr[i].size())
                    pq.push({- arr[i][j + 1], { i, j + 1 } });
            }
         return output;
 }

 int main()
   {
      int m,n ; cin>>m>>n;

      vector<vector<int> > arr(m,vector<int>(n));
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              cin>>arr[i][j];
          }
      }
      vector<int> output = mergeKArrays(arr);
      cout << "Merged array is " << endl;
      for (auto x : output)
         cout << x << " ";
     return 0;
 }
