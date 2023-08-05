#ifndef XIEITE_HEADER__META__VERSION
#	define XIEITE_HEADER__META__VERSION

#	include <compare>
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../math/baseTo.hpp"

namespace xieite::meta {
	struct Version {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		std::string label;

		constexpr Version(const std::size_t major = 0, const std::size_t minor = 0, const std::size_t patch = 0, const std::string_view label = "") noexcept
		: major(major), minor(minor), patch(patch), label(label) {}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::meta::Version& version) const noexcept {
			return ((this->major != version.major) ? (this->major <=> version.major) : ((this->minor != version.minor) ? (this->minor <=> version.minor) : (this->patch <=> version.patch)));
		}

		[[nodiscard]]
		constexpr std::string string() const noexcept {
			std::string result = 'v' + xieite::math::baseTo(10, this->major) + '.' + xieite::math::baseTo(10, this->minor) + '.' + xieite::math::baseTo(this->patch, 10);
			if (this->label.size()) {
				result += '-' + this->label;
			}
			return result;
		}
	};
}

#endif
