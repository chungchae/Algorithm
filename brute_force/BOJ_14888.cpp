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

// BOJ 14888 연산자 끼워넣기 (brute_force) (S1)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N, 0);

    // 숫자 배열 입력받기
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; 
    }
    int temp; vector<int> op;
    for (int i = 1; i <= 4; i++) {
        // 연산자별로 op 벡터에 push_back
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            op.push_back(i);
        }
    }
    int now; int k;
    int max = -1e9; int min = 1e9;
    do {
        // 순열 함수로, 모든 경우의 수 시도
        now = arr[0]; k = 1;
        for (int i = 0; i < op.size(); i++) {
            switch (op[i]) {
            case 1: 
                now += arr[k];
                break;
            case 2:
                now -= arr[k];
                break;
            case 3:
                now *= arr[k];
                break;
            case 4:
                now /= arr[k];
                break;
            }
            k++;
        }
        // 최대, 최소 갱신
        if (now < min) {
            min = now;
        }
        if (now > max) {
            max = now;
        }
    } while (next_permutation(op.begin(), op.end()));

    cout << max << "\n";
    cout << min << "\n";
    
}

