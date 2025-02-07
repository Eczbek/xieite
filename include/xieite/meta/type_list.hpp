#pragma once

#include <algorithm>
#include <concepts>
#include <cstddef>
#include <string_view>
#include <type_traits>
#include "../fn/unroll.hpp"
#include "../math/diff.hpp"
#include "../math/str_num.hpp"
#include "../meta/end.hpp"
#include "../meta/fold.hpp"
#include "../meta/value.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_satisfd.hpp"
#include "../trait/is_satisfd_all.hpp"
#include "../trait/is_satisfd_any.hpp"

namespace xieite {
	template<typename... Ts>
	struct type_list {
		static constexpr std::size_t size = sizeof...(Ts);

		template<auto cond>
		static constexpr bool all = xieite::is_satisfd_all<cond, Ts...>;

		template<auto cond>
		static constexpr bool any = xieite::is_satisfd_any<cond, Ts...>;

		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr bool has = (... || xieite::is_satisfd<cmp, T, Ts>);

		template<std::size_t idx>
		requires(idx < sizeof...(Ts))
		using at = decltype(([]<typename... Us> static {
			return std::type_identity<Us...[idx]>();
		}).template operator()<Ts...>())::type;

		template<auto cond>
		static constexpr std::size_t find_idx = ([] static -> std::size_t {
			std::size_t idx = 0;
			(... && (!xieite::is_satisfd<cond, Ts> && ++idx));
			return idx;
		})();

		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr std::size_t idx_of =
			xieite::type_list<Ts...>
			::find_idx<[]<typename U> requires(xieite::is_satisfd<cmp, T, U>) {}>;

		template<auto cond>
		requires(xieite::is_satisfd_any<cond, Ts...>)
		using find = xieite::type_list<Ts...>::at<xieite::type_list<Ts...>::find_idx<cond>>;

		static constexpr auto apply(auto&& fn, auto&&... args)
			XIEITE_ARROW(XIEITE_FWD(fn).template operator()<Ts...>(XIEITE_FWD(args)...))

		template<auto cond>
		static constexpr bool satisf = xieite::is_satisfd<cond, Ts...>;

		template<template<typename...> typename M>
		using to = M<Ts...>;

		template<typename Ret>
		using as_fn = decltype(([] static {
			if constexpr ((... && !std::is_void_v<Ts>)) {
				return std::type_identity<Ret(Ts...)>();
			} else {
				static_assert(false, "function signature must not have void parameters");
			}
		})())::type;

		template<typename... Us>
		using append = xieite::type_list<Ts..., Us...>;

		template<typename R>
		using append_range = decltype(([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) static {
			return std::type_identity<xieite::type_list<Ts...>::append<Us...>>();
		})(std::type_identity<R>()))::type;

		template<typename... Us>
		using prepend = xieite::type_list<Us..., Ts...>;

		template<typename R>
		using prepend_range = decltype(([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) static {
			return std::type_identity<xieite::type_list<Ts...>::prepend<Us...>>();
		})(std::type_identity<R>()))::type;

		template<xieite::end...>
		using reverse = decltype(xieite::unroll<Ts...>([]<std::size_t... i> static {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<(sizeof...(Ts) - i - 1)>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = sizeof...(Ts)>
		using slice = decltype(xieite::unroll<xieite::diff(start, end)>([]<std::size_t... i> static {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<(i + std::min(start, end))>...>>();
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

		template<std::size_t idx0, std::size_t idx1>
		using swap =
			xieite::type_list<Ts...>
			::set<idx0, xieite::type_list<Ts...>::at<idx1>>
			::template set<idx1, xieite::type_list<Ts...>::at<idx0>>;

		template<std::size_t start0, std::size_t end0, std::size_t start1, std::size_t end1>
		using swap_slices =
			xieite::type_list<Ts...>
			::replace_range<start0, end0, xieite::type_list<Ts...>::slice<start1, end1>>
			::template replace_range<start1, end1, xieite::type_list<Ts...>::slice<start0, end0>>;

		template<std::size_t... idxs>
		using arrange = xieite::type_list<xieite::type_list<Ts...>::at<idxs>...>;

		template<auto cond>
		using filter =
			xieite::fold<
				[]<typename List, typename T> static {
					if constexpr (xieite::is_satisfd<cond, T>) {
						return std::type_identity<typename List::type::template append<T>>();
					} else {
						return List();
					}
				},
				std::type_identity<xieite::type_list<>>,
				std::type_identity<Ts>...
			>::type;

		template<auto cmp = []<typename T, std::same_as<T>> {}>
		using dedup =
			xieite::fold<
				[]<typename List, typename T> static {
					if constexpr (!List::template has<T, cmp>) {
						return std::type_identity<typename List::type::template append<T>>();
					} else {
						return List();
					}
				},
				std::type_identity<xieite::type_list<>>,
				std::type_identity<Ts>...
			>::type;

		template<std::size_t n>
		using repeat = decltype(xieite::unroll<n>([]<std::size_t... i> static {
			return xieite::fold<
				[]<typename List, typename> static {
					return std::type_identity<typename List::type::template append<Ts...>>();
				},
				std::type_identity<xieite::type_list<>>,
				decltype(i)...
			>();
		}))::type;

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using xform = decltype(xieite::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> static {
			return xieite::type_list<
				typename decltype(xieite::type_list<Ts...>
					::template slice<arity * i, arity * (i + 1)>
					::template append_range<
						xieite::type_list<Ts...>
							::template slice<0, arity * i>
					>::apply(fn)
				)::type...
			>();
		}));

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using xform_flat = decltype(xieite::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> static {
			return xieite::fold<
				[]<typename List, typename Idx> static {
					return std::type_identity<typename List::template append_range<
						typename decltype(xieite::type_list<Ts...>
							::template slice<arity * Idx::value, arity * (Idx::value + 1)>
							::template append_range<
								xieite::type_list<Ts...>
								::template slice<0, arity * Idx::value>
							>::apply(fn)
						)::type
					>>();
				},
				std::type_identity<xieite::type_list<>>,
				xieite::value<i>...
			>();
		}))::type;

		template<typename... Us>
		requires(sizeof...(Ts) == sizeof...(Us))
		using zip = decltype(xieite::unroll<Ts...>([]<std::size_t... i> static {
			return xieite::type_list<xieite::type_list<xieite::type_list<Ts...>::at<i>, Us>...>();
		}));

		template<typename R>
		using zip_range = decltype(([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) static {
			return xieite::type_list<Ts...>::zip<Us...>();
		})(std::type_identity<R>()));
	};
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer
