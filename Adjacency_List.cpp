#include <iostream>
#include <vector>
using namespace std;

void bournVita() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
}

void addEdge(vector<int> adj[], int f, int s) {
    adj[f].push_back(s);
    adj[s].push_back(f);
}

int main() {
    bournVita();

    int n, e;
    cin >> n >> e;

    vector<int> adj[n];

    for(int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;
        addEdge(adj, f, s);
    }

    for(int i=0; i<n; i++) {
        cout << i << "->";

        for(auto &ele : adj[i]) {
            cout << ele << ",";
        }
        cout << endl;
    }
    
    return 0;
}