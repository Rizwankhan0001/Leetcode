//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
     int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    queue<pair<pair<int, int>, int>> w;
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 2) {
                vis[i][j] = true;
                w.push({{i, j}, 0});
            }
        }
    }
    
    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    while (!w.empty()) {
        int x = w.front().first.first;
        int y = w.front().first.second;
        int steps = w.front().second;
        res = max(res, steps);
        w.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !vis[nx][ny] && grid[nx][ny] == 1) {
                vis[nx][ny] = true;
                grid[nx][ny] = 2;
                w.push({{nx, ny}, steps + 1});
            }
        }
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                return -1; 
            }
        }
    }

    return res;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends