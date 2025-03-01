#pragma once

#include <concepts>
#include <cstddef>
#include <type_traits>
#include "../fn/unroll.hpp"
#include "../meta/end.hpp"
#include "../meta/fold.hpp"
#include "../meta/value.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/issatisfd.hpp"
#include "../trait/issatisfd_all.hpp"
#include "../trait/issatisfd_any.hpp"

namespace x4 {
	template<typename... Ts>
	struct type_list {
		static constexpr std::size_t size = sizeof...(Ts);

		template<auto cond>
		static constexpr bool all = x4::issatisfd_all<cond, Ts...>;

		template<auto cond>
		static constexpr bool any = x4::issatisfd_any<cond, Ts...>;

		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr bool has = (... || x4::issatisfd<cmp, T, Ts>);

		template<std::size_t idx>
		requires(idx < sizeof...(Ts))
		using at = decltype(([]<typename... Us> static {
			return std::type_identity<Us...[idx]>();
		}).template operator()<Ts...>())::type;

		template<auto cond>
		static constexpr std::size_t find_idx = ([] static -> std::size_t {
			std::size_t idx = 0;
			(... && (!x4::issatisfd<cond, Ts> && ++idx));
			return idx;
		})();

		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr std::size_t idx_of =
			x4::type_list<Ts...>
			::find_idx<[]<typename U> requires(x4::issatisfd<cmp, T, U>) {}>;

		template<auto cond>
		requires(x4::issatisfd_any<cond, Ts...>)
		using find = x4::type_list<Ts...>::at<x4::type_list<Ts...>::find_idx<cond>>;

		static constexpr auto apply(auto&& fn, auto&&... args)
			X4AR(X4FWD(fn).template operator()<Ts...>(X4FWD(args)...))

		template<auto cond>
		static constexpr bool satisf = x4::issatisfd<cond, Ts...>;

		template<template<typename...> typename M>
		using to = M<Ts...>;

		template<typename Ret>
		using asfn = decltype(([]<typename... Us> static {
			return std::type_identity<Ret(Us...)>();
		}).template operator()<Ts...>())::type;

		template<typename... Us>
		using append = x4::type_list<Ts..., Us...>;

		template<typename R>
		using append_range = decltype(([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) static {
			return std::type_identity<x4::type_list<Ts...>::append<Us...>>();
		})(std::type_identity<R>()))::type;

		template<typename... Us>
		using prepend = x4::type_list<Us..., Ts...>;

		template<typename R>
		using prepend_range = decltype(([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) static {
			return std::type_identity<x4::type_list<Ts...>::prepend<Us...>>();
		})(std::type_identity<R>()))::type;

		template<x4::end...>
		using reverse = decltype(x4::unroll<Ts...>([]<std::size_t... i> static {
			return std::type_identity<x4::type_list<x4::type_list<Ts...>::at<(sizeof...(Ts) - i - 1)>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = sizeof...(Ts)>
		requires((start <= end) && (end <= sizeof...(Ts)))
		using slice = decltype(x4::unroll<(end - start)>([]<std::size_t... i> static {
			return std::type_identity<x4::type_list<x4::type_list<Ts...>::at<(start + i)>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = start + 1>
		using erase =
			x4::type_list<Ts...>
			::slice<0, start>
			::template append_range<
				x4::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t start, std::size_t end, typename... Us>
		using replace =
			x4::type_list<Ts...>
			::slice<0, start>
			::template append<Us...>
			::template append_range<
				x4::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t start, std::size_t end, typename R>
		using replace_range =
			x4::type_list<Ts...>
			::slice<0, start>
			::template append_range<R>
			::template append_range<
				x4::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t idx, typename... Us>
		using insert = x4::type_list<Ts...>::replace<idx, idx, Us...>;

		template<std::size_t idx, typename R>
		using insert_range = x4::type_list<Ts...>::replace_range<idx, idx, R>;

		template<std::size_t idx, typename T>
		using set = x4::type_list<Ts...>::replace<idx, idx + 1, T>;

		template<std::size_t idx0, std::size_t idx1>
		using swap =
			x4::type_list<Ts...>
			::set<idx0, x4::type_list<Ts...>::at<idx1>>
			::template set<idx1, x4::type_list<Ts...>::at<idx0>>;

		template<std::size_t start0, std::size_t end0, std::size_t start1, std::size_t end1>
		using swap_slices =
			x4::type_list<Ts...>
			::replace_range<start0, end0, x4::type_list<Ts...>::slice<start1, end1>>
			::template replace_range<start1, end1, x4::type_list<Ts...>::slice<start0, end0>>;

		template<std::size_t... idxs>
		using arrange = x4::type_list<x4::type_list<Ts...>::at<idxs>...>;

		template<auto cond>
		using filter =
			x4::fold<
				[]<typename List, typename T> static {
					if constexpr (x4::issatisfd<cond, T>) {
						return std::type_identity<typename List::type::template append<T>>();
					} else {
						return List();
					}
				},
				std::type_identity<x4::type_list<>>,
				std::type_identity<Ts>...
			>::type;

		template<auto cmp = []<typename T, std::same_as<T>> {}>
		using dedup =
			x4::fold<
				[]<typename List, typename T> static {
					if constexpr (!List::template has<T, cmp>) {
						return std::type_identity<typename List::type::template append<T>>();
					} else {
						return List();
					}
				},
				std::type_identity<x4::type_list<>>,
				std::type_identity<Ts>...
			>::type;

		template<std::size_t n>
		using repeat = decltype(x4::unroll<n>([]<std::size_t... i> static {
			return x4::fold<
				[]<typename List, typename> static {
					return std::type_identity<typename List::type::template append<Ts...>>();
				},
				std::type_identity<x4::type_list<>>,
				decltype(i)...
			>();
		}))::type;

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using xform = decltype(x4::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> static {
			return x4::type_list<
				typename decltype(
					x4::type_list<Ts...>
					::slice<arity * i, arity * (i + 1)>
					::apply(fn)
				)::type...
			>();
		}));

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using xform_flat = decltype(x4::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> static {
			return x4::fold<
				[]<typename List, typename Idx> static {
					return std::type_identity<typename List::type::template append_range<
						typename decltype(
							x4::type_list<Ts...>
							::slice<arity * Idx::value, arity * (Idx::value + 1)>
							::apply(fn)
						)::type
					>>();
				},
				std::type_identity<x4::type_list<>>,
				x4::value<i>...
			>();
		}))::type;

		template<typename... Us>
		requires(sizeof...(Ts) == sizeof...(Us))
		using zip = decltype(x4::unroll<Ts...>([]<std::size_t... i> static {
			return x4::type_list<x4::type_list<x4::type_list<Ts...>::at<i>, Us>...>();
		}));

		template<typename R>
		using zip_range = decltype(([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) static {
			return x4::type_list<Ts...>::zip<Us...>();
		})(std::type_identity<R>()));
	};
}
