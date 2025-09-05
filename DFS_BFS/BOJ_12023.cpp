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

// BOJ_13023 (DFS)

static vector<vector <int>> A;
static vector<bool> visited;
static bool anwser;

void DFS(int num, int depth) {

	if (depth == 5 || anwser) {
		anwser = true;
		return;
	}
	visited[num] = true;
	
	for (int i : A[num]) {
		if (!visited[i]) {
			DFS(i, depth + 1);
		}
	}

	visited[num] = false;
}

int main() {
	anwser = false;
	int N, E;
	cin >> N >> E;
	int s, e;
	A.resize(N);
	visited = vector<bool>(N, false);

	for (int i = 0; i < E; i++) {
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for (int i = 0; i < N; i++) {
		DFS(i, 1);
		if (anwser)
			break;
	}

	if (anwser)
		cout << "1";
	else
		cout << "0";
}