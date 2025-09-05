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

// PGS 최소 직사각형 (brute_force) (L1)

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int x_max = sizes[0][0];
    int y_max = sizes[0][1];

    for (int i = 0; i < sizes.size(); i++) {
        int a, b;
        // 그대로 넣는 경우
        a = abs(x_max - sizes[i][0]) + abs(y_max - sizes[i][1]);
        // 돌려서 넣는 경우
        b = abs(x_max - sizes[i][1]) + abs(y_max - sizes[i][0]);

        if (a < b) {
            x_max = max(x_max, sizes[i][0]);
            y_max = max(y_max, sizes[i][1]);
        }
        else {
            x_max = max(x_max, sizes[i][1]);
            y_max = max(y_max, sizes[i][0]);
        }

    }
    answer = x_max * y_max;
    return answer;
}