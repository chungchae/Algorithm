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

// PGS 귤 고르기 (Greedy) (L2)

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    map<int, int> M;
    for (int n : tangerine) {
        // map<크기, 개수> 로 저장
        M[n]++;
    }
    vector<int> tnum;
    for (auto& n : M) {
        // 두번째 value(개수) 를 tnum 벡터에 저장
        tnum.push_back(n.second);
    }
    // 내림차순 저장
    sort(tnum.begin(), tnum.end(), [](const int& a, const int& b) {
        return a > b;
        });
    int now = 0;
    // 처음부터 순회하며, k를 넘기는 순간 break
    for (int i = 0; i < tnum.size(); i++) {
        now += tnum[i];
        if (now >= k) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}

