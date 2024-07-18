#include<bits/stdc++.h>
using namespace std;


//Brute Force Solution
int brute(int x,int n)
{
    double ans=1.0;
    for(int i=0;i<n;i++)
    {
        ans*=x;
    }
    return (int)ans;
}


//Optimal Solution
int optimal(int x,int n)
{
    double ans=1.0;
    int n2=n;
    if(n2<0)n2=-1*n2;


    while(n2!=0)
    {
        if(n2%2==0)
        {
            x=x*x;
            n2=n2/2;
        }
        else
        {
           ans=ans*x;
            n2=n2-1;
        }
    }
    if(n<0) return (int)1/(int)ans;
    return ans;
}

int main()
{
    int x=2,n=10;

    // cout<<brute(x,n);
    cout<<optimal(x,n);
}