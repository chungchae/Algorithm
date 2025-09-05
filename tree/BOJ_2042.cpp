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

// BOJ 2042 구간 합 구하기 (tree) (G1)

static vector<long> tree;
long getSum(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K; cin >> N >> M >> K;
	int treeHeight = 0; int length = N;

	// 트리 높이 구하기
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}

	// 트리 사이즈 구하기
	int treeSize = pow(2, treeHeight + 1);
	tree.resize(treeSize + 1);

	int startIndex = treeSize / 2 - 1;

	for (int i = startIndex + 1; i <= startIndex + N; i++) {
		cin >> tree[i];
	}
	setTree(treeSize - 1);

	for (int i = 0; i < M + K; i++) {
		long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			changeVal(startIndex + b, c);
		}
		else {
			cout << getSum(startIndex + b, startIndex + c) << "\n";
		}
	}
}

// 트리 초기화 함수
void setTree(int i) {
	while (i != 1) {
		tree[i / 2] += tree[i];
		i--;
	}
}

// 구간 합 함수
long getSum(int s, int e) {
	long ans = 0;

	while (s <= e) {
		// 왼쪽 노드가 홀수 인덱스면 포함
		if (s % 2 == 1) {
			ans += tree[s];
			s++;
		}
		// 오른쪽 노드가 짝수 인덱스면 포함
		if (e % 2 == 0) {
			ans += tree[e];
			e--;
		}
		s /= 2; e /= 2;
	}
	return ans;
}

// 값 변경 함수
void changeVal(int index, long val) {
	long diff = val - tree[index];

	// 해당 노드의 부모 노드 전부 변경
	while (index > 0) {
		tree[index] += diff;
		index /= 2;
	}
}