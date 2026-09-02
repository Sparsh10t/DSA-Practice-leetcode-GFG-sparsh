class Solution {
public:
    long long modPow(long long x, long long y) {
        long long ans = 1;
        while (y > 0) {
            if (y & 1) ans = (ans * x) % 1000000007;
            x = (x * x) % 1000000007;
            y >>= 1;
        }
        return ans;
    }

    void findXY(int width, long long d, int& x, int& y){
        string sd = to_string(d);
        string x1 = sd.substr(0,width);
        string y1 = sd.substr(x1.length());
        x = stoi(x1);
        y = stoi(y1);
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            int width = nums[i]%10;
            long long d = floor(nums[i]/10);
            int x,y;
            findXY(width,d,x,y);
            sum = (sum + modPow(x, y)) % 1000000007;
        }
        return sum;
    }
};