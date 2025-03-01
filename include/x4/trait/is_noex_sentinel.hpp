#pragma once

#include <iterator>
#include <utility>
#include "../trait/hasnoexcpass.hpp"
#include "../trait/hasnoexcpctor.hpp"
#include "../trait/hasnoedfltctor.hpp"
#include "../trait/hasnoexdtor.hpp"
#include "../trait/hasnoexmvass.hpp"
#include "../trait/hasnoexmvctor.hpp"
#include "../trait/isnoexbool_testable.hpp"
#include "../trait/isnoexswap.hpp"

namespace x4 {
	template<typename T, typename U>
	concept isnoexsentinel =
		std::sentinel_for<T, U>
		&& x4::hasnoedfltctor<T>
		&& x4::hasnoexcpctor<T>
		&& x4::hasnoexmvctor<T>
		&& x4::hasnoexdtor<T>
		&& x4::hasnoexcpass<T>
		&& x4::hasnoexmvass<T>
		&& x4::isnoexswap<T>
		&& requires(T s0, const T s1, U i0, const U i1) {
			{ s0 == i0 } noexcept -> x4::isnoexbool_testable;
			{ s0 == i1 } noexcept -> x4::isnoexbool_testable;
			{ s1 == i0 } noexcept -> x4::isnoexbool_testable;
			{ s1 == i1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) == i0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) == i1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) == i0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) == i1 } noexcept -> x4::isnoexbool_testable;
			{ s0 == std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ s0 == std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ s1 == std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ s1 == std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) == std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) == std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) == std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) == std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ i0 == s0 } noexcept -> x4::isnoexbool_testable;
			{ i0 == s1 } noexcept -> x4::isnoexbool_testable;
			{ i1 == s0 } noexcept -> x4::isnoexbool_testable;
			{ i1 == s1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) == s0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) == s1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) == s0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) == s1 } noexcept -> x4::isnoexbool_testable;
			{ i0 == std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ i0 == std::move(s1) } noexcept -> x4::isnoexbool_testable;
			{ i1 == std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ i1 == std::move(s1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) == std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) == std::move(s1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) == std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) == std::move(s1) } noexcept -> x4::isnoexbool_testable;
			{ s0 != i0 } noexcept -> x4::isnoexbool_testable;
			{ s0 != i1 } noexcept -> x4::isnoexbool_testable;
			{ s1 != i0 } noexcept -> x4::isnoexbool_testable;
			{ s1 != i1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) != i0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) != i1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) != i0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) != i1 } noexcept -> x4::isnoexbool_testable;
			{ s0 != std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ s0 != std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ s1 != std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ s1 != std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) != std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s0) != std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) != std::move(i0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(s1) != std::move(i1) } noexcept -> x4::isnoexbool_testable;
			{ i0 != s0 } noexcept -> x4::isnoexbool_testable;
			{ i0 != s1 } noexcept -> x4::isnoexbool_testable;
			{ i1 != s0 } noexcept -> x4::isnoexbool_testable;
			{ i1 != s1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) != s0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) != s1 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) != s0 } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) != s1 } noexcept -> x4::isnoexbool_testable;
			{ i0 != std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ i0 != std::move(s1) } noexcept -> x4::isnoexbool_testable;
			{ i1 != std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ i1 != std::move(s1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) != std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i0) != std::move(s1) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) != std::move(s0) } noexcept -> x4::isnoexbool_testable;
			{ std::move(i1) != std::move(s1) } noexcept -> x4::isnoexbool_testable;
		} && (!std::sized_sentinel_for<T, U>
			|| requires(T s0, const T s1, U i0, const U i1) {
				{ s0 - i0 } noexcept;
				{ s0 - i1 } noexcept;
				{ s1 - i0 } noexcept;
				{ s1 - i1 } noexcept;
				{ std::move(s0) - i0 } noexcept;
				{ std::move(s0) - i1 } noexcept;
				{ std::move(s1) - i0 } noexcept;
				{ std::move(s1) - i1 } noexcept;
				{ s0 - std::move(i0) } noexcept;
				{ s0 - std::move(i1) } noexcept;
				{ s1 - std::move(i0) } noexcept;
				{ s1 - std::move(i1) } noexcept;
				{ std::move(s0) - std::move(i0) } noexcept;
				{ std::move(s0) - std::move(i1) } noexcept;
				{ std::move(s1) - std::move(i0) } noexcept;
				{ std::move(s1) - std::move(i1) } noexcept;
				{ i0 - s0 } noexcept;
				{ i0 - s1 } noexcept;
				{ i1 - s0 } noexcept;
				{ i1 - s1 } noexcept;
				{ std::move(i0) - s0 } noexcept;
				{ std::move(i0) - s1 } noexcept;
				{ std::move(i1) - s0 } noexcept;
				{ std::move(i1) - s1 } noexcept;
				{ i0 - std::move(s0) } noexcept;
				{ i0 - std::move(s1) } noexcept;
				{ i1 - std::move(s0) } noexcept;
				{ i1 - std::move(s1) } noexcept;
				{ std::move(i0) - std::move(s0) } noexcept;
				{ std::move(i0) - std::move(s1) } noexcept;
				{ std::move(i1) - std::move(s0) } noexcept;
				{ std::move(i1) - std::move(s1) } noexcept;
			}
		);
}
