#ifndef XIEITE_HEADER_CONTAINERS_TUPLE_SET
#	define XIEITE_HEADER_CONTAINERS_TUPLE_SET

#	include <concepts>
#	include <cstddef>
#	include <initializer_list>
#	include <tuple>
#	include <utility>

namespace xieite::containers {
	template<template<typename> typename, typename>
	struct TupleSet;

	template<template<typename> typename Container, typename FirstKey, typename... RestKeys>
	class TupleSet<Container, std::tuple<FirstKey, RestKeys...>> {
	public:
		TupleSet(const std::initializer_list<std::pair<FirstKey, TupleSet<Container, std::tuple<RestKeys...>>>> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] const bool operator[](KeysReference&& keys) const noexcept {
			return this->contains(std::forward<KeysReference>(keys));
		}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		void insert(KeysReference&& keys) noexcept {
			return ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) {
				this->set[std::get<0>(std::forward<KeysReference>(keys))].insert(std::make_tuple(std::get<indices + 1>(std::forward<KeysReference>(keys))...));
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

		template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
		[[nodiscard]] bool contains(KeysReference&& keys) const noexcept {
			return this->set.contains(std::get<0>(std::forward<KeysReference>(keys))) && ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) {
				return this->set.at(std::get<0>(std::forward<KeysReference>(keys))).contains(std::make_tuple(std::get<indices + 1>(std::forward<KeysReference>(keys))...));
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

	private:
		Container<FirstKey, TupleSet<Container, std::tuple<RestKeys...>>> set;
	};

	template<template<typename, typename> typename Container, typename Key>
	class TupleSet<Container, std::tuple<Key>> {
	public:
		TupleSet(const std::initializer_list<Key> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] const bool operator[](KeyReference&& key) const noexcept {
			return this->contains(std::forward<KeyReference>(key));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		void insert(KeyReference&& key) noexcept {
			this->set.emplace(std::get<0>(std::forward<KeyReference>(key)));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] bool contains(KeyReference&& key) const noexcept {
			return this->set.contains(std::get<0>(std::forward<KeyReference>(key)));
		}

	private:
		Container<Key> set;
	};
}

#endif
