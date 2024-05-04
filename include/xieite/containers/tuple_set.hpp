#ifndef XIEITE_HEADER_CONTAINERS_TUPLE_SET
#	define XIEITE_HEADER_CONTAINERS_TUPLE_SET

#	include <concepts>
#	include <cstddef>
#	include <initializer_list>
#	include <tuple>
#	include <utility>
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<template<typename> typename, typename>
	struct TupleSet;

	template<template<typename> typename Container_, typename FirstKey_, typename... RestKeys_>
	struct TupleSet<Container_, std::tuple<FirstKey_, RestKeys_...>> {
	public:
		constexpr TupleSet(const std::initializer_list<std::pair<FirstKey_, xieite::containers::TupleSet<Container_, std::tuple<RestKeys_...>>>> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
		[[nodiscard]] constexpr bool operator[](KeysReference_&& keys) const {
			return this->contains(XIEITE_FORWARD(keys));
		}

		template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
		constexpr void insert(KeysReference_&& keys) {
			return ([this, &keys]<std::size_t... i_>(std::index_sequence<i_...>) {
				this->set[std::get<0>(keys)].insert(std::make_tuple(std::get<i_ + 1>(keys)...));
			})(std::make_index_sequence<sizeof...(RestKeys_)>());
		}

		template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
		[[nodiscard]] constexpr bool contains(KeysReference_&& keys) const {
			return this->set.contains(std::get<0>(keys)) && ([this, &keys]<std::size_t... i_>(std::index_sequence<i_...>) {
				return this->set.at(std::get<0>(keys)).contains(std::make_tuple(std::get<i_ + 1>(keys)...));
			})(std::make_index_sequence<sizeof...(RestKeys_)>());
		}

	private:
		Container_<FirstKey_, xieite::containers::TupleSet<Container_, std::tuple<RestKeys_...>>> set;
	};

	template<template<typename, typename> typename Container_, typename Key_>
	struct TupleSet<Container_, std::tuple<Key_>> {
	public:
		constexpr TupleSet(const std::initializer_list<Key_> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key_>> KeyReference_>
		[[nodiscard]] constexpr bool operator[](KeyReference_&& key) const {
			return this->contains(XIEITE_FORWARD(key));
		}

		template<std::convertible_to<std::tuple<Key_>> KeyReference_>
		constexpr void insert(KeyReference_&& key) {
			this->set.emplace(std::get<0>(XIEITE_FORWARD(key)));
		}

		template<std::convertible_to<std::tuple<Key_>> KeyReference_>
		[[nodiscard]] constexpr bool contains(KeyReference_&& key) const {
			return this->set.contains(std::get<0>(XIEITE_FORWARD(key)));
		}

	private:
		Container_<Key_> set;
	};
}

#endif
