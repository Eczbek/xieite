#ifndef DETAIL_XIEITE_HEADER_META_TYPE_LIST
#	define DETAIL_XIEITE_HEADER_META_TYPE_LIST
#
#	include <concepts>
#	include <cstddef>
#	include "../fn/unroll.hpp"
#	include "../meta/end.hpp"
#	include "../meta/fold.hpp"
#	include "../meta/fold_for.hpp"
#	include "../meta/type_id.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_satisfied.hpp"
#	include "../trait/is_satisfied_all.hpp"
#	include "../trait/is_satisfied_any.hpp"

namespace xieite {
	template<typename... Ts>
	struct type_list {
	public:
		static constexpr std::size_t size = sizeof...(Ts);

		template<auto cond>
		static constexpr bool all = xieite::is_satisfied_all<cond, Ts...>;

		template<auto cond>
		static constexpr bool any = xieite::is_satisfied_any<cond, Ts...>;

		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr bool has = (... || xieite::is_satisfied<cmp, T, Ts>);

	private:
		template<std::size_t idx, typename... Us>
		static xieite::type_id<Us...[idx]> at_impl(xieite::type_id<Us>...);

	public:
		template<std::size_t idx>
		requires(idx < sizeof...(Ts))
		using at = decltype(xieite::type_list<Ts...>::at_impl<idx>(xieite::type_id<Ts>()...))::type;

		template<auto cond>
		static constexpr std::size_t find_idx = ([] -> std::size_t {
			std::size_t idx = 0;
			(... && (!xieite::is_satisfied<cond, Ts> && ++idx));
			return idx;
		})();

		template<typename T, auto cmp = []<typename U, std::same_as<U>> {}>
		static constexpr std::size_t idx_of =
			xieite::type_list<Ts...>
			::find_idx<[]<typename U> requires(xieite::is_satisfied<cmp, T, U>) {}>;
	
		template<auto cond>
		requires(xieite::is_satisfied_any<cond, Ts...>)
		using find = xieite::type_list<Ts...>::at<xieite::type_list<Ts...>::find_idx<cond>>;

		static constexpr auto apply(auto&& fn, auto&&... args)
			XIEITE_ARROW(XIEITE_FWD(fn).template operator()<Ts...>(XIEITE_FWD(args)...))

		template<auto cond>
		static constexpr bool satisfies = xieite::is_satisfied<cond, Ts...>;

		template<template<typename...> typename Template>
		using to = Template<Ts...>;

	private:
		template<typename Ret, typename... Us>
		static xieite::type_id<Ret(Us...)> as_fn_impl(xieite::type_id<Us>...);

	public:
		template<typename Ret>
		using as_fn = decltype(xieite::type_list<Ts...>::as_fn_impl<Ret>(xieite::type_id<Ts>()...))::type;

		template<typename... Us>
		using append = xieite::type_list<Ts..., Us...>;

	private:
		template<typename>
		struct append_range_impl;

		template<template<typename...> typename Template, typename... Us>
		struct append_range_impl<Template<Us...>> : xieite::type_id<xieite::type_list<Ts...>::append<Us...>> {};
	
	public:
		template<typename Range>
		using append_range = xieite::type_list<Ts...>::append_range_impl<Range>::type;

		template<typename... Us>
		using prepend = xieite::type_list<Us..., Ts...>;

	private:
		template<typename>
		struct prepend_range_impl;

		template<template<typename...> typename Template, typename... Us>
		struct prepend_range_impl<Template<Us...>> : xieite::type_id<xieite::type_list<Ts...>::prepend<Us...>> {};

	public:
		template<typename Range>
		using prepend_range = xieite::type_list<Ts...>::prepend_range_impl<Range>::type;

	private:
		template<auto>
		static constexpr auto reverse_impl = []<std::size_t... i> {
			return xieite::type_list<xieite::type_list<Ts...>::at<(sizeof...(Ts) - i - 1)>...>();
		};
	
	public:
		template<xieite::end...>
		using reverse = decltype(xieite::unroll<Ts...>(xieite::type_list<Ts...>::reverse_impl<[] {}>));

	private:
		template<std::size_t start>
		static constexpr auto slice_impl = []<std::size_t... i> {
			return xieite::type_list<xieite::type_list<Ts...>::at<(start + i)>...>();
		};

	public:
		template<std::size_t start, std::size_t end = sizeof...(Ts)>
		requires((start <= end) && (end <= sizeof...(Ts)))
		using slice = decltype(xieite::unroll<(end - start)>(xieite::type_list<Ts...>::slice_impl<start>));

		template<std::size_t start, std::size_t end = start + 1>
		using erase =
			xieite::type_list<Ts...>::slice<0, start>
			::template append_range<xieite::type_list<Ts...>::slice<end>>;

		template<std::size_t start, std::size_t end, typename... Us>
		using replace =
			xieite::type_list<Ts...>::slice<0, start>
			::template append<Us...>
			::template append_range<xieite::type_list<Ts...>::slice<end>>;

		template<std::size_t start, std::size_t end, typename Range>
		using replace_range =
			xieite::type_list<Ts...>::slice<0, start>
			::template append_range<Range>
			::template append_range<xieite::type_list<Ts...>::slice<end>>;

		template<std::size_t idx, typename... Us>
		using insert = xieite::type_list<Ts...>::replace<idx, idx, Us...>;

		template<std::size_t idx, typename Range>
		using insert_range = xieite::type_list<Ts...>::replace_range<idx, idx, Range>;

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
		static constexpr auto filter_impl = []<typename List, typename T> {
			if constexpr (xieite::is_satisfied<cond, T>) {
				return typename List::template append<T>();
			} else {
				return List();
			}
		};
	
	public:
		template<auto cond>
		using filter = xieite::fold<xieite::type_list<Ts...>::filter_impl<cond>, xieite::type_list<>, Ts...>;

	private:
		template<auto cmp>
		static constexpr auto dedup_impl = []<typename List, typename T> {
			if constexpr (!List::template has<T, cmp>) {
				return typename List::template append<T>();
			} else {
				return List();
			}
		};

	public:
		template<auto cmp = []<typename T, std::same_as<T>> {}>
		using dedup = xieite::fold<xieite::type_list<Ts...>::dedup_impl<cmp>, xieite::type_list<>, Ts...>;

	private:
		static constexpr auto repeat_impl = []<typename List, auto> {
			return typename List::template append<Ts...>();
		};

	public:
		template<std::size_t count>
		using repeat = xieite::fold_for<xieite::type_list<Ts...>::repeat_impl, xieite::type_list<>, count>;

	private:
		template<std::size_t arity, auto fn>
		static constexpr auto transform_impl = []<std::size_t... i> {
			return xieite::type_list<typename decltype(
				xieite::type_list<Ts...>
				::slice<(arity * i), (arity * i + arity)>
				::apply(fn)
			)::type...>();
		};

	public:
		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using transform = decltype(xieite::unroll<(sizeof...(Ts) / arity)>(xieite::type_list<Ts...>::transform_impl<arity, fn>));

	private:
		template<std::size_t arity, auto fn>
		static constexpr auto transform_flat_impl = []<typename List, std::size_t i> {
			return typename List::template append_range<typename decltype(
				xieite::type_list<Ts...>
				::slice<(arity * i), (arity * i + arity)>
				::apply(fn)
			)::type>();
		};

	public:
		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using transform_flat = xieite::fold_for<xieite::type_list<Ts...>::transform_flat_impl<arity, fn>, xieite::type_list<>, (sizeof...(Ts) / arity)>;

	private:
		template<typename... Us>
		static constexpr auto zip_impl = []<std::size_t... i> {
			return xieite::type_list<xieite::type_list<xieite::type_list<Ts...>::at<i>, Us>...>();
		};

	public:
		template<typename... Us>
		requires(sizeof...(Ts) == sizeof...(Us))
		using zip = decltype(xieite::unroll<Ts...>(xieite::type_list<Ts...>::zip_impl<Us...>));

	private:
		template<typename>
		struct zip_range_impl;

		template<template<typename...> typename Template, typename... Us>
		struct zip_range_impl<Template<Us...>> : xieite::type_id<xieite::type_list<Ts...>::zip<Us...>> {};

	public:
		template<typename Range>
		using zip_range = xieite::type_list<Ts...>::zip_range_impl<Range>::type;
	};
}

#endif

// Thanks to eightfold (https://github.com/8ightfold) for helping compact the slicer
