#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector<int>arr,int d)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==d)
            return i;       //n
    }
    return -1;
}

int  main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int d=3;
    cout<<linearsearch(arr,d);
}