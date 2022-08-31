#include <algorithm>
#include <gcufl/BigInt.hpp>


gcufl::BigInt::BigInt(const gcufl::BigInt& other) noexcept : digits(other.digits.begin(), other.digits.end()), sign(other.sign) {}

bool gcufl::BigInt::operator==(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign || digits.size() != other.digits.size())
		return false;
	for (std::size_t i = 0; i < digits.size(); ++i)
		if (digits[i] != other.digits[i])
			return false;
	return true;
}

bool gcufl::BigInt::operator!=(const gcufl::BigInt& other) const noexcept {
	return !(*this == other);
}

bool gcufl::BigInt::operator>(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign)
		return sign;
	if (sign && digits.size() > other.digits.size() || !sign && digits.size() < other.digits.size())
		return true;
	for (std::size_t i = 0; i < digits.size(); ++i)
		if (digits[i] != other.digits[i])
			return sign && digits[i] > other.digits[i] || !sign && digits[i] < other.digits[i];
	return false;
}

bool gcufl::BigInt::operator>=(const gcufl::BigInt& other) const noexcept {
	return *this > other || *this == other;
}

bool gcufl::BigInt::operator<(const gcufl::BigInt& other) const noexcept {
	return !(*this >= other);
}

bool gcufl::BigInt::operator<=(const gcufl::BigInt& other) const noexcept {
	return *this < other || *this == other;
}

gcufl::BigInt gcufl::BigInt::operator+(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign) {
		gcufl::BigInt copy(other);
		copy.sign = sign;
		return *this - copy;
	}
	gcufl::BigInt result;
	result.digits = {};
	result.sign = sign;
	bool carry = false;
	const std::size_t minSize = std::min(digits.size(), other.digits.size());
	for (std::size_t i = 0; i < minSize || carry; ++i) {
		short sum = carry;
		if (i < digits.size())
			sum += digits[i];
		if (i < other.digits.size())
			sum += other.digits[i];
		carry = sum > 9;
		result.digits.push_back(sum % 10);
	}
	return result;
}

gcufl::BigInt gcufl::BigInt::operator-(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign) {
		gcufl::BigInt copy(other);
		copy.sign = sign;
		return *this + copy;
	}
	if (sign && *this < other || !sign && *this > other) {
		gcufl::BigInt result(other - *this);
		result.sign = !sign;
		return result;
	}
	gcufl::BigInt result;
	result.digits = {};
	result.sign = sign;
	bool borrow = false;
	for (std::size_t i = 0; i < digits.size(); ++i) {
		short difference = -borrow;
		if (i < digits.size())
			difference += digits[i];
		if (i < other.digits.size())
			difference -= other.digits[i];
		borrow = difference < 0;
		result.digits.push_back(std::abs(difference));
	}
	result.sign ^= borrow;
	if (!result.digits.size()) {
		result.digits = { 0 };
		result.sign = true;
	}
	return result;
}
