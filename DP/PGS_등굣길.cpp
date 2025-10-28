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
#include <limits.h>

using namespace std;

// PGS 등굣길 (DP) (L3)

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    for (vector<int> v : puddles) {
        arr[v[1]][v[0]] = -1;
    }
    arr[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (arr[i][j] == -1) continue;

            int left = 0;
            if (i > 0 && arr[i - 1][j] != -1)left += arr[i - 1][j];

            int up = 0;
            if (j > 0 && arr[i][j - 1] != -1)up += arr[i][j - 1];

            arr[i][j] = (left + up) % 1000000007;
        }
    }
    answer = arr[n][m];
    return answer;
}