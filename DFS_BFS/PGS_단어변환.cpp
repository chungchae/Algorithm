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

// PGS 단어 변환 (BFS) (L3)

//변환 가능 여부 체크 함수
bool check(string str1, string str2) {
    int count = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i])count++;
    }
    if (count == 1)return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();

    vector<vector<int>> num(n);

    //변환 가능하면, num에 2차원 배열 형태로 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)continue;
            if (check(words[i], words[j])) {
                num[i].push_back(j);
            }
        }
    }

    queue<pair<int, int>> q;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (check(begin, words[i])) {
            q.push({ i, 1 });
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int now = q.front().first;
        int now_time = q.front().second;

        q.pop();

        for (int node : num[now]) {
            if (!visited[node]) {
                visited[node] = true;
                q.push({ node, now_time + 1 });
            }
        }

        if (words[now] == target)return now_time;
    }

    return 0;
}