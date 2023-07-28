class Solution {
private:
    void dfs(int start,vector<int>adj[],vector<int>&vis){
        vis[start]=1;
        //Going through all adjacsent connected city and marking them visited
        for(auto &it:adj[start]){
            if(!vis[it]){
                //if that adjacent city is not marked and is reachable call dfs() to mark that as well
                vis[it]=1;
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        //Creating a adjacency list
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
        vector<int>vis(n+1,0);
        int ans=0;
        //Going through all nodes 
        for(int i=1;i<=n;i++){
            if(!vis[i]) {
                //This will mark all connected nodes from any node i
                dfs(i,adj,vis);
                //increasing number of provinces
               ans++;
            }
        }
        return ans;
    }
};