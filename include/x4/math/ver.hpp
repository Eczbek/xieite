#pragma once

#include <compare>
#include <cstddef>
#include <string>
#include <utility>
#include "../math/strn.hpp"

namespace x4 {
	struct ver {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		std::string label;

		[[nodiscard]] constexpr ver(std::size_t major = 0, std::size_t minor = 0, std::size_t patch = 0, std::string label = "") noexcept
		: major(major), minor(minor), patch(patch), label(std::move(label)) {}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const x4::ver& l, const x4::ver& r) noexcept {
			return (l.major != r.major)
				? (l.major <=> r.major)
				: ((l.minor != r.minor)
					? (l.minor <=> r.minor)
					: (l.patch <=> r.patch));
		}

		[[nodiscard]] friend bool operator==(const x4::ver&, const x4::ver&) = default;

		[[nodiscard]] constexpr std::string str() const noexcept {
			std::string result = 'v' + x4::strn(this->major) + '.' + x4::strn(this->minor) + '.' + x4::strn(this->patch);
			if (this->label.size()) {
				result += '-';
				result += this->label;
			}
			return result;
		}
	};
}
