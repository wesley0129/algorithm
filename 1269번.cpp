#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int a, b;
    unordered_map<int, int> A;
    unordered_map<int, int> B;
    cin>>N>>M;
    for(size_t i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        A[tmp]++;
    }
    for(size_t i=0; i<M; i++){
        int tmp;
        cin>>tmp;
        B[tmp]++;
    }
    a = A.size();
    b = B.size();
    for(auto i: A){
        if(B.find(i.first) != B.end()){
            b--;
        }
    }
    for(auto i: B){
        if(A.find(i.first) != A.end()){
            a--;
        }
    }
    cout<<a+b<<"\n";
    return 0;
}
