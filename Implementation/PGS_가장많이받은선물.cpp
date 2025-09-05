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

// PGS 가장 많이 받은 선물 (Implementation) (L1)

int solution(vector<string> friends, vector<string> gifts) {
	int N = friends.size();

	map<string, int> M;

	for (int i = 0; i < N; i++) {
		M.insert({ friends[i], i });
	}

	vector<vector<int>> arr(N, vector<int>(N, 0));

	for (int i = 0; i < gifts.size(); i++) {
		stringstream ss(gifts[i]);
		string temp;
		vector<string> name;

		while (getline(ss, temp, ' ')) {
			name.push_back(temp);
		}

		arr[M[name[0]]][M[name[1]]]++;
	}

	vector<int> point(N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			point[i] += arr[i][j];
			point[j] -= arr[i][j];
		}
	}

	// 최대 선물 계산
	vector<int> receive(N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (arr[i][j] > arr[j][i]) {
				receive[i]++;
			}
			else if (arr[i][j] == arr[j][i]) {
				if (point[i] > point[j]) {
					receive[i]++;
				}
			}
		}
	}

	int max_gift = *max_element(receive.begin(), receive.end());
	return max_gift;
}


