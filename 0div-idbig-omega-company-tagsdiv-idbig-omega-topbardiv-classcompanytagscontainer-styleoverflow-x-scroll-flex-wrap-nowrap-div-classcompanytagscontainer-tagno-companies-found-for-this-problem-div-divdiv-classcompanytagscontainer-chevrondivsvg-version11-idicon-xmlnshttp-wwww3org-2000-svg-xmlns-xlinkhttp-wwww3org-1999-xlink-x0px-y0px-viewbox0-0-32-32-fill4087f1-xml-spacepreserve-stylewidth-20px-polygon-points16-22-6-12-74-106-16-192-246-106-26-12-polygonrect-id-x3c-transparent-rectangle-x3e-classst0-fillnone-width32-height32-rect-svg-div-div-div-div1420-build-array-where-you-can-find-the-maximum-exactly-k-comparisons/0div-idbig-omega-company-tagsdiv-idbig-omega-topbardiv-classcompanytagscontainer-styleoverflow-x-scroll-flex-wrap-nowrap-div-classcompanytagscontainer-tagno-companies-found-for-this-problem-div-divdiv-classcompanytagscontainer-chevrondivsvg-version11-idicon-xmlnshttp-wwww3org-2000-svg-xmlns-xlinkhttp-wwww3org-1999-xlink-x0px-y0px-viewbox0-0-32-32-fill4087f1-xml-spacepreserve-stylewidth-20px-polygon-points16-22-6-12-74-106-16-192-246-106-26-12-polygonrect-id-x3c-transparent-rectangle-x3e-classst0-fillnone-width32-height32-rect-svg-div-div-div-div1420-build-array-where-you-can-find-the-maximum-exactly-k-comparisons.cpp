class Solution {
public:
    int dp[51][51][101]; // Memoization table for dynamic programming
    int n, m, k;        // Inputs: n, m, k

    // Recursive function to count valid arrays
    int solve(int idx, int lenLis, int lar) {
        // Base case: If we have reached the end of the array 'n'
        if (idx == n) {
            // If we have formed a list of length 'k', return 1 (valid array), else return 0
            if (lenLis == k) {
                return 1;
            }
            return 0;
        }
        
        // If the value is already computed, return it to avoid recomputation
        if (dp[idx][lenLis][lar] != -1)
            return dp[idx][lenLis][lar];

        int ans = 0;

        // Loop through possible values 'i' from 1 to 'm'
        for (int i = 1; i <= m; i++) {
            if (i > lar) {
                // If 'i' is greater than the previous largest value 'lar', increment length
                ans += solve(idx + 1, lenLis + 1, i);
            } else {
                // If 'i' is less than or equal to 'lar', keep the length the same
                ans += solve(idx + 1, lenLis, lar);
            }
            ans = ans % 1000000007; // Keep the result within modulo 10^9+7
        }
        return dp[idx][lenLis][lar] = ans; // Memoize and return the result
    }

    // Main function to calculate the number of valid arrays
    int numOfArrays(int N, int M, int K) {
        n = N;
        m = M;
        k = K;
        memset(dp, -1, sizeof(dp)); // Initialize the memoization table with -1
        return solve(0, 0, 0);      // Call the recursive solver from the start
    }
};
