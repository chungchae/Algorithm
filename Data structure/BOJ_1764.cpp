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

// BOJ 1764 듣보잡 (Data structure) (S4)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	
	set<string> S;
	string temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		S.insert(temp);
	}
	vector<string> ans;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (S.find(temp) != S.end()) {
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (string s : ans)
		cout << s << "\n";
}

