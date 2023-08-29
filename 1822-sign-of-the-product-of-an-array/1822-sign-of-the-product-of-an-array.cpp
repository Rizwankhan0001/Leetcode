class Solution {
public:
    int arraySign(vector<int>& nums) {
        
         // maintain count of negative number.
        int neg=0;

        for(auto i:nums)
        {
             // if zero is present, then return 0;
             if(i==0) return 0;

            // if number is negative, then increase the count
            if(i<0) neg++;
        }

        // if count appears odd number of times.
        if(neg&1) return -1;

        return 1;
        
    }
};