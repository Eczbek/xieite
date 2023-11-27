#ifndef XIEITE_HEADER_GRAPHICS_CANVAS
#	define XIEITE_HEADER_GRAPHICS_CANVAS

#	include <cmath>
#	include <cstddef>
#	include <iostream>
#	include <vector>
#	include "../concepts/linear_shape.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/segment.hpp"
#	include "../graphics/color.hpp"
#	include "../math/almost_equal.hpp"
#	include "../streams/position.hpp"
#	include "../streams/standard_handle.hpp"

namespace xieite::graphics {
	class Canvas {
	public:
		xieite::geometry::Point center;
		xieite::geometry::Point radii;
		xieite::streams::StandardHandle handle;

		constexpr Canvas(const xieite::geometry::Point center, const xieite::geometry::Point radii, const xieite::streams::StandardHandle handle = xieite::streams::StandardHandle(std::cin, std::cout)) noexcept
		: center(center), radii(radii), handle(handle), data(static_cast<std::size_t>(this->radii.x * 2) + 1, std::vector<xieite::graphics::Color>(static_cast<std::size_t>(this->radii.y * 2) + 1)) {}

		void print(const xieite::streams::Position position) const noexcept {
			const std::size_t width = this->data.size();
			if (!width) {
				return;
			}
			const std::size_t height = this->data[0].size();
			for (std::size_t y = 0; y < height; ++y) {
				this->handle.setCursorPosition(xieite::streams::Position(position.row + y, position.column));
				for (std::size_t x = 0; x < width; ++x) {
					handle.setBackgroundColor(this->data[x][height - y - 1]);
					handle.outputStream << "  ";
				}
				handle.resetBackgroundColor();
			}
		}

		constexpr void clear(const xieite::graphics::Color& color = xieite::graphics::Color()) noexcept {
			for (std::vector<xieite::graphics::Color>& column : this->data) {
				for (xieite::graphics::Color& item : column) {
					item = color;
				}
			}
		}

		constexpr void draw(const xieite::geometry::Point point, const xieite::graphics::Color& color) noexcept {
			if ((point.x >= this->center.x - this->radii.x) && (point.x <= this->center.x + this->radii.x) && (point.y >= this->center.y - this->radii.y) && (point.y <= this->center.y + this->radii.y)) {
				this->data[static_cast<std::size_t>(std::round(point.x - this->center.x + this->radii.x))][static_cast<std::size_t>(std::round(point.y - this->center.y + this->radii.y))] = color;
			}
		}

		template<xieite::concepts::LinearShape LinearShape>
		constexpr void draw(const LinearShape& line, const xieite::graphics::Color& color) noexcept {
			this->draw(line.start, color);
			this->draw(line.end, color);
			if ((line.slope() <= 1) && (line.slope() >= -1)) {
				for (double x = this->center.x - this->radii.x; x <= this->center.x + this->radii.x; ++x) {
					const double divisor = line.end.x - line.start.x;
					if (!xieite::math::almostEqual(divisor, 0)) {
						const xieite::geometry::Point intersection = xieite::geometry::Point(x, (-(line.start.x * line.end.y - line.start.y * line.end.x) - (line.start.y - line.end.y) * x) / divisor);
						if (std::same_as<LinearShape, xieite::geometry::Segment> ? (line.start.distanceTo(intersection) + line.end.distanceTo(intersection) - line.length() < 1) : ((std::abs((line.end.x - line.start.x) * (intersection.y - line.start.y) - (line.end.y - line.start.y) * (intersection.x - line.start.x)) < 1) && (std::same_as<LinearShape, xieite::geometry::Line> || (std::same_as<LinearShape, xieite::geometry::Ray> && ((line.start.x <= line.end.x) ? (line.start.x <= intersection.x) : (line.start.x > intersection.x)) && ((line.start.y <= line.end.y) ? (line.start.y <= intersection.y) : (line.start.y > intersection.y)))))) {
							this->draw(intersection, color);
						}
					}
				}
			} else {
				for (double y = this->center.y - this->radii.y; y <= this->center.y + this->radii.y; ++y) {
					const double divisor = line.start.y - line.end.y;
					if (!xieite::math::almostEqual(divisor, 0)) {
						const xieite::geometry::Point intersection = xieite::geometry::Point((-(line.start.x * line.end.y - line.start.y * line.end.x) + (line.start.x - line.end.x) * y) / divisor, y);
						if (std::same_as<LinearShape, xieite::geometry::Segment> ? (line.start.distanceTo(intersection) + line.end.distanceTo(intersection) - line.length() < 1) : ((std::abs((line.end.x - line.start.x) * (intersection.y - line.start.y) - (line.end.y - line.start.y) * (intersection.x - line.start.x)) < 1) && (std::same_as<LinearShape, xieite::geometry::Line> || (std::same_as<LinearShape, xieite::geometry::Ray> && ((line.start.x <= line.end.x) ? (line.start.x <= intersection.x) : (line.start.x > intersection.x)) && ((line.start.y <= line.end.y) ? (line.start.y <= intersection.y) : (line.start.y > intersection.y)))))) {
							this->draw(intersection, color);
						}
					}
				}
			}
		}

		constexpr void draw(const xieite::geometry::Polygon& polygon, const xieite::graphics::Color& color) noexcept {
			for (const xieite::geometry::Segment& side : polygon.sides()) {
				this->draw(side, color);
			}
		}

	private:
		std::vector<std::vector<xieite::graphics::Color>> data;
	};
}

#endif
