module;

#include <xieite/forward.hpp>

export module xieite:containers.TupleSet;

import std;

export namespace xieite::containers {
	template<template<typename> typename, typename>
	struct TupleSet;

	template<template<typename> typename Container, typename FirstKey, typename... RestKeys>
	struct TupleSet<Container, std::tuple<FirstKey, RestKeys...>> {
	public:
		constexpr TupleSet(const std::initializer_list<std::pair<FirstKey, xieite::containers::TupleSet<Container, std::tuple<RestKeys...>>>> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] constexpr bool operator[](KeysReference&& keys) const {
			return this->contains(XIEITE_FORWARD(keys));
		}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		constexpr void insert(KeysReference&& keys) {
			([&keys]<std::size_t... i>(std::index_sequence<i...>) {
				this->set[std::get<0>(keys)].insert(std::make_tuple(std::get<i + 1>(keys)...));
			})(std::index_sequence_for<RestKeys...>());
		}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] constexpr bool contains(KeysReference&& keys) const {
			return this->set.contains(std::get<0>(keys)) && ([&keys]<std::size_t... i>(std::index_sequence<i...>) {
				return this->set.at(std::get<0>(keys)).contains(std::make_tuple(std::get<i + 1>(keys)...));
			})(std::index_sequence_for<RestKeys...>());
		}

	private:
		Container<xieite::containers::TupleSet<Container, std::tuple<RestKeys...>>> set;
	};

	template<template<typename> typename Container, typename Key>
	struct TupleSet<Container, std::tuple<Key>> {
	public:
		constexpr TupleSet(const std::initializer_list<Key> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr bool operator[](KeyReference&& key) const {
			return this->contains(XIEITE_FORWARD(key));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		constexpr void insert(KeyReference&& key) {
			this->set.emplace(std::get<0>(XIEITE_FORWARD(key)));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr bool contains(KeyReference&& key) const {
			return this->set.contains(std::get<0>(XIEITE_FORWARD(key)));
		}

	private:
		Container<Key> set;
	};
}
