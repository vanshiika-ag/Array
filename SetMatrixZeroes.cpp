#include<bits/stdc++.h>
using namespace std;

//Print the matrix
void print(vector<vector<int>> &mat)
{
    cout<<"Matrix is:"<<endl;
    for(auto it:mat)
    {
        for(auto el:it )
        {
            cout<<el<<"  ";
        }
       cout<<endl;
    }
     
}


//Make Row zero
void markRow(vector<vector<int>> &mat,int i,int n,int m)
{
    for(int j=0;j<m;j++)
    {
        if(mat[i][j]!=0)
            mat[i][j]=-1;
    }
}

//Make column zero
void markCol(vector<vector<int>> &mat,int j,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        if(mat[i][j]!=0)
            mat[i][j]=-1;
    }
}


//Brute force Solution
void matbruteforce(vector<vector<int>> &mat,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                markRow(mat,i,n,m);
                markCol(mat,j,n,m);
            }


        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==-1)
                mat[i][j]=0;
        }
    }
    print(mat);
}

//Better Solution
void matbetter(vector<vector<int>>&mat,int n,int m)
{
    int row[n]={0};
    int col[m]={0};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }    

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i] || col[j]!=0)
            {
                mat[i][j]=0;
                cout<<i<<","<<j<<"   ";
            }
          
        }
        cout<<endl;
    }

    print(mat);
}

//Optimal Solution
void matoptimal(vector<vector<int>> &mat,int n,int m)
{
    int col0=1;

    for(int i=0;i<n;i++)   
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                mat[i][0]=0;
                if(j!=0)
                    mat[0][j]=0;
                else
                    col0=0;
            }
        }
    }


    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j]!=0)
            {
                if(mat[i][0]==0 || mat[0][j]==0)
                {
                    mat[i][j]=0;
                }
            }
        }
    }

    if(mat[0][0]==0)
    {
        for(int j=0;j<m;j++)
        {
            mat[0][j]=0;
        }
    }

    if(col0==0)
    {
        for(int i=0;i<n;i++)
        {
            mat[i][0]=0;
        }
    }

    print(mat);
}

int main()
{
    vector<vector<int>> mat={{1,1,1,1},
                             {1,0,1,1},
                             {1,1,0,1},
                             {0,1,1,1}
                            };

    int n=4,m=4;

    // matbruteforce(mat,n,m);
    matbetter(mat,n,m);
    // matoptimal(mat,n,m);
}