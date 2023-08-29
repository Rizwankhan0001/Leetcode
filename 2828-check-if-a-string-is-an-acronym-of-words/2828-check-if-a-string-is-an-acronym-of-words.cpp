class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(int i=0;i<words.size();i++){
            string acro=words[i];
            ans+=acro[0];
        }
        return ans==s;
        
    }
};
