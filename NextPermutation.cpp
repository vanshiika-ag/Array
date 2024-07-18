#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for(auto it: arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

void npbetter(vector<int> &arr)
{
    next_permutation(arr.begin(),arr.end());
    print(arr);
}

void npoptimal(vector<int> &arr)
{
    int index=-1;
    int n=arr.size();
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            index=i;
            break;
        }
    }

    if(index==-1)
    {
        reverse(arr.begin(),arr.end());
        print(arr);
    }

    for(int i=n-1;i>index;i--)
    {
        if(arr[i]>arr[index])
        {
            swap(arr[i],arr[index]);
            break;
        }
    }

    reverse(arr.begin()+index+1,arr.end());
    print(arr);

}

int main()
{
    vector<int> arr={1,3,2};

    npbetter(arr);
    npoptimal(arr);
}