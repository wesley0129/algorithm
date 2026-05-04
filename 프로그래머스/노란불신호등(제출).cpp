#include <vector>
#include <iostream>
using namespace std;

struct Signal {
    int green, yellow, red;
    int cycle;
};

int ucd(int a, int b){
    while(b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
};

int Lcm(int a, int b){
    return a/ucd(a,b)*b;
};

bool isYellow(Signal signal, long long time){
    int cycle = signal.cycle;
    long long remain_time = time%cycle;
    return {(signal.green < remain_time) && (remain_time < (signal.green + signal.yellow))};
};

/// ex: [[2, 3, 2], [3, 1, 3], [2, 1, 1]]
int solution(vector<vector<int>> signals) {
    int answer = 0;

    //배열에 삽입
    vector<Signal> arr;
    for(auto i: signals) {
        Signal tmp = {i[0], i[1], i[2], i[0]+i[1]+i[2]};
        arr.push_back(tmp);
    }
    
    //신호등 주기들의 최소공배수 구하기(한 사이클 구하기)
    int lcm = 1;
    for(auto i: arr){
        lcm = Lcm(lcm, i.cycle);
    }

    //노란불이 겹치는 부분 구하기
    long long time=1;
    for(int i=0; i<lcm; i++){
        bool correct = true;
        for(auto sig: arr){
            if(!isYellow(sig, time)){
                correct=false;
                break;
            }    
        }
        if(correct){
            return time;
        }
        time++;
    }
    answer = -1;

    return answer;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
};