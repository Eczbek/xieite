module;

#include <xieite/forward.hpp>
#include <xieite/sequence.hpp>

export module xieite:containers.TupleMap;

import std;

export namespace xieite::containers {
	template<template<typename, typename> typename, typename, typename>
	struct TupleMap;

	template<template<typename, typename> typename Container, typename Value, typename FirstKey, typename... RestKeys>
	struct TupleMap<Container, std::tuple<FirstKey, RestKeys...>, Value> {
	public:
		constexpr TupleMap(const std::initializer_list<std::pair<FirstKey, xieite::containers::TupleMap<Container, std::tuple<RestKeys...>, Value>>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, KeysReference&& keys) {
			return XIEITE_SEQUENCE(i, sizeof...(RestKeys), std::forward_like<Self>(self.map.at(std::get<0>(keys))[std::make_tuple(std::get<i + 1>(keys)...)]));
		}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference, std::convertible_to<Value> ValueReference>
		constexpr void insert(KeysReference&& keys, ValueReference&& value) {
			XIEITE_SEQUENCE(i, sizeof...(RestKeys), this->map[std::get<0>(keys)].insert(std::make_tuple(std::get<i + 1>(keys)...), XIEITE_FORWARD(value)));
		}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] constexpr bool contains(KeysReference&& keys) const {
			return this->map.contains(std::get<0>(keys)) && XIEITE_SEQUENCE(i, sizeof...(RestKeys), this->map.at(std::get<0>(keys)).contains(std::make_tuple(std::get<i + 1>(keys)...)));
		}

	private:
		Container<FirstKey, xieite::containers::TupleMap<Container, std::tuple<RestKeys...>, Value>> map;
	};

	template<template<typename, typename> typename Container, typename Value, typename Key>
	struct TupleMap<Container, std::tuple<Key>, Value> {
	public:
		constexpr TupleMap(const std::initializer_list<std::pair<Key, Value>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, KeyReference&& key) {
			return std::forward_like<Self>(self.map.at(std::get<0>(XIEITE_FORWARD(key))));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference, std::convertible_to<Value> ValueReference>
		constexpr void insert(KeyReference&& key, ValueReference&& value) {
			this->map.emplace(std::make_pair(std::get<0>(XIEITE_FORWARD(key)), XIEITE_FORWARD(value)));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr bool contains(KeyReference&& key) const {
			return this->map.contains(std::get<0>(XIEITE_FORWARD(key)));
		}

	private:
		Container<Key, Value> map;
	};
}
