#ifndef XIEITE_HEADER__META__VERSION
#	define XIEITE_HEADER__META__VERSION

#	include <compare>
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../math/toBase.hpp"

namespace xieite::meta {
	struct Version {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		std::string label;

		constexpr Version(const std::size_t major = 0, const std::size_t minor = 0, const std::size_t patch = 0, const std::string_view label = "") noexcept
		: major(major), minor(minor), patch(patch), label(label) {}

		friend constexpr std::strong_ordering operator<=>(const xieite::meta::Version& version1, const xieite::meta::Version& version2) noexcept {
			return (version1.major != version2.major) ? (version1.major <=> version2.major) : ((version1.minor != version2.minor) ? (version1.minor <=> version2.minor) : (version1.patch <=> version2.patch));
		}
		
		friend constexpr bool operator==(const xieite::meta::Version& version1, const xieite::meta::Version& version2) noexcept {
			return std::is_eq(version1 <=> version2);
		}

		constexpr std::string string() const noexcept {
			std::string result = 'v' + xieite::math::toBase(10, this->major) + '.' + xieite::math::toBase(10, this->minor) + '.' + xieite::math::toBase(10, this->patch);
			if (this->label.size()) {
				result += '-' + this->label;
			}
			return result;
		}
	};
}

#endif
