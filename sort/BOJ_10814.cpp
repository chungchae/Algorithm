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

// BOJ 10814 나이순 정렬 (sort) (S5)

struct T {
	int age;
	string name;
	int index;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<T> arr;

	int a;
	string b;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back({ a,b,i });
	}

	sort(arr.begin(), arr.end(), [](const T &a, const T &b) {
		if (a.age == b.age) {
			return a.index < b.index;
		}
	return a.age < b.age;
		});

	for (auto a : arr) {
		cout << a.age << " " << a.name << "\n";
	}
}


