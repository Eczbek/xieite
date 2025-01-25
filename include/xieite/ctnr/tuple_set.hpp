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
	template<template<typename> typename, typename>
	struct tuple_set;

	template<template<typename> typename Ctnr, typename K, typename... Ks>
	struct tuple_set<Ctnr, std::tuple<K, Ks...>> {
	private:
		Ctnr<xieite::tuple_set<Ctnr, std::tuple<Ks...>>> set;

	public:
		[[nodiscard]] constexpr tuple_set(std::initializer_list<std::pair<K, xieite::tuple_set<Ctnr, std::tuple<Ks...>>>> list = {})
		noexcept(noexcept(decltype(this->set)(list.begin(), list.end())))
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto operator[](KsRef&& keys) const
			XIEITE_ARROW(this->set.has(std::get<0>(std::move(keys))) && this->set.at(std::get<0>(keys)).has(xieite::splice_tuple<0, 1>(XIEITE_FWD(keys))))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		constexpr auto insert(KsRef&& keys)
			XIEITE_ARROW(this->set[std::get<0>(std::move(keys))].insert(xieite::splice_tuple<0, 1>(XIEITE_FWD(keys))))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto has(KsRef&& keys) const
			XIEITE_ARROW((*this)[XIEITE_FWD(keys)])
	};

	template<template<typename> typename Ctnr, typename Key>
	struct tuple_set<Ctnr, std::tuple<Key>> {
	private:
		Ctnr<Key> set;

	public:
		[[nodiscard]] constexpr tuple_set(std::initializer_list<Key> list = {})
		noexcept(noexcept(decltype(this->set)(list.begin(), list.end())))
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto operator[](KRef&& key) const
			XIEITE_ARROW(this->set.contains(std::get<0>(XIEITE_FWD(key))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		constexpr auto insert(KRef&& key)
			XIEITE_ARROW(this->set.emplace(std::get<0>(XIEITE_FWD(key))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto has(KRef&& key) const
			XIEITE_ARROW((*this)[XIEITE_FWD(key)])
	};
}

// NOTE: GCC insists on the private member variable being defined above its usage
