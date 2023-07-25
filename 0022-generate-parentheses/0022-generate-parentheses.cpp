class Solution {
public:
    void f(string s,int ct,int counter,int n,vector<string>&v){
        if(ct<0) return;
        if(counter==2*n){
            if(ct==0){
                v.push_back(s);
            }
            return;
        }
        
        f(s+'(',ct+1,counter+1,n,v);
        f(s+')',ct-1,counter+1,n,v);
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
        string s="";
        f(s,0,0,n,v);
        return v;
        
    }
};