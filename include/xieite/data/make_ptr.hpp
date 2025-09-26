#ifndef DETAIL_XIEITE_HEADER_DATA_MAKE_PTR
#	define DETAIL_XIEITE_HEADER_DATA_MAKE_PTR
#
#	include <cstddef>
#	include <new>
#	include <type_traits>
#	include "../data/ptr.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_unbounded_array.hpp"

namespace xieite {
	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr xieite::ptr<Value> make_ptr() noexcept(false) {
		return xieite::ptr<Value>(new Value);
	}

	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr xieite::ptr<Value> make_ptr_noex() noexcept {
		return xieite::ptr<Value>(new(std::nothrow) Value);
	}

	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr xieite::ptr<Value> make_ptr_init(
		auto&&... args
	) noexcept(false) {
		return xieite::ptr<Value>(new Value(XIEITE_FWD(args)...));
	}

	template<typename Value>
	requires(!xieite::is_unbounded_array<Value>)
	[[nodiscard]] constexpr xieite::ptr<Value> make_ptr_noex_init(
		auto&&... args
	) noexcept {
		return xieite::ptr<Value>(new(std::nothrow) Value(XIEITE_FWD(args)...));
	}

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr xieite::ptr<Array> make_ptr(
		std::size_t length
	) noexcept(false) {
		using Bounded = std::remove_extent_t<Array>[length];
		return xieite::ptr<Array>(new Bounded);
	}

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr xieite::ptr<Array> make_ptr_noex(
		std::size_t length
	) noexcept {
		using Bounded = std::remove_extent_t<Array>[length];
		return xieite::ptr<Array>(new(std::nothrow) Bounded);
	}

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr xieite::ptr<Array> make_ptr_init(
		std::size_t length,
		auto&&... args
	) noexcept(false) {
		using Bounded = std::remove_extent_t<Array>[length];
		return xieite::ptr<Array>(new Bounded { XIEITE_FWD(args)... });
	}

	template<xieite::is_unbounded_array Array>
	[[nodiscard]] constexpr xieite::ptr<Array> make_ptr_noex_init(
		std::size_t length,
		auto&&... args
	) noexcept {
		using Bounded = std::remove_extent_t<Array>[length];
		return xieite::ptr<Array>(new(std::nothrow) Bounded {
			XIEITE_FWD(args)...
		});
	}
}

#endif
