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

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const Version& left, const Version& right) noexcept {
			return (left.major != right.major)
				? (left.major <=> right.major)
				: ((left.minor != right.minor)
					? (left.minor <=> right.minor)
					: (left.patch <=> right.patch));
		}

		[[nodiscard]] friend bool operator==(const Version&, const Version&) = default;

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
