#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int ucd(int f, int s){
    if(f%s == 0){
        return s;
    }
    return ucd(s, f%s);
}
int main(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int top = a*d + b*c;
    int bot = b*d;
    int gcd = ucd(top, bot);
    cout<<top/gcd<<" "<<bot/gcd<<endl;
    return 0;
}