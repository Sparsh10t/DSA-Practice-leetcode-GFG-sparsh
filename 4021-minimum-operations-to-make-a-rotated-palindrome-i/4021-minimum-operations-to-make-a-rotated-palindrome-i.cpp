class Solution {
public:
    void rotate(string& s,int n){
        char temp = s[0];
        for(int i=1;i<n;i++){
            s[i-1] = s[i];
        }
        s[n-1]=temp;
    }
    int minOperations(string s) {
        int n = s.size();
        int ans=INT_MAX;
        vector<string> v;
        for(int i=0;i<n;i++){
            v.push_back(s);
            rotate(s,n);
        }
        for(int k=0;k<n;k++){
            string st = v[k];
            int op = k;
            int i=0;
            int j=n-1;
            while(i<j){
                int diff = abs(st[i]-st[j]);
                op += min(diff, 26-diff);
                i++;
                j--;
            }
            ans = min(ans,op);
        }
        return ans;
    }
};