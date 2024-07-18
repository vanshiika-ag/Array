
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,1,1,1,1,4,2,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    int len=0;
    int i,j;
    for(i=0;i<size;i++)
    {
        int sum=0;
        for(j=i;j<size;j++)
        {
            sum=sum+arr[j];
        }
        if(sum==k)
            len=max(len,j-i+1);
    }
    cout<<"Max Length:"<<len;


}