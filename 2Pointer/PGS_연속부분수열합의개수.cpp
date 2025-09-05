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

// PGS 연속 부분 수열 합의 개수 (2Pointer) (L2)

int solution(vector<int> elements) {
    int answer = 0;

    // 원형 수열 저장할 배열
    vector<int> arr(elements);

    // 합 저장할 set (중복 방지)
    set<int> S;

    arr.insert(arr.end(), elements.begin(), elements.end());

    // 1개부터 N-1 개까지
    for (int i = 1; i <= elements.size(); i++) {
        int start = 0; int end = i;
        int sum = 0;

        for (int j = start; j < end; j++) {
            sum += arr[j];
        }
        S.insert(sum);
        while (end < arr.size()) {
            // 이중 포인터
            start++; end++;
            sum -= arr[start]; sum += arr[end - 1];
            S.insert(sum);
        }
    }

    int sum = 0;
    // 범위가 N인 경우
    for (int i = 0; i < elements.size(); i++) {
        sum += elements[i];
    }
    S.insert(sum);

    return S.size();
}