#ifndef INC_5_THREADSAFEQUEUE_H
#define INC_5_THREADSAFEQUEUE_H

#include <queue>
#include <mutex>
#include <optional>

template<typename T>
class ThreadSafeQueue {
    std::queue<T> queue_;
    mutable std::mutex mutex_;

private:
    bool empty() const {
        return queue_.empty();
    }

public:
    ThreadSafeQueue() = default;

    virtual ~ThreadSafeQueue() { }

    unsigned long size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }

    std::optional<T> pop() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            return {};
        }
        T tmp = queue_.front();
        queue_.pop();
        return tmp;
    }

    void push(const T &item) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
    }
};

#endif //INC_5_THREADSAFEQUEUE_H
