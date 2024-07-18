#include<bits/stdc++.h>
using namespace std;

void print(vector<int>arr)
{
    for(auto it:arr)
        cout<<it<<" ";
}

vector<int> intersectionbrute(vector<int> arr1,vector<int>arr2)
{
    int n=arr1.size();
    int m=arr2.size();

    int vis[m]={0};
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j] && vis[j]==0)
            {
                ans.push_back(arr1[i]);
                vis[j]=1;                       //n*m
                break;
            }
            if(arr2[j]>arr1[i]) 
            break;    
        }     
    }
    return ans;
}


vector<int> intersectionoptimal(vector<int> arr1,vector<int>arr2)
{
    int i=0,j=0;
    int n=arr1.size(),m=arr2.size();
    vector<int> ans;

    while(i<n && j<m)               //n+m;
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else 
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int>arr1= {1,2,2,3,3,4,5,6};
    vector<int>arr2= {2,3,3,5,6,6,7};

    vector<int> ans=intersectionbrute(arr1,arr2);
    print(ans);
}