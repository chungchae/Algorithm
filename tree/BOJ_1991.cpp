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

// BOJ 1991 (tree) (S1)

static int node[26][2];

void preorder(int cur) {
	if (cur == -1) return;
	cout << (char)(cur + 'A');
	preorder(node[cur][0]);
	preorder(node[cur][1]);
}

void inorder(int cur) {
	if (cur == -1) return;
	inorder(node[cur][0]);
	cout << (char)(cur + 'A');
	inorder(node[cur][1]);
}

void postorder(int cur) {
	if (cur == -1) return;
	postorder(node[cur][0]);
	postorder(node[cur][1]);
	cout << (char)(cur + 'A');
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	char x, y, z;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		
		int now = x - 'A';

		// 왼쪽 자식 노드 저장
		if (y == '.') {
			node[now][0] = -1;
		}
		else
			node[now][0] = y - 'A';
		// 오른쪽 자식 노드 저장
		if (z == '.') {
			node[now][1] = -1;
		}
		else
			node[now][1] = z - 'A';
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);

	return 0;
}