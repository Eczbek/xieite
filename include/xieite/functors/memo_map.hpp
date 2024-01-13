#ifndef XIEITE_HEADER_FUNCTORS_MEMO_MAP
#	define XIEITE_HEADERS_FUNCTORS_MEMO_MAP

#	include <unordered_map>
#	include <utility>

namespace xieite::functors {
	template<typename Value, typename FirstKey, typename... RestKeys>
	class MemoMap {
	public:
		const Value& set(Value&& value, FirstKey&& firstKey, RestKeys&&... restKeys) noexcept {
			return this->map[std::forward<FirstKey>(firstKey)].set(std::forward<Value>(value), std::forward<RestKeys>(restKeys)...);
		}

		[[nodiscard]] const Value& get(FirstKey&& firstKey, RestKeys&&... restKeys) const noexcept {
			return this->map.at(std::forward<FirstKey>(firstKey)).get(std::forward<RestKeys...>(restKeys)...);
		}

		[[nodiscard]] bool has(FirstKey&& firstKey, RestKeys&&... restKeys) const noexcept {
			return this->map.contains(std::forward<FirstKey>(firstKey)) && this->map.at(std::forward<FirstKey>(firstKey)).has(std::forward<RestKeys>(restKeys)...);
		}

	private:
		std::unordered_map<FirstKey, MemoMap<Value, RestKeys...>> map;
	};

	template<typename Value, typename Key>
	class MemoMap<Value, Key> {
	public:
		const Value& set(Value&& value, Key&& key) noexcept {
			if (!this->map.contains(std::forward<Key>(key))) {
				this->map.emplace(std::make_pair(std::forward<Key>(key), std::forward<Value>(value)));
			}
			return this->map.at(std::forward<Key>(key));
		}

		[[nodiscard]] const Value& get(Key&& key) const noexcept {
			return this->map.at(std::forward<Key>(key));
		}

		[[nodiscard]] bool has(Key&& key) const noexcept {
			return this->map.contains(std::forward<Key>(key));
		}

	private:
		std::unordered_map<Key, Value> map;
	};
}

#endif
