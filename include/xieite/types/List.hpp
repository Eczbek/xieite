#ifndef XIEITE_HEADER__TYPES__LIST
#	define XIEITE_HEADER__TYPES__LIST

#	include <cmath>
#	include <concepts>
#	include <tuple>
#	include <type_traits>
#	include <utility>

namespace xieite::types {
	template<typename... Types>
	class List {
	public:
		static constexpr std::size_t size = sizeof...(Types);

		using Data = std::tuple<Types...>;

		template<std::size_t index>
		using At = std::conditional_t<index < sizeof...(Types), std::tuple_element<index, xieite::types::List<Types...>::Data>, std::type_identity<void>>::type;

		using First = xieite::types::List<Types...>::At<0>;

		using Last = xieite::types::List<Types...>::At<sizeof...(Types) - 1>;

		template<typename... OtherTypes>
		using Append = xieite::types::List<Types..., OtherTypes...>;

		template<typename... OtherTypes>
		using Prepend = xieite::types::List<OtherTypes..., Types...>;

	private:
		template<std::size_t offset, std::size_t... indices>
		static consteval xieite::types::List<xieite::types::List<Types...>::At<indices + offset>...> sliceHelper(std::index_sequence<indices...>) noexcept;

	public:
		template<std::size_t start, std::size_t end = sizeof...(Types)>
		using Slice = decltype(xieite::types::List<Types...>::sliceHelper<std::min(start, end)>(std::make_index_sequence<std::min(std::max(start, end), sizeof...(Types)) - std::min(std::min(start, end), sizeof...(Types))>()));

	private:
		template<std::size_t... indices>
		static consteval xieite::types::List<xieite::types::List<Types...>::At<sizeof...(Types) - indices - 1>...> reverseHelper(std::index_sequence<indices...>) noexcept;

	public:
		using Reverse = decltype(xieite::types::List<Types...>::reverseHelper(std::make_index_sequence<sizeof...(Types)>()));

	private:
		template<template<typename...> typename Operation, typename... OtherTypes>
		struct RangeTypesHelper {
			using Data = Operation<OtherTypes...>;
		};

		template<template<typename...> typename Operation, template<typename...> typename Range, typename... OtherTypes>
		struct RangeTypesHelper<Operation, Range<OtherTypes...>>
		: xieite::types::List<Types...>::RangeTypesHelper<Operation, OtherTypes...> {};

	public:
		template<typename Range>
		using AppendRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::Append, Range>::Data;

		template<typename Range>
		using PrependRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::Prepend, Range>::Data;

		template<std::size_t start, std::size_t end = start + 1>
		using Erase = xieite::types::List<Types...>::Slice<0, start>::template AppendRange<xieite::types::List<Types...>::Slice<end>>;

		template<std::size_t index, typename... OtherTypes>
		using Insert = xieite::types::List<Types...>::Slice<0, index>::template Append<OtherTypes...>::template AppendRange<xieite::types::List<Types...>::Slice<index>>;

		template<std::size_t index, typename OtherType>
		using Set = xieite::types::List<Types...>::Erase<index>::template Insert<index, OtherType>;

		template<std::size_t index1, std::size_t index2>
		using Swap = xieite::types::List<Types...>::template Set<index1, xieite::types::List<Types...>::At<index2>>::template Set<index2, xieite::types::List<Types...>::At<index1>>;

	private:
		template<std::size_t index>
		struct InsertRangeHelper {
			template<typename... OtherTypes>
			using Data = xieite::types::List<Types...>::Insert<index, OtherTypes...>;
		};

	public:
		template<std::size_t index, typename Range>
		using InsertRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::InsertRangeHelper<index>::template Data, Range>::Data;

		template<std::size_t start, std::size_t end, typename... OtherTypes>
		using Replace = xieite::types::List<Types...>::Erase<start, end>::template Insert<start, OtherTypes...>;

	private:
		template<std::size_t start, std::size_t end>
		struct ReplaceRangeHelper {
			template<typename... OtherTypes>
			using Data = xieite::types::List<Types...>::Replace<start, end, OtherTypes...>;
		};

	public:
		template<std::size_t start, std::size_t end, typename Range>
		using ReplaceRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::ReplaceRangeHelper<start, end>::template Data, Range>::Data;

		template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
		using SwapRanges = xieite::types::List<Types...>::ReplaceRange<start1, end1, xieite::types::List<Types...>::Slice<start2, end2>>::template ReplaceRange<start2, end2, xieite::types::List<Types...>::Slice<start1, end1>>;

	private:
		template<typename... UniqueTypes>
		struct UniqueHelper {
			using Data = xieite::types::List<UniqueTypes...>;

			template<typename Type>
			consteval std::conditional_t<(... || std::same_as<UniqueTypes, Type>), xieite::types::List<Types...>::UniqueHelper<UniqueTypes...>, xieite::types::List<Types...>::UniqueHelper<UniqueTypes..., Type>> operator->*(xieite::types::List<Types...>::UniqueHelper<Type>) const noexcept;
		};

	public:
		using Unique = decltype((xieite::types::List<Types...>::UniqueHelper<>()->*...->*xieite::types::List<Types...>::UniqueHelper<Types>()))::Data;
	};
}

// Thanks to Eisenwave and eightfold for help

#endif
