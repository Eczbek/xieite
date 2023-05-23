#ifndef XIEITE_HEADER_META_VERSION
#	define XIEITE_HEADER_META_VERSION

#	include <compare>
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include <xieite/math/toBase.hpp>

namespace xieite::meta {
	struct Version final {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		std::string label;

		constexpr Version(const std::size_t major = 0, const std::size_t minor = 0, const std::size_t patch = 0, const std::string_view label = "") noexcept
		: major(major), minor(minor), patch(patch), label(label) {}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::meta::Version& version) noexcept {
			return (this->major != version.major) ? (this->major <=> version.major) : ((this->minor != version.minor) ? (this->minor <=> version.minor) : (this->patch <=> version.patch));
		}

		[[nodiscard]]
		constexpr std::string string() noexcept {
			std::string result = 'v' + xieite::math::toBase(this->major, 10) + '.' + xieite::math::toBase(this->minor, 10) + '.' + xieite::math::toBase(this->patch, 10);
			if (this->label.size()) {
				result += '-' + this->label;
			}
			return result;
		}
	};
}

#endif
