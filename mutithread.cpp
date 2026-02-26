#include <iostream>
#include <pthread.h>

void thread_func1() {
    std::cout << "thread1 start\n";
    // 스레드가 시작된 후 수행할 작업
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "thread1 end\n";
}

void thread_func2() {
    std::cout << "thread2 start\n";
    // 스레드가 시작된 후 수행할 작업
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "thread2 end\n";
}

void thread_func3() {
    std::cout << "thread3 start\n";
    // 스레드가 시작된 후 수행할 작업
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "thread3 end\n";
}

int main() {
    std::cout << "===process start\n";

    std::thread thread_1(thread_func1);
    std::thread thread_2(thread_func2);
    std::thread thread_3(thread_func3);

    thread_1.join();
    thread_2.join();
    thread_3.join();
    // 각 함수를 스레드로 실행
    // 코드를 완성하시오

    std::cout << "===process end\n";

    return 0;
}
