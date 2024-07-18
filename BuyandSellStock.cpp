#include<bits/stdc++.h>
using namespace std;


//Brute force
int brute(vector<int> arr)
{
  int n=arr.size(); 
  int profit=0;
  int ans=0;

  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arr[i]<arr[j])
      {
        profit=arr[j]-arr[i];
        ans=max(profit,ans);
        // cout<<ans<<" ";
      }
      
    }
  }
 return ans;
}


//Optimal Solution
int optimal(vector<int> arr)
{
    int mini=arr[0];
    int ans=0;
    for(int i=1;i<arr.size();i++)
    {
      int profit=arr[i]-mini;
      ans=max(ans,profit);
      mini=min(mini,arr[i]);
    }

    return ans;
}

int main()
{
  vector<int> arr={7,1,5,3,6,4};
  cout<<brute(arr);
}