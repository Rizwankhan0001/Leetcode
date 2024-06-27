class Solution {
public:
    int secondHighest(string s) {
        int max1=-1;
        int max2=-1;

        for(const char&ch:s){
            if(isdigit(ch)){
                int num=ch-'0';
                if(num>max1){
                    max2=max1;
                    max1=num;
                }else if(num>max2 && num!=max1){
                    max2=num;
                }
            }
        }
        return max2;
    }
};