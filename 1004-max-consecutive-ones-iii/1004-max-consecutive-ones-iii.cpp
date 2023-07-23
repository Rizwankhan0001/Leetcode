class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int flip=0;
        int ans=0;
        
        int i=0; //help in moving forward
        int j=0; //help in unflipping
        
        
        int n=nums.size();
        
        while(i<n)
        {
            if(nums[i]==0)
            {
                flip++;
            }
            while (flip>k)
            {
                //unflip pprevios 0  because you cannot go forward
                if(nums[j]==0)
                    flip--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
        
    }
};