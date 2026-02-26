#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int result = 0;
    cin >> N >> M;
    unordered_map<string, int> cMap;
    for(size_t i=0; i<N; i++){
        string str;
        cin >> str;
        cMap[str];
    }
    for(size_t i=0; i<M; i++){
        string str;
        cin >> str;
        if(cMap.find(str) != cMap.end()){
            result++;
        }
    }
    cout << result;
    return 0;
}