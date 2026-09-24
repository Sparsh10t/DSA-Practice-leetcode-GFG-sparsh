//  SPACE OPTIMIZED VERSION
// for (int i = 0; i < n; i++) {
//     for (int j = coins[i]; j <= amount; j++) { 
//         dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
//     }
// } 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;
        vector<vector<int>> dp(n,vector<int>(amount+1,INF));
        for(int i=0;i<n;i++) dp[i][0] = 0;

        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                int take=INF;
                int donttake = INF;
                if(j>=coins[i]) take = 1+dp[i][j-coins[i]];
                if(i==0){
                    donttake = INF;
                }
                else donttake = dp[i-1][j];
                dp[i][j] = min(take , donttake);
            }
        }
        return dp[n-1][amount] == INF ? -1 : dp[n-1][amount];
    }
};