#pragma once

#include <cmath>
#include <concepts>
#include <cstdint>
#include <ostream>
#include <vector>


namespace gcufl {
	struct BigInt {
	private:
		std::vector<uint8_t> digits;
		bool sign;

	public:
		template <std::integral N = int>
		BigInt(N value = 0) noexcept : sign(value >= 0) {
			value = std::abs(value);
			do {
				digits.push_back(value % 10);
				value /= 10;
			} while (value);
		}

		BigInt(const gcufl::BigInt& other) noexcept;

		bool operator==(const gcufl::BigInt& other) const noexcept;

		bool operator!=(const gcufl::BigInt& other) const noexcept;

		bool operator>(const gcufl::BigInt& other) const noexcept;
		
		bool operator>=(const gcufl::BigInt& other) const noexcept;

		bool operator<(const gcufl::BigInt& other) const noexcept;

		bool operator<=(const gcufl::BigInt& other) const noexcept;

		gcufl::BigInt operator+(const gcufl::BigInt& other) const noexcept;

		gcufl::BigInt& operator+=(const gcufl::BigInt& other) noexcept;

		gcufl::BigInt operator-(const gcufl::BigInt& other) const noexcept;

		gcufl::BigInt& operator-=(const gcufl::BigInt& other) noexcept;

		friend std::ostream& operator<<(std::ostream& stream, const gcufl::BigInt& self) {
			if (!self.sign)
				stream << '-';
			for (std::size_t i = self.digits.size(); i > 0; --i)
				stream << static_cast<int>(self.digits[i - 1]);
			return stream;
		}
	};
}
