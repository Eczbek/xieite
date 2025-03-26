#ifndef DETAIL_XIEITE_HEADER_CTNR_TUPLE_SET
#	define DETAIL_XIEITE_HEADER_CTNR_TUPLE_SET
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

	template<template<typename> typename Ctnr, typename K, typename... Ks>
	struct tuple_set<Ctnr, std::tuple<K, Ks...>> {
	private:
		Ctnr<xieite::tuple_set<Ctnr, std::tuple<Ks...>>> set;

	public:
		[[nodiscard]] constexpr tuple_set(std::initializer_list<std::pair<K, xieite::tuple_set<Ctnr, std::tuple<Ks...>>>> list = {})
			XIEITE_ARROW_CTOR(, set, ((std::from_range, list)))

		[[nodiscard]] constexpr auto operator[](xieite::is_ref_to<std::tuple<K, Ks...>> auto&& keys) const
			XIEITE_ARROW(this->set.has(std::get<0>(std::move(keys))) && this->set.at(std::get<0>(keys)).has(xieite::subtuple<1>(XIEITE_FWD(keys))))

		constexpr auto insert(xieite::is_ref_to<std::tuple<K, Ks...>> auto&& keys)
			XIEITE_ARROW(this->set[std::get<0>(std::move(keys))].insert(xieite::subtuple<1>(XIEITE_FWD(keys))))

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<K, Ks...>> auto&& keys) const
			XIEITE_ARROW((*this)[XIEITE_FWD(keys)])
	};

	template<template<typename> typename Ctnr, typename K>
	struct tuple_set<Ctnr, std::tuple<K>> {
	private:
		Ctnr<K> set; // GCC insists on this being defined above its usage

	public:
		[[nodiscard]] constexpr tuple_set(std::initializer_list<K> list = {})
			XIEITE_ARROW_CTOR(, set, ((std::from_range, list)))

		[[nodiscard]] constexpr auto operator[](xieite::is_ref_to<std::tuple<K>> auto&& key) const
			XIEITE_ARROW(this->set.contains(std::get<0>(XIEITE_FWD(key))))

		constexpr auto insert(xieite::is_ref_to<std::tuple<K>> auto&& key)
			XIEITE_ARROW(this->set.emplace(std::get<0>(XIEITE_FWD(key))))

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<K>> auto&& key) const
			XIEITE_ARROW((*this)[XIEITE_FWD(key)])
	};
}

#endif
