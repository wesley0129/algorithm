#include <iostream>
#include <vector>
using namespace std;

//bubble sort
vector<int> bubbleSort(vector<int>& arr) {
    for(size_t i=0; i<arr.size()-1; i++) {
        for(size_t j=0; j<arr.size()-i-1; j++) {
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return arr;
}
int main(){
    int N;
    vector<int> arr1;
    cin>>N;
    for(size_t i=0; i<N; i++){
        int num;
        cin>>num;
        arr1.push_back(num);
    }
    arr1 = bubbleSort(arr1);
    for(auto num : arr1){
        cout<<num<<'\n';
    }
}