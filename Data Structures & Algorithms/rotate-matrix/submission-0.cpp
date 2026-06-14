class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     // transpose
     int n = matrix.size();
     for(int i=0;i<n;++i)
     {
        for(int j=i;j<n;++j)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
     }   
     for(int i=0;i<n;++i)
     {
        reverse(matrix[i].begin(),matrix[i].end());
     }

    }
};
/*
1 2 3   7 4 1
4 5 6 =>8 5 2
7 8 9   9 6 3

1 2 3 4
5 6 7 8
9 1 2 3
5 6 7 8
*/
