class Solution {
    public :
        int minDifference(vector<int>nums) {
            if(nums.size() <= 3) return 0;
            int n = nums.size();
            sort(nums.begin(),nums.end());
        
        int res = INT_MAX; 
        res = min(res, abs(nums[3] - nums[n - 1]));
        res = min(res, abs(nums[2] - nums[n - 2]));
        res = min(res, abs(nums[1] - nums[n - 3]));
        res = min(res, abs(nums[0] - nums[n - 4]));
        
        return res;
    }
};