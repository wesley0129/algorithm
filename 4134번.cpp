#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

bool check(long long int a){
    long long int p = sqrt(a);
    for(size_t i=2; i<=p; i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int cnt;
    cin >> cnt;
    vector<long long int> num;
    for(size_t i=0; i<cnt; i++){
        long long int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    vector<long long int> prime;
    for(auto a : num){
        if(a == 1 or a == 0){
            prime.push_back(2);
            continue;
        }

        if(check(a)){
            prime.push_back(a);
        }
        else{
            int i=0;
            while(a){
                if(check(a+i)){
                    prime.push_back(a+i);
                    i=0;
                    break;
                }
                i++;
            }
        }
    }
    for(auto a : prime){
        cout<<a<<"\n";
    }
}
