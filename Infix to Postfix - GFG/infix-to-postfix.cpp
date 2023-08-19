//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    bool op(char c)
    {
        if(c=='*'||c=='-'||c=='+'||c=='/'||c=='^')
        return true;
    }
    int pre(char c)
    {
        if(c=='^')
        return 3;
        if(c=='/'||c=='*')
        return 2;
        if(c=='+'||c=='-')
        return 1;
        return 0;
    }
    string infixToPostfix(string s) {
        // Your code here
        string ans="";
        stack<char> st;
        for(char i:s)
        {
            if(isalnum(i))
            ans+=i;
            else if(i=='(')
            {
                st.push(i);
            }
            else if(i==')')
            {
                while(!st.empty() and st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty() and st.top()=='(')
                st.pop();
            }
            else if(op(i))
            {
                 
                    while(!st.empty() and st.top()!='(' and pre(st.top())>=pre(i))
                    {
                        ans+=st.top();
                        st.pop();
                    }
                
                st.push(i);
            }
            
        }
        while(!st.empty()){
        ans+=st.top();
        st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends