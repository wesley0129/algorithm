#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool order(pair<string, int> a, pair<string, int> b){
    return a.first > b.first;
}
int main(){
    int N;
    cin >> N;
    map<string, int, greater<string>> cMap;
    for(size_t i=0; i<N; i++){
        string name, str;
        cin >> name >> str;
        if(str == "enter"){
            cMap[name]++;
        } else {
            cMap[name]--;
        }
    }
    for(auto iter : cMap){
        if(iter.second == 1){
            cout << iter.first << "\n";
        }
    }
    return 0;
}