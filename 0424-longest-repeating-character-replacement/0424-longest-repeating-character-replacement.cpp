class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        int MaxFreq = 0;
        vector<int> freq(26,0);
        for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            MaxFreq = max(MaxFreq,freq[s[r]-'A']);
            if(r-l+1 - MaxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};