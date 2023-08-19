//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        unordered_map<char,int> m;
int mx = 0;

    for(auto it:tasks)
    {
        m[it]++;
        mx = max(mx,m[it]);
    }
    
    int ans = (mx-1)*(K+1);
    for(auto it:m)
        if(it.second==mx)
            ans++;
    
    return max((int)tasks.size(),ans);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends