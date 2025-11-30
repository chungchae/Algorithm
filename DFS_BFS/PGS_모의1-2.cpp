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

// PGS PCCP 모의1-2 (dfs) (*)
vector<vector<int>> ans;
vector<bool> visited;

void dfs(vector<int> now, int target, int size) {
    if (now.size() == target) {
        ans.push_back(now);
        return;
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            now.push_back(i);
            visited[i] = true;
            dfs(now, target, size);
            visited[i] = false;
            now.pop_back();
        }
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;

    int n = ability.size();
    int m = ability[0].size();

    visited = vector<bool>(n, false);

    dfs({}, m, n);

    for (vector<int> v : ans) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += ability[v[i]][i];
        }
        answer = max(sum, answer);
    }

    return answer;
}