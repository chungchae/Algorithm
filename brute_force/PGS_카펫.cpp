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

// PGS 카펫 (brute_force) (L2)

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 노랑 = ab, 갈색 = 2(a+b) + 4
    // 먼저 (a+b)를 구한다
    int num = (brown - 4) / 2;

    int i;
    for (i = 1; i < num; i++) {
        if (i * (num - i) == yellow)
            break;
    }

    answer.push_back(max(i, num - i) + 2);
    answer.push_back(min(i, num - i) + 2);

    return answer;
}