#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(pair<int,int>a , pair<int,int>b){
    if(a.first == b.first){
        // cout<<"element equal "<<endl;
       return a.second > b.second;
    }
    return a.first < b.first;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> >v(n);
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        v[i] ={x,y};
    }
    sort(v.begin(),v.end(),comp);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i].first <<" " <<v[i].second<<" ";
        cout<<endl;
    }
    
    

 return 0;
}