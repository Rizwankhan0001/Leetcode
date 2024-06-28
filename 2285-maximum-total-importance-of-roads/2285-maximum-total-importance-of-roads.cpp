class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> N(n,0);			
        for(int i=0;i<roads.size();i++)
        {
            N[roads[i][0]]++;
            N[roads[i][1]]++;
        }
        sort(N.begin(),N.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=((long long)N[i]*(i+1));
        }
        return ans;
    }
};