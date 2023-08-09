#ifndef XIEITE_HEADER__GEOMETRY__GET__ANGLE
#	define XIEITE_HEADER__GEOMETRY__GET__ANGLE

#	include <cmath>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../math/pi.hpp"
#	include "../math/tau.hpp"

namespace xieite::geometry {
	constexpr double getAngle(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return std::fmod(std::atan2(point1.y - point2.y, point1.x - point2.x) + xieite::math::tau<double>, xieite::math::pi<double>);
	}

	template<xieite::concepts::LinearShape LinearShape>
	constexpr double getAngle(const LinearShape& linearShape) noexcept {
		return xieite::geometry::getAngle(linearShape.start, linearShape.end);
	}
}

#endif
