#include<bits/stdc++.h>
using namespace std;


void print(vector<int> &arr)
{
    for(auto it: arr)
    {
        cout<<it<<"  ";
    }
}


//Merging two sorted Arrays
void merge(vector<int> &arr,int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    vector<int>temp;

    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
         temp.push_back(arr[left]);
         left++;
    }

    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    } 
}


//count Reverse Pairs function
int countPairs(vector<int> &arr,int low,int mid,int high)
{
    int cnt=0;
    int right=mid+1;

    for(int i=low;i<=mid;i++)
    {
        while(right<=high && arr[i]>(2*arr[right]))
        {
            right++;
        }
        cnt+=(right-(mid+1));
    }
    return cnt;
}

//Merge Sort
int ms(vector<int> &arr,int low,int high)
{
    int cnt=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        cnt+=ms(arr,low,mid);
        cnt+=ms(arr,mid+1,high);
        cnt+=countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
    }
    // cout<<cnt<<endl;
    return cnt;
    
}

int brute(vector<int>&arr)
{
    int cnt=0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]>(2*arr[j]))
            {
                cnt++;
            }
        }
    }
    return cnt;
}


int main()
{
    vector<int> arr={2,4,3,5,1};
    cout<<brute(arr);
    // cout<<ms(arr,0,arr.size()-1);
    // print(arr);
}