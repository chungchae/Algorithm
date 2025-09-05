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
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

// BOJ 15651 N과 M(3) (DFS) (S3)

int N; int M;
vector<int> arr;
vector<bool> visited;

// DFS 백트래킹
void BT(int depth) {
	if (depth == M) {
		for (int node : arr) {
			if (node != 0) {
				cout << node << " ";
			}
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[depth] = i;
		BT(depth + 1);
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	arr = vector<int>(M, 0);
	visited = vector<bool>(N + 1, false);

	BT(0);
}


