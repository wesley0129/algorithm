#include <iostream>
using namespace std;

int main() {
    int N;
    int result = 0;
    cin>>N;
    for(int i=1; i<=N; i++){
        int sum=i;
        int tmp=i;
        while(tmp){
            sum += tmp%10;
            tmp /= 10;
        }
        if(sum == N){
            result = i;
            break;
        }
    }
    cout << result;

    return 0;
}

