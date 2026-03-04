#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long int ucd(long long int a, long long int b){
    if(a%b == 0){
        return b;
    }
    return ucd(b, a%b);
}

int main(){
    long long int A, B;
    cin>>A>>B;
    cout<<A*B/ucd(A, B)<<endl;
    return 0;
}