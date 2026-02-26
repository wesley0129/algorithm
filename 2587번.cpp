#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int>& arr){
    for(size_t i=0; i<arr.size()-1; i++){
        for(size_t j=0; j<arr.size()-i-1; j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return arr;
}
int main() {
    vector<int> arr;
    int sum=0;
    for (size_t i=0;i<5;i++){
        int num;
        cin>>num;
        arr.push_back(num);
        sum+=num;
    }
    arr = bubbleSort(arr);
    cout<<sum/5<<'\n'<<arr[2];
}