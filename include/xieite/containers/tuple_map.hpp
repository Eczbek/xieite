#ifndef XIEITE_HEADER_CONTAINERS_TUPLE_MAP
#	define XIEITE_HEADER_CONTAINERS_TUPLE_MAP

#	include <cstddef>
#	include <initializer_list>
#	include <tuple>
#	include <unordered_map>
#	include <utility>

namespace xieite::containers {
	template<typename, typename>
	struct TupleMap;

	template<typename Value, typename FirstKey, typename... RestKeys>
	class TupleMap<std::tuple<FirstKey, RestKeys...>, Value> {
	public:
		TupleMap(const std::initializer_list<std::pair<FirstKey, TupleMap<std::tuple<RestKeys...>, Value>>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		[[nodiscard]] const Value& operator[](const std::tuple<FirstKey, RestKeys...>& keys) const noexcept {
			return ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) -> const Value& {
				return this->map.at(std::get<0>(keys))[std::make_tuple(std::get<indices + 1>(keys)...)];
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

		[[nodiscard]] Value& operator[](const std::tuple<FirstKey, RestKeys...>& keys) noexcept {
			return ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) -> Value& {
				return this->map.at(std::get<0>(keys))[std::make_tuple(std::get<indices + 1>(keys)...)];
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

		void insert(const std::tuple<FirstKey, RestKeys...>& keys, const Value& value) noexcept {
			return ([this, &keys, &value]<std::size_t... indices>(std::index_sequence<indices...>) {
				this->map[std::get<0>(keys)].insert(std::make_tuple(std::get<indices + 1>(keys)...), value);
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

		[[nodiscard]] bool contains(const std::tuple<FirstKey, RestKeys...>& keys) const noexcept {
			return this->map.contains(std::get<0>(keys)) && ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) {
				return this->map.at(std::get<0>(keys)).contains(std::make_tuple(std::get<indices + 1>(keys)...));
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

	private:
		std::unordered_map<FirstKey, TupleMap<std::tuple<RestKeys...>, Value>> map;
	};

	template<typename Value, typename Key>
	class TupleMap<std::tuple<Key>, Value> {
	public:
		TupleMap(const std::initializer_list<std::pair<Key, Value>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		[[nodiscard]] const Value& operator[](const std::tuple<Key>& key) const noexcept {
			return this->map.at(std::get<0>(key));
		}

		[[nodiscard]] Value& operator[](const std::tuple<Key>& key) noexcept {
			return this->map.at(std::get<0>(key));
		}

		void insert(const std::tuple<Key>& key, const Value& value) noexcept {
			this->map.emplace(std::make_pair(std::get<0>(key), value));
		}

		[[nodiscard]] bool contains(const std::tuple<Key>& key) const noexcept {
			return this->map.contains(std::get<0>(key));
		}

	private:
		std::unordered_map<Key, Value> map;
	};
}

#endif
