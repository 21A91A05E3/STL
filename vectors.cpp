#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(60);
    v.push_back(50);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    v.pop_back();
    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
    auto x=v.begin();
    cout<<*x;
    cout<<endl;
    auto y=v.end()-1;
    cout<<*y;
    cout<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    
}
