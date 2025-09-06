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

// BOJ 5430 AC (Implementation) (G5)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;

    for (int total = 0; total < T; total++) {
        // 함수 입력
        string func; cin >> func;

        // 배열 입력
        int size; cin >> size;
        string s_arr; cin >> s_arr;
        // 배열을 진짜 뒤집으면 시간초과, deque 자료구조 활용
        deque<int> arr;

        string temp;

        for (int i = 1; i < s_arr.length() - 1; i++) {
            if (s_arr[i] != ',') {
                temp += s_arr[i];
            }
            else {
                arr.push_back(stoi(temp));
                temp = "";
            }
        }
        if (temp != "") {
            arr.push_back(stoi(temp));
        }

        // 함수 수행, 결과 출력

        bool dir = true;
        bool pass = false;

        for (char c : func) {
            if (c == 'D') {
                if (arr.empty()) {
                    cout << "error\n";
                    pass = true;
                    break;
                }
                else {
                    // 정방향이면 front에서,
                    if (dir) {
                        arr.pop_front();
                    }
                    // 역방향이면 back에서 pop
                    else {
                        arr.pop_back();
                    }
                }
            }
            else {
                // R이 입력되면 방향 뒤집기
                dir = !dir;
            }
        }

        if (!arr.empty()) {
            if (dir) {
                cout << "[";

                for (int p = 0; p < arr.size() - 1; p++) {
                    cout << arr[p] << ",";
                }
                cout << arr[arr.size() - 1];

                cout << "]\n";
            }
            else {
                cout << "[";

                for (int p = arr.size() - 1; p > 0; p--) {
                    cout << arr[p] << ",";
                }
                cout << arr[0];

                cout << "]\n";
            }
        }
        else {
            if (!pass) {
                cout << "[]\n";
            }
        }
    }

    
}