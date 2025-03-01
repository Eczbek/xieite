#pragma once

#include <concepts>
#include <initializer_list>
#include <tuple>
#include <utility>
#include "../meta/splicetup.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<template<typename> typename, typename>
	struct tupset;

	template<template<typename> typename Ctnr, typename K, typename... Ks>
	struct tupset<Ctnr, std::tuple<K, Ks...>> {
	private:
		Ctnr<x4::tupset<Ctnr, std::tuple<Ks...>>> set;

	public:
		[[nodiscard]] constexpr tupset(std::initializer_list<std::pair<K, x4::tupset<Ctnr, std::tuple<Ks...>>>> list = {})
		noexcept(noexcept(decltype(this->set)(list.begin(), list.end())))
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto operator[](KsRef&& keys) const
			X4AR(this->set.has(std::get<0>(std::move(keys))) && this->set.at(std::get<0>(keys)).has(x4::splicetup<0, 1>(X4FWD(keys))))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		constexpr auto insert(KsRef&& keys)
			X4AR(this->set[std::get<0>(std::move(keys))].insert(x4::splicetup<0, 1>(X4FWD(keys))))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto has(KsRef&& keys) const
			X4AR((*this)[X4FWD(keys)])
	};

	template<template<typename> typename Ctnr, typename Key>
	struct tupset<Ctnr, std::tuple<Key>> {
	private:
		Ctnr<Key> set;

	public:
		[[nodiscard]] constexpr tupset(std::initializer_list<Key> list = {})
		noexcept(noexcept(decltype(this->set)(list.begin(), list.end())))
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto operator[](KRef&& key) const
			X4AR(this->set.contains(std::get<0>(X4FWD(key))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		constexpr auto insert(KRef&& key)
			X4AR(this->set.emplace(std::get<0>(X4FWD(key))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto has(KRef&& key) const
			X4AR((*this)[X4FWD(key)])
	};
}
