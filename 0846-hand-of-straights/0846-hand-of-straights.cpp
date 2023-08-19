class Solution {
public:
   bool isNStraightHand(vector<int>& hand, int groupSize) {
        //base case 
        int n=hand.size();

        if(hand.size()%groupSize!=0){
            return false;
        }

        //for reamining we will check whether we can make a group where next index is current index+1
        
        //can be done using ordered map
        map<int,int>mapping;
        for(auto &card : hand){
            mapping[card]++;
        }

        //now check if value is present or not
        while(!mapping.empty()){
            int curr=mapping.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mapping[curr+i]==0){ //mean not present 
                    return false; 
                }
                else if(--mapping[curr+i]<1){
                    // mean after this iteration count of that value will be less than 1
                    mapping.erase(curr+i);
                }
            }
        }

        return true;        
    }
};