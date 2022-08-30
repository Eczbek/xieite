#include <cmath>
#include <gcufl/BigInt.hpp>


gcufl::BigInt::BigInt(const gcufl::BigInt& other) noexcept : digits(other.digits.begin(), other.digits.end()) {}

gcufl::BigInt gcufl::BigInt::operator+(const gcufl::BigInt& other) const noexcept {
	gcufl::BigInt result;
	bool carry = false;
	for (std::size_t i = 0; i < std::min(digits.size(), other.digits.size()) || carry; ++i) {
		int sum = carry;
		if (i < digits.size())
			sum += digits[i];
		if (i < other.digits.size())
			sum += other.digits[i];
		carry = sum > 9;
		sum -= 10 * carry;
		result.digits.push_back(sum);
	}
	return result;
}
