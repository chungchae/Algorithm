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

// BOJ 14425 (tree) (S3)
// set 을 사용해 저장, find로 있는지 찾기

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	set<string> A;

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.insert(temp);
	}

	int count = 0;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		// find 함수는 없으면 end 위치를 반환함
		if (A.find(temp) != A.end())
			count++;
	}

	cout << count;
}