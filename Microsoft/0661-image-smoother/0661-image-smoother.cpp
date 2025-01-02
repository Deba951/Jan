class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Rows
        int n = img.size();
        // Columns
        int m = img[0].size();

        vector<vector<int>> ans;

        for(int i=0; i<n; ++i){
            vector<int> temp;

            // Let i=1, j=1
            for(int j=0; j<m; ++j){
                int count = 1;
                int sum=img[i][j];

                // i=0, j=0
                if(i-1>=0 && j-1>=0){
                    sum+=img[i-1][j-1];
                    count+=1;
                }

                // i=1, j=0
                if(j-1>=0){
                    sum+=img[i][j-1];
                    count+=1;
                }

                // i=2, j=0
                if(i+1<=n-1 && j-1>=0){
                    sum+=img[i+1][j-1];
                    count+=1;
                }

                // i=0, j=1
                if(i-1>=0){
                    sum+=img[i-1][j];
                    count+=1;
                }

                // i=2, j=1
                if(i+1<=n-1){
                    sum+=img[i+1][j];
                    count+=1;
                }

                // i=0, j=2
                if(i-1>=0 && j+1<=m-1){
                    sum+=img[i-1][j+1];
                    count+=1;
                }

                // i=1, j=2
                if(j+1<=m-1){
                    sum+=img[i][j+1];
                    count+=1;
                }

                // i=2, j=2
                if(i+1<=n-1 && j+1<=m-1){
                    sum+=img[i+1][j+1];
                    count+=1;
                }

                temp.push_back(sum/count);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};