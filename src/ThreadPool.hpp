#include "thread"
#include "condition_variable"
#include "future"
#include "functional"
#include "queue"


namespace SpStochLib {
    class ThreadPool {
        std::queue<std::function<void()>> m_tasks;
        std::vector<std::thread> m_threads;
        std::mutex m_mutex;
        std::condition_variable m_condition;
        bool stop = false;

    public:
        explicit ThreadPool(size_t threadAmount) {
            for (int i = 0; i < threadAmount; ++i) {
                m_threads.emplace_back([this] {
                    while (true) {
                        std::function<void()> task;

                        {
                            std::unique_lock lock(m_mutex);

                            m_condition.wait(lock, [this] {
                                return stop || !m_tasks.empty();
                            });

                            if (stop && m_tasks.empty()) {
                                return;
                            }

                            task = std::move(m_tasks.front());
                            m_tasks.pop();
                        }

                        task();
                    }
                });
            }
        }

        ThreadPool(const ThreadPool&) = delete;
        ThreadPool& operator=(const ThreadPool&) = delete;

        ~ThreadPool() {
            {
                std::scoped_lock lock(m_mutex);
                stop = true;  // Signal all threads to stop.
            }

            m_condition.notify_all();  // Wake up all threads.

            // Wait for all threads to finish.
            for (auto &thread: m_threads) {
                thread.join();
            }
        }

        void addTask(std::function<void()> task) {
            {
                std::scoped_lock lock(m_mutex);
                m_tasks.push(std::move(task));  // Add the task to the queue.
            }

            m_condition.notify_one();  // Wake up one thread to handle the new task.
        }
    };
}