export module xieite:version;

import std;
import :str_num;

export namespace xieite {
	struct version {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		std::string label;

		[[nodiscard]] constexpr version(std::size_t major = 0, std::size_t minor = 0, std::size_t patch = 0, std::string label = "") noexcept
		: major(major), minor(minor), patch(patch), label(std::move(label)) {}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::version& left, const xieite::version& right) noexcept {
			return (left.major != right.major)
				? (left.major <=> right.major)
				: ((left.minor != right.minor)
					? (left.minor <=> right.minor)
					: (left.patch <=> right.patch));
		}

		[[nodiscard]] friend bool operator==(const xieite::version&, const xieite::version&) = default;

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
