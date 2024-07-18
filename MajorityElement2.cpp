#include<bits/stdc++.h>
using namespace std;

//Brute force Solution
int brute(vector<int> arr)
{
    int ans=-1;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=i;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                cnt++;
                // cout<<arr[i]<<" "<<cnt<<endl;
            }
        }
        if(cnt>n/2)
            ans=arr[i];
    }
    return ans;
}


//Better Solution using hashmaps
int better(vector<int>arr)
{
    map<int,int>mpp;
    int maxi=(arr.size()/2)+1;
    for(int i=0;i<arr.size();i++)
    {
        mpp[arr[i]]++;
        if(mpp[arr[i]]==maxi)
            return arr[i];
    }

    return -1;
}

//Optimal Solution using Moores Voting Algorithm
int optimal(vector<int>arr)
{
    int cnt=0;
    int el=-1;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            cnt=1;
            el=arr[i];
        }
        else if(el==arr[i])
            cnt++;
        else
            cnt--;
    }
    return el;
}


int main()
{
    vector<int> arr={2,2,1,1,1,2,2};
    cout<<brute(arr);

}