//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
            ans^=nums[i];
        //now we have to separate it
        //x & ~(x-1) 
        ans=ans & ~(ans-1);
        // separate  numbers -> &with the numbers, different
        //set1 & set2
        
        int set1=0;
        int set2=0;
        
        for(int i=0;i<n;i++)
        {
            if(ans & nums[i])
            set1^=nums[i];
            else set2^=nums[i];
        }
        vector<int>result;
        result.push_back(set1);
        result.push_back(set2);
        
        sort(result.begin(),result.end());
        
        return result;
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends