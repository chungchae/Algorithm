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

// BOJ 16953 A->B (greedy) (S2)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B; cin >> A >> B;
    int count = 0;

    while (A < B) {
        if (B % 2 == 0) {
            B /= 2;
        }
        else {
            // 81 -> 8
            if (B % 10 == 1) {
                B /= 10;
            }
            else break;
        }
        count++;
    }
    if (A == B)
        cout << count + 1;
    else
        cout << -1;
}
