#ifndef XIEITE_HEADER_RANGES_CONVERT
#	define XIEITE_HEADER_RANGES_CONVERT

#	include <cmath>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../functors/static_cast.hpp"

namespace xieite::ranges {
	template<std::ranges::range RangeFrom, std::ranges::range RangeTo, xieite::concepts::Functable<std::ranges::range_value_t<RangeTo>(std::ranges::range_value_t<RangeFrom>)> Converter = decltype(xieite::functors::staticCast<std::ranges::range_value_t<RangeFrom>, std::ranges::range_value_t<RangeTo>>)>
	[[nodiscard]] constexpr void convert(const RangeFrom& rangeFrom, RangeTo& rangeTo, const Converter& converter = Converter())
	noexcept(xieite::concepts::NoThrowInvocable<Converter, std::ranges::range_value_t<RangeFrom>>) {
		const std::size_t size = std::min(std::ranges::size(rangeFrom), std::ranges::size(rangeTo));
		auto iteratorFrom = std::ranges::begin(rangeFrom);
		auto iteratorTo = std::ranges::begin(rangeTo);
		const auto endFrom = std::ranges::next(iteratorFrom, size, std::ranges::end(rangeFrom));
		const auto endTo = std::ranges::next(iteratorTo, size, std::ranges::end(rangeTo));
		while ((iteratorFrom != endFrom) && (iteratorTo != endTo)) {
			*iteratorTo = std::invoke(converter, *iteratorFrom);
			++iteratorFrom;
			++iteratorTo;
		}
	}
}

#endif
