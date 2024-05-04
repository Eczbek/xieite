#ifndef XIEITE_HEADER_CONTAINERS_TUPLE_MAP
#	define XIEITE_HEADER_CONTAINERS_TUPLE_MAP

#	include <concepts>
#	include <cstddef>
#	include <initializer_list>
#	include <tuple>
#	include <utility>
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<template<typename, typename> typename, typename, typename>
	struct TupleMap;

	template<template<typename, typename> typename Container_, typename Value_, typename FirstKey_, typename... RestKeys_>
	struct TupleMap<Container_, std::tuple<FirstKey_, RestKeys_...>, Value_> {
	public:
		constexpr TupleMap(const std::initializer_list<std::pair<FirstKey_, xieite::containers::TupleMap<Container_, std::tuple<RestKeys_...>, Value_>>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self_, std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
		[[nodiscard]] constexpr auto&& operator[](this Self_&& self, KeysReference_&& keys) {
			return ([&self, &keys]<std::size_t... i_>(std::index_sequence<i_...>) -> auto&& {
				return XIEITE_FORWARD(self).map.at(std::get<0>(keys))[std::make_tuple(std::get<i_ + 1>(keys)...)];
			})(std::make_index_sequence<sizeof...(RestKeys_)>());
		}

		template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_, std::convertible_to<Value_> ValueReference_>
		constexpr void insert(KeysReference_&& keys, ValueReference_&& value) {
			return ([this, &keys, &value]<std::size_t... i_>(std::index_sequence<i_...>) {
				this->map[std::get<0>(keys)].insert(std::make_tuple(std::get<i_ + 1>(keys)...), XIEITE_FORWARD(value));
			})(std::make_index_sequence<sizeof...(RestKeys_)>());
		}

		template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
		[[nodiscard]] constexpr bool contains(KeysReference_&& keys) const {
			return this->map.contains(std::get<0>(keys)) && ([this, &keys]<std::size_t... i_>(std::index_sequence<i_...>) {
				return this->map.at(std::get<0>(keys)).contains(std::make_tuple(std::get<i_ + 1>(keys)...));
			})(std::make_index_sequence<sizeof...(RestKeys_)>());
		}

	private:
		Container_<FirstKey_, xieite::containers::TupleMap<Container_, std::tuple<RestKeys_...>, Value_>> map;
	};

	template<template<typename, typename> typename Container_, typename Value_, typename Key_>
	struct TupleMap<Container_, std::tuple<Key_>, Value_> {
	public:
		constexpr TupleMap(const std::initializer_list<std::pair<Key_, Value_>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self_, std::convertible_to<std::tuple<Key_>> KeyReference_>
		[[nodiscard]] constexpr std::convertible_to<Value_> auto&& operator[](this Self_&& self, KeyReference_&& key) {
			return XIEITE_FORWARD(self).map.at(std::get<0>(XIEITE_FORWARD(key)));
		}

		template<std::convertible_to<std::tuple<Key_>> KeyReference_, std::convertible_to<Value_> ValueReference_>
		constexpr void insert(KeyReference_&& key, ValueReference_&& value) {
			this->map.emplace(std::make_pair(std::get<0>(XIEITE_FORWARD(key)), XIEITE_FORWARD(value)));
		}

		template<std::convertible_to<std::tuple<Key_>> KeyReference_>
		[[nodiscard]] constexpr bool contains(KeyReference_&& key) const {
			return this->map.contains(std::get<0>(XIEITE_FORWARD(key)));
		}

	private:
		Container_<Key_, Value_> map;
	};
}

#endif
