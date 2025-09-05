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

// BOJ 11286 절댓값 힙 (Data structure) (S1)

using namespace std;

struct Compare {
    // 함수 이름이 () 인 것!!
    // 객체를 함수처럼 호출할 수 있게 해주는 장치! 
    // priority queue는 인수로 비교 객체를 요구하기에 이렇게 사용
    bool operator()(const int a, const int b) {
        if (abs(a) == abs(b))  // 절댓값이 같다면
            return a > b;      // 값이 작은 게 우선
        return abs(a) > abs(b);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 우선순위 큐 선언
    priority_queue<int, vector<int>, Compare> pq;

    int N; cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == 0) {
            if (pq.empty())
                cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(temp);
        }
    }
}

