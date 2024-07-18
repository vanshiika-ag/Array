#include<bits/stdc++.h>
using namespace std;


int secondLargest(int arr[],int size)
{
    int large=INT_MIN,slarge=INT_MIN;

    for(int i=0;i<size;i++){
        if(arr[i]>large)
        {
            slarge=large;
            large=arr[i];
        }
        else if(arr[i]<large && arr[i]>slarge)
        {
            slarge=arr[i];
        }
    }
    return slarge;
}

int secondSmallest(int arr[],int size)
{
    int small=INT_MAX,ssmall=INT_MAX;

    for(int i=0;i<size;i++)
    {
        if(arr[i]<small)
        {
            ssmall=small;
            small=arr[i];
        }
        else if(arr[i]>small && arr[i])
    }
}

int main()
{
    int arr[]={1,4,5,67,89,23,1,3,48};
    int size=sizeof(arr)/sizeof(arr[0]);


    cout<<"Second Largest: "<<secondLargest(arr,size);
    cout<<"\nSecond Smallest: "<<secondSmallest(arr,size);
}