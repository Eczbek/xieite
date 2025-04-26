#ifndef DETAIL_XIEITE_HEADER_DATA_TUPLE_SET
#	define DETAIL_XIEITE_HEADER_DATA_TUPLE_SET
#
#	include <initializer_list>
#	include <ranges>
#	include <tuple>
#	include <utility>
#	include "../meta/subtuple.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ref_to.hpp"

namespace xieite {
	template<template<typename> typename, typename>
	struct tuple_set;

	template<template<typename> typename Container, typename Key, typename... Keys>
	struct tuple_set<Container, std::tuple<Key, Keys...>> {
	private:
		Container<xieite::tuple_set<Container, std::tuple<Keys...>>> set;

	public:
		[[nodiscard]] constexpr tuple_set(std::initializer_list<std::pair<Key, xieite::tuple_set<Container, std::tuple<Keys...>>>> list = {})
			XIEITE_ARROW_CTOR(, set, ((std::from_range, list)))

		[[nodiscard]] constexpr auto operator[](xieite::is_ref_to<std::tuple<Key, Keys...>> auto&& keys) const
			XIEITE_ARROW(this->set.has(std::get<0>(std::move(keys))) && this->set.at(std::get<0>(keys)).has(xieite::subtuple<1>(XIEITE_FWD(keys))))

		constexpr auto insert(xieite::is_ref_to<std::tuple<Key, Keys...>> auto&& keys)
			XIEITE_ARROW(this->set[std::get<0>(std::move(keys))].insert(xieite::subtuple<1>(XIEITE_FWD(keys))))

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<Key, Keys...>> auto&& keys) const
			XIEITE_ARROW((*this)[XIEITE_FWD(keys)])
	};

	template<template<typename> typename Container, typename Key>
	struct tuple_set<Container, std::tuple<Key>> {
	private:
		Container<Key> set; // GCC insists on this being defined above its usage

	public:
		[[nodiscard]] constexpr tuple_set(std::initializer_list<Key> list = {})
			XIEITE_ARROW_CTOR(, set, ((std::from_range, list)))

		[[nodiscard]] constexpr auto operator[](xieite::is_ref_to<std::tuple<Key>> auto&& key) const
			XIEITE_ARROW(this->set.contains(std::get<0>(XIEITE_FWD(key))))

		constexpr auto insert(xieite::is_ref_to<std::tuple<Key>> auto&& key)
			XIEITE_ARROW(this->set.emplace(std::get<0>(XIEITE_FWD(key))))

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<Key>> auto&& key) const
			XIEITE_ARROW((*this)[XIEITE_FWD(key)])
	};
}

#endif
