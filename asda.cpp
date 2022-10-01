#include<iostream>
#include <queue>
#include <map>
#include<cstring>
#include <math.h>
#include <algorithm>
#define ll long long
const int N = 1e5 + 5;
using namespace std;
vector<ll> graph[N];
int vis[N], dis[N];
vector<ll> visiting;

//+++++++++++++++++++++++++++++++++++++++count path++++++++++++++++++++++++++++++++++++++++++++++++++
void dfs(ll src, ll dst, ll &c) {
	// if(src==dst){
	//     c++;
	//     return;
	// }
	vis[src] = 1;
	visiting.push_back(src);
	for (auto i : graph[src]) {
		if (!vis[i]) {
			dfs(i, dst, c);
			if (visiting.size() == dst) c++;
			visiting.pop_back();
			vis[i] = 0;
		}

	}
}

//+++++++++SSP single source path+++++++++++
void cycle(int i) {
	vis[i] = 1;
	for (auto it : graph[i]) {
		if (!vis[it]) {
			dis[it] = dis[i] + 1; //i is parent of it so length is just 1 greater
			cycle(it);
		}
	}
}


//--------------cycle detection using bfs----------------

bool bfs(int node, int parent) {
	queue<pair<int, int>>q;
	vis[node] = 1;
	q.push({node, parent});
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (auto i : graph[a]) {
			if (!vis[i]) {
				vis[i] = 1;
				q.push({i, a});
			} else if (i != b) {
				return true;
			}
		}
	} return false;
}

int main() {
	int n, m; cin >> n >> m;
	for (auto i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cout << bfs(1, -1);
}