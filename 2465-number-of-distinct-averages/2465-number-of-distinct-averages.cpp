class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        
        set<double> st;       
        int i= 0, j= nums.size()-1;
        
        sort(nums.begin(), nums.end());
        while(i<j){
            st.insert(double (nums[i]+nums[j])/2);
            i++; j--;
        }
        
        return st.size();
        
        
    }
};