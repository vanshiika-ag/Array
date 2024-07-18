#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{
    for(auto it:arr)
        cout<<it<<" ";
}

void remdupBrute(vector<int> &arr)
{
    set <int> st;

    for(auto it:arr)            //nlogn
        st.insert(it);
    
    int index=0;
    for(auto it:st)
    {                           //m
        arr[index]=it;
        index++;     
    }
    
    arr.erase(arr.begin()+index,arr.end());       //n-m
   
}
void remdupOpt(vector<int> &arr)
{
    int i=0;

    for(int j=1;j<arr.size();j++)           //n
    {
        if(arr[i]!=arr[j])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }
    arr.erase(arr.begin()+i+1,arr.end());       //about n
   
}

int main()
{
    vector<int> arr={1,1,4,5,6,6,9,23,23,78};

    remdupBrute(arr);
    print(arr);

    // cout<<endl;
    // remdupOpt(arr);
    // print(arr);
}