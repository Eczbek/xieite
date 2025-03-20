#pragma once

#include <cstddef>
#include <new>
#include <type_traits>
#include "../ctnr/ptr.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_unbounded_array.hpp"

namespace xieite {
	template<typename T>
	requires(!xieite::is_unbounded_array<T>)
	[[nodiscard]] constexpr auto make_ptr()
		XIEITE_ARROW(xieite::ptr<T>(new T))

	template<typename T>
	requires(!xieite::is_unbounded_array<T>)
	[[nodiscard]] constexpr auto make_ptr_noex()
		XIEITE_ARROW(xieite::ptr<T>(new(std::nothrow) T))

	template<typename T>
	requires(!xieite::is_unbounded_array<T>)
	[[nodiscard]] constexpr auto make_ptr_init(auto&&... args)
		XIEITE_ARROW(xieite::ptr<T>(new T(XIEITE_FWD(args)...)))

	template<typename T>
	requires(!xieite::is_unbounded_array<T>)
	[[nodiscard]] constexpr auto make_ptr_noex_init(auto&&... args)
		XIEITE_ARROW(xieite::ptr<T>(new(std::nothrow) T(XIEITE_FWD(args)...)))

	template<xieite::is_unbounded_array A>
	[[nodiscard]] constexpr auto make_ptr(std::size_t n)
		XIEITE_ARROW(xieite::ptr<A>(new std::remove_extent_t<A>[n]))

	template<xieite::is_unbounded_array A>
	[[nodiscard]] constexpr auto make_ptr_noex(std::size_t n)
		XIEITE_ARROW(xieite::ptr<A>(new(std::nothrow) std::remove_extent_t<A>[n]))

	template<xieite::is_unbounded_array A>
	[[nodiscard]] constexpr auto make_ptr_init(std::size_t n, auto&&... args)
		XIEITE_ARROW(xieite::ptr<A>(new std::remove_extent_t<A>[n] { XIEITE_FWD(args)... }))

	template<xieite::is_unbounded_array A>
	[[nodiscard]] constexpr auto make_ptr_noex_init(std::size_t n, auto&&... args)
		XIEITE_ARROW(xieite::ptr<A>(new(std::nothrow) std::remove_extent_t<A>[n] { XIEITE_FWD(args)... }))
}
