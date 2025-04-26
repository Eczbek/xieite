#ifndef DETAIL_XIEITE_HEADER_DATA_MAKE_PTR
#	define DETAIL_XIEITE_HEADER_DATA_MAKE_PTR
#
#	include <cstddef>
#	include <new>
#	include <type_traits>
#	include "../data/ptr.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_unbounded_array.hpp"

namespace xieite {
	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr auto make_ptr()
		XIEITE_ARROW(xieite::ptr<Value>(new Value))

	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr auto make_ptr_noex()
		XIEITE_ARROW(xieite::ptr<Value>(new(std::nothrow) Value))

	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr auto make_ptr_init(auto&&... args)
		XIEITE_ARROW(xieite::ptr<Value>(new Value(XIEITE_FWD(args)...)))

	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr auto make_ptr_noex_init(auto&&... args)
		XIEITE_ARROW(xieite::ptr<Value>(new(std::nothrow) Value(XIEITE_FWD(args)...)))

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr auto make_ptr(std::size_t length)
		XIEITE_ARROW(xieite::ptr<Array>(new std::remove_extent_t<Array>[length]))

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr auto make_ptr_noex(std::size_t length)
		XIEITE_ARROW(xieite::ptr<Array>(new(std::nothrow) std::remove_extent_t<Array>[length]))

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr auto make_ptr_init(std::size_t length, auto&&... args)
		XIEITE_ARROW(xieite::ptr<Array>(new std::remove_extent_t<Array>[length] { XIEITE_FWD(args)... }))

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr auto make_ptr_noex_init(std::size_t length, auto&&... args)
		XIEITE_ARROW(xieite::ptr<Array>(new(std::nothrow) std::remove_extent_t<Array>[length] { XIEITE_FWD(args)... }))
}

#endif
