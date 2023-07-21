//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    long long powFunction(long long x, long long N){
        if(N == 0){
            return 1;
        }
        long long ans = powFunction(x, N/2);
        ans *= ans;
        ans %= 1000000007;
        if(N%2==1){
            ans *= x;
            ans %= 1000000007;
        }
        return ans;
    }
    
  public:
    int countGoodNumbers(long long N) {
        // code here
         long long odd = N/2;
        long long even =N/2 + N%2;
        return (powFunction(5, even) * powFunction(4, odd))%1000000007;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends