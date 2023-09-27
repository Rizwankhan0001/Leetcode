class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long dLength=0;
        for(auto character:s){
            if(isdigit(character)){
                dLength*=character-'0';
            }else{
                dLength++;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(isdigit(s[i])){
                dLength/=(s[i]-'0');
                k=k%dLength;
            }else{
                 if (k == 0 || dLength == k)
                    return string("") + s[i];
                dLength--;
            }
        }
        return "";
    }
};