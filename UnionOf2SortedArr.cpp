#include<bits/stdc++.h>
using namespace std;

void print(vector<int>arr)
{
    for(auto it:arr)
        cout<<it<<" ";
}

vector<int> unionbrute(vector<int> arr1,vector<int>arr2)
{
    map<int,int>mpp;

    vector<int> ans;

    for(int i=0;i<arr1.size();i++)
    {
        mpp[arr1[i]++];         //n1 logn
    }

    
    for(int i=0;i<arr2.size();i++)
    {
        mpp[arr2[i]++];        //n2 log n
    }

    for(auto it: mpp)
    {
        ans.push_back(it.first);        //n1+n2
    }
    return ans;
}

vector<int> unionbetter(vector<int> arr1,vector<int> arr2)
{
    set <int> st;

    for(int i=0;i<arr1.size();i++)
    {                                       //n1logn
        st.insert(arr1[i]);
    }

    for(int i=0;i<arr2.size();i++)
    {                                       //n2log n
        st.insert(arr2[i]);
    }

    vector<int> temp;
    for(auto it:st)                         
    {                                   //n1+n2
        temp.push_back(it);
    }
    return temp;
}

vector<int> unionoptimal(vector<int> arr1,vector<int> arr2)
{
    int n1=arr1.size();
    int n2=arr2.size();

    vector<int>ans;

    int i=0,j=0;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            if(ans.size()==0 || ans.back()!=arr1[i])
                 ans.push_back(arr1[i]);
                    i++;        
        }
        else 
        {
            if(ans.size()==0 || ans.back()!=arr2[j])
                    ans.push_back(arr2[j]);   
                 j++;
        }
    }

    while(i<n1)
    {
    
            if(ans.back()!=arr1[i])
                 ans.push_back(arr1[i]);
               i++;
        
    }

    while(j<n2)
    {
          if(ans.back()!=arr2[j])
                    ans.push_back(arr2[j]);
                   j++;
    }

     return ans;
}

int main()
{
    vector<int>arr1= {1,1,2,3,4,5,6};
    vector<int>arr2= {2,3,4,4,5,6};

 //   vector<int>ans=unionbrute(arr1,arr2);
    //vector <int> ans=unionbetter(arr1,arr2);
    vector<int> ans=unionoptimal(arr1,arr2);
    print(ans);
}