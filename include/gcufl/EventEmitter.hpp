#pragma once

#include <any>
#include <concepts>
#include <functional>
#include <string>
#include <unordered_map>


namespace gcufl {
	class EventEmitter {
	private:
		std::unordered_map<std::string, std::any> events;

	public:
		template <typename... P, std::invocable<P...> C>
		void on(const std::string& event, const C& callback) noexcept {
			events[event] = std::any(std::function<void(P...)>(callback));
		}

		template <typename... P, std::invocable<P...> C>
		void once(const std::string& event, const C& callback) noexcept {
			events[event] = std::any(std::function<void(P...)>([&](P... arguments) {
				events.erase(event);
				callback(arguments...);
			}));
		}

		void off(const std::string& event) noexcept;

		template <typename... A>
		void emit(const std::string& event, A... arguments) {
			if (events.contains(event))
				std::any_cast<std::function<void(A...)>>(events[event])(arguments...);
		}
	};
}