class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size=s.size();
        int p_size=p.size();
        vector<vector<int>> DP(s_size+1,vector<int>(p_size+1,0));
        DP[0][0]=1;
        for(int j(2);j<=DP[0].size()-1;j++)
        {
            if(DP[0][j-2]&&p[j-1]=='*')
            {
                DP[0][j]=1;
            }
        }
        for(int i(1);i<=DP.size()-1;i++)
        {
            for(int j(1);j<=DP[0].size()-1;j++)
            {
                if(p[j-1] == '*')
                {
                    DP[i][j] = DP[i][j-2];//*we use totally 0 character before it
                    //so if DP[i][j-2]=1, we can directly assign 1 to DP[i][j] Think about s="a",p="ac*"
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                    {
                        if(DP[i-1][j])
                        {
                            DP[i][j]=1;// we need to use * to copy the element before it
                        }
                    }
                }
                else if(p[j-1]==s[i-1]||p[j-1]=='.')
                {
                    DP[i][j]=DP[i-1][j-1];
                }
            }
        }
        return DP[s_size][p_size]==1;
    }
};