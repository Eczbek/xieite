#ifndef XIEITE_HEADER_GEOMETRY_GETANGLE
#	define XIEITE_HEADER_GEOMETRY_GETANGLE

#	include <cmath>
#	include <xieite/concepts/LinearShape.hpp>
#	include <xieite/geometry/Point.hpp>
#	include <xieite/math/pi.hpp>
#	include <xieite/math/tau.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getAngle(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return std::fmod(std::atan2(point1.y - point2.y, point1.x - point2.x) + xieite::math::tau<double>, xieite::math::pi<double>);
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr double getAngle(const LinearShape& linearShape) noexcept {
		return xieite::geometry::getAngle(linearShape.start, linearShape.end);
	}
}

#endif
