#include <iostream>
#include <algorithm>
using namespace std;

struct Rect{
    int x1, y1, x2, y2;
};

int main(){
    int a, b, c, d, e, f, g, h;
    try{
        cin>>a>>b>>c>>d>>e>>f>>g>>h;
        if(a>100000 || a<0 || b>100000 || b<0 || c>100000 || c<0 || d>100000 || d<0 || e>100000 || e<0 || f>100000 || f<0 || g>100000 || g<0 || h>100000 || h<0){
            throw exception();
        }
    }catch(exception& e){
        cout<<"숫자가 입력 범위를 벗어났습니다."<<endl;
        return 1;
    }
    Rect rect1 = {a, b, c, d};
    Rect rect2 = {e, f, g, h};
    
    int x = min(rect1.x2, rect2.x2) - max(rect1.x1, rect2.x1);
    int y = min(rect1.y2, rect2.y2) - max(rect1.y1, rect2.y1);

    if(x>0 && y>0){
        cout<<1<<"\n";
    }
    else{
        cout<<0<<"\n";
    }

    return 0;
}