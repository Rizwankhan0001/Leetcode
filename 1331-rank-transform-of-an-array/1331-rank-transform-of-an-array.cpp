class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n=arr.size();
         vector<int>result;
    vector<int>temp=arr;
    sort(temp.begin(),temp.end());
    unordered_map<int,int>mp;
    int count=1;
    for(int i=0;i<n;i++){
        if(mp.find(temp[i])!=mp.end()){
            continue;
        }else{
            mp[temp[i]]=count;
            count++;
        }
    }
    for(int i=0;i<n;i++){
        result.push_back(mp[arr[i]]);
    }
    return result;
    }
};