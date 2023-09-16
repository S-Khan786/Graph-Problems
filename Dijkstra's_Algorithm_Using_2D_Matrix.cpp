//Problem Name: Path With Minimum Effort(LeetCode)
class Solution {
public:
    typedef pair<int, pair<int, int> > P;
    vector<vector<int> >dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int r, c;
    bool isSafe(int x, int y) {
      if(x >= 0 and x < r and y >= 0 and y < c) {
        return true;
      }

      return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();

        vector<vector<int> > result(r, vector<int>(c, INT_MAX));

        priority_queue<P, vector<P>, greater<P> > pq;
        pq.push({0, {0, 0}}); // {0->diff, {0, 0}->coordinates};
        result[0][0] = 0;

        while(!pq.empty()) {
          int diff = pq.top().first;
          int x = pq.top().second.first;
          int y = pq.top().second.second;
          pq.pop();

          for(auto& dir : dirs) {
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if(isSafe(x_, y_)) {
              
              //Route effort means --> maxm abs diff in one route 
              //that's why we finding maxDiff
              int absDiff = abs(heights[x][y] - heights[x_][y_]);
              int maxDiff = max(absDiff, diff);

              //After that store minm in result
              if(result[x_][y_] > maxDiff) {
                result[x_][y_] = maxDiff;
                pq.push({maxDiff, {x_, y_}});
              }
            }
          }
        }

        return result[r-1][c-1];
    }
};
