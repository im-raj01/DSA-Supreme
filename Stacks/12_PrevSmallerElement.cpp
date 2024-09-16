#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<int> v = {2,1,4,3};

    stack<int>st;
    st.push(-1);
    int n = v.size();
    // cout<<n<<endl;
    vector<int>ans(n);
    for(int i = 0; i< n; i++){
        int curr = v[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    


 return 0;
}