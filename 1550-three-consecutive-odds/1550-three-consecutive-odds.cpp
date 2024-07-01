class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if(arr[i]%2!=0){
                ans++;
                if(ans>=3) return true;
            }
            else ans=0;
        }
        return false;
    }
};