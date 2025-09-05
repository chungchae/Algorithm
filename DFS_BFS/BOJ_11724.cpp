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

using namespace std;

// BOJ_11724 (DFS)

static vector <vector<int>> arr;
static vector<bool> visited;
void DFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	arr.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int count = 0;

	for (int i = 1; i < N + 1; i++) {
		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}
	cout << count;
}

void DFS(int v) {
	if (visited[v]) {
		return;
	}

	visited[v] = true;

	for (int i : arr[v]) {
		if (visited[i] == false) {
			DFS(i);
		}
	}
}