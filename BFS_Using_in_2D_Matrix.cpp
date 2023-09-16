//Problem: Shortest Path in Binary Matrix(LeetCode)
//Wgt is 1 for ALL EDGES So That's why BFS is used
class Solution {
public:
    int row, col;
    int dx[8] = {0,0,-1,1,-1,-1,1,1};
    int dy[8] = {1,-1,0,0,-1,1,1,-1}; 
    bool isValid(vector<vector<int>>& grid, vector<vector<bool> >& visited, int i, int j) {
        if(i < row and i >= 0 and j < col and j >= 0 and visited[i][j] == false and grid[i][j] == 0) {
            return true;
        }

        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        if(grid[0][0] == 1) return -1;

        vector<vector<bool> > visited(row, vector<bool>(col, false));

        queue<pair<pair<int, int>, int> > q; 
        q.push({{0, 0}, 1}); // at (0, 0) distance is 1

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if(i == (row - 1) and j == (col - 1)) {
                return dist;
            }

            for(int k=0; k<8; k++) {
                int newX = i + dx[k];
                int newY = j + dy[k];

                if(isValid(grid, visited, newX, newY)) {
                    visited[newX][newY] = true;

                    q.push({{newX, newY}, dist + 1});
                }
            }
        }    

        return -1;
    }
};
