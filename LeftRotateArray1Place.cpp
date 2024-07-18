#include<bits/stdc++.h>
using namespace std;


void print(vector<int>&arr)
{
    for(auto it: arr)
        cout<<it<<"  ";
}

vector<int> leftrotateBrute(vector<int>&arr)
{
    int n=arr.size();
    vector<int> temp(n);

    for(int i=1;i<n;i++)            //tc -n
                                    //sc -n
    {
        temp[i-1]=arr[i];
    }
    temp[n-1]=arr[0];
    return temp;
}

void leftrotateOpt(vector<int>&arr)
{
    int temp=arr[0];

    for(int i=1;i<arr.size();i++)
    {                                          //n
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6,70};

   vector<int> temp= leftrotateBrute(arr);
   print(temp);
   leftrotateOpt(arr);
   print(arr);
}