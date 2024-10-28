module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:type_list;

import std;
import :diff;
import :fold;
import :is_satisfied_by;
import :is_satisfied_by_all;
import :is_satisfied_by_any;
import :is_satisfies;
import :unroll;
import :value_const;
import :visitor;

export namespace xieite {
	template<typename... Ts>
	struct type_list {
		static constexpr std::size_t size = sizeof...(Ts);

		template<auto cond>
		static constexpr bool all = xieite::is_satisfied_by_all<cond, Ts...>;

		template<auto cond>
		static constexpr bool any = xieite::is_satisfied_by_any<cond, Ts...>;

		template<typename T, auto comp = []<typename U, std::same_as<U>> {}>
		static constexpr bool has = (... || xieite::is_satisfied_by<comp, T, Ts>);

		template<auto fn>
		requires(xieite::type_list<Ts...>::any<fn>)
		static constexpr std::size_t find = ([] {
				std::size_t idx = 0;
				(... && (!xieite::is_satisfied_by<fn, Ts> && ++idx));
				return idx;
			})();

		template<typename T, auto comp = []<typename U, std::same_as<U>> {}>
		requires(xieite::type_list<Ts...>::has<T, comp>)
		static constexpr std::size_t get =
			xieite::type_list<Ts...>
			::find<[]<typename U> requires(xieite::is_satisfied_by<comp, T, U>) {}>;

		template<std::size_t idx>
		requires(idx < sizeof...(Ts))
		using at = decltype(xieite::unroll<Ts...>([]<std::size_t... i> {
			return xieite::visitor(
				[](xieite::value_const<i>) {
					return std::type_identity<Ts>();
				}...
			)(xieite::value_const<idx>());
		}))::type;

		static constexpr auto apply(auto&& fn)
		XIEITE_ARROW(XIEITE_FWD(fn).template operator()<Ts...>())

		template<auto fn>
		static constexpr bool is_satisfies = xieite::is_satisfied_by<fn, Ts...>;

		template<template<typename...> typename M>
		using to = M<Ts...>;

		template<typename Ret>
		using as_fn = decltype(([] {
			if constexpr ((sizeof...(Ts) < 2) || (... && !std::is_void_v<Ts>)) {
				return std::type_identity<Ret(Ts...)>();
			} else {
				static_assert(false, "function signature must not have void parameters");
			}
		})())::type;

		template<typename... Us>
		using append = xieite::type_list<Ts..., Us...>;

		template<typename R>
		using append_range = decltype(
			([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) {
				return std::type_identity<xieite::type_list<Ts...>::append<Us...>>();
			})(std::type_identity<R>())
		)::type;

		template<typename... Us>
		using prepend = xieite::type_list<Us..., Ts...>;

		template<typename R>
		using prepend_range = decltype(
			([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) {
				return std::type_identity<xieite::type_list<Ts...>::prepend<Us...>>();
			})(std::type_identity<R>())
		)::type;

		using reverse = decltype(xieite::unroll<Ts...>([]<std::size_t... i> {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<sizeof...(Ts) - i - 1>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = sizeof...(Ts)>
		using slice = decltype(xieite::unroll<xieite::diff(start, end)>([]<std::size_t... i> {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<i + std::min(start, end)>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = start + 1>
		using erase =
			xieite::type_list<Ts...>
			::slice<0, start>
			::template append_range<
				xieite::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t start, std::size_t end, typename... Us>
		using replace =
			xieite::type_list<Ts...>
			::slice<0, start>
			::template append<Us...>
			::template append_range<
				xieite::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t start, std::size_t end, typename R>
		using replace_range =
			xieite::type_list<Ts...>
			::slice<0, start>
			::template append_range<R>
			::template append_range<
				xieite::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t idx, typename... Us>
		using insert = xieite::type_list<Ts...>::replace<idx, idx, Us...>;

		template<std::size_t idx, typename R>
		using insert_range = xieite::type_list<Ts...>::replace_range<idx, idx, R>;

		template<std::size_t idx, typename T>
		using set = xieite::type_list<Ts...>::replace<idx, idx + 1, T>;

		template<std::size_t idx1, std::size_t idx2>
		using swap =
			xieite::type_list<Ts...>
			::set<idx1, xieite::type_list<Ts...>::at<idx2>>
			::template set<idx2, xieite::type_list<Ts...>::at<idx1>>;

		template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
		using swap_ranges =
			xieite::type_list<Ts...>
			::replace_range<start1, end1, type_list::slice<start2, end2>>
			::template replace_range<start2, end2, type_list::slice<start1, end1>>;

		template<std::size_t... indices>
		using arrange =
			xieite::type_list<
				xieite::type_list<Ts...>::at<indices>...
			>;

		template<auto fn>
		using filter =
			xieite::fold<
				[]<typename T, typename List> {
					if constexpr (xieite::is_satisfies<fn, T>) {
						return std::type_identity<List::append<T>>();
					} else {
						return std::type_identity<List>();
					}
				},
				xieite::type_list<>,
				Ts...
			>;

		template<auto comp = []<typename U, std::same_as<U>> {}>
		using deduplicate = xieite::type_list<Ts...>::filter<[]<typename U, typename... Ret>;

		template<std::size_t n>
		using repeat =
			decltype(xieite::unroll<n>([]<std::size_t... i> {
				return xieite::visitor(
					[]<typename... Us>(this auto self, xieite::value_const<i>) {
						return self.template operator()<Us..., Ts...>(xieite::value_const<i + 1>());
					}...,
					[]<typename... Us>(xieite::value_const<n>) {
						return std::type_identity<type_list<Us...>>();
					}
				)(xieite::value_const<0uz>());
			}))
			::type;

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using transform = decltype(xieite::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> {
			return std::type_identity<
				type_list<typename decltype(
					type_list::template slice<arity * i, arity * (i + 1)>
					::template append_range<type_list::template slice<0, arity * i>>
					::apply(fn)
				)::type...>
			>();
		}))::type;

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using transform_flat = decltype(xieite::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> {
			return xieite::fold<
				[]<typename Index, typename> {
					return type_list
					::template slice<arity * Index::value, arity * (Index::value + 1)>
					::template append_range<type_list::template slice<0, arity * Index::value>>
					::apply(fn);
				},
				type_list<>,
				Ts...
			>();
		}))::type;

		template<typename... Us>
		requires(sizeof...(Ts) == sizeof...(Us))
		using zip = decltype(xieite::unroll<Ts...>([]<std::size_t... i> {
			return std::type_identity<type_list<type_list<type_list::at<i>, Us>...>>();
		}))::type;

		template<typename R>
		using zip_range = decltype(
			([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) {
				return std::type_identity<type_list::zip<Us...>>();
			})(std::type_identity<R>())
		)::type;
	};
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer