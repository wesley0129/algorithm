#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

bool check(int a){
    int p = sqrt(a);
    for(size_t i=2; i<=p; i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<int> prime;    
    for(size_t i=m; i<=n; i++){
        if(i==1){
            continue;
        }
        if(check(i)){
            prime.push_back(i);
        }
    }
    for(auto a: prime){
        cout<<a<<"\n";
    }

    return 0;
}