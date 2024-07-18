#include<bits/stdc++.h>
using namespace std;


bool sortedBrute(vector<int>arr)
{
    int n=arr.size();           //n*n

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
                return false;
        }
    }
    return true;
}

bool sortedOpt(vector<int > arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]<arr[i+1])                 //n
            {}
        else 
            return false;
    }
    return true;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6,90,8};
    cout<<sortedBrute(arr);
    cout<<sortedOpt(arr);
}