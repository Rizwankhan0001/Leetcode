//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


  class Solution {
  private:    
    void traversal(int node, vector<vector<int>> &adj, vector<int> &vis, int V) {
        queue<int> q;
        
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(int i=0; i<V; i++) {
                if(!vis[i] && adj[front][i] == 1) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        
    }

  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans = 0;
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                traversal(i, adj, vis, V);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends