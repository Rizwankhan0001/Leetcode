class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
int mx = 0;

    for(auto it:tasks)
    {
        m[it]++;
        mx = max(mx,m[it]);
    }
    
    int ans = (mx-1)*(n+1);
    for(auto it:m)
        if(it.second==mx)
            ans++;
    
    return max((int)tasks.size(),ans);

    }
};