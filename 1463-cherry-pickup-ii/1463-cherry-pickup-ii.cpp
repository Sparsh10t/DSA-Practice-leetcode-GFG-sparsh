class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));

        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];

        for (int i = 1; i < m; i++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    int combo = -1;
                    for(int k =-1;k<2;k++){
                        for(int p=-1;p<2;p++){
                            int prej1 = j1+k;
                            int prej2 = j2+p;
                            if(prej1>=0 && prej1<n && prej2>=0 && prej2<n){
                                combo = max(combo,dp[i-1][prej1][prej2]);
                            }
                        }
                    }
                    if (combo == -1) continue;
                    if(j1==j2){
                        dp[i][j1][j2] = grid[i][j1] + combo;
                    }
                    else{
                        dp[i][j1][j2] = grid[i][j1]+grid[i][j2]+combo;
                    }
                }
            }
        }
        int ans = 0;

        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                ans = max(ans, dp[m-1][j1][j2]);
            }
        }
        return ans;
    }
};