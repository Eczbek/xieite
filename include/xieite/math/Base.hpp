#ifndef XIEITE_HEADER__MATH__BASE
#	define XIEITE_HEADER__MATH__BASE

#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../strings/lowercase.hpp"

namespace xieite::math {
	class Base {
	public:
		int radix;
		char negativeSign;
		
		constexpr Base(const int radix, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char negativeSign = '-', const bool caseSensitive = false) noexcept
		: radix(radix), digits(caseSensitive ? digits : xieite::strings::lowercase(digits)), negativeSign(negativeSign), caseSensitive(caseSensitive) {}
		
		constexpr char digit(const std::size_t position) const noexcept {
			return this->digits[position * (position < this->digits.size())];
		}
		
		constexpr std::size_t position(const char digit) const noexcept {
			const std::size_t index = this->digits.find(this->caseSensitive ? digit : xieite::strings::lowercase(digit));
			return index * (index != std::string::npos);
		}
			
	private:
		std::string digits;
		bool caseSensitive;
	};
}

#endif
