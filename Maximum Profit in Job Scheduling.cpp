Question Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06

============================================================================================================================================================================================================
Explanation:

1) There are only two possibilities for each Job (Either Include it or exclude it),
2) As we want to have the maximum profit , we will explore both the possibilities and take maximum among them.

# Important Points:
1) If one Job is included then the next job to be included should be non overlapping with the previous one.
i.e,
The StartTime of next Job >= EndTime of Current Job (Condition of non overlapping interval)
2) As we have to consider the job according to start time, so its better to sort the jobs according to startTime.

#How to get the next non overlapping Job:
** As the jobs are sorted , hence we can use Binary Search  to find out the next Job,
which follow this condition
	StartTime of next Job >= EndTime of Current Job.

============================================================================================================================================================================================================

Solution:

class Solution {
public:
    static bool const comp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }

    int getbestind(int ind,vector<vector<int>>&v)
    {
        int l=ind+1,h=v.size()-1,m,ans=-1;
        while(l<=h)
        {
            m=(l+h)/2;
            if(v[m][0]>=v[ind][1])
            {
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }

    int maxprofit(int ind,vector<vector<int>>&v,vector<int>&dp)
    {
        if(ind==v.size())return 0;

        if(dp[ind]!=-1)return dp[ind];

        int nextind=getbestind(ind,v);

        int pick=v[ind][2]+((nextind==-1)?0:maxprofit(nextind,v,dp));
        
        int nonpick=maxprofit(ind+1,v,dp);

        return dp[ind]=max(pick,nonpick);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>v(n,vector<int>(3));
        for(int i=0;i<n;i++)
        {
            v[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(v.begin(),v.end(),comp);
        vector<int>dp(n+1,-1);
        return maxprofit(0,v,dp);
        
    }
};
