//Using unordered_map we created a graph
class Solution {
public:
    void dfs(unordered_map<int, vector<int> >& adj, int sv, vector<bool>& visited) {
        visited[sv] = true;

        for(auto &node : adj[sv]) {
            if(!visited[node]) {
                dfs(adj, node, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int> > adj;
        int n = isConnected.size();

        for(int i=0; i<n; i++) {

            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    int u = i;
                    int v = j;

                    adj[u].push_back(v);
                    //adj[v].push_back(u);
                }
            }
        }

        // for(int i=0; i<n; i++) {
        //     cout << i << "->";
        //     for(auto &node : adj[i]) {
        //         cout << node << ",";
        //     }
        //     cout << endl;
        // }

        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(adj, i, visited);
                cnt++;
            }
        }

        return cnt;
    }
};

//Using only matrix we solved a question
class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected, int sv, vector<bool>& visited) {
        visited[sv] = true;

        for(int v=0; v<n; v++) {
            if(!visited[v] and isConnected[sv][v] == 1) {
                dfs(isConnected, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        // for(int i=0; i<n; i++) {
        //     cout << i << "->";
        //     for(auto &node : adj[i]) {
        //         cout << node << ",";
        //     }
        //     cout << endl;
        // }

        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(isConnected, i, visited);
                cnt++;
            }
        }

        return cnt;
    }
};