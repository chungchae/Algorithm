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

// BOJ_1940 (2-pointer)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int i, j; int count = 0;

	for (int k = 0; k < N; k++) {
		i = 0; j = N - 1;
		while (i < j) {
			if (arr[i] + arr[j] == arr[k]) {
				if (i == k)
					i++;
				else if (j == k)
					j--;
				else {
					count++;
					break;
				}
			}
			else if (arr[i] + arr[j] < arr[k]) {
				i++;
			}
			else
				j--;
		}
	}

	cout << count;
}