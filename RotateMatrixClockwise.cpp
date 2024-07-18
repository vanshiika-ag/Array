#include<bits/stdc++.h>
using namespace std;

//Print the matrix
void print(vector<vector<int>>mat)
{
  for(auto it:mat)
  {
    for(auto el:it)
    {
      cout<<el<<" ";
    }
    cout<<endl;
  }
}

//Brute Force method
void brute(vector<vector<int>> &mat)
{
  int n=mat.size();
  int m=mat[0].size();  
  vector<vector<int>>ans(n,vector<int>(m,0));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      ans[j][n-1-i]=mat[i][j];
    }
  }
  print(ans);
}


//Optimal Solution
void optimal(vector<vector<int>> &mat)
{
  int n=mat.size();
  int m=mat[0].size();
    //Transpose
    for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<m;j++)
      {
        swap(mat[i][j],mat[j][i]);
      }
    }

    for(int i=0;i<n;i++)
    {
      reverse(mat[i].begin(),mat[i].end());
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