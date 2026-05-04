#include <vector>
using namespace std;

// 최대공약수
int gcd(int a, int b) {
    while (b != 0) { 
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 최소공배수
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// 특정 시간 t에 해당 신호등이 노란불인지 확인
bool isYellow(vector<int>& signal, long long t) {
    int G = signal[0];
    int Y = signal[1];
    int R = signal[2];

    int cycle = G + Y + R;

    // 시간은 1초부터 시작
    int pos = (t - 1) % cycle;

    return (pos >= G && pos < G + Y);
}

int solution(vector<vector<int>> signals) {
    long long totalCycle = 1;

    // 전체 반복 주기 계산
    for (auto& signal : signals) {
        int cycle = signal[0] + signal[1] + signal[2];
        totalCycle = lcm(totalCycle, cycle);
    }

    // 1초부터 전체 주기까지만 탐색
    for (long long t = 1; t <= totalCycle; t++) {
        bool allYellow = true;

        for (auto& signal : signals) {
            if (!isYellow(signal, t)) {
                allYellow = false;
                break;
            }
        }

        if (allYellow) {
            return (int)t;
        }
    }

    return -1;
}