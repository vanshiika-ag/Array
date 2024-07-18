#include<bits/stdc++.h>
using namespace std;

void print(vector<int>arr)
{
    for(auto it:arr)
        cout<<it<<" ";
}

void rightRotatebrute(vector<int> &arr,int d)
{
    d=d%arr.size();
    int temp
}

int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int d=3;

    rightRotatebrute(arr,d);
    print(arr);
}