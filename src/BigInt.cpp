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

gcufl::BigInt& gcufl::BigInt::operator=(const gcufl::BigInt& other) noexcept {
	digits = other.digits;
	sign = other.sign;
	return *this;
}

gcufl::BigInt gcufl::BigInt::operator+(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign) {
		gcufl::BigInt copy = other;
		copy.sign = sign;
		return *this - copy;
	}
	gcufl::BigInt result;
	result.digits = {};
	result.sign = sign;
	bool carry = false;
	const std::size_t maxSize = std::max(digits.size(), other.digits.size());
	for (std::size_t i = 0; i < maxSize || carry; ++i) {
		int sum = carry;
		if (i < digits.size())
			sum += digits[i];
		if (i < other.digits.size())
			sum += other.digits[i];
		carry = sum > 9;
		result.digits.push_back(sum % 10);
	}
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator+=(const gcufl::BigInt& other) noexcept {
	if (sign != other.sign) {
		gcufl::BigInt copy = other;
		copy.sign = sign;
		return *this -= copy;
	}
	std::vector<uint8_t> oldDigits = digits;
	digits = {};
	bool carry = false;
	const std::size_t maxSize = std::max(oldDigits.size(), other.digits.size());
	for (std::size_t i = 0; i < maxSize || carry; ++i) {
		int sum = carry;
		if (i < oldDigits.size())
			sum += oldDigits[i];
		if (i < other.digits.size())
			sum += other.digits[i];
		carry = sum > 9;
		digits.push_back(sum % 10);
	}
	return *this;
}

gcufl::BigInt& gcufl::BigInt::operator++() noexcept {
	return *this += 1;
}

gcufl::BigInt gcufl::BigInt::operator++(int) noexcept {
	const gcufl::BigInt old = *this;
	++*this;
	return old;
}

gcufl::BigInt gcufl::BigInt::operator-(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign) {
		gcufl::BigInt copy = other;
		copy.sign = sign;
		return *this + copy;
	}
	if (sign && *this < other || !sign && *this > other) {
		gcufl::BigInt result = other - *this;
		result.sign = !sign;
		return result;
	}
	gcufl::BigInt result = *this;
	bool borrow = false;
	for (std::size_t i = 0; i < other.digits.size() || borrow; ++i) {
		int difference = digits[i] - borrow;
		if (i < other.digits.size())
			difference -= other.digits[i];
		if (i < digits.size() - 1)
			borrow = difference < 0;
		result.digits[i] = std::abs(difference);
	}
	result.sign ^= borrow;
	if (!result.digits.size()) {
		result.digits = { 0 };
		result.sign = true;
	}
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator-=(const gcufl::BigInt& other) noexcept {
	if (sign != other.sign) {
		gcufl::BigInt copy = other;
		copy.sign = sign;
		return *this += copy;
	}
	if (sign && *this < other || !sign && *this > other) {
		gcufl::BigInt result = other - *this;
		digits = result.digits;
		sign ^= 1;
		return *this;
	}
	bool borrow = false;
	for (std::size_t i = 0; i < digits.size(); ++i) {
		int difference = -borrow;
		if (i < digits.size())
			difference += digits[i];
		if (i < other.digits.size())
			difference -= other.digits[i];
		borrow = difference < 0;
		digits[i] = std::abs(difference);
	}
	sign ^= borrow;
	if (!digits.size()) {
		digits = { 0 };
		sign = true;
	}
	return *this;
}

gcufl::BigInt& gcufl::BigInt::operator--() noexcept {
	return *this -= 1;
}

gcufl::BigInt gcufl::BigInt::operator--(int) noexcept {
	const gcufl::BigInt old = *this;
	--*this;
	return old;
}

gcufl::BigInt gcufl::BigInt::operator*(gcufl::BigInt other) const noexcept {
	gcufl::BigInt result;
	gcufl::BigInt increment = *this;
	increment.sign ^= !other.sign;
	other.sign = true;
	for (; other > 0; --other)
		result += increment;
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator*=(gcufl::BigInt other) noexcept {
	gcufl::BigInt result = *this * other;
	digits = result.digits;
	sign = result.sign;
	return *this;
}
