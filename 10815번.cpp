#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    unordered_map<int, int> cMap;
    vector<int> result;
    for(size_t i=0; i<N; i++){
        int num;
        cin >> num;
        cMap[num];
    }
    cin >> M;
    for(size_t i=0; i<M; i++){
        int num;
        cin >> num;
        if(cMap.find(num) != cMap.end()){
            result.push_back(1);
        }
        else{
            result.push_back(0);
        }
    }
    for(auto a: result){
        cout << a << ' ';
    }
    return 0;
}