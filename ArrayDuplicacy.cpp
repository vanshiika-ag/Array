#include<bits/stdc++.h>
using namespace std;

void print(int a[],int size)
{
    cout<<"\nArray Is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}
//BRUTE FORCE
int remDup(int a[],int size)
{
    set<int>st;

    for(int i=0;i<size;i++)
    {
        st.insert(a[i]);                //O(N log M)
    }

    int index=0;
    for(auto it:st)
    {
        a[index]=it;                   //O(M)
        index++;
    }
    return index;

}


///OPTIMIZED
int removeduplicacy(int a[],int size)
{
     int i=0;
    for(int j=1;j<size;j++)
    {
        if(a[j]!=a[i])                                //O(N)
        {
            a[i+1]=a[j];
            i++;
        }
    }
    return i+1;
}


int main()
{
    int a[]={1,1,1,2,3,4,4};
    int n=7;

   // int size=removeduplicacy(a,n);

    int size=remDup(a,n);

    print(a,size);
}