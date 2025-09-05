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

// PGS 소수 찾기 (DFS) (L2)

// 소수 판별 함수
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

set<int> generated;

// DFS
void dfs(string numbers, string cur, vector<bool>& visited) {
    if (!cur.empty()) {
        generated.insert(stoi(cur));
    }
    for (int i = 0; i < numbers.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(numbers, cur + numbers[i], visited);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> visited(numbers.length(), false);

    dfs(numbers, "", visited);

    for (int num : generated) {
        if (isPrime(num)) answer++;
    }


    return answer;
}