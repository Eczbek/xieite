#pragma once
#include <concepts> // std::invocable
#include <cstdlib> // std::exit
#include <functional> // std::function
#include <mutex> // std::lock_guard, std::mutex
#include <type_traits> // std::invoke_result_t
#include <vector> // std::vector

namespace xieite::process {
	template<std::invocable<> C>
	requires(std::same_as<std::invoke_result_t<C>, void>)
	void atExit(C&& callback) noexcept {
		static std::vector<std::function<void()>> callbacks;
		static std::mutex callbacksMutex;
		static struct Lock {
			~Lock() {
				const std::lock_guard<std::mutex> callbacksLock(callbacksMutex);
				for (const std::function<void()>& callback : callbacks)
					callback();
			}
		} lock;

		const std::lock_guard<std::mutex> callbacksLock(callbacksMutex);
		callbacks.push_back(std::function(callback));
	}
}
