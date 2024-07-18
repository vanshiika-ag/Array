#include<bits/stdc++.h>
using namespace std;

int secondsmallestOpt(vector<int> arr)
{
    int small=INT_MAX,ssmall=INT_MAX;

    for(int i=0;i<arr.size()-1;i++)         //n
    {
        if(arr[i]<small)
        {
            ssmall=small;
            small=arr[i];
        }   
        else if(arr[i]>small && arr[i]<ssmall)
            ssmall=arr[i];
    }
    return ssmall;
}

int secondsmallestBetter(vector<int> arr)
{
    int small=arr[0];
    int n=arr.size()-1;
    for(int i=0;i<n;i++)    //n
    {
        if(small>arr[i])
            small=arr[i];
    }

    int ssmall=INT_MAX;
    for(int i=0;i<n;i++)        //n
    {
        if(arr[i]<ssmall && arr[i]!=small)
            ssmall=arr[i];
    }
    return ssmall;
}

int secondsmallestBrute(vector<int> arr)
{
    sort(arr.begin(),arr.end());        //nlogn
    for(int i=1;i<arr.size()-1;i++)     //n
    {
        if(arr[0]!=arr[i])
            return arr[i];
    }
}

int main()
{
    vector<int> arr={5,6,4,23,45,7,8};

    cout<<secondsmallestBrute(arr);
     cout<<secondsmallestBetter(arr);
     cout<<secondsmallestOpt(arr);
    
  

}