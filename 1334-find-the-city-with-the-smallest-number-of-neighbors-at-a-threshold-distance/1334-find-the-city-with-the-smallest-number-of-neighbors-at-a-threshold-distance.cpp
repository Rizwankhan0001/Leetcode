class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> matrix(n,vector<int> (n,INT_MAX));
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];

            matrix[u][v]  = edge[2];
            matrix[v][u] = edge[2];
        }
        for(int i=0;i<n;i++)
        {
            matrix[i][i] = 0;
        }
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                if(i==via) //via wali row skipped
                    continue;
                for(int j=0;j<n;j++)
                {
                    if(j==via) //via wala column skipped
                        continue;
                    else
                    {
                        if(matrix[i][via] == INT_MAX || matrix[via][j] == INT_MAX)
                        {
                            continue;
                        }
                        matrix[i][j] = min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of neighbors within the threshold
        int cntCity = n; // Initialize the count to maximum
        int cityNo = -1; // Initialize City number with fewest neighbours
        for(int i=0;i<n;i++)
        {
            int count =0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] <= distanceThreshold)
                {
                    count++;
                } 
            }
            if(count <= cntCity)
            {
                cntCity = count;
                cityNo = i;
            }
        }

        return cityNo;
    }
};