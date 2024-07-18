#include<bits/stdc++.h>
using namespace std;

//Print the array
void print(vector<int> &arr)
{
  for(auto it: arr)
  {
    cout<<it<<"  ";
  }
}


//Brute Force_Merge Sort
void merge(vector<int> &arr,int low,int mid,int high)
{
  vector<int> temp;
  int left=low;
  int right=mid+1;

  while(left<=mid && right<=high)
  {
    if(arr[left]<=arr[right])
    {
        temp.push_back(arr[left]);
        left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while(left<=mid)
  {
    temp.push_back(arr[left]);
    left++;
  }

  while(right<=high)
  {
    temp.push_back(arr[right]);
    right++;
  }


  for(int i=low;i<=high;i++)
  {
    arr[i]=temp[i-low];
  }

}

void brute(vector<int> &arr,int low,int high)
{

  if(low<high)
  {
    int mid=(low+high)/2;
    brute(arr,low,mid);
    brute(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}

//Better Solution
void better(vector<int>&arr)
{
  int n=arr.size();
  int cnt0=0,cnt1=0,cnt2=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]==0)cnt0++;
    else if(arr[i]==1)cnt1++;
    else 
      cnt2++;
  }

  for(int i=0;i<cnt1;i++)
  {
    arr[i]=0;
  }
  for(int i=cnt0;i<cnt0+cnt1;i++)
  {
    arr[i]=1;
  }

  for(int i=cnt0+cnt1;i<n;i++)
  {
    arr[i]=2;
  }
}


//Optimal Solution_DNF a lgo
void optimal(vector<int> &arr)
{
  int low=0,mid=0,high=arr.size()-1;

  while(mid<=high)
  {
    if(arr[mid]==0)
    {
      swap(arr[mid],arr[low]);
      low++;
      mid++;
    }
    else if(arr[mid]==1)
      mid++;
    else
    {
      swap(arr[mid],arr[high]);
      high--;
    }
  }
}

int main()
{
  vector<int> arr={2,0,2,1,1,0};

  // brute(arr,0,arr.size()-1);
  // better(arr);
    optimal(arr);
    print(arr);

}