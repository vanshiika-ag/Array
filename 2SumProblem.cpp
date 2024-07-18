#include<bits/stdc++.h>
using namespace std;

//Print the Array
void print(vector<int>arr)
{
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
}


//Brute force solution
bool brute(vector<int> arr,int target)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                return true;
            }
        }
    }
    return false;
}


//Better solution using hashmap
bool better(vector<int> arr,int target)
{
    map<int,int> mpp;

    for(int i=0;i<arr.size();i++)
    {
        int a=arr[i];
        int b=target-a;

        if(mpp.find(b)!=mpp.end())
            return true;
        mpp[a]=i;
    }
    return false;
}


//Optimal Solution
bool optimal(vector<int> arr,int target)
{
    int sum=0;
    int left=0;
    int right=arr.size()-1;
    sort(arr.begin(),arr.end());

    while(left<=right)
    {
        sum=arr[left]+arr[right];
        if(sum==target)
            return true;
        else if(sum<target)
            left++;
        else
        right--;
    }
    return false;
}


//Brute solution to return the index
void bruteIndex(vector<int> arr,int target)
{
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==target)
                {
                    ans.push_back(i);
                ans.push_back(j);
                }
        }
    }
    print(ans);
}



//Optimal solution to return the index
void optimalIndex(vector<int> arr,int target)
{
    map<int,int> mpp;
    vector<int> ans;
    for(int i=0;i<arr.size();i++)
    {
        int a=arr[i];
        int b=target-a;
        if(mpp.find(b)!=mpp.end()) 
            ans={mpp[b],i};
        mpp[a]=i;
    }   
    print(ans);
}

int main()
{
    vector<int> arr={2,6,5,8,11};
    int target=14;

    // cout<<brute(arr,target);
    // cout<<better(arr,target);
    // cout<<optimal(arr,target);
    // bruteIndex(arr,target);
    optimalIndex(arr,target);
}