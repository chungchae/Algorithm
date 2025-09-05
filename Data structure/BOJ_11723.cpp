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

// BOJ 11723 집합 (Data structure) (S5)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	set<int> S;
	string of; int num;


	for (int i = 0; i < N; i++) {
		cin >> of;
		if (of != "all" && of!="empty") {
			cin >> num;
		}
		if (of == "add") {
			S.insert(num);
		}
		else if (of == "check") {
			if (S.end() == S.find(num)) cout << "0\n";
			else cout << "1\n";
		}
		else if (of == "remove") {
			S.erase(num);
		}
		else if (of == "toggle") {
			if (S.end() == S.find(num)) S.insert(num);
			else S.erase(num);
		}
		else if (of == "all") {
			for (int i = 1; i < 21; i++) {
				S.insert(i);
			}
		}
		else S.clear();
	}
}

