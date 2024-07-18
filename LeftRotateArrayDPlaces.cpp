#include<bits/stdc++.h>
using namespace std;

void print(vector<int>arr)
{
    for(auto it:arr)
        cout<<it<<" ";
}

void leftRotatebrute(vector<int> &arr,int d)
{
    d=d%arr.size();
    int n=arr.size();
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=arr[i];         //d
    }

    for(int i=d;i<n;i++)
    {                              //n-d
        arr[i-d]=arr[i];
    }

    for(int i=n-d;i<n;i++)          //d
    {
        arr[i]=temp[i-n+d];
    }
    //Total TC-> n+d
}


void leftRotateoptimal(vector <int> &arr,int d)
{
    reverse(arr.begin(),arr.begin()+d);     //d
    reverse(arr.begin()+d,arr.end());       //n-d
    reverse(arr.begin(),arr.end());         //n
                                            //total Tc->2n
}

void leftRotateanother(vector<int> &arr,int d)
{
    int n=arr.size();
    vector<int> newArray(n);
    for(int i=0;i<n;i++)
    {                                            //TC->n
                                                //SC->n
        newArray[(i-d+n)%n]=arr[i];
    }
    swap(newArray,arr);
}

int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int d=3;
  //  leftRotatebrute(arr,d);
 // leftRotateoptimal(arr,d);
leftRotateanother(arr,d);
    print(arr);
}