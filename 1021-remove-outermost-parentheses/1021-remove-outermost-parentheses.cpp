class Solution {
public:
    string removeOuterParentheses(string s) {
        
         int cnt = 0;
        string res;

        for (auto c: s) {
            if (c == '(' && cnt++ > 0 ) res.push_back(c);
            if (c == ')' && cnt-- > 1 ) res.push_back(c);
        }

        return res;
        
    }
};