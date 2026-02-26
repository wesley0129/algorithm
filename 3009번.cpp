#include <iostream>

using namespace std;

int main(){
    int check[2] = {-2, -2};
    int tx, ty;
    for(size_t i = 0; i < 3; i++){
        int x, y;
        cin >> x >> y;
        if(i == 0){
            check[0] = x;
            check[1] = y;
            continue;
        }
        if(x == check[0]){
            check[0] = -1;
            if(i==2) check[0] = tx;
        }else if(check[0] == -1){
            check[0] = x;
        }else{
            tx = x;
        }
        if(y == check[1]){
            check[1] = -1;
            if(i==2) check[1] = ty;
        }else if(check[1] == -1){
            check[1] = y;
        }else{
            ty = y;
        }    
    }
    cout << check[0] << " " << check[1] <<"\n";
    return 0;

}

//스택을 사용해서 처리한 코드드
// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
//     stack<int> sx, sy;
//     for (int i = 0; i < 3; i++) {
//         int x, y;
//         cin >> x >> y;

//         // x 좌표 처리
//         if (!sx.empty() && sx.top() == x) {
//             sx.pop();
//         } else {
//             sx.push(x);
//         }

//         // y 좌표 처리
//         if (!sy.empty() && sy.top() == y) {
//             sy.pop();
//         } else {
//             sy.push(y);
//         }
//     }

//     // 남아있는 값이 정답
//     cout << sx.top() << " " << sy.top() << "\n";
//     return 0;
// }