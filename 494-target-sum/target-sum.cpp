class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size(), total = 0;

        for(int i=0;i<n;i++) total += arr[i];

        if(total-d<0 || (total-d)%2==1) return 0;

        int sum = (total - d)/2;
        vector<vector<int>> dp(n, vector<int> (sum+1,0));

        if(arr[0]==0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(arr[0]!=0 && arr[0]<=sum) dp[0][arr[0]] = 1; 

        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=sum;t++){
                int notpick = dp[ind-1][t];
                int pick = 0;
                if(arr[ind]<=t) pick = dp[ind-1][t-arr[ind]];
                dp[ind][t] = pick+notpick;
            }
        }
        return dp[n-1][sum];
    }
};