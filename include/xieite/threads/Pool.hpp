#ifndef XIEITE_HEADER_THREADS_POOL
#	define XIEITE_HEADER_THREADS_POOL

#	include <condition_variable>
#	include <cstddef>
#	include <functional>
#	include <mutex>
#	include <queue>
#	include <thread>
#	include <utility>
#	include <vector>

namespace xieite::threads {
	class Pool {
	public:
		Pool(const std::size_t threadCount = std::thread::hardware_concurrency()) {
			this->setThreadCount(threadCount);
		}

		~Pool() {
			for (std::jthread& thread : this->threads) {
				thread.request_stop();
			}
			this->jobsCondition.notify_all();
		}

		void setThreadCount(std::size_t threadCount) {
			if (!threadCount) {
				throw std::invalid_argument("Cannot resize thread pool to zero");
			}
			if (threadCount < this->threads.size()) {
				this->threads.resize(threadCount);
			} else {
				while (threadCount--) {
					this->threads.emplace_back([this](const std::stop_token stopToken) -> void {
						while (true) {
							auto jobsLock = std::unique_lock<std::mutex>(this->jobsMutex);
							this->jobsCondition.wait(jobsLock, [this, stopToken] noexcept -> bool {
								return this->jobs.size() || stopToken.stop_requested();
							});
							if (!this->jobs.size() && stopToken.stop_requested()) {
								break;
							}
							std::function<void()> job = std::move(this->jobs.front());
							this->jobs.pop();
							jobsLock.unlock();
							job();
						}
					});
				}
			}
		}

		void enqueue(const std::function<void()>& job) noexcept {
			auto jobsLock = std::unique_lock<std::mutex>(this->jobsMutex);
			this->jobs.push(job);
			jobsLock.unlock();
			this->jobsCondition.notify_one();
		}

	private:
		std::vector<std::jthread> threads;
		std::queue<std::function<void()>> jobs;
		std::mutex jobsMutex;
		std::condition_variable jobsCondition;
	};
}

// Thanks to when for help

#endif
