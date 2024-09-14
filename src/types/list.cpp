export module xieite:types.List;

import std;
import :concepts.Satisfies;
import :functors.Visitor;
import :types.Value;

export namespace xieite::types {
	template<typename... Types>
	struct List {
		static constexpr std::size_t size = sizeof...(Types);

		template<auto selector>
		static constexpr bool all = (... && xieite::concepts::Satisfies<selector, Types>);

		template<auto selector>
		static constexpr bool any = (... || xieite::concepts::Satisfies<selector, Types>);

		template<typename Type, auto comparator = []<typename First, typename Second> requires(std::same_as<First, Second>) {}>
		static constexpr bool has = (... || xieite::concepts::Satisfies<comparator, Type, Types>);

		template<auto selector>
		requires(xieite::types::List<Types...>::any<selector>)
		static constexpr std::size_t find = ([] {
			std::size_t index = 0;
			(... && (!xieite::concepts::Satisfies<selector, Types> && ++index));
			return index;
		})();

		template<typename Type, auto comparator = []<typename First, typename Second> requires(std::same_as<First, Second>) {}>
		requires(xieite::types::List<Types...>::has<Type, comparator>)
		static constexpr std::size_t get = xieite::types::List<Types...>::find<[]<typename OtherType> requires(xieite::concepts::Satisfies<comparator, Type, OtherType>) {}>;

		template<std::size_t index>
		requires(index < sizeof...(Types))
		using At = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return xieite::functors::Visitor([](xieite::types::Value<i>) {
				return std::type_identity<Types>();
			}...)(xieite::types::Value<index>());
		})(std::index_sequence_for<Types...>()))::type;

		static constexpr auto apply(auto callback) noexcept {
			return callback.template operator()<Types...>();
		}

		template<typename Type>
		using Signature = decltype(([] {
			if constexpr ((... && !std::is_void_v<Types>)) {
				return std::type_identity_t<Type(Types...)>();
			} else {
				static_assert(false, "must not evaluate function signature with void parameters");
			}
		})())::type;

		template<typename... OtherTypes>
		using Append = xieite::types::List<Types..., OtherTypes...>;

		template<typename Range>
		using AppendRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(Template<OtherTypes...>) {
			return std::type_identity<xieite::types::List<Types...>::Append<OtherTypes...>>();
		})(std::declval<Range>()))::type;

		template<typename... OtherTypes>
		using Prepend = xieite::types::List<OtherTypes..., Types...>;

		template<typename Range>
		using PrependRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(Template<OtherTypes...>) {
			return std::type_identity<xieite::types::List<Types...>::Prepend<OtherTypes...>>();
		})(std::declval<Range>()))::type;

		using Reverse = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<xieite::types::List<xieite::types::List<Types...>::At<sizeof...(Types) - i - 1>...>>();
		})(std::index_sequence_for<Types...>()))::type;

		template<std::size_t start, std::size_t end = sizeof...(Types)>
		using Slice = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<xieite::types::List<xieite::types::List<Types...>::At<i + std::min(start, end)>...>>();
		})(std::make_index_sequence<std::min(std::max(start, end), sizeof...(Types)) - std::min(std::min(start, end), sizeof...(Types))>()))::type;

		template<std::size_t start, std::size_t end = start + 1>
		using Erase = xieite::types::List<Types...>::Slice<0, start>::template AppendRange<xieite::types::List<Types...>::Slice<end>>;

		template<std::size_t start, std::size_t end, typename... OtherTypes>
		using Replace = xieite::types::List<Types...>::Slice<0, start>::template Append<OtherTypes...>::template AppendRange<xieite::types::List<Types...>::Slice<end>>;

		template<std::size_t start, std::size_t end, typename Range>
		using ReplaceRange = xieite::types::List<Types...>::Slice<0, start>::template AppendRange<Range>::template AppendRange<xieite::types::List<Types...>::Slice<end>>;

		template<std::size_t index, typename... OtherTypes>
		using Insert = xieite::types::List<Types...>::Replace<index, index, OtherTypes...>;

		template<std::size_t index, typename Range>
		using InsertRange = xieite::types::List<Types...>::ReplaceRange<index, index, Range>;

		template<std::size_t index, typename Type>
		using Set = xieite::types::List<Types...>::Replace<index, index + 1, Type>;

		template<std::size_t index1, std::size_t index2>
		using Swap = xieite::types::List<Types...>::Set<index1, xieite::types::List<Types...>::At<index2>>::template Set<index2, xieite::types::List<Types...>::At<index1>>;

		template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
		using SwapRanges = xieite::types::List<Types...>::ReplaceRange<start1, end1, xieite::types::List<Types...>::Slice<start2, end2>>::template ReplaceRange<start2, end2, xieite::types::List<Types...>::Slice<start1, end1>>;

		template<std::size_t... indices>
		using Arrange = xieite::types::List<xieite::types::List<Types...>::At<indices>...>;

	private:
		template<auto conditional, typename... Results>
		struct FilterHelper
		: std::type_identity<xieite::types::List<Results...>> {
			template<typename Type>
			std::conditional_t<xieite::concepts::Satisfies<conditional, Type, Results...>, xieite::types::List<Types...>::FilterHelper<conditional, Results..., Type>, xieite::types::List<Types...>::FilterHelper<conditional, Results...>> operator->*(xieite::types::List<Types...>::FilterHelper<conditional, Type>) const noexcept;
		};

	public:
		template<auto selector>
		using Filter = decltype((xieite::types::List<Types...>::FilterHelper<selector>()->*...->*xieite::types::List<Types...>::FilterHelper<selector, Types>()));

		template<auto comparator = []<typename First, typename... Rest> requires((... && !std::same_as<First, Rest>)) {}>
		using Deduplicate = xieite::types::List<Types...>::Filter<comparator>;

		template<std::size_t repetitions>
		using Repeat = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return xieite::functors::Visitor([]<typename... Results>(this auto self, xieite::types::Value<i>) {
				return self.template operator()<Results..., Types...>(xieite::types::Value<i + 1>());
			}..., []<typename... Results>(xieite::types::Value<repetitions>) {
				return std::type_identity<xieite::types::List<Results...>>();
			})(xieite::types::Value<0uz>());
		})(std::make_index_sequence<repetitions>()))::type;

		template<auto transformer, std::size_t arity>
		requires((sizeof...(Types) % arity) == 0)
		using Transform = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<xieite::types::List<decltype(transformer.template operator()<xieite::types::List<Types...>::Slice<arity * i, arity * (i + 1)>>())...>>();
		})(std::make_index_sequence<sizeof...(Types) / arity>()))::type;

		template<typename... OtherTypes>
		requires(sizeof...(Types) == sizeof...(OtherTypes))
		using Zip = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<xieite::types::List<xieite::types::List<xieite::types::List<Types...>::At<i>, OtherTypes>...>>();
		})(std::index_sequence_for<Types...>()))::type;

		template<typename Range>
		using ZipRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(Template<OtherTypes...>) {
			return std::type_identity<xieite::types::List<Types...>::Zip<OtherTypes...>>();
		})(std::declval<Range>()))::type;
	};
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer
// TODO: Shorten comparator lambdas to `[]<typename T, std::same_as<T>> {}`
