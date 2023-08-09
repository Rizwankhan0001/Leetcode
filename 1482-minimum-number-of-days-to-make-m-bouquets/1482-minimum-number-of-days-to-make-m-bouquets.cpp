class Solution {
public:
    bool possible(vector<int>& nums, int day, int m, int k) {
        int cnt = 0, num = 0;
        for(int i = 0; i< nums.size(); i++) {
            if(nums[i] <= day) cnt++;
            else {
                num += cnt/k;
                cnt = 0;
            }
        }
        num += cnt/k;
        return num>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if(val>n) return -1;
        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i< n; i++) {
            low = min(bloomDay[i], low);
            high = max(bloomDay[i], high);
        }
        while(low<=high) {
            int mid = (low+high)/2;
            if(possible(bloomDay, mid, m, k)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};