//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
         stack<string>s;
        int len=pre_exp.length();
        for(int i=len-1;i>=0;i--)
        {
            if (pre_exp[i] == '+' || pre_exp[i] == '-' || pre_exp[i] == '*' || pre_exp[i] == '/' || pre_exp[i] == '^')
            {
                string val1=s.top();
                s.pop();
                 string val2=s.top();
                s.pop();
                string val3='('+val1+pre_exp[i]+val2+')';
                s.push(val3);
            }
            else
            {
                s.push(string(1,pre_exp[i]));
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends