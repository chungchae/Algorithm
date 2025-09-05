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

// BOJ_2075

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//store in reverse order
	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N * N; i++) {
		cin >> temp;
		pq.push(temp);
		//Maintain a size of pq at N
		if (pq.size() > N)
			pq.pop();
	}
	
	cout << pq.top();
}