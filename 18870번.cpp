#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedVec(vector<int> arr){
    sort(arr.begin(), arr.end());
    return arr;
};

int main(){
    int N;
    cin >> N;
    vector<int> numArr(N);
    for(size_t i=0; i<N; i++){
        int num;
        cin >> num;
        numArr[i] = num;
    }
    vector<int> checkArr = sortedVec(numArr);
    checkArr.erase(unique(checkArr.begin(), checkArr.end()), checkArr.end());
    for(auto num: numArr){
        cout << lower_bound(checkArr.begin(), checkArr.end(), num) - checkArr.begin() << " ";
    }
}
// unordered_map<int, int> numMap;
// for(int i=0;i<tmpArr.size();i++) numMap[tmpArr[i]] = i;
// for(auto num: numArr){
//     cout <<numMap[num]<<" ";
// }