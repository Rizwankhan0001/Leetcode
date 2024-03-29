class Solution {
public:
    int singleNumber(vector<int>& nums) {
                int ans=0;
        for(int i=0;i<32;i++){
            int cSet=0,cUnset=0;
            for(int j=0;j<nums.size();j++){
               if((1<<i)&nums[j])    cSet++;
               else cUnset++;
            }
            if(cSet%3)   
                ans=ans|(1<<i);
        }
        return ans;

    }
};