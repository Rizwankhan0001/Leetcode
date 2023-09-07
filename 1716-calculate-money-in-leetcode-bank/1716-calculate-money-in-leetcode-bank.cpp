class Solution {
public:
    int totalMoney(int n) {
        int nw=n/7;
        int nd=n%7;
        
        int sum=0;
        for(int i=0;i<nw;i++){
           sum += (28) + (7*i);
        }
        
        int start=nw+1;
        for(int i=0;i<nd;i++){
            sum+=start+i;
        }
        return sum;
        
    }
};