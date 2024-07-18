#include<bits/stdc++.h>
using namespace std;


//Print the matrix

void print(vector<vector<int>>mat)
{
    for(auto it:mat)
    {
        for(auto el:it)
        {
            cout<<el<<"  ";
        }
        cout<<endl;
    }
}

//Brute force method
void brute(vector<vector<int>>&mat)
{
    int n=mat.size();
    vector<vector<int>> ans(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[n-1-j][i]=mat[i][j];
        }
    }
    print(ans);
}


//Optimal Method
void optimal(vector<vector<int>>&mat)
{
    int n=mat.size();
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }

    
    for(int i=0;i<n;i++)
    {
      int ind=n-1;
      for(int j=0;j<n/2;j++)
      {
        int temp=mat[j][i];
        mat[j][i]=mat[ind][i];
        mat[ind][i]=temp;
        ind--;
      }
    }

    print(mat);
}

int main()
{
     vector<vector<int>> mat={{1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}};
    // brute(mat);
    optimal(mat);
}