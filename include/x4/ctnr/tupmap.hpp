#pragma once

#include <concepts>
#include <initializer_list>
#include <tuple>
#include <utility>
#include "../meta/splicetup.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<template<typename, typename> typename, typename, typename>
	struct tupmap;

	template<template<typename, typename> typename Map, typename V, typename K, typename... Ks>
	struct tupmap<Map, std::tuple<K, Ks...>, V> {
	private:
		Map<K, x4::tupmap<Map, std::tuple<Ks...>, V>> map;

	public:
		[[nodiscard]] constexpr tupmap(std::initializer_list<std::pair<K, x4::tupmap<Map, std::tuple<Ks...>, V>>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto operator[](this Self&& self, KsRef&& keys)
			X4AR(std::forward_like<Self>(self.map.at(std::get<0>(std::move(keys)))[x4::splicetup<0, 1>(X4FWD(keys))]))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef, std::convertible_to<V> VRef>
		constexpr auto insert(KsRef&& keys, VRef&& value)
			X4AR(this->map[std::get<0>(std::move(keys))].insert(x4::splicetup<0, 1>(X4FWD(keys)), X4FWD(value)))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto has(KsRef&& keys) const
			X4AR(this->map.has(std::get<0>(keys)) && this->map.at(std::get<0>(std::move(keys))).has(x4::splicetup<0, 1>(X4FWD(keys))))
	};

	template<template<typename, typename> typename Map, typename V, typename Key>
	struct tupmap<Map, std::tuple<Key>, V> {
	private:
		Map<Key, V> map;

	public:
		[[nodiscard]] constexpr tupmap(std::initializer_list<std::pair<Key, V>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<typename Self, std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto operator[](this Self&& self, KRef&& key)
			X4AR(std::forward_like<Self>(self.map.at(std::get<0>(std::move(key)))))

		template<std::convertible_to<std::tuple<Key>> KRef, std::convertible_to<V> VRef>
		constexpr auto insert(KRef&& key, VRef&& value)
			X4AR(this->map.emplace(std::make_pair(std::get<0>(std::move(key)), X4FWD(value))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto has(KRef&& key) const
			X4AR(this->map.contains(std::get<0>(std::move(key))))
	};
}
