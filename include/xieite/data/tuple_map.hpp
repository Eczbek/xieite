#ifndef DETAIL_XIEITE_HEADER_DATA_TUPLE_MAP
#	define DETAIL_XIEITE_HEADER_DATA_TUPLE_MAP
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

	template<template<typename, typename> typename Container, typename Value, typename Key, typename... Keys>
	struct tuple_map<Container, std::tuple<Key, Keys...>, Value> {
	private:
		Container<Key, xieite::tuple_map<Container, std::tuple<Keys...>, Value>> map;

	public:
		[[nodiscard]] constexpr tuple_map(std::initializer_list<std::pair<Key, xieite::tuple_map<Container, std::tuple<Keys...>, Value>>> list = {}) XIEITE_ARROW_CTOR(,
			map, ((std::from_range, list))
		)

		[[nodiscard]] constexpr auto operator[](this auto&& self, xieite::is_ref_to<std::tuple<Key, Keys...>> auto&& keys) XIEITE_ARROW(
			std::forward_like<decltype(self)>(self.map.at(std::get<0>(std::move(keys)))[xieite::subtuple<1>(XIEITE_FWD(keys))])
		)

		constexpr auto insert(xieite::is_ref_to<std::tuple<Key, Keys...>> auto&& keys, xieite::is_ref_to<Value> auto&& value) XIEITE_ARROW(
			this->map[std::get<0>(std::move(keys))].insert(xieite::subtuple<1>(XIEITE_FWD(keys)), XIEITE_FWD(value))
		)

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<Key, Keys...>> auto&& keys) const XIEITE_ARROW(
			this->map.has(std::get<0>(keys)) && this->map.at(std::get<0>(std::move(keys))).has(xieite::subtuple<1>(XIEITE_FWD(keys)))
		)
	};

	template<template<typename, typename> typename Container, typename Value, typename Key>
	struct tuple_map<Container, std::tuple<Key>, Value> {
	private:
		Container<Key, Value> map; // GCC insists on this being defined above its usage

	public:
		[[nodiscard]] constexpr tuple_map(std::initializer_list<std::pair<Key, Value>> list = {}) XIEITE_ARROW_CTOR(,
			map, ((std::from_range, list))
		)

		[[nodiscard]] constexpr auto operator[](this auto&& self, xieite::is_ref_to<std::tuple<Key>> auto&& key) XIEITE_ARROW(
			std::forward_like<decltype(self)>(self.map.at(std::get<0>(std::move(key))))
		)

		constexpr auto insert(xieite::is_ref_to<std::tuple<Key>> auto&& key, xieite::is_ref_to<Value> auto&& value) XIEITE_ARROW(
			this->map.emplace(std::make_pair(std::get<0>(std::move(key)), XIEITE_FWD(value)))
		)

		[[nodiscard]] constexpr auto has(xieite::is_ref_to<std::tuple<Key>> auto&& key) const XIEITE_ARROW(
			this->map.contains(std::get<0>(std::move(key)))
		)
	};
}

#endif
