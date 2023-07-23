class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int count[3] = {0}; 
        
        int left = 0, right = 0;
        while (right < n) {
            count[s[right] - 'a']++; 
            
            while (count[0] && count[1] && count[2]) {
                ans += n - right; 
                
                count[s[left] - 'a']--; 
                left++; 
            }
            
            right++;
        }
        
        return ans;
    }
};
