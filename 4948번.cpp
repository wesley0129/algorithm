// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <unordered_set>
// #include <cmath>
// using namespace std;

// bool check(int a){
//     int p = sqrt(a);
//     for(int i=2; i<=p; i++){
//         if(a%i == 0){
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     int n;
//     vector<int> prime;
//     unordered_map<int, int> m;
//     while(cin>>n){
//         int cnt = 0;
//         if(n==0){
//             break;
//         }
//         if(m.find(n) != m.end()){
//             prime.push_back(m[n]);
//             continue;
//         }
//         for(int i=n+1; i<=2*n; i++){
//             if(i==1){
//                 continue;
//             }
//             if(check(i)){
//                 cnt++;
//             }
//         }
//         m[n] = cnt;
//         prime.push_back(cnt);
//     }
//     for(auto a: prime){
//         cout<<a<<"\n";
//     }
//     return 0;
// }

// 에라토스테네스의 체를 이용한 풀이
#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int MAX = 246912;
    vector<bool> prime(MAX+1, true);
    prime[0] = prime[1] = false;

    for(int i=2; i*i<=MAX; i++){
        if(prime[i]){
            for(int j=i*i; j<=MAX; j+=i){
                prime[j] = false;
            }
        }
    }

    while(true){
        int n;
        cin >> n;
        if(n==0) break;

        int cnt = 0;
        for(int i=n+1; i<=2*n; i++){
            if(prime[i]) cnt++;
        }

        cout << cnt << "\n";
    }
}

