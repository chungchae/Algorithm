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

// BOJ_11003 (sliding_window)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //(index, value)
    typedef pair<int, int> Node;

    int N, L;
    cin >> N >> L;

    deque<Node> arr;

    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;
        //추가하는 노드의 value가 더 작으면, 앞의 노드를 제거
        while (arr.size() && arr.back().second > now) {
            arr.pop_back();
        }
        //현재 노드 추가
        arr.push_back(Node(i, now));
        //인덱스를 초과하면 front노드를 제거
        if (arr.front().first <= i - L) {
            arr.pop_front();
        }
        cout << arr.front().second << ' ';
    }
}