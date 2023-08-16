//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
         
        int last=-1;
        
         for(int i=0;i<s.size();i++){
             if(s[i]%2!=0){
                last=i;
            }
        }
        if(last!=-1){
            return s.substr(0,last+1);  
        }
        else
        return "";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends