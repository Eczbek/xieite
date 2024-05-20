#ifndef XIEITE_HEADER_TYPES_LIST
#	define XIEITE_HEADER_TYPES_LIST

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <type_traits>
#	include <utility>
#	include "../traits/is_same_as_any.hpp"

namespace xieite::types {
	template<typename... Types_>
	struct List {
	public:
		static constexpr std::size_t size = sizeof...(Types_);

		template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
		static constexpr std::size_t count = (... + Comparator_<Type_, Types_>::value);

		template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
		static constexpr bool has = (... || Comparator_<Type_, Types_>::value);

		template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
		requires(xieite::types::List<Types_...>::has<Type_, Comparator_>)
		static constexpr std::size_t find = ([] {
			std::size_t index = 0;
			(... && (!Comparator_<Type_, Types_>::value && ++index));
			return index;
		})();

	private:
		template<typename>
		struct AtHelper;

		template<std::size_t... i_>
		struct AtHelper<std::index_sequence<i_...>> {
			template<typename Type_>
			Type_ operator()(std::void_t<decltype(i_)>*..., Type_*, ...);
		};

	public:
		template<std::size_t index_>
		using At = std::invoke_result_t<xieite::types::List<Types_...>::AtHelper<std::make_index_sequence<index_>>, Types_*...>;

		template<template<typename...> typename Template_>
		using Apply = Template_<Types_...>;

		template<typename... OtherTypes_>
		using Append = xieite::types::List<Types_..., OtherTypes_...>;

		template<typename... OtherTypes_>
		using Prepend = xieite::types::List<OtherTypes_..., Types_...>;

		template<std::size_t start_, std::size_t end_ = sizeof...(Types_)>
		using Slice = decltype(([]<std::size_t... i_>(std::index_sequence<i_...>) -> xieite::types::List<xieite::types::List<Types_...>::At<i_ + std::min(start_, end_)>...> {})(std::make_index_sequence<std::min(std::max(start_, end_), sizeof...(Types_)) - std::min(std::min(start_, end_), sizeof...(Types_))>()));

		using Reverse = decltype(([]<std::size_t... i_>(std::index_sequence<i_...>) -> xieite::types::List<xieite::types::List<Types_...>::At<sizeof...(Types_) - i_ - 1>...> {})(std::make_index_sequence<sizeof...(Types_)>()));

	private:
		template<template<typename...> typename Operator_, typename... OtherTypes_>
		struct RangeTypesHelper {
			using Type = Operator_<OtherTypes_...>;
		};

		template<template<typename...> typename Operator_, template<typename...> typename Range_, typename... OtherTypes_>
		struct RangeTypesHelper<Operator_, Range_<OtherTypes_...>>
		: xieite::types::List<Types_...>::RangeTypesHelper<Operator_, OtherTypes_...> {};

	public:
		template<typename Range_>
		using AppendRange = xieite::types::List<Types_...>::RangeTypesHelper<xieite::types::List<Types_...>::Append, Range_>::Type;

		template<typename Range_>
		using PrependRange = xieite::types::List<Types_...>::RangeTypesHelper<xieite::types::List<Types_...>::Prepend, Range_>::Type;

		template<std::size_t start_, std::size_t end_ = start_ + 1>
		using Erase = xieite::types::List<Types_...>::Slice<0, start_>::template AppendRange<xieite::types::List<Types_...>::Slice<end_>>;

		template<std::size_t index_, typename... OtherTypes_>
		using Insert = xieite::types::List<Types_...>::Slice<0, index_>::template Append<OtherTypes_...>::template AppendRange<xieite::types::List<Types_...>::Slice<index_>>;

		template<std::size_t index_, typename OtherType_>
		using Set = xieite::types::List<Types_...>::Erase<index_>::template Insert<index_, OtherType_>;

		template<std::size_t index1_, std::size_t index2_>
		using Swap = xieite::types::List<Types_...>::template Set<index1_, xieite::types::List<Types_...>::At<index2_>>::template Set<index2_, xieite::types::List<Types_...>::At<index1_>>;

	private:
		template<std::size_t index_>
		struct InsertRangeHelper {
			template<typename... OtherTypes_>
			using Type = xieite::types::List<Types_...>::Insert<index_, OtherTypes_...>;
		};

	public:
		template<std::size_t index_, typename Range_>
		using InsertRange = xieite::types::List<Types_...>::RangeTypesHelper<xieite::types::List<Types_...>::InsertRangeHelper<index_>::template Type_, Range_>::Type;

		template<std::size_t start_, std::size_t end_, typename... OtherTypes_>
		using Replace = xieite::types::List<Types_...>::Erase<start_, end_>::template Insert<start_, OtherTypes_...>;

	private:
		template<std::size_t start_, std::size_t end_>
		struct ReplaceRangeHelper {
			template<typename... OtherTypes_>
			using Type = xieite::types::List<Types_...>::Replace<start_, end_, OtherTypes_...>;
		};

	public:
		template<std::size_t start_, std::size_t end_, typename Range_>
		using ReplaceRange = xieite::types::List<Types_...>::RangeTypesHelper<xieite::types::List<Types_...>::ReplaceRangeHelper<start_, end_>::template Type_, Range_>::Type;

		template<std::size_t start1_, std::size_t end1_, std::size_t start2_, std::size_t end2_>
		using SwapRanges = xieite::types::List<Types_...>::ReplaceRange<start1_, end1_, xieite::types::List<Types_...>::Slice<start2_, end2_>>::template ReplaceRange<start2_, end2_, xieite::types::List<Types_...>::Slice<start1_, end1_>>;

	private:
		template<template<typename, typename...> typename Selector_, typename... OtherTypes_>
		struct FilterHelper {
			using Type = xieite::types::List<OtherTypes_...>;

			template<typename Type_>
			std::conditional_t<Selector_<Type_, OtherTypes_...>::value, xieite::types::List<Types_...>::FilterHelper<Selector_, OtherTypes_..., Type_>, xieite::types::List<Types_...>::FilterHelper<Selector_, OtherTypes_...>> operator->*(xieite::types::List<Types_...>::FilterHelper<Selector_, Type_>) const noexcept;
		};

	public:
		template<template<typename, typename...> typename Selector_>
		using Filter = decltype((xieite::types::List<Types_...>::FilterHelper<Selector_>()->*...->*xieite::types::List<Types_...>::FilterHelper<Selector_, Types_>()))::Type;

	private:
		template<template<typename, typename...> typename Comparator_>
		struct UniqueHelper {
			template<typename Type_, typename... OtherTypes_>
			using Selector = std::bool_constant<!Comparator_<Type_, OtherTypes_...>::value>;
		};

	public:
		template<template<typename, typename...> typename Comparator_ = xieite::traits::IsSameAsAny>
		using Unique = typename xieite::types::List<Types_...>::Filter<xieite::types::List<Types_...>::UniqueHelper<Comparator_>::template Selector>;

		template<std::size_t... indices_>
		using Rearrange = xieite::types::List<xieite::types::List<Types_...>::At<indices_>...>;

		template<template<typename...> typename Transformer_, std::size_t arguments_>
		requires((sizeof...(Types_) % arguments_) == 0)
		using Transform = decltype(([]<std::size_t... i_>(std::index_sequence<i_...>) -> xieite::types::List<typename xieite::types::List<Types_...>::Slice<i_ * arguments_, (i_ + 1) * arguments_>::Apply<Transformer_>...> {})(std::make_index_sequence<sizeof...(Types_) / arguments_>()));

	private:
		template<std::size_t count_>
		struct RepeatHelper {
			using Type = xieite::types::List<Types_...>::template AppendRange<typename xieite::types::List<Types_...>::RepeatHelper<count_ - 1>::Type>;
		};

		template<std::size_t count_>
		requires(count_ == 0)
		struct RepeatHelper<count_> {
			using Type = xieite::types::List<>;
		};

	public:
		template<std::size_t count_>
		using Repeat = xieite::types::List<Types_...>::RepeatHelper<count_>::Type;

	private:
		template<typename... OtherTypes_>
		requires(sizeof...(Types_) == sizeof...(OtherTypes_))
		struct ZipHelper {
			using Type = decltype(([]<std::size_t... i_>(std::index_sequence<i_...>) {
				return xieite::types::List<xieite::types::List<xieite::types::List<Types_...>::At<i_>, typename xieite::types::List<OtherTypes_...>::template At<i_>>...>();
			})(std::make_index_sequence<sizeof...(OtherTypes_)>()));
		};

		template<template<typename...> typename Range_, typename... OtherTypes_>
		struct ZipHelper<Range_<OtherTypes_...>>
		: xieite::types::List<Types_...>::ZipHelper<OtherTypes_...> {};

	public:
		template<typename... OtherTypes_>
		using Zip = xieite::types::List<Types_...>::ZipHelper<OtherTypes_...>::Type;

		template<typename Range_>
		using ZipRange = xieite::types::List<Types_...>::ZipHelper<Range_>::Type;
	};
}

#endif

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer
