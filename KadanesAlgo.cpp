#include<bits/stdc++.h>
using namespace std;


//Brute force solution
int brute(vector<int> arr)
{
  long long ans=INT_MIN;
  int n=arr.size();
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      long long sum=0;
      for(int k=i;k<=j;k++)
      {
        sum+=arr[k];
        ans=max(ans,sum);
      }
    }
  }
  return (int)ans;
}


//Better Solution
int better(vector<int> arr)
{
   long long  ans=INT_MIN;
   int n=arr.size();
   for(int i=0;i<n;i++)
   {
    long long sum=0;
    for(int j=i;j<n;j++)
    {
      sum=sum+arr[j];
      ans=max(sum,ans);
    }
   }

   return (int)ans;
}


//Optimal Solution
int optimal(vector<int> arr)
{
  long long ans=INT_MIN;
  long long sum=0;

  for(int i=0;i<arr.size();i++)
  {
    sum+=arr[i];
    // if(sum>ans)
    // {
      ans=max(ans,sum);
    // }
    if(sum<0)
      sum=0;
  }
  return (int)ans;
}

void printArray(vector<int> arr)
{
    int sum=0;
    int ans=INT_MIN;
    int start=-1,end=-1;
    int s;
    for(int i=0;i<arr.size();i++)
    {
        if(sum==0)
          s=i;
          sum+=arr[i];
        if(sum>ans)
        {
          ans=sum;
          start=s;
          end=i;
        }
        if(sum<0)
          sum=0;
    }
  // cout<<"Hello";
    for(int i=start;i<=end;i++)
    {
      cout<<arr[i]<<" ";
    }
}

int main()
{
  vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
  // cout<<brute(arr);
  // cout<<better(arr);
  // cout<<optimal(arr);   
  printArray(arr);
}