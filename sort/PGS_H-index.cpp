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

// PGS H-index (sort) (L2)

int solution(vector<int> citations) {
    int answer = 0;

    // 1. 일단 정렬
    sort(citations.begin(), citations.end(), [](const int& a, const int& b) {
        return a > b;
        });
    // 2. i번째 값이 i+1 보다 작은 최초의 i가 H-index
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] < i + 1)
            return i;
    }
}