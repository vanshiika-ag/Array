#include<bits/stdc++.h>
using namespace std;

//Using Sorting Algo(n*n)
int brute(vector<int> arr)
{
     for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]==arr[j])
            return arr[i];
        }
    }
    return -1;


   
}

//Using Sum formula(n)
int maths(vector<int>&arr)
{
    int n=arr.size();
    
    int s=0;

    for(int i=0;i<n;i++)
    {
        s+=arr[i];
    }
       return s-(n*(n-1))/2;
}


//Better using two loops(nlogn+n)
int better(vector<int> arr)
{
    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]==arr[i+1])
        return arr[i];
    }
    return -1;
}

//Using Visited Array(n)
int vis(vector<int> arr)
{
    int n=arr.size();
    int visited[n+1]={0};

    for(int i=0;i<n;i++)
    {
        visited[arr[i]]++;
        if(visited[i]>1)
            return i;
    }
    return -1;
}


//Using hashing technique(n)
int hashing(vector<int> arr)
{
    map<int,int>mpp;

    for(int i=0;i<arr.size();i++)
    {
        mpp[arr[i]]++;
        if(mpp[arr[i]]>1)
            return arr[i];
    }
    return -1;
}

//Linked List cycle method(Slow and fast )
int lin(vector<int> arr)
{
    
}


int main()
{
    vector<int> arr={3,1,3,4,2};

    // cout<<brute(arr);
    // cout<<maths(arr);
    // cout<<better(arr);
    // cout<<vis(arr);
    // cout<<hashing(arr);
    cout<<lin(arr);
}