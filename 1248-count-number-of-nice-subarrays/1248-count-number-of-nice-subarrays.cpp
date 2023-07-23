class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int res = 0, i = 0, j = 0, count = 0;
        while(j < nums.size()) {
            if (nums[j] % 2 == 1) {
                k--;
                count = 0;
            }
            while (k == 0) {
                 
                if(nums[i] % 2 == 1) {
                    k++;   
                }
                count++;
                i++;
            }
            j++;
            res += count;
        }
        return res;
    }
};