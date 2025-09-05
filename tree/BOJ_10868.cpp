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
#include <limits.h>

using namespace std;

// BOJ 10868 최솟값 (tree) (G1)

static vector<long> tree;
long getMin(int s, int e);
void setTree(int i);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	int treeHeight = 0; int length = N;

	// 트리 높이 구하기
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}

	// 트리 사이즈 설정
	int treeSize = pow(2, treeHeight + 1);
	// 시작 인덱스 설정
	// 만약 트리 사이즈가 16이라면, 인덱스 8-15 에 리프 노드를 저장
	int startIndex = treeSize / 2;

	tree.resize(treeSize + 1);
	fill(tree.begin(), tree.end(), LONG_MAX);

	for (int i = startIndex; i < startIndex + N; i++) {
		cin >> tree[i];
	}

	setTree(treeSize - 1);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << getMin(startIndex + a, startIndex + b)<<"\n";
	}
}

// 부모 노드는 두 자식 중 최소 노드
void setTree(int i) {
	while (i != 1) {
		tree[i / 2] = min(tree[i], tree[i / 2]);
		i--;
	}
}

// 구간 중 최소 구하기
long getMin(int s, int e) {
	long ans = LONG_MAX;

	while (s <= e) {
		if (s % 2 == 1) {
			ans = min(ans, tree[s]);
			s++;
		}
		if (e % 2 == 0) {
			ans = min(ans, tree[e]);
			e--;
		}
		s /= 2; e /= 2;
	}
	return ans;
}