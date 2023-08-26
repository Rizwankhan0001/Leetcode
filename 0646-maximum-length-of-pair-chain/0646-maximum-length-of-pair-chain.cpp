class Solution {
private:
    static bool cmp(vector<int> &a , vector<int> &b){
        return a[1]<b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);// sort based on end values

        int cnt =0;
        for(int i=0, j=0; j<pairs.size(); j++){
            //   now check for start value of j should be more than i's end and substitute i to j
            if(j==0 || pairs[i][1] < pairs[j][0]){
                cnt++;
                i=j;
            }
        }
        return cnt;
    }
};