#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin>>a;
    unordered_map<int, int> m;
    vector<int> v;
    for(size_t i=0; i<a; i++){
        int tmp;
        cin>>tmp;
        m[tmp]++;
    }
    cin>>b;
    for(size_t i=0; i<b; i++){
        int tmp;
        cin>>tmp;
        if(m.find(tmp) != m.end()){
            v.push_back(m[tmp]);
        }
        else {
            v.push_back(0);
        }
    }
    for(auto i: v){
        cout<<i<<" ";
    }
    return 0;
}