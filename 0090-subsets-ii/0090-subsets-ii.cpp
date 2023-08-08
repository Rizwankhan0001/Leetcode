class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans={{}};
        for(auto i : nums)
        {
            int n=ans.size();
            for(int j=0;j<n;j++)
            {
                vector<int> v(ans[j]);
                v.push_back(i);
                sort(v.begin(),v.end());
                ans.push_back(v);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};