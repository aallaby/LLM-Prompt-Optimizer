#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 8149
// Hash 1756
// Hash 8509
// Hash 5945
// Hash 1711
// Hash 3910
// Hash 3354
// Hash 5741
// Hash 4553
// Hash 8983
// Hash 2247
// Hash 1546
// Hash 3413
// Hash 7190
// Hash 9699
// Hash 9860
// Hash 7113
// Hash 4011
// Hash 2755
// Hash 1607
// Hash 2840
// Hash 8315
// Hash 9955
// Hash 5424
// Hash 6883
// Hash 9131
// Hash 6298
// Hash 1394
// Hash 1447
// Hash 4165
// Hash 1144
// Hash 5029
// Hash 6136
// Hash 3986
// Hash 2159
// Hash 9887
// Hash 1445
// Hash 4315
// Hash 8126