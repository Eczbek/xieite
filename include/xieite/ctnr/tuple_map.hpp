#pragma once

#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../meta/splice_tuple.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<template<typename, typename> typename, typename, typename>
	struct tuple_map;

	template<template<typename, typename> typename Map, typename V, typename K, typename... Ks>
	struct tuple_map<Map, std::tuple<K, Ks...>, V> {
	private:
		Map<K, xieite::tuple_map<Map, std::tuple<Ks...>, V>> map;

	public:
		[[nodiscard]] constexpr tuple_map(std::initializer_list<std::pair<K, xieite::tuple_map<Map, std::tuple<Ks...>, V>>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto operator[](this Self&& self, KsRef&& keys)
			XIEITE_ARROW(std::forward_like<Self>(self.map.at(std::get<0>(std::move(keys)))[xieite::splice_tuple<0, 1>(XIEITE_FWD(keys))]))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef, std::convertible_to<V> VRef>
		constexpr auto insert(KsRef&& keys, VRef&& value)
			XIEITE_ARROW(this->map[std::get<0>(std::move(keys))].insert(xieite::splice_tuple<0, 1>(XIEITE_FWD(keys)), XIEITE_FWD(value)))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto has(KsRef&& keys) const
			XIEITE_ARROW(this->map.has(std::get<0>(keys)) && this->map.at(std::get<0>(std::move(keys))).has(xieite::splice_tuple<0, 1>(XIEITE_FWD(keys))))
	};

	template<template<typename, typename> typename Map, typename V, typename Key>
	struct tuple_map<Map, std::tuple<Key>, V> {
	private:
		Map<Key, V> map;

	public:
		[[nodiscard]] constexpr tuple_map(std::initializer_list<std::pair<Key, V>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto operator[](this Self&& self, KRef&& key)
			XIEITE_ARROW(std::forward_like<Self>(self.map.at(std::get<0>(std::move(key)))))

		template<std::convertible_to<std::tuple<Key>> KRef, std::convertible_to<V> VRef>
		constexpr auto insert(KRef&& key, VRef&& value)
			XIEITE_ARROW(this->map.emplace(std::make_pair(std::get<0>(std::move(key)), XIEITE_FWD(value))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto has(KRef&& key) const
			XIEITE_ARROW(this->map.contains(std::get<0>(std::move(key))))
	};
}

// NOTE: GCC insists on the private member variable being defined above its usage
