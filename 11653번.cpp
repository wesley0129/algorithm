#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n < 2){
        return 0;
    }
    for(size_t it=2; it<= n ; it++){
        if(n%it == 0){
            cout << it << "\n";
            n /= it;
            it--;
        }
    }

    return 0;
}