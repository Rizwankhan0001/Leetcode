class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
          int n=nums.size();
        vector<vector<int>> ans;
        // (1<<n) =2^n (left chit  of n)
        for(int subset_num=0; subset_num < (1<<n); subset_num++)
        {
            vector<int> subset;
            for(int i=0;i<n;i++)
            {
                // if the ith bit is set 
                if( (subset_num & (1<<i)) )
                {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};