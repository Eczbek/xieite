#pragma once

#include <concepts>
#include <vector>


namespace gcufl {
	struct BigInt {
	public:
		std::vector<short> digits;

		template <std::integral N = int>
		BigInt(N value = 0) noexcept {
			while (value) {
				digits.push_back(value % 10);
				value /= 10;
			}
		}

		BigInt(const gcufl::BigInt& other) noexcept;

		gcufl::BigInt operator+(const gcufl::BigInt& other) const noexcept;
	};
}
