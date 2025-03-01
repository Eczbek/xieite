#pragma once

#include <cstddef>
#include <functional>
#include <ranges>
#include "../ctnr/findnthif.hpp"
#include "../pp/fn.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::ranges::forward_range R, x4::isinvoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::iterator_t<R> findnth(R& range, std::size_t n, std::ranges::range_reference_t<R> value, F&& cmp = {})
	noexcept(x4::isnoexinvoc<F, bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> && x4::isnoexrange<R>) {
		return x4::findnthif(range, n, X4FNLOC(std::invoke_r<bool>(cmp, value, $0)));
	}
}
