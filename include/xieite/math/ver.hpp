#ifndef DETAIL_XIEITE_HEADER_MATH_VER
#	define DETAIL_XIEITE_HEADER_MATH_VER
#
#	include <compare>
#	include <cstddef>
#	include <string>
#	include <utility>
#	include "../math/str_num.hpp"

namespace xieite {
	struct ver {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		std::string label;

		[[nodiscard]] constexpr ver(std::size_t major = 0, std::size_t minor = 0, std::size_t patch = 0, std::string label = "") noexcept
		: major(major), minor(minor), patch(patch), label(std::move(label)) {}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::ver& l, const xieite::ver& r) noexcept {
			return (l.major != r.major)
				? (l.major <=> r.major)
				: ((l.minor != r.minor)
					? (l.minor <=> r.minor)
					: (l.patch <=> r.patch));
		}

		[[nodiscard]] friend bool operator==(const xieite::ver&, const xieite::ver&) = default;

		[[nodiscard]] constexpr std::string str() const noexcept {
			std::string result = 'v' + xieite::str_num(this->major) + '.' + xieite::str_num(this->minor) + '.' + xieite::str_num(this->patch);
			if (this->label.size()) {
				result += '-';
				result += this->label;
			}
			return result;
		}
	};
}

#endif
