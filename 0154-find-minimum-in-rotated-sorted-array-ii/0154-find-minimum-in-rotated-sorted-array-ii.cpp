class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int s = 0,e = nums.size() - 1;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (nums[m] > nums[e]) { 
                s = m + 1;
            }
            else if (nums[m] < nums[s]) { 
                e = m;
                s++;
            }
            else { // nums[lo] <= nums[mi] <= nums[hi] 
                e--;
            }
        }
        
        return nums[s];
    }
    
};