
/*Problem*/
/*Dijkstra's Algorithm Using  priority Queue for finding
Minm Wgt*/
/*Time Complexity: V(logV) + E(logV) = E(logV) if E > V */
#include<bits/stdc++.h>
using namespace std;

void bournVita() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

typedef pair<int, int> P;
unordered_map<int, vector<P> > adj;
void solve1() {	
	int v, e;
	cin >> v >> e;

	for(int i=0; i<e; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		adj[x].push_back({y, w});
	}

	priority_queue<P, vector<P>, greater<P> > pq;
	vector<int> result(v, INT_MAX);
	//I suppose 0 as a source
	pq.push({0, 0}); // {0-->distance, 0->src}
	result[0] = 0;

	while(!pq.empty()) {
		int dist = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for(auto& temp : adj[node]) {
			int child = temp.first;
			int d = temp.second;

			if(d + dist < result[child]) {
				result[child] = d + dist;
				pq.push({d + dist, child});
			}
		}
	}

	for(int i=0; i<v; i++) {
		//from 0 to minm wgt path for all vertices
		cout << i << "->" << result[i] << endl;
	}
}

int32_t main() {

	bournVita();
	
	solve1();

	return 0;
}
