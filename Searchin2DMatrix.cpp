#include<bits/stdc++.h>
using namespace std;


//Brute Force Solution
bool brute(vector<vector<int>> &mat,int target)
{
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==target)
                return true;
        }
    }
    return false;
}


//Applying Binary Search
bool bs(vector<int> arr,int target)
{
    int low=0;
    int high=arr.size()-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target)
            return true;
        else if(arr[mid]>target)
            high=mid-1;
        else
        low=mid+1;
    }
    return true;
}

//Better Solution
bool better(vector<vector<int>>&mat,int target)
{
    int n=mat.size();
    int m=mat[0].size();
    
    for(int i=0;i<n;i++)
    {
        if(target>=mat[i][0] && target<=mat[i][m-1])
            return bs(mat[i],target);
    }
    return false;
}


//Optimal Solution(Flattening a 2D matrix into 1D)
bool optimal(vector<vector<int>> &mat,int target)
{
    int n=mat.size();
    int m=mat[0].size();

    int low=0;
    int high=n*m-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;

        if(mat[row][col]==target)
            return true;
        else if(mat[row][col]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
}

int main()
{
    vector<vector<int>> mat={{1,2,3,4},
                             {5,6,7,8},
                             {9,10,11,12}};

    int target=123;

    // cout<<brute(mat,target);
    // cout<<better(mat,target);
    cout<<optimal(mat,target);
}
    