#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}
int main()
{
    vector<pair<int,int>>vp;
    vp.push_back({10,12});
    vp.push_back({4,32});
    vp.push_back({10,13});
    vp.push_back({12,4});
    vp.push_back({7,1});
    
    for(auto it:vp)
    {
    cout<<it.first<<" "<<it.second<<" ";
    cout<<endl;
    }
    cout<<"sorting first";
    cout<<endl;
    sort(vp.begin(),vp.end());
    for(auto it:vp)
    {
    cout<<it.first<<" "<<it.second<<" ";
    cout<<endl;
    }
    
    cout<<"sorting second";
    cout<<endl;
    sort(vp.begin(),vp.end(),comp);
    for(auto it:vp)
    {
    cout<<it.first<<" "<<it.second<<" ";
    cout<<endl;
    }
    
}
