#include<bits/stdc++.h>
using namespace std;

//Print the Array
void print(vector<int> arr)
{
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
}


//Brute Force Solution
void brute(vector <int> arr)
{
    int n=arr.size();
    vector<int> ans;    
    for(int i=0;i<n;i++)
    {
       if(ans.size()==0 || ans[0]!=arr[i])
        {
             int cnt=0;
            for(int j=i;j<n;j++)
            {
            if(arr[i]==arr[j])
                cnt++; 
            }
         if(cnt>n/3)
            ans.push_back(arr[i]);
        }
        
        if(ans.size()==2)
            break;
    }
    print(ans);
}



//Better Solution using Hashmap
void better(vector<int>arr)
{
    vector<int> ans;
    map<int,int>mpp;
    int maxi=(arr.size()/3)+1;
    for(int i=0;i<arr.size();i++)
    {
        mpp[arr[i]]++;
        if(mpp[arr[i]]==maxi)
            ans.push_back(arr[i]);
    }

    print(ans);
}


//Optimal Solution
void optimal(vector<int> arr)
{
    int cnt1=0;
    int cnt2=0;
    int el1,el2;
    int n=arr.size();
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && arr[i]!=el2)
        {
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=el1)
        {
            cnt2=1;
            el2=arr[i];
        }
        else if(el1==arr[i])    
            cnt1++;
        else if(el2==arr[i])
                cnt2++;
        else
            {
                cnt1--;
                cnt2--;
            }
    }

    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==el1)
            cnt1++;
        if(arr[i]=el2)
            cnt2++;
    }

    int maxi=n/3;
    if(cnt1>maxi)   
        ans.push_back(el1);
    if(cnt2>maxi)
        ans.push_back(el2);

    print(ans);
}

int main()
{
    vector <int> arr={11, 33, 33, 11, 33, 11};
    // brute(arr);
    // better(arr);
    optimal(arr);
}