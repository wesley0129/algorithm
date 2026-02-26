#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    vector<string> v;
    map<string, int> n;
    for(size_t i=0; i<N; i++){
        string name;
        cin>>name;
        n[name]++;
    }
    for(size_t i=0; i<M; i++){
        string name;
        cin>>name;
        n[name]++;
    }
    for(auto i: n){
        if(i.second == 2){
            v.push_back(i.first);
        }
    }
    cout<<v.size()<<"\n";
    for(auto i: v){
        cout<<i<<"\n";
    }
    return 0;
}
