#include<bits/stdc++.h>
using namespace std;

int largestOpt(vector<int> arr)
{
    int maxi=arr[0];
    for(int i=0;i<arr.size();i++)
    {                                         //n
        if(arr[i]>maxi)
            maxi=arr[i];
    }
    return maxi;
}

int largestBrute(vector<int> arr)
{
    sort(arr.begin(),arr.end());        //nlogn
    return arr.back();
}

int main()
{
    vector<int> arr={5,6,4,23,45,7,8};

//    cout<<largestBrute(arr);
    cout<<largestOpt(arr);

}