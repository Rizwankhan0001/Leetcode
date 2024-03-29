class Solution {
public:
    bool isSubsequence(string s, string t) {
         int i = 0;
        int n = s.size();
        int m = t.size();

        if(n == 0)
            return true;
        if(n > m)
            return false;

        for(int j = 0; j < m; j++){
            if(s[i] == t[j])
                i++;
            if(i == n)
                return true;
        }
        return false;
    }
};