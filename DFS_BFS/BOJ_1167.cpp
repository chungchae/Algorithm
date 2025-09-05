#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>

using namespace std;

// BOJ_1167 (DFS, BFS)

typedef pair<int, int> edge;
static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> m_distance;
void BFS(int index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int V;
	cin >> V;

	A.resize(V + 1);

	//get node & edge weight
	for (int i = 0; i < V; i++) {
		int S;
		cin >> S;
		while (1) {
			int E, V;
			cin >> E;
			if (E == -1)
				break;
			cin >> V;
			A[S].push_back(edge(E, V));
		}
	}
	m_distance = vector<int>(V + 1, 0);
	visited = vector<bool>(V + 1, false);
	BFS(1);
	int Max = 1;

	for (int i = 2; i <= V; i++) {
		if (m_distance[Max] < m_distance[i]) {
			Max = i;
		}
	}

	//initalize distance & visited list
	fill(m_distance.begin(), m_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);
	BFS(Max);
	sort(m_distance.begin(), m_distance.end());
	cout << m_distance[V];
}

void BFS(int index) {
	deque<int> myqueue;
	myqueue.push_back(index);
	visited[index] = true;

	while (!myqueue.empty()) {
		int now_node = myqueue.front();
		myqueue.pop_front();
		for (edge i : A[now_node]) {
			if (!visited[i.first]) {
				visited[i.first] = true;
				myqueue.push_back(i.first);
				m_distance[i.first] = m_distance[now_node] + i.second;
			}
		}
	}
}