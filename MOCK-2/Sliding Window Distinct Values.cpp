//Key idea:(CSES PROBLEM SET)
// Moto:Find number of Distinct element in each K size subbary
// First find the number of Distinct number of element in first k length subarray and push it in ans array
//To get the number of Distinct element in each subarray we are using a unordered map where map size will tell us the number of Distinct  element in the k subarray 
//take two pointers l=0,r=k-1 then slide the window one ny one and calculate the number of Distinct element in the each subarray while moving l pointer moahe sure that if mpp[arr[l]]==0 delete that element from the map
//At last as per question need they asked to print n-j+1 element we printed

#include <bits/stdc++.h>
using namespace std;
int main() {
   
   int n,k;
   
   cin>>n>>k;
   
   int arr[n];
   
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   
   unordered_map<int,int> mpp;
   
   //Finding the first k len subarray Distinct element 
   for(int i=0;i<k;i++){
       mpp[arr[i]]++;
   }
   
   vector<int> ans;
   
   ans.push_back(mpp.size());
   
   int l=0,r=k-1;
   
   while(r<n){
      
       r++;
       
       mpp[arr[r]]++;
       
       mpp[arr[l]]--;
       
       if(mpp[arr[l]]==0){
            mpp.erase(arr[l]);
        }
        
        l++;
        
       if(r-l+1==k) ans.push_back(mpp.size());
   }
   
   for(int i=0;i<n-k+1;i++){
       cout<<ans[i]<<" ";
   }

}

//TC->O(N)
//SC->O(N)
