export module xieite:math.Version;

import std;
import :math.stringify;

export namespace xieite::math {
	struct Version {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		std::string label;

		constexpr Version(const std::size_t major = 0, const std::size_t minor = 0, const std::size_t patch = 0, const std::string_view label = "") noexcept
		: major(major), minor(minor), patch(patch), label(label) {}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::Version& version1, const xieite::math::Version& version2) noexcept {
			return (version1.major != version2.major) ? (version1.major <=> version2.major) : ((version1.minor != version2.minor) ? (version1.minor <=> version2.minor) : (version1.patch <=> version2.patch));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::Version& version1, const xieite::math::Version& version2) noexcept {
			return std::is_eq(version1 <=> version2);
		}

		[[nodiscard]] constexpr std::string string() const noexcept {
			std::string result = 'v' + xieite::math::stringify(this->major) + '.' + xieite::math::stringify(this->minor) + '.' + xieite::math::stringify(this->patch);
			if (this->label.size()) {
				result += '-';
				result += this->label;
			}
			return result;
		}
	};
}
