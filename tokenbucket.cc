#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class TokenBucket {
public:
    TokenBucket(int capacity, int tokensPerSecond) : capacity_(capacity), tokensPerSecond_(tokensPerSecond), tokens_(capacity) {}

    bool consume() {
        unique_lock<mutex> lock(mutex_);
        if (tokens_ == 0) {
            return false;
        }
        tokens_--;
        return true;
    }

    void refill() {
        unique_lock<mutex> lock(mutex_);
        tokens_ = min(capacity_, tokens_ + tokensPerSecond_);
    }

private:
    const int capacity_;
    const int tokensPerSecond_;
    int tokens_;
    mutex mutex_;
};

int main() {
    TokenBucket tokenBucket(10, 2);

    // consume 10 tokens as fast as possible
    for (int i = 0; i < 10; i++) {
        while (!tokenBucket.consume()) {
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout << "Consumed token " << i + 1 << std::endl;
    }

    // wait for 5 seconds to refill the bucket
    this_thread::sleep_for(chrono::seconds(5));
    tokenBucket.refill();

    // consume 10 tokens at a rate of 1 token per second
    for (int i = 0; i < 30; i++) {
        while (!tokenBucket.consume()) {
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        cout << "Consumed token " << i + 1 << std::endl;
    }

    return 0;
}
