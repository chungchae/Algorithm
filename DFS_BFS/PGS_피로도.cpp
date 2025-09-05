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

// PGS 피로도 (DFS) (L2)

void DFS(vector<vector<int>> dungeons, vector<bool>& visited, int depth, int now, int& answer) {
    answer = max(answer, depth);
    // depth가 최대인 경우 종료
    if (depth == dungeons.size())
        return;
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= now) {
            visited[i] = true;
            DFS(dungeons, visited, depth + 1, now - dungeons[i][1], answer);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    vector<bool> visited(dungeons.size(), false);
    int depth = 0;

    DFS(dungeons, visited, 0, k, answer);
    return answer;
}