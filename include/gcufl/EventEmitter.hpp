#pragma once

#include <any>
#include <concepts>
#include <functional>
#include <string>
#include <unordered_map>


namespace gcufl {
	template<typename K>
	class EventEmitter {
	private:
		std::unordered_map<K, std::any> events;

	public:
		template<typename... A>
		void emit(const K& event, A... arguments) {
			if (events.contains(event))
				std::any_cast<std::function<void(A...)>>(events[event])(arguments...);
		}

		void off(const K& event) noexcept {
			events.erase(event);
		}

		template<typename... P, std::invocable<P...> C>
		void on(const K& event, const C& callback) noexcept {
			events[event] = std::any(std::function<void(P...)>(callback));
		}

		template<typename... P, std::invocable<P...> C>
		void once(const K& event, const C& callback) noexcept {
			events[event] = std::any(std::function<void(P...)>([&](P... arguments) {
				events.erase(event);
				callback(arguments...);
			}));
		}
	};
}