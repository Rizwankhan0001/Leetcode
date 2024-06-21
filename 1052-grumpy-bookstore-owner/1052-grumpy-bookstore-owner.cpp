class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int directly_satisfied=0; //where he has to not use his mintes quates to not keep him grumpy

        for(int i=0;i<n;i++){
            if(!grumpy[i]){
                directly_satisfied+=customers[i];
                customers[i]=0;
            }
        }
        int secretly_satisfied=0,sum=0;
        for(int i=0,j=0;j<n;j++){
            sum+=customers[j];
            if(j-i==minutes)
                sum-=customers[i++];
                secretly_satisfied=max(secretly_satisfied,sum);        
                }

                return directly_satisfied+secretly_satisfied;
    }
};