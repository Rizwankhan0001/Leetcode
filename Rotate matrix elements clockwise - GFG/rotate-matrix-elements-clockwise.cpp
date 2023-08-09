//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int m, int n, vector<vector<int>> mat) {
       int left=0;
       int right=n-1;
       int botm=m-1;
       int top=0;
       while(top<botm and left<right){
           
           if(left<right){
           for(int i=right;i>left;i--){
               swap(mat[top][i],mat[top][i-1]);
           }
           }
           if(top<botm){
            for(int i=top;i<botm;i++){
               swap(mat[i][left],mat[i+1][left]);
           }
           }
           if(left<right){
            for(int i=left;i<right;i++){
               swap(mat[botm][i],mat[botm][i+1]);
           }
           
           }
           if(top<botm){
           for(int i=botm;i>top+1;i--){
              swap(mat[i][right],mat[i-1][right]); 
           }
           }
           botm--;
           top++;
           left++;
           right--;
       }
       return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends