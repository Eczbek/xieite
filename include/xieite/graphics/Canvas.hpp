#ifndef XIEITE_HEADER__GRAPHICS__CANVAS
#	define XIEITE_HEADER__GRAPHICS__CANVAS

#	include <cmath>
#	include <cstddef>
#	include <vector>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Polygon.hpp"
#	include "../geometry/Segment.hpp"
#	include "../graphics/Color.hpp"
#	include "../math/almostEqual.hpp"
#	include "../streams/Position.hpp"
#	include "../streams/StandardController.hpp"
#	include "../system/terminal.hpp"

namespace xieite::graphics {
	class Canvas {
	public:
		xieite::geometry::Point center;
		xieite::geometry::Point radii;
		xieite::streams::StandardController controller;

		constexpr Canvas(const xieite::geometry::Point center, xieite::geometry::Point radii, const xieite::streams::StandardController controller = xieite::system::terminal) noexcept
		: center(center), radii(radii), controller(controller), data(static_cast<std::size_t>(this->radii.x * 2) + 1, std::vector<xieite::graphics::Color>(static_cast<std::size_t>(this->radii.y * 2) + 1, xieite::graphics::Color(255, 255, 255))) {}

		void print(const xieite::streams::Position position) const noexcept {
			const std::size_t width = this->data.size();
			if (!width) {
				return;
			}
			const std::size_t height = this->data[0].size();
			for (std::size_t y = 0; y < height; ++y) {
				this->controller.setCursorPosition(xieite::streams::Position(position.row + y, position.column));
				for (std::size_t x = 0; x < width; ++x) {
					controller.setBackgroundColor(this->data[x][height - y - 1]);
					controller.outputStream << "  ";
				}
				controller.resetBackgroundColor();
			}
		}

		void clear() noexcept {
			for (std::vector<xieite::graphics::Color>& line : this->data) {
				for (xieite::graphics::Color& color : line) {
					color = xieite::graphics::Color(255, 255, 255);
				}
			}
		}

		void draw(const xieite::geometry::Point point, const xieite::graphics::Color& color) noexcept {
			if ((point.x >= this->center.x - this->radii.x) && (point.x <= this->center.x + this->radii.x) && (point.y >= this->center.y - this->radii.y) && (point.y <= this->center.y + this->radii.y)) {
				this->data[static_cast<std::size_t>(std::round(point.x - this->center.x + this->radii.x))][static_cast<std::size_t>(std::round(point.y - this->center.y + this->radii.y))] = color;
			}
		}

		template<xieite::concepts::LinearShape LinearShape>
		void draw(const LinearShape& line, const xieite::graphics::Color& color) noexcept {
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

		void draw(const xieite::geometry::Polygon& polygon, const xieite::graphics::Color& color) noexcept {
			for (const xieite::geometry::Segment& side : polygon.sides()) {
				this->draw(side, color);
			}
		}

	private:
		std::vector<std::vector<xieite::graphics::Color>> data;
	};
}

#endif
