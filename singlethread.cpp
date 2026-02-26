#include <iostream>

void thread1(){
    std::cout << "tread1 start\n";
    std::cout << "tread1 end\n";
}
void thread2(){
    std::cout << "tread2 start\n";
    std::cout << "tread2 end\n";
}
void thread3(){
    std::cout << "tread3 start\n";
    std::cout << "tread3 end\n";
}

int main(){
    std::cout << "===porcess start\n";
    thread1();
    thread2();
    thread3();
    std::cout << "===porcess end\n";
    return 0;
}