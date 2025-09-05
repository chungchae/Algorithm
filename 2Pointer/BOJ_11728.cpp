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

using namespace std;

// BOJ_11728 (2-pointer)
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<long long> arr1(N);
    vector<long long> arr2(M);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr1[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%lld", &arr2[i]);
    }

    int p1 = 0, p2 = 0;
    vector<long long> result;

    while (p1 < N && p2 < M) {
        if (arr1[p1] < arr2[p2]) {
            result.push_back(arr1[p1]);
            p1++;
        }
        else {
            result.push_back(arr2[p2]);
            p2++;
        }
    }

    while (p1 < N) {
        result.push_back(arr1[p1]);
        p1++;
    }
    while (p2 < M) {
        result.push_back(arr2[p2]);
        p2++;
    }

    for (size_t i = 0; i < result.size(); i++) {
        printf("%lld ", result[i]);
    }

    return 0;
}