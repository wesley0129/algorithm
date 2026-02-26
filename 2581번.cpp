#include <iostream>
using namespace std;
int main() {
    int n, m, first;
    int sum = 0;
    cin >> n >> m;
    for(size_t i=n; i <= m; i++){
        bool check = false;
        if(i<2){
            continue;
        }
        for(size_t j=2; j*j <= i; j++){ // 소수인지 판단 j*j를 이용해서 시간을 단축시킴.
            if(i%j == 0){
                check = true;
                break;
            }
        }
        if(!check){
            if(sum == 0){
                first = i;
            }
            sum += i;
        }
    }
    if(sum == 0){
        cout << -1 << "\n";
    }else{
        cout << sum << "\n" << first;
    }
    return 0;
}