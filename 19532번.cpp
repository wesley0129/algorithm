#include <iostream>
using namespace std;

int main() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int x = (b*f-e*c)/(d*b-a*e);
    int y = (a*f-d*c)/(a*e-d*b);
    cout<<x<<" "<<y<<endl;
    return 0;
}