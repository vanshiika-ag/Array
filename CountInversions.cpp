#include<bits/stdc++.h>
using namespace std;

//Print the array
void print(vector<int> &arr)
{
    for(auto it: arr)
    {
        cout<<it<<"  ";
    }
}

//Merge two sorted Arrays
int merge(vector<int> &arr,int low,int mid,int high)
{
    int count=0;
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
            count=(mid+1-left);
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
    return count;
}

 
//Merge Sort
int ms(vector<int> &arr,int low,int high)
{
    
    int count=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        count+=ms(arr,low,mid);
        count+=ms(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
    }
    return count;
}


int brute(vector<int> &arr)
{
    int cnt=0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]>arr[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr={5,4,3,2,1};
    cout<<brute(arr);
    // cout<<ms(arr,0,arr.size()-1);
}