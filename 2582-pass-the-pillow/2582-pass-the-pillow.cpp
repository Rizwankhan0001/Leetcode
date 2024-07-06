class Solution {
public:
    int passThePillow(int n, int time) {
        int trip=time/(n-1); //total no of trip
        int index=time % (n-1); //Direction-LR

        if(trip%2==0){
            return index+1;
        } else{
            return n-index;
        }
    }
};