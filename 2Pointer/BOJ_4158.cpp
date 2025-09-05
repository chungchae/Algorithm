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

// BOJ_1253 (2-pointer)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1){
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		vector<int> arr1(N, 0);
		vector<int> arr2(M, 0);
		int count = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> arr1[i];
		}
		for (int i = 0; i < M; i++)
		{
			cin >> arr2[i];
		}

		int index1 = 0, index2 = 0;

		while (index1 < N && index2 < M) {
			if (arr1[index1] == arr2[index2]) {
				count++;
				index1++;
				index2++;
			}
			else if (arr1[index1] < arr2[index2]) {
				index1++;
			}
			else {
				index2++;
			}
		}

		cout << count << '\n';
	}
}