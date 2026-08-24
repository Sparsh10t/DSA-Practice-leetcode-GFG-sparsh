class Solution {
public:
    void primeFactorCount(int r,vector<int>& nums,unordered_map<int,int>& mp,vector<vector<int>>& adj){
        int x = nums[r];
        for(long long i=2; i*i<=x; i++) {
            if(x % i == 0) {
            mp[i]++;
            adj[r].push_back(i);
            while(x % i == 0) {
                x /= i;
            }
            }
        }
        if(x > 1) {
            mp[x]++;
            adj[r].push_back(x);
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int> mp;
        vector<vector<int>> adj(n);
        int l=0;
        int ans = 0;
        for(int r=0;r<n;r++){
            primeFactorCount(r,nums,mp,adj);
            while(mp.size()>k){
                for(auto it:adj[l]){
                    mp[it]--;
                    if(mp[it]==0) mp.erase(it);
                }
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};