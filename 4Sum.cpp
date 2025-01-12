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


//Brute force solution
void brute(vector<int> arr,int target)
{
    set<vector<int>>st;
    int n=arr.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    int sum=arr[i];
                    sum+=arr[j];
                    sum+=arr[k];
                    sum+=arr[l];

                    if(sum==target)
                    {
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>>ans(st.begin(),st.end());
    print(ans);
}

//Better solution using a hashset
void better(vector<int>arr,int target)
{
    int n=arr.size();
    set<vector<int>> st;

    for(int i=0;i<n;i++)
    {
       
        for(int j=i+1;j<n;j++)
        {
            set<int> hashset;
            for(int k=j+1;k<n;k++)
            {
                int a=arr[i];
                int b=arr[j];
                int c=arr[k];
                int d=target-(a+b+c);
                if(hashset.find(d)!=hashset.end())
                {
                    vector<int> temp={a,b,c,d};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    print(ans);
}


//Optimal Solution
void optimal(vector<int>arr,int target)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1])continue;

        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1;
            int l=n-1;

            while(k<l)
            {
                int sum=arr[i];
            sum+=arr[j];
            sum+=arr[k];
            sum+=arr[l];

            if(sum==target)
            {
                vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                ans.push_back(temp);
                k++;
                l--;

                while(k<l && arr[k]==arr[k-1])k++;
                while(k<l && arr[l]==arr[l+1])l--;
            }   
            else if(sum<0)k++;
            else l--;
            }
        }
    }    
    print(ans);
}   

int main()
{
    vector<int> arr={1,0,-1,0,-2,2};
    // brute(arr,0);
    // better(arr,0);
    optimal(arr,0);
}