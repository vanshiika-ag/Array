#include<bits/stdc++.h>
using namespace std;

// // Print the set
// void printset(set<vector<int>> arr)
// {
//     for(auto it:arr)
//     {
//         for(auto el:it)
//         {
//             cout<<el<<" ";
//         }
//         cout<<endl;
//     }
// }


//Print the matrix
void printmat(vector<vector<int>> mat)
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


//Brute force solution
void brute(vector<int>arr)
{
   
    set<vector<int>> st;

    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            
            for(int k=j+1;k<arr.size();k++)
            {
                if(arr[i]+arr[j]+arr[k]==0)
                {
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }

     vector<vector<int>>ans(st.begin(),st.end());
    // print(ans);
}

//Better Solution
void better(vector<int> arr)
{

    int n=arr.size();
    set<vector<int>> st;

    for(int i=0;i<n;i++)
    {
        set<int> hashset;
        for(int j=i+1;j<n;j++)
        {
            int a=arr[i];
            int b=arr[j];
            int c=-(a+b);
             if(hashset.find(c)!=hashset.end())
            {
                vector<int> temp={a,b,c};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(b);
        }
    }

    vector<vector<int>>ans(st.begin(),st.end());
    printmat(ans);
    // printset(st);
}


//Optimal Solution
void optimal(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int n=arr.size();

    vector<vector<int>> ans;

    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1])continue;
        int j=i+1;
         int k=n-1;
        while(j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];

            if(sum==0)
            {
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k]==arr[k+1])k--;
            }
            else if(sum<0) j++;
            else k--; 
        }
    }
   printmat(ans);
}

int main()
{
    vector<int> arr={-2,-2,-2,-2,-1,-1,-1,-1,0,0,0,2,2,2,2};

    // brute(arr);
    // better(arr);
    optimal(arr);
}-+








