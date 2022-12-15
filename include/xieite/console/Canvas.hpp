#pragma once
#include <string> // std::string
#include <vector> // std::vector
#include <xieite/console/codes.hpp>
#include <xieite/console/cursorControls.hpp>
#include <xieite/console/moveCursor.hpp>
#include <xieite/console/setBackground.hpp>
#include <xieite/console/setCursorPosition.hpp>
#include <xieite/graphics/Color.hpp>
#include <xieite/graphics/colors.hpp>

namespace xieite::console {
	class Canvas {
	private:
		int width;
		int height;
		std::vector<std::vector<xieite::graphics::Color>> data;

	public:
		constexpr Canvas(const int width, const int height, const xieite::graphics::Color color = xieite::graphics::colors::white) noexcept
		: width(width), height(height) {
			for (int x = 0; x < width; ++x) {
				data.emplace_back();
				for (int y = 0; y < height; ++y)
					data[x].push_back(color);
			}
		}

		constexpr void draw(const int x, const int y, const xieite::graphics::Color color) noexcept {
			if (x < width && x >= 0 && y < height && y >= 0)
				data[x][y] = color;
		}

		constexpr std::string string(const int top = 0, const int left = 0) const noexcept {
			std::string result;
			for (int y = height; y--;) {
				result += xieite::console::setCursorPosition({ top + height - y - 1, left });
				for (int x = 0; x < width; ++x)
					result += xieite::console::setBackground(data[x][y]) + "  ";
				result += std::string(xieite::console::resetColors);
			}
			return result + xieite::console::setCursorPosition({ top + height - 1, left + width * 2 });
		}
	};
}
