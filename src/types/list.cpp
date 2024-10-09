module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:types.List;

import std;
import :concepts.SatisfiedBy;
import :concepts.SatisfiedByAll;
import :concepts.SatisfiedByAny;
import :functors.unroll;
import :functors.Visitor;
import :types.Value;

export namespace xieite::types {
	template<typename... Types>
	struct List {
	public:
		static constexpr std::size_t size = sizeof...(Types);

		template<auto condition>
		static constexpr bool all = xieite::concepts::SatisfiedByAll<condition, Types...>;

		template<auto condition>
		static constexpr bool any = xieite::concepts::SatisfiedByAny<condition, Types...>;

		template<typename Type, auto comparator = []<typename First, std::same_as<First>> {}>
		static constexpr bool has = (... || xieite::concepts::SatisfiedBy<comparator, Type, Types>);

		template<auto selector>
		requires(List::any<selector>)
		static constexpr std::size_t find = ([] {
			std::size_t index = 0;
			(... && (!xieite::concepts::SatisfiedBy<selector, Types> && ++index));
			return index;
		})();

		template<typename Type, auto comparator = []<typename First, std::same_as<First>> {}>
		requires(List::has<Type, comparator>)
		static constexpr std::size_t get = List::find<[]<typename OtherType> requires(xieite::concepts::SatisfiedBy<comparator, Type, OtherType>) {}>;

		template<std::size_t index>
		requires(index < sizeof...(Types))
		using At = decltype(xieite::functors::unroll<Types...>([]<std::size_t... i> {
			return xieite::functors::Visitor([](xieite::types::Value<i>) {
				return std::type_identity<Types>();
			}...)(xieite::types::Value<index>());
		}))::type;

		static constexpr auto apply(auto&& callback)
		XIEITE_ARROW(XIEITE_FORWARD(callback).template operator()<Types...>())

		template<auto validator>
		static constexpr bool satisfies = xieite::concepts::SatisfiedBy<validator, Types...>;

		template<template<typename...> typename Template>
		using To = Template<Types...>;

		template<typename Type>
		using Signature = decltype(([] {
			if constexpr ((... && !std::is_void_v<Types>)) {
				return std::type_identity_t<Type(Types...)>();
			} else {
				static_assert(false, "function signature must not have void parameters");
			}
		})())::type;

		template<typename... OtherTypes>
		using Append = List<Types..., OtherTypes...>;

		template<typename Range>
		using AppendRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(std::type_identity<Template<OtherTypes...>>) {
			return std::type_identity<List::Append<OtherTypes...>>();
		})(std::type_identity<Range>()))::type;

		template<typename... OtherTypes>
		using Prepend = List<OtherTypes..., Types...>;

		template<typename Range>
		using PrependRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(std::type_identity<Template<OtherTypes...>>) {
			return std::type_identity<List::Prepend<OtherTypes...>>();
		})(std::type_identity<Range>()))::type;

		using Reverse = decltype(xieite::functors::unroll<Types...>([]<std::size_t... i> {
			return std::type_identity<List<List::At<sizeof...(Types) - i - 1>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = sizeof...(Types)>
		using Slice = decltype(xieite::functors::unroll<std::min(std::max(start, end), sizeof...(Types)) - std::min(std::min(start, end), sizeof...(Types))>([]<std::size_t... i> {
			return std::type_identity<List<List::At<i + std::min(start, end)>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = start + 1>
		using Erase = List::Slice<0, start>::template AppendRange<List::Slice<end>>;

		template<std::size_t start, std::size_t end, typename... OtherTypes>
		using Replace = List::Slice<0, start>::template Append<OtherTypes...>::template AppendRange<List::Slice<end>>;

		template<std::size_t start, std::size_t end, typename Range>
		using ReplaceRange = List::Slice<0, start>::template AppendRange<Range>::template AppendRange<List::Slice<end>>;

		template<std::size_t index, typename... OtherTypes>
		using Insert = List::Replace<index, index, OtherTypes...>;

		template<std::size_t index, typename Range>
		using InsertRange = List::ReplaceRange<index, index, Range>;

		template<std::size_t index, typename Type>
		using Set = List::Replace<index, index + 1, Type>;

		template<std::size_t index1, std::size_t index2>
		using Swap = List::Set<index1, List::At<index2>>::template Set<index2, List::At<index1>>;

		template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
		using SwapRanges = List::ReplaceRange<start1, end1, List::Slice<start2, end2>>::template ReplaceRange<start2, end2, List::Slice<start1, end1>>;

		template<std::size_t... indices>
		using Arrange = List<List::At<indices>...>;

	private:
		template<auto condition, auto transformer, typename... Results>
		struct TransformHelper
		: std::type_identity<List<Results...>> {
			template<typename Type>
			auto operator->*(std::type_identity<Type>) const noexcept {
				if constexpr (xieite::concepts::SatisfiedBy<condition, Type, Results...>) {
					return decltype(transformer.template operator()<Type, Results...>())::type::apply(([]<typename... Additions> {
						return TransformHelper<condition, transformer, Results..., Additions...>();
					}));
				} else {
					return TransformHelper<condition, transformer, Results...>();
				}
			}
		};

	public:
		template<auto selector>
		using Filter = decltype((List::TransformHelper<selector, []<typename Type> { return std::type_identity<Type>(); }>()->*...->*std::type_identity<Types>()))::type;

		template<auto comparator = []<typename First, typename... Rest> requires(... && !std::same_as<First, Rest>) {}>
		using Deduplicate = List::Filter<comparator>;

		template<std::size_t repetitions>
		using Repeat = decltype(xieite::functors::unroll<repetitions>([]<std::size_t... i> {
			return xieite::functors::Visitor(
				[]<typename... Results>(this auto self, xieite::types::Value<i>) {
					return self.template operator()<Results..., Types...>(xieite::types::Value<i + 1>());
				}...,
				[]<typename... Results>(xieite::types::Value<repetitions>) {
					return std::type_identity<List<Results...>>();
				}
			)(xieite::types::Value<0uz>());
		}))::type;

		template<std::size_t arity, auto transformer>
		requires(!(sizeof...(Types) % arity))
		using Transform = decltype(xieite::functors::unroll<sizeof...(Types) / arity>([]<std::size_t... i> {
			return std::type_identity<List<typename decltype(List::template Slice<arity * i, arity * (i + 1)>::template AppendRange<List::template Slice<0, arity * i>>::apply(transformer))::type...>>();
		}))::type;

		template<std::size_t arity, auto transformer>
		requires(!(sizeof...(Types) % arity))
		using TransformFlat = decltype(xieite::functors::unroll<sizeof...(Types) / arity>([]<std::size_t... i> {
			return (List::TransformHelper<[]<typename...> {}, []<typename Value, typename...> {
				return List::template Slice<arity * Value::value, arity * (Value::value + 1)>::template AppendRange<List::template Slice<0, arity * Value::value>>::apply(transformer);
			}>()->*...->*std::type_identity<xieite::types::Value<i>>());
		}))::type;

		template<typename... OtherTypes>
		requires(sizeof...(Types) == sizeof...(OtherTypes))
		using Zip = decltype(xieite::functors::unroll<Types...>([]<std::size_t... i> {
			return std::type_identity<List<List<List::At<i>, OtherTypes>...>>();
		}))::type;

		template<typename Range>
		using ZipRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(std::type_identity<Template<OtherTypes...>>) {
			return std::type_identity<List::Zip<OtherTypes...>>();
		})(std::type_identity<Range>()))::type;
	};
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer
// TODO: Replace default comparator of deduplicator with `[]<typename First, xieite::concepts::Dissatisfies<[]<std::same_as<First>> {}>...> {}`
