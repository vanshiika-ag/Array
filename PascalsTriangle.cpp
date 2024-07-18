#include<bits/stdc++.h>
using namespace std;


//Print a matrix
void print(vector<vector<int>> ans)
{
  for(auto it: ans)
  {
    for(auto el:it)
    {
      cout<<el<<" ";
    }
    cout<<endl;
  }
}


//Print element given row and col
void element(int row,int col)
{
  row=row-1.;
  col=col-1;
  int ans=1;
  for(int i=0;i<col;i++)
  {
      ans*=(row-i);
      ans/=(i+1);
  }
  cout<<ans<<" ";
}


//Print entire Row method 1
void printRow(int row)
{
  int ans=1;
  vector<int> temp;
  temp.push_back(1);

  for(int col=1;col<row;col++)
  {
    ans=ans*(row-col)/col;
    temp.push_back(ans);
  }

  for(auto it: temp)
  {
    cout<<it <<" ";
  }
}

//Print entire Row method 2
void PrintRow(int row)
{
  for(int col=1;col<=row;col++)
  {
    element(row,col);
  }
}


//Generate a row
vector<int> generateRow(int row)
{
  int ans=1;
  vector<int> temp;
  temp.push_back(1);

  for(int col=1;col<row;col++)
  {
    ans=ans*(row-col)/col;
    temp.push_back(ans);
  }
  return temp;
}

//Print entire Pascals Triangle given numbers of rows
void printEntire(int row)
{
  vector<vector<int>> ans;
  for(int i=1;i<=row;i++)
  {
    ans.push_back(generateRow(i));
  }
  print(ans);

}

int main()
{
  int row=6;
  int col=3;

  // element(row,col);
 // printRow(row);
    // PrintRow(row);
    printEntire(row);
}