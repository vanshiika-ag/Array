#include<bits/stdc++.h>
using namespace std;

//Print the Array
void print(vector<int> &arr){
    for(auto it:arr)
    {
        cout<<it<<"  ";
    }
}

 
//brute force solution
void brute(vector<int> &arr1,vector<int>&arr2)
{
    int n=arr1.size();
    int m=arr2.size();
    vector<int>arr3;

    int left=0;
    int right=0;

    while(left<n && right<m)
    {
        if(arr1[left]<=arr2[right])
        {
            arr3.push_back(arr1[left]);
            left++;
        }
        else{
            arr3.push_back(arr2[right]);
            right++;
        }
    }

    while(left<n)
    {
         arr3.push_back(arr1[left]);
            left++;
    }

    while(right<m)
    {
          arr3.push_back(arr2[right]);
            right++;
    }


    for(int i=0;i<n+m;i++)
    {
        if(i<n)arr1[i]=arr3[i];
        else    arr2[i-n]=arr3[i];
    }
    // print(arr3);
    print(arr1);
    print(arr2);
}


//OPtimal Solution 1
void optimal1(vector<int>&arr1,vector<int>&arr2)
{
    int n=arr1.size();
    int m=arr2.size();

    int left=n-1;
    int right=0;

    for(int i=n-1;i>=0;i--)
    {
        if(arr1[left]>arr2[right])
        {
            swap(arr1[left],arr2[right]);
            right++;
        }
        else
            break;
    }

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    print(arr1);
    print(arr2);
}

//Swapping Function
void swapping(vector<int> &arr1,vector<int> &arr2,int left,int right)
{
    if(arr1[left]>arr2[right])
        swap(arr1[left],arr2[right]);
}

//Optimal Solution 2
void optimal2(vector<int>&arr1,vector<int>&arr2)
{
    int n=arr1.size();
    int m=arr2.size();
    int len=n+m;
    int gap=(len/2)+(len%2);

    while(gap>0)
    {
        int left=0;
        int right=left+gap;

        while(right<len)
        {
            //arr1 and arr2
            if(left<n && right>=n)
            {
                swapping(arr1,arr2,left,right-n);
            }
            //arr2 and arr2
            else if(left>=n){
                swapping(arr2,arr2,left-n,right-n);
            }
            //arr1 and arr1  
            else
            {
                swapping(arr1,arr1,left,right);
            }
            left++;
            right++;
        }

        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }

    print(arr1);
    print(arr2);
}



int main()
{
    vector<int> arr1={1,3,5,7};
    vector<int> arr2={0,2,6,8,9};
    // brute(arr1,arr2);
    // optimal1(arr1,arr2);
    optimal2(arr1,arr2);
}
