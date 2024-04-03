#ifndef XIEITE_HEADER_TYPES_LIST
#	define XIEITE_HEADER_TYPES_LIST

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <type_traits>
#	include <utility>
#	include "../concepts/same_as_any.hpp"

namespace xieite::types {
	template<typename... Types>
	struct List {
	public:
		static constexpr std::size_t size = sizeof...(Types);

		template<typename Type, template<typename, typename> typename Comparator = std::is_same>
		static constexpr std::size_t count = (... + Comparator<Type, Types>::value);

		template<typename Type, template<typename, typename> typename Comparator = std::is_same>
		static constexpr bool has = (... || Comparator<Type, Types>::value);

		template<typename Type, template<typename, typename> typename Comparator = std::is_same>
		requires(xieite::types::List<Types...>::has<Type, Comparator>)
		static constexpr std::size_t find = ([] {
			std::size_t index = 0;
			(... && (!Comparator<Type, Types>::value && ++index));
			return index;
		})();

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

		template<template<typename...> typename Template>
		using Apply = Template<Types...>;

		template<typename... OtherTypes>
		using Append = xieite::types::List<Types..., OtherTypes...>;

		template<typename... OtherTypes>
		using Prepend = xieite::types::List<OtherTypes..., Types...>;

	private:
		template<std::size_t offset, std::size_t... i>
		static xieite::types::List<xieite::types::List<Types...>::At<i + offset>...> sliceHelper(std::index_sequence<i...>) noexcept;

	public:
		template<std::size_t start, std::size_t end = sizeof...(Types)>
		using Slice = decltype(xieite::types::List<Types...>::sliceHelper<std::min(start, end)>(std::make_index_sequence<std::min(std::max(start, end), sizeof...(Types)) - std::min(std::min(start, end), sizeof...(Types))>()));

	private:
		template<std::size_t... i>
		static xieite::types::List<xieite::types::List<Types...>::At<sizeof...(Types) - i - 1>...> reverseHelper(std::index_sequence<i...>) noexcept;

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
		template<template<typename, typename...> typename Selector, typename... OtherTypes>
		struct FilterHelper {
			using Type = xieite::types::List<OtherTypes...>;

			template<typename Type>
			std::conditional_t<Selector<Type, OtherTypes...>::value, xieite::types::List<Types...>::FilterHelper<Selector, OtherTypes..., Type>, xieite::types::List<Types...>::FilterHelper<Selector, OtherTypes...>> operator->*(xieite::types::List<Types...>::FilterHelper<Selector, Type>) const noexcept;
		};

	public:
		template<template<typename, typename...> typename Selector>
		using Filter = decltype((xieite::types::List<Types...>::FilterHelper<Selector>()->*...->*xieite::types::List<Types...>::FilterHelper<Selector, Types>()))::Type;

	private:
		template<typename Type, typename... OtherTypes>
		struct UniqueHelper
		: std::bool_constant<!xieite::concepts::SameAsAny<Type, OtherTypes...>> {};

	public:
		using Unique = xieite::types::List<Types...>::Filter<xieite::types::List<Types...>::UniqueHelper>;

		template<std::size_t... i>
		using Transform = xieite::types::List<xieite::types::List<Types...>::At<i>...>;

	private:
		template<std::size_t>
		struct RepeatHelper {
			using Type = xieite::types::List<>;
		};

		template<std::size_t count>
		requires(count > 0)
		struct RepeatHelper<count> {
			using Type = xieite::types::List<Types...>::template AppendRange<typename xieite::types::List<Types...>::RepeatHelper<count - 1>::Type>;
		};

	public:
		template<std::size_t count>
		using Repeat = xieite::types::List<Types...>::RepeatHelper<count>::Type;

	private:
		template<typename... OtherTypes>
		requires(sizeof...(Types) == sizeof...(OtherTypes))
		struct ZipHelper {
			using Type = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
				return xieite::types::List<xieite::types::List<xieite::types::List<Types...>::At<i>, typename xieite::types::List<OtherTypes...>::template At<i>>...>();
			})(std::make_index_sequence<sizeof...(OtherTypes)>()));
		};

		template<template<typename...> typename Range, typename... OtherTypes>
		struct ZipHelper<Range<OtherTypes...>>
		: xieite::types::List<Types...>::ZipHelper<OtherTypes...> {};

	public:
		template<typename... OtherTypes>
		using Zip = xieite::types::List<Types...>::ZipHelper<OtherTypes...>::Type;

		template<typename Range>
		using ZipRange = xieite::types::List<Types...>::ZipHelper<Range>::Type;
	};
}

#endif

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer
