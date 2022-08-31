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
		BigInt(const gcufl::BigInt& other) noexcept;

		template <std::integral N = int>
		BigInt(N value = 0) noexcept : sign(value >= 0) {
			value = std::abs(value);
			do {
				digits.push_back(value % 10);
				value /= 10;
			} while (value);
		}

		bool operator==(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		bool operator==(const N value) const noexcept {
			return *this == gcufl::BigInt(value);
		}

		bool operator!=(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		bool operator!=(const N value) const noexcept {
			return *this != gcufl::BigInt(value);
		}

		bool operator>(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		bool operator>(const N value) const noexcept {
			return *this > gcufl::BigInt(value);
		}
		
		bool operator>=(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		bool operator>=(const N value) const noexcept {
			return *this >= gcufl::BigInt(value);
		}

		bool operator<(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		bool operator<(const N value) const noexcept {
			return *this < gcufl::BigInt(value);
		}

		bool operator<=(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		bool operator<=(const N value) const noexcept {
			return *this <= gcufl::BigInt(value);
		}

		gcufl::BigInt& operator=(const gcufl::BigInt& other) noexcept;

		template <std::integral N>
		gcufl::BigInt& operator=(const N value) noexcept {
			const gcufl::BigInt other(value);
			digits = other.digits;
			sign = other.sign;
			return *this;
		}

		gcufl::BigInt operator+(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		gcufl::BigInt operator+(const N value) const noexcept {
			return *this + gcufl::BigInt(value);
		}

		gcufl::BigInt& operator+=(const gcufl::BigInt& other) noexcept;

		template <std::integral N>
		gcufl::BigInt& operator+=(const N value) noexcept {
			return *this += gcufl::BigInt(value);
		}

		gcufl::BigInt& operator++() noexcept;

		gcufl::BigInt operator++(int) noexcept;

		gcufl::BigInt operator-(const gcufl::BigInt& other) const noexcept;

		template <std::integral N>
		gcufl::BigInt operator-(const N value) const noexcept {
			return *this - gcufl::BigInt(value);
		}

		gcufl::BigInt& operator-=(const gcufl::BigInt& other) noexcept;

		template <std::integral N>
		gcufl::BigInt& operator-=(const N value) noexcept {
			return *this -= gcufl::BigInt(value);
		}

		gcufl::BigInt& operator--() noexcept;

		gcufl::BigInt operator--(int) noexcept;

		gcufl::BigInt operator*(gcufl::BigInt other) const noexcept;

		template <std::integral N>
		gcufl::BigInt operator*(const N value) const noexcept {
			return *this * gcufl::BigInt(value);
		}

		gcufl::BigInt& operator*=(gcufl::BigInt other) noexcept;

		template <std::integral N>
		gcufl::BigInt& operator*=(const N value) noexcept {
			return *this *= gcufl::BigInt(value);
		}

		friend std::ostream& operator<<(std::ostream& stream, const gcufl::BigInt& self) {
			if (!self.sign)
				stream << '-';
			for (std::size_t i = self.digits.size(); i > 0; --i)
				stream << static_cast<int>(self.digits[i - 1]);
			return stream;
		}
	};
}
