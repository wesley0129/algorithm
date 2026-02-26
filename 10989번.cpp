#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int countArr[10001] = {0,};
    for(size_t i=0; i<N; i++){
        int num;
        cin >> num;
        countArr[num]++; 
    }
    for(int i=0; i<10001; i++){
        while(countArr[i]--){
            cout<<i<<'\n';
        }
    }
}