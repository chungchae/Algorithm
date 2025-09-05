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

// BOJ_1715 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	//min heap
	priority_queue<int, vector<int>, greater<int>> pq;
	int data;

	for (int i = 0; i < N; i++) {
		cin >> data;
		pq.push(data);
	}

	int data1 = 0; int data2 = 0; int sum = 0;
	while (pq.size()> 1) {
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();
		sum += data1 + data2;
		pq.push(data1 + data2);
	}
	cout << sum;

}