#include<bits/stdc++.h>
using namespace std;

void print(vector<int>arr)
{
    for(auto it:arr)
        cout<<it<<" ";
}

void moveZeroesbrute(vector<int> &arr)
{
    vector<int>temp;
    int n=arr.size();
    for(int i=0;i<n;i++)                    //n
    {
        if(arr[i]!=0)
           temp.push_back(arr[i]);
    }

    for(int i=0;i<temp.size();i++)          //x
    {
        arr[i]=temp[i];
    }

    for(int i=temp.size();i<n;i++)      //n-x
    {
        arr[i]=0;
    }                                      //TC->2n
}

void moveZeroesoptimal(vector<int> &arr)
{
    int j=-1;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {                                   //x
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)
        return;
    for(int i=j+1;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);      //n-x
            j++;
        }
    }
    //TC->n
}

int main()
{
    vector<int>arr={4,3,1,2,0,5,9,41,2,0,0};

  //  moveZeroesbrute(arr);
        moveZeroesoptimal(arr);
    print(arr);
}