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

// PGS 입국심사 (binary_serach) (L3)

long long getnum(long long t, vector<int> times) {
    long long result = 0;

    for (int node : times) {
        result += t / node;
    }
    return result;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long left = 1;
    long long right = *max_element(times.begin(), times.end());

    right *= n;
    long long mid;

    // '='반드시넣기!!!!!!!!!!!!
    while (left <= right) {
        mid = (left + right) / 2;

        if (getnum(mid, times) >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return answer;
}