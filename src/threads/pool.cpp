export module xieite:threads.Pool;

import std;
import :functors.Function;

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
						auto jobsLock = std::unique_lock<std::mutex>(this->mutex);
						this->condition.wait(jobsLock, [this, stopToken] {
							return this->jobs.size() || stopToken.stop_requested();
						});
						if (!this->jobs.size() && stopToken.stop_requested()) {
							break;
						}
						const xieite::functors::Function<void()> job = this->jobs.front();
						this->jobs.pop();
						jobsLock.unlock();
						job();
					}
				});
			}
		}

		[[nodiscard]] std::size_t getThreadCount() const noexcept {
			const auto _ = std::unique_lock<std::mutex>(this->mutex);
			return this->threads.size();
		}

		template<std::invocable<> Functor>
		void enqueue(Functor&& job) noexcept {
			auto jobsLock = std::unique_lock<std::mutex>(this->mutex);
			this->jobs.emplace(job);
			jobsLock.unlock();
			this->condition.notify_one();
		}

	private:
		// Destruction order is important!!!
		std::queue<xieite::functors::Function<void()>> jobs;
		std::vector<std::jthread> threads;
		mutable std::mutex mutex;
		std::condition_variable condition;
	};
}

// Thanks to Evan for help
