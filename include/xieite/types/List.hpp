#ifndef XIEITE_HEADER__TYPES__LIST
#	define XIEITE_HEADER__TYPES__LIST

#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include <utility>

namespace xieite::types {
	template<typename... Types>
	class List {
	public:
		static constexpr std::size_t size = sizeof...(Types);

	private:
		template<std::size_t, typename...>
		struct AtHelper;

		template<std::size_t index, typename First, typename... Rest>
		struct AtHelper<index, First, Rest...>
		: xieite::types::List<Types...>::AtHelper<index - 1, Rest...> {};

		template<typename First, typename... Rest>
		struct AtHelper<0, First, Rest...> {
			using Type = First;
		};

	public:
		template<std::size_t index>
		using At = xieite::types::List<Types...>::AtHelper<index, Types...>::Type;

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
			using Type = Operation<OtherTypes...>;
		};

		template<template<typename...> typename Operation, template<typename...> typename Range, typename... OtherTypes>
		struct RangeTypesHelper<Operation, Range<OtherTypes...>>
		: xieite::types::List<Types...>::RangeTypesHelper<Operation, OtherTypes...> {};

	public:
		template<typename Range>
		using AppendRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::Append, Range>::Type;

		template<typename Range>
		using PrependRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::Prepend, Range>::Type;

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
			using Type = xieite::types::List<Types...>::Insert<index, OtherTypes...>;
		};

	public:
		template<std::size_t index, typename Range>
		using InsertRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::InsertRangeHelper<index>::template Type, Range>::Type;

		template<std::size_t start, std::size_t end, typename... OtherTypes>
		using Replace = xieite::types::List<Types...>::Erase<start, end>::template Insert<start, OtherTypes...>;

	private:
		template<std::size_t start, std::size_t end>
		struct ReplaceRangeHelper {
			template<typename... OtherTypes>
			using Type = xieite::types::List<Types...>::Replace<start, end, OtherTypes...>;
		};

	public:
		template<std::size_t start, std::size_t end, typename Range>
		using ReplaceRange = xieite::types::List<Types...>::RangeTypesHelper<xieite::types::List<Types...>::ReplaceRangeHelper<start, end>::template Type, Range>::Type;

		template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
		using SwapRanges = xieite::types::List<Types...>::ReplaceRange<start1, end1, xieite::types::List<Types...>::Slice<start2, end2>>::template ReplaceRange<start2, end2, xieite::types::List<Types...>::Slice<start1, end1>>;

	private:
		template<std::size_t>
		struct RepeatHelper {
			using Type = xieite::types::List<>;
		};

		template<std::size_t count>
		requires(static_cast<bool>(count))
		struct RepeatHelper<count> {
			using Type = xieite::types::List<Types...>::template AppendRange<typename xieite::types::List<Types...>::RepeatHelper<count - 1>::Type>;
		};

	public:
		template<std::size_t count>
		using Repeat = xieite::types::List<Types...>::RepeatHelper<count>::Type;

	private:
		template<typename... UniqueTypes>
		struct UniqueHelper {
			using Type = xieite::types::List<UniqueTypes...>;

			template<typename Type>
			consteval std::conditional_t<(... || std::same_as<UniqueTypes, Type>), xieite::types::List<Types...>::UniqueHelper<UniqueTypes...>, xieite::types::List<Types...>::UniqueHelper<UniqueTypes..., Type>> operator->*(xieite::types::List<Types...>::UniqueHelper<Type>) const noexcept;
		};

	public:
		using Unique = decltype((xieite::types::List<Types...>::UniqueHelper<>()->*...->*xieite::types::List<Types...>::UniqueHelper<Types>()))::Type;
	};
}

// Thanks to Eisenwave and eightfold for help

#endif
