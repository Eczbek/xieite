#ifndef DETAIL_XIEITE_HEADER_CTNR_TUPLE_MAP
#	define DETAIL_XIEITE_HEADER_CTNR_TUPLE_MAP
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
	template<template<typename, typename> typename, typename, typename>
	struct tuple_map;

	template<template<typename, typename> typename Map, typename V, typename K, typename... Ks>
	struct tuple_map<Map, std::tuple<K, Ks...>, V> {
	private:
		Map<K, xieite::tuple_map<Map, std::tuple<Ks...>, V>> map;

	public:
		[[nodiscard]] constexpr tuple_map(std::initializer_list<std::pair<K, xieite::tuple_map<Map, std::tuple<Ks...>, V>>> list = {})
			XIEITE_ARROW_CTOR(, map, ((std::from_range, list)))

		[[nodiscard]] constexpr auto operator[](this auto&& self, xieite::is_ref_to<std::tuple<K, Ks...>> auto&& keys)
			XIEITE_ARROW(std::forward_like<decltype(self)>(self.map.at(std::get<0>(std::move(keys)))[xieite::subtuple<1>(XIEITE_FWD(keys))]))

		constexpr auto insert(xieite::is_ref_to<std::tuple<K, Ks...>> auto&& keys, xieite::is_ref_to<V> auto&& value)
			XIEITE_ARROW(this->map[std::get<0>(std::move(keys))].insert(xieite::subtuple<1>(XIEITE_FWD(keys)), XIEITE_FWD(value)))

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<K, Ks...>> auto&& keys) const
			XIEITE_ARROW(this->map.has(std::get<0>(keys)) && this->map.at(std::get<0>(std::move(keys))).has(xieite::subtuple<1>(XIEITE_FWD(keys))))
	};

	template<template<typename, typename> typename Map, typename V, typename K>
	struct tuple_map<Map, std::tuple<K>, V> {
	private:
		Map<K, V> map; // GCC insists on this being defined above its usage

	public:
		[[nodiscard]] constexpr tuple_map(std::initializer_list<std::pair<K, V>> list = {})
			XIEITE_ARROW_CTOR(, map, ((std::from_range, list)))

		[[nodiscard]] constexpr auto operator[](this auto&& self, xieite::is_ref_to<std::tuple<K>> auto&& key)
			XIEITE_ARROW(std::forward_like<decltype(self)>(self.map.at(std::get<0>(std::move(key)))))

		constexpr auto insert(xieite::is_ref_to<std::tuple<K>> auto&& key, xieite::is_ref_to<V> auto&& value)
			XIEITE_ARROW(this->map.emplace(std::make_pair(std::get<0>(std::move(key)), XIEITE_FWD(value))))

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<K>> auto&& key) const
			XIEITE_ARROW(this->map.contains(std::get<0>(std::move(key))))
	};
}

#endif
