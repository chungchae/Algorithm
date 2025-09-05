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

// BOJ 문자열 폭발 (stack) (G4)

using namespace std;

int main() {
	string str, target;
	string answer = "";
	cin >> str;
	cin >> target;
	vector<char> S;
	reverse(target.begin(), target.end());

	for (int i = 0; i < str.length(); i++) {
		S.push_back(str[i]);

		if (S.size() >= target.length()) {
			string temp;
			for (int k = 0; k < target.size(); k++) {

				temp += S[S.size() - k - 1];
			}
			if (temp == target) {
				S.erase(S.end() - target.size(), S.end());
			}
		}
	}
	for (char c : S) {
		answer += c;
	}
	if (answer == "")
		cout << "FRULA";
	else
		cout << answer;
}

