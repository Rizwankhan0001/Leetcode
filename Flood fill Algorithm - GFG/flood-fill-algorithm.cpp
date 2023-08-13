//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   private:
    void dfs(int crow,int ccol,int color, vector<vector<int>>& image,int scolor){
        image[crow][ccol]=color;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for (int i=0;i<4;i++){
            int nrow=crow+delrow[i];
            int ncol=ccol+delcol[i];
            if (nrow<image.size() && nrow>=0 && ncol<image[0].size() && ncol>=0
            && image[nrow][ncol]==scolor && image[nrow][ncol]!=color){
                dfs(nrow,ncol,color,image,scolor);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        dfs(sr,sc,color,image,image[sr][sc]);
        return image; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends