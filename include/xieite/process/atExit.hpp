#pragma once

#include <functional>
#include <mutex>
#include <vector>

namespace xieite::process {
	inline void atExit(const std::function<void()>& callback) noexcept {
		static std::vector<std::function<void()>> callbacks;
		static std::mutex callbacksMutex;
		static struct Lock {
			~Lock() {
				const std::lock_guard<std::mutex> callbacksLock(callbacksMutex);
				for (const std::function<void()>& callback : callbacks) {
					callback();
				}
			}
		} lock;

		const std::lock_guard<std::mutex> callbacksLock(callbacksMutex);
		callbacks.push_back(callback);
	}
}
