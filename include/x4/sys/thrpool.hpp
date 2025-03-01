#pragma once

#include <concepts>
#include <condition_variable>
#include <cstddef>
#include <future>
#include <mutex>
#include <queue>
#include <stop_token>
#include <thread>
#include <utility>
#include <vector>

namespace x4 {
	struct thrpool {
	public:
		[[nodiscard]] explicit thrpool(std::size_t n = std::thread::hardware_concurrency()) noexcept {
			this->setN(n);
		}

		~thrpool() {
			auto lock = std::unique_lock<std::mutex>(this->mutex);
			for (std::jthread& thread : this->n) {
				thread.request_stop();
			}
			lock.unlock();
			this->cond.notify_all();
		}

		void setN(std::size_t n) noexcept {
			const auto _ = std::unique_lock<std::mutex>(this->mutex);
			const std::size_t curr = this->n.size();
			if (n < curr) {
				this->n.resize(n);
				return;
			}
			while (n-- > curr) {
				this->n.emplace_back([this](std::stop_token token) -> void {
					while (true) {
						auto lock = std::unique_lock<std::mutex>(this->mutex);
						this->cond.wait(
							lock,
							[this, token] -> bool {
								return this->tasks.size() || token.stop_requested();
							}
						);
						if (!this->tasks.size() && token.stop_requested()) {
							break;
						}
						std::packaged_task<void()> task = std::move(this->tasks.front());
						this->tasks.pop();
						lock.unlock();
						task();
					}
				});
			}
		}

		[[nodiscard]] std::size_t getN() const noexcept {
			const auto _ = std::unique_lock<std::mutex>(this->mutex);
			return this->n.size();
		}

		template<std::invocable<> F>
		std::future<void> enqueue(F&& fn) noexcept {
			auto task = std::packaged_task<void()>(fn);
			std::future<void> future = task.get_future();
			auto lock = std::unique_lock<std::mutex>(this->mutex);
			this->tasks.emplace(std::move(task));
			lock.unlock();
			this->cond.notify_one();
			return future;
		}

	private:
		std::queue<std::packaged_task<void()>> tasks;
		std::vector<std::jthread> n;
		mutable std::mutex mutex;
		std::condition_variable cond;
	};
}
