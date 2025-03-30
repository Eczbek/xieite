#ifndef DETAIL_XIEITE_HEADER_META_TYPE_LIST
#	define DETAIL_XIEITE_HEADER_META_TYPE_LIST
#
#	include <concepts>
#	include <cstddef>
#	include <type_traits>
#	include "../fn/unroll.hpp"
#	include "../meta/end.hpp"
#	include "../meta/fold.hpp"
#	include "../meta/value.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_satisfd.hpp"
#	include "../trait/is_satisfd_all.hpp"
#	include "../trait/is_satisfd_any.hpp"

namespace xieite {
	template<typename... Ts>
	struct type_list {
	public:
		static constexpr std::size_t size = sizeof...(Ts);

		template<auto cond>
		static constexpr bool all = xieite::is_satisfd_all<cond, Ts...>;

		template<auto cond>
		static constexpr bool any = xieite::is_satisfd_any<cond, Ts...>;

		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr bool has = (... || xieite::is_satisfd<cmp, T, Ts>);

	private:
		template<std::size_t idx, typename... Us>
		using at_impl = Us...[idx];

	public:
		template<std::size_t idx>
		requires(idx < sizeof...(Ts))
		using at = xieite::type_list<Ts...>::at_impl<idx, Ts...>;

		template<auto cond>
		static constexpr std::size_t find_idx = ([] static -> std::size_t {
			std::size_t idx = 0;
			(... && (!xieite::is_satisfd<cond, Ts> && ++idx));
			return idx;
		})();

	private:
		template<typename T, auto cmp>
		static constexpr auto idx_of_impl = []<typename U> requires(xieite::is_satisfd<cmp, T, U>) {};

	public:
		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr std::size_t idx_of = xieite::type_list<Ts...>::find_idx<xieite::type_list<Ts...>::idx_of_impl<T, cmp>>;
	
		template<auto cond>
		requires(xieite::is_satisfd_any<cond, Ts...>)
		using find = xieite::type_list<Ts...>::at<xieite::type_list<Ts...>::find_idx<cond>>;

		static constexpr auto apply(auto&& fn, auto&&... args)
			XIEITE_ARROW(XIEITE_FWD(fn).template operator()<Ts...>(XIEITE_FWD(args)...))

		template<auto cond>
		static constexpr bool satisf = xieite::is_satisfd<cond, Ts...>;

		template<template<typename...> typename M>
		using to = M<Ts...>;

	private:
		template<typename Ret, typename... Us>
		using as_fn_impl = Ret(Us...);

	public:
		template<typename Ret>
		using as_fn = xieite::type_list<Ts...>::as_fn_impl<Ret, Ts...>;

		template<typename... Us>
		using append = xieite::type_list<Ts..., Us...>;

	private:
		template<typename>
		struct append_range_impl;

		template<template<typename...> typename M, typename... Us>
		struct append_range_impl<M<Us...>> : std::type_identity<xieite::type_list<Ts...>::append<Us...>> {};
	
	public:
		template<typename R>
		using append_range = xieite::type_list<Ts...>::append_range_impl<R>::type;

		template<typename... Us>
		using prepend = xieite::type_list<Us..., Ts...>;

	private:
		template<typename>
		struct prepend_range_impl;

		template<template<typename...> typename M, typename... Us>
		struct prepend_range_impl<M<Us...>> : std::type_identity<xieite::type_list<Ts...>::prepend<Us...>> {};

	public:
		template<typename R>
		using prepend_range = xieite::type_list<Ts...>::prepend_range_impl<R>::type;

	private:
		template<int = 0>
		struct reverse_impl : decltype(xieite::unroll<Ts...>([]<std::size_t... i> static {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<(sizeof...(Ts) - i - 1)>...>>();
		})) {};
	
	public:
		template<xieite::end...>
		using reverse = xieite::type_list<Ts...>::reverse_impl<>::type;

	private:
		template<std::size_t start, std::size_t end>
		struct slice_impl : decltype(xieite::unroll<(end - start)>([]<std::size_t... i> static {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<(start + i)>...>>();
		})) {};

	public:
		template<std::size_t start, std::size_t end = sizeof...(Ts)>
		requires((start <= end) && (end <= sizeof...(Ts)))
		using slice = xieite::type_list<Ts...>::slice_impl<start, end>::type;

		template<std::size_t start, std::size_t end = start + 1>
		using erase =
			xieite::type_list<Ts...>::slice<0, start>
			::template append_range<xieite::type_list<Ts...>::slice<end>>;

		template<std::size_t start, std::size_t end, typename... Us>
		using replace =
			xieite::type_list<Ts...>::slice<0, start>
			::template append<Us...>
			::template append_range<xieite::type_list<Ts...>::slice<end>>;

		template<std::size_t start, std::size_t end, typename R>
		using replace_range =
			xieite::type_list<Ts...>::slice<0, start>
			::template append_range<R>
			::template append_range<xieite::type_list<Ts...>::slice<end>>;

		template<std::size_t idx, typename... Us>
		using insert = xieite::type_list<Ts...>::replace<idx, idx, Us...>;

		template<std::size_t idx, typename R>
		using insert_range = xieite::type_list<Ts...>::replace_range<idx, idx, R>;

		template<std::size_t idx, typename T>
		using set = xieite::type_list<Ts...>::replace<idx, (idx + 1), T>;

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

	private:
		template<auto cond>
		struct filter_impl : std::type_identity<xieite::fold<
			[]<typename List, typename T> static {
				if constexpr (xieite::is_satisfd<cond, T>) {
					return typename List::template append<T>();
				} else {
					return List();
				}
			},
			xieite::type_list<>,
			Ts...
		>> {};
	
	public:
		template<auto cond>
		using filter = xieite::type_list<Ts...>::filter_impl<cond>::type;

	private:
		template<auto cmp>
		struct dedup_impl : std::type_identity<xieite::fold<
			[]<typename List, typename T> static {
				if constexpr (!List::template has<T, cmp>) {
					return typename List::template append<T>();
				} else {
					return List();
				}
			},
			xieite::type_list<>,
			Ts...
		>> {};

	public:
		template<auto cmp = []<typename T, std::same_as<T>> {}>
		using dedup = xieite::type_list<Ts...>::dedup_impl<cmp>::type;

	private:
		template<std::size_t n>
		struct repeat_impl : decltype(xieite::unroll<n>([]<std::size_t... i> static {
			return std::type_identity<xieite::fold<
				[]<typename List, typename> static {
					return typename List::template append<Ts...>();
				},
				xieite::type_list<>,
				decltype(i)...
			>>();
		})) {};

	public:
		template<std::size_t n>
		using repeat = xieite::type_list<Ts...>::repeat_impl<n>::type;

	private:
		template<std::size_t arity, auto fn>
		struct xform_impl : decltype(xieite::unroll<(sizeof...(Ts) / arity)>([]<std::size_t... i> static {
			return std::type_identity<xieite::type_list<typename decltype(
				xieite::type_list<Ts...>
				::slice<arity * i, arity * (i + 1)>
				::apply(fn)
			)::type...>>();
		})) {};

	public:
		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using xform = xieite::type_list<Ts...>::xform_impl<arity, fn>::type;

	private:
		template<std::size_t arity, auto fn>
		struct xform_flat_impl : decltype(xieite::unroll<(sizeof...(Ts) / arity)>([]<std::size_t... i> static {
			return std::type_identity<xieite::fold<
				[]<typename List, typename Idx> static {
					return typename List::template append_range<typename decltype(
						xieite::type_list<Ts...>
						::slice<arity * Idx::value, arity * (Idx::value + 1)>
						::apply(fn)
					)::type>();
				},
				xieite::type_list<>,
				xieite::value<i>...
			>>();
		})) {};

	public:
		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using xform_flat = xieite::type_list<Ts...>::xform_flat_impl<arity, fn>::type;

	private:
		template<typename... Us>
		struct zip_impl : decltype(xieite::unroll<Ts...>([]<std::size_t... i> static {
			return xieite::type_list<xieite::type_list<xieite::type_list<xieite::type_list<Ts...>::at<i>, Us>...>>();
		})) {};

	public:
		template<typename... Us>
		requires(sizeof...(Ts) == sizeof...(Us))
		using zip = xieite::type_list<Ts...>::zip_impl<Us...>::type;

	private:
		template<typename>
		struct zip_range_impl;

		template<template<typename...> typename M, typename... Us>
		struct zip_range_impl<M<Us...>> : std::type_identity<xieite::type_list<Ts...>::zip<Us...>> {};

	public:
		template<typename R>
		using zip_range = xieite::type_list<Ts...>::zip_range_impl<R>::type;
	};
}

#endif

// Thanks to eightfold (https://github.com/8ightfold) for helping compact the slicer
