#include <bits/stdc++.h>
using namespace std;
#define ll long long

int minGroups(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    cout<<"After sorting "<<endl;
        for (int i = 0; i < intervals.size(); i++)
        {
           cout<<intervals[i][0] << " " << intervals[i][1]<<" "; 
        }
        cout<<endl;
    int group = 0;
    int i = 0;
    while (!intervals.empty())
    {
        group++;
        int end_ptr = intervals[i][1];
        cout<<"After erasing the ith element "<< intervals[i][1] <<endl;
        intervals.erase(intervals.begin() + i);
        
        for (int i = 0; i < intervals.size(); i++)
        {
           cout<<intervals[i][0] << " " << intervals[i][1]<<" "; 
        }
        cout<<endl;
        

        int j = 0;
        while (j < intervals.size())
        {
            int start_ptr = intervals[j][0];
            if (start_ptr > end_ptr)
            {
                cout<<"After erasing the jth element "<< intervals[j][0] <<endl;
                intervals.erase(intervals.begin() + j);
                
                    for (int i = 0; i < intervals.size(); i++)
                    {
                    cout<<intervals[i][0] << " " << intervals[i][1]<<" "; 
                    }
                    cout<<endl;
            }
            else
            {
                j++;
            }
        }
    }
    return group;
}

int main()
{
    vector<vector<int>> intervals = {{441459, 446342}, {801308, 840640}, {871890, 963447}, {228525, 336985}, {807945, 946787}, {479815, 507766}, {693292, 944029}, {751962, 821744}};
    cout << "Ans is " <<minGroups(intervals);
    return 0;
}