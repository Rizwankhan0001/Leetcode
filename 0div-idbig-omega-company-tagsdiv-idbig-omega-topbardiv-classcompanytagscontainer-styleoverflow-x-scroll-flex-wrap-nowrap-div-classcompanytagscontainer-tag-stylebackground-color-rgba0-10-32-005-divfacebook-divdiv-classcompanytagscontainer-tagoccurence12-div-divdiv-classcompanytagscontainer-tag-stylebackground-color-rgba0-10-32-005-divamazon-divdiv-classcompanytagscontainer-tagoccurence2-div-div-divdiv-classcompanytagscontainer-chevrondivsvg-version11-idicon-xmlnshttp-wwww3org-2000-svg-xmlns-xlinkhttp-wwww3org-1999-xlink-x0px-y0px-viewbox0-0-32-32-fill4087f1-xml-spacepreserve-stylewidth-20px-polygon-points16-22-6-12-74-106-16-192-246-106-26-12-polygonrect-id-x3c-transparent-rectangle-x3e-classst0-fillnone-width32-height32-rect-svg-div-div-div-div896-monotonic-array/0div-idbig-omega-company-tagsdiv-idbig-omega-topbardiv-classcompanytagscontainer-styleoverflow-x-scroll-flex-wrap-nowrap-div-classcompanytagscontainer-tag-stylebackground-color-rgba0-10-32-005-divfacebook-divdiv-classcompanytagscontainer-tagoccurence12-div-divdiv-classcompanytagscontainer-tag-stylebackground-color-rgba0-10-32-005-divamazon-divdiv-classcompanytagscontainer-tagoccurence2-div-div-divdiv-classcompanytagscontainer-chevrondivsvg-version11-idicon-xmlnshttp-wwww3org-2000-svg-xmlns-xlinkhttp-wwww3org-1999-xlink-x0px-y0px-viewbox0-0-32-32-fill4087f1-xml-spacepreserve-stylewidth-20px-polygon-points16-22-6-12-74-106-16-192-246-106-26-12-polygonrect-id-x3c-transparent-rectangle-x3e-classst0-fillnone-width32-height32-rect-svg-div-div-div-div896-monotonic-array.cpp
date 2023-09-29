class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        // direction is initialize to track weather it is increasing or it is decreasing 
        int direction = 0;
        for(int i = 1; i < n; i++){
            if(direction > 0 && nums[i] < nums[i-1]) return false;
            if(direction < 0 && nums[i] > nums[i-1]) return false;
            if(direction == 0) direction = nums[i] - nums[i-1];
        }
        return true;
    }
};