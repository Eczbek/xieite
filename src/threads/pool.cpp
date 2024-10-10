export module xieite:threads.Pool;

import std;

export namespace xieite::threads {
	struct Pool {
	public:
		Pool(const std::size_t threadCount = std::thread::hardware_concurrency()) noexcept {
			this->setThreadCount(threadCount);
		}

		~Pool() {
			auto threadsLock = std::unique_lock<std::mutex>(this->mutex);
			for (std::jthread& thread : this->threads) {
				thread.request_stop();
			}
			threadsLock.unlock();
			this->condition.notify_all();
		}

		void setThreadCount(std::size_t threadCount) noexcept {
			const auto _ = std::unique_lock<std::mutex>(this->mutex);
			const std::size_t currentThreadCount = this->threads.size();
			if (threadCount < currentThreadCount) {
				this->threads.resize(threadCount);
				return;
			}
			while (threadCount-- > currentThreadCount) {
				this->threads.emplace_back([this](const std::stop_token stopToken) {
					while (true) {
						auto tasksLock = std::unique_lock<std::mutex>(this->mutex);
						this->condition.wait(
							tasksLock,
							[this, stopToken] {
								return this->tasks.size() || stopToken.stop_requested();
							}
						);
						if (!this->tasks.size() && stopToken.stop_requested()) {
							break;
						}
						std::packaged_task<void()> task = std::move(this->tasks.front());
						this->tasks.pop();
						tasksLock.unlock();
						task();
					}
				});
			}
		}

		[[nodiscard]] std::size_t getThreadCount() const noexcept {
			const auto _ = std::unique_lock<std::mutex>(this->mutex);
			return this->threads.size();
		}

		template<std::invocable<> Functor>
		/* discardable */ std::future<void> enqueue(Functor&& functor) noexcept {
			auto task = std::packaged_task<void()>(functor);
			std::future<void> future = task.get_future();
			auto tasksLock = std::unique_lock<std::mutex>(this->mutex);
			this->tasks.emplace(std::move(task));
			tasksLock.unlock();
			this->condition.notify_one();
			return future;
		}

	private:
		// Destruction order is important!!!
		std::queue<std::packaged_task<void()>> tasks;
		std::vector<std::jthread> threads;
		mutable std::mutex mutex;
		std::condition_variable condition;
	};
}

// Thanks to Evan for help
