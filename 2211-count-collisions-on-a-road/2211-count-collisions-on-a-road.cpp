class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, cnt = 0;
        stack<char>st;
        for(auto ch : directions){
            if(ch == 'R') st.push('R'), cnt++;
            else if(ch == 'L'){
                if(!st.empty() && st.top() == 'S'){
                    ans++;
                }
                else if(!st.empty() && st.top() == 'R'){
                    ans += 2;
                    if(cnt > 1) ans += (cnt-1);
                    st.push('S');
                    cnt = 0;
                }
            }
            else {
                if(!st.empty() && st.top() == 'R') {
                    ans++;
                    if(cnt > 1) ans += (cnt-1);
                    st.push('S');
                    cnt = 0;
                }
                st.push('S');
            }
        }
        return ans;
    }
};