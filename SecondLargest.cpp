#include<bits/stdc++.h>
using namespace std;

int slargebrute(vector<int> a)
{

    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=a[i-1])
            return a[i-1];          //nlogn +n
    }
    return -1;
}

int slargebetter(vector<int> a)
{
    int largest=a[0];
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>largest)
            largest=a[i];           //n
    }

    int slargest=INT_MIN;

    for(int i=0;i<a.size();i++)
    {                                                               
        if(a[i]<largest && a[i]>slargest)                       //n
            slargest=a[i];
    }
    return slargest;
}

int slargeoptimal(vector<int> a)
{
    int largest=INT_MIN,slargest=INT_MIN;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]>largest)                //n
        {
            slargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>slargest)
            slargest=a[i];
    }
    return slargest;
}

int main()
{
    vector <int> a={1,2,3,5,6,4};
   

 //   int slargest=slargebrute(a);
   // int slargest=slargebetter(a);  
    int slargest=slargeoptimal(a);
    cout<<slargest;
}
