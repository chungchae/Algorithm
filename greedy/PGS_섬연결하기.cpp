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

// PGS 섬 연결하기 (greedy) (L3)
// MST-크루스칼

vector<int> parent, sz;

int findp(int x) {
    return parent[x] == x ? x : parent[x] = findp(parent[x]);
}

bool unite(int a, int b) {
    a = findp(a);
    b = findp(b);

    if (a == b)return false;

    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;

}

//사이클 여부(부모) 확인 함수

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int picked = 0;

    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n, 1);

    //간선 가중치 오름차순 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
        });

    //사이클을 형성하지 않으면서, 차례로 선택
    for (auto& e : costs) {
        int u = e[0], v = e[1], w = e[2];
        if (unite(u, v)) {
            answer += w;
            if (++picked == n - 1)break;
        }
    }

    return answer;
}