module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:containers.TupleSet;

import std;
import :functors.unroll;

export namespace xieite::containers {
	template<template<typename> typename, typename>
	struct TupleSet;

	template<template<typename> typename Container, typename FirstKey, typename... RestKeys>
	struct TupleSet<Container, std::tuple<FirstKey, RestKeys...>> {
	public:
		constexpr TupleSet(const std::initializer_list<std::pair<FirstKey, xieite::containers::TupleSet<Container, std::tuple<RestKeys...>>>> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] constexpr auto operator[](KeysReference&& keys) const
		XIEITE_ARROW(this->contains(XIEITE_FORWARD(keys)))

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		constexpr auto insert(KeysReference&& keys)
		XIEITE_ARROW(xieite::functors::unroll<RestKeys...>([this, &keys]<std::size_t... i> XIEITE_ARROW(this->set[std::get<0>(keys)].insert(std::make_tuple(std::get<i + 1>(keys)...)))))

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] constexpr auto contains(KeysReference&& keys) const
		XIEITE_ARROW(
			this->set.contains(std::get<0>(keys))
			&& xieite::functors::unroll<RestKeys...>(
				[this, &keys]<std::size_t... i>
				XIEITE_ARROW(this->set.at(std::get<0>(keys)).contains(std::make_tuple(std::get<i + 1>(keys)...)))
			)
		)

	private:
		Container<xieite::containers::TupleSet<Container, std::tuple<RestKeys...>>> set;
	};

	template<template<typename> typename Container, typename Key>
	struct TupleSet<Container, std::tuple<Key>> {
	public:
		constexpr TupleSet(const std::initializer_list<Key> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr auto operator[](KeyReference&& key) const
		XIEITE_ARROW(this->contains(XIEITE_FORWARD(key)))

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		constexpr auto insert(KeyReference&& key)
		XIEITE_ARROW(this->set.emplace(std::get<0>(XIEITE_FORWARD(key))))

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr auto contains(KeyReference&& key) const
		XIEITE_ARROW(this->set.contains(std::get<0>(XIEITE_FORWARD(key))))

	private:
		Container<Key> set;
	};
}
