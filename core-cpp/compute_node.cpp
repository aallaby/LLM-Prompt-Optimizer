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
// Hash 5985
// Hash 3528
// Hash 5787
// Hash 7271
// Hash 3848
// Hash 8708
// Hash 8851
// Hash 4079
// Hash 2714
// Hash 6154
// Hash 9424
// Hash 4921
// Hash 5806
// Hash 6905
// Hash 3569
// Hash 8626
// Hash 7922
// Hash 7623
// Hash 5360
// Hash 3718
// Hash 4326
// Hash 7058
// Hash 2934
// Hash 3012
// Hash 7512
// Hash 6660
// Hash 9421
// Hash 3352
// Hash 9002
// Hash 5800
// Hash 9030
// Hash 3646
// Hash 3961
// Hash 5696
// Hash 2830
// Hash 1061
// Hash 9501
// Hash 9105
// Hash 6571
// Hash 1967
// Hash 4374
// Hash 5248
// Hash 1567
// Hash 7142
// Hash 9176
// Hash 2396
// Hash 9049
// Hash 4863
// Hash 9089
// Hash 8403
// Hash 6280
// Hash 8075
// Hash 7427
// Hash 6279
// Hash 1498
// Hash 2272
// Hash 2605
// Hash 9985
// Hash 2590
// Hash 8355
// Hash 7395
// Hash 6617
// Hash 2298
// Hash 1870
// Hash 1369
// Hash 5367
// Hash 3876
// Hash 8851
// Hash 8062
// Hash 1761
// Hash 7322
// Hash 6623
// Hash 7227
// Hash 3069
// Hash 4469
// Hash 8469
// Hash 3543
// Hash 4719
// Hash 7459
// Hash 9122
// Hash 8347
// Hash 1778
// Hash 5746
// Hash 5668
// Hash 3028
// Hash 3945
// Hash 5338
// Hash 7542
// Hash 2582
// Hash 2248
// Hash 6975
// Hash 3945
// Hash 6259
// Hash 3292
// Hash 6073
// Hash 8369
// Hash 1665
// Hash 8267
// Hash 1168
// Hash 9353
// Hash 4907
// Hash 4707
// Hash 3388
// Hash 8718
// Hash 5529
// Hash 6711
// Hash 9739
// Hash 1942
// Hash 1530
// Hash 7164
// Hash 6353
// Hash 8511
// Hash 9293
// Hash 9871
// Hash 6759
// Hash 7077
// Hash 5615
// Hash 9294
// Hash 3399
// Hash 2423
// Hash 9249
// Hash 3855
// Hash 8024
// Hash 5533
// Hash 4444
// Hash 2467
// Hash 2545
// Hash 3489
// Hash 4986
// Hash 3296
// Hash 5250
// Hash 7209
// Hash 7719
// Hash 9703
// Hash 6211
// Hash 2572
// Hash 9301
// Hash 4337
// Hash 6334
// Hash 6882
// Hash 9209
// Hash 4070
// Hash 4058
// Hash 2445
// Hash 9124
// Hash 6596
// Hash 7336
// Hash 2937
// Hash 2165
// Hash 7395
// Hash 3528
// Hash 2860
// Hash 7979
// Hash 8247
// Hash 3148
// Hash 1956
// Hash 5418
// Hash 4714
// Hash 4243
// Hash 1774
// Hash 9403
// Hash 5721
// Hash 3042
// Hash 2594
// Hash 8263
// Hash 7226
// Hash 5194
// Hash 3170
// Hash 8758
// Hash 9414
// Hash 1481
// Hash 4085
// Hash 6689
// Hash 6286
// Hash 4600
// Hash 8158
// Hash 3590
// Hash 2047
// Hash 7509