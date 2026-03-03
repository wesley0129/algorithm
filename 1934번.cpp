#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int ucd(int a, int b){
    if(a%b == 0){
        return b;
    }
    return ucd(b, a%b);
}

int main(){
    int t;
    vector<pair<int,int>> v;
    cin>>t;
    for(size_t i=0; i<t; i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(auto a : v){
        int b = a.first * a.second / ucd(a.first, a.second);
        cout<<b<<"\n";
    }
    return 0;
}
