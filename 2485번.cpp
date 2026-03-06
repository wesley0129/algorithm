#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    vector<int> interval;
    for(int i=1;i<n;i++){
        interval.push_back(v[i]-v[i-1]);
    }

    int g = interval[0];
    for(int i=1;i<interval.size();i++){
        g = gcd(g, interval[i]);
    }

    int ans = 0;
    for(auto val : interval){
        ans += val/g - 1;
    }

    cout << ans;
}