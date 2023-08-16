class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       sort(strs.begin(), strs.end()); //sorting the array
        
        string ans=""; //creating a new empty string to store the common prefixes
        
        for(int i=0;i<strs[0].length();i++) // max iterations = length of the first string
        {
            if(strs[0][i]!=strs[strs.size()-1][i]) // checking the characters of the first and last string
                
                break;
            ans+=strs[0][i]; // concatinate if the characters are matching
        }
        return ans;
    }
};