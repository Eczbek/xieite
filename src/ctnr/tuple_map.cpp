module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:tuple_map;

import std;
import :unroll;

export namespace xieite {
	template<template<typename, typename> typename, typename, typename>
	struct tuple_map;

	template<template<typename, typename> typename Map, typename V, typename K, typename... Ks>
	struct tuple_map<Map, std::tuple<K, Ks...>, V> {
	public:
		constexpr tuple_map(std::initializer_list<std::pair<K, xieite::tuple_map<Map, std::tuple<Ks...>, V>>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto operator[](this Self&& self, KsRef&& keys)
		XIEITE_ARROW(xieite::unroll<Ks...>(
			[&self, &keys]<std::size_t... i>
			XIEITE_ARROW(std::forward_like<Self>(self.map.at(std::get<0>(keys))[std::make_tuple(std::get<i + 1>(keys)...)]))
		))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef, std::convertible_to<V> VRef>
		constexpr auto insert(KsRef&& keys, VRef&& value)
		XIEITE_ARROW(xieite::unroll<Ks...>(
			[this, &keys, &value]<std::size_t... i>
			XIEITE_ARROW(this->map[std::get<0>(keys)].insert(std::make_tuple(std::get<i + 1>(keys)...), XIEITE_FWD(value)))
		))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto has(KsRef&& keys) const
		XIEITE_ARROW(
			this->map.has(std::get<0>(keys))
			&& xieite::unroll<Ks...>(
				[this, &keys]<std::size_t... i>
				XIEITE_ARROW(this->map.at(std::get<0>(keys)).has(std::make_tuple(std::get<i + 1>(keys)...)))
			)
		)

	private:
		Map<K, xieite::tuple_map<Map, std::tuple<Ks...>, V>> map;
	};

	template<template<typename, typename> typename Map, typename V, typename Key>
	struct tuple_map<Map, std::tuple<Key>, V> {
	public:
		constexpr tuple_map(std::initializer_list<std::pair<Key, V>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto operator[](this Self&& self, KRef&& key)
		XIEITE_ARROW(std::forward_like<Self>(self.map.at(std::get<0>(XIEITE_FWD(key)))))

		template<std::convertible_to<std::tuple<Key>> KRef, std::convertible_to<V> VRef>
		constexpr auto insert(KRef&& key, VRef&& value)
		XIEITE_ARROW(this->map.emplace(std::make_pair(std::get<0>(XIEITE_FWD(key)), XIEITE_FWD(value))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto has(KRef&& key) const
		XIEITE_ARROW(this->map.contains(std::get<0>(XIEITE_FWD(key))))

	private:
		Map<Key, V> map;
	};
}
