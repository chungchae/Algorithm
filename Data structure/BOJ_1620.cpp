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

using namespace std;

// BOJ_1620 (data structure)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> dogam(N + 1);
    unordered_map<string, int> nameToIndex;
    string temp;

    for (int i = 1; i <= N; i++) {
        cin >> dogam[i];
        nameToIndex[dogam[i]] = i;

    }

    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (isdigit(temp[0])) {
            cout << dogam[stoi(temp)] << "\n";
        }
        else {
            cout << nameToIndex[temp] << "\n";
        }
    }
}