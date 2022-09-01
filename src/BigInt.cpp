#include <gcufl/BigInt.hpp>


gcufl::BigInt::BigInt(const gcufl::BigInt& other) noexcept : digits(other.digits.begin(), other.digits.end()), sign(other.sign) {}

gcufl::BigInt::operator bool() const noexcept {
	return *this != 0;
}

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
	if (digits.size() != other.digits.size())
		return (digits.size() < other.digits.size()) ^ sign;
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

bool gcufl::BigInt::operator!() const noexcept {
	return !static_cast<bool>(*this);
}

gcufl::BigInt& gcufl::BigInt::operator=(const gcufl::BigInt& other) noexcept {
	digits = other.digits;
	sign = other.sign;
	return *this;
}

gcufl::BigInt gcufl::BigInt::operator+() const noexcept {
	return *this;
}

gcufl::BigInt gcufl::BigInt::operator+(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign)
		return *this - (-other);
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
	return *this = *this + other;
}

gcufl::BigInt& gcufl::BigInt::operator++() noexcept {
	return *this += 1;
}

gcufl::BigInt gcufl::BigInt::operator++(int) noexcept {
	const gcufl::BigInt old = *this;
	++*this;
	return old;
}

gcufl::BigInt gcufl::BigInt::operator-() const noexcept {
	gcufl::BigInt copy = *this;
	if (copy)
		copy.sign ^= 1;
	return copy;
}

gcufl::BigInt gcufl::BigInt::operator-(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign)
		return *this + (-other);
	if (sign && *this < other || !sign && *this > other)
		return -(other - *this);
	gcufl::BigInt result = *this;
	bool borrow = false;
	for (std::size_t i = 0; i < other.digits.size() || borrow; ++i) {
		int difference = 10 + digits[i] - borrow;
		if (i < other.digits.size())
			difference -= other.digits[i];
		borrow = i < digits.size() - 1 && difference < 10;
		result.digits[i] = difference % 10;
	}
	while (result.digits.size() > 1 && !result.digits.back())
		result.digits.pop_back();
	result.sign = result
		? result.sign ^ borrow
		: true;
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator-=(const gcufl::BigInt& other) noexcept {
	return *this = *this - other;
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
	if (other == 1)
		return *this;
	if (!other)
		return gcufl::BigInt(0);
	if (other == -1)
		return -*this;
	gcufl::BigInt result;
	gcufl::BigInt increment = *this;
	increment.sign ^= !other.sign;
	other.sign = true;
	for (; other > 0; --other)
		result += increment;
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator*=(const gcufl::BigInt& other) noexcept {
	return *this = *this * other;
}

gcufl::BigInt gcufl::BigInt::operator/(gcufl::BigInt other) const {
	if (other == 1)
		return *this;
	if (!other)
		throw std::runtime_error("Cannot divide by 0");
	if (other == -1)
		return -*this;
	gcufl::BigInt result;
	gcufl::BigInt copy = abs();
	const bool otherSign = other.sign;
	other.sign = true;
	for (; copy >= other; copy -= other)
		++result;
	result.sign ^= !sign ^ !otherSign;
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator/=(const gcufl::BigInt& other) {
	return *this = *this / other;
}

gcufl::BigInt gcufl::BigInt::operator%(gcufl::BigInt other) const {
	gcufl::BigInt result = *this;
	result.sign = other.sign = true;
	if (result == other)
		return gcufl::BigInt(0);
	if (!other)
		throw std::runtime_error("Cannot divide by 0");
	if (result < other)
		return *this;
	while (result >= other)
		result -= other;
	if (result)
		result.sign ^= !sign;
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator%=(const gcufl::BigInt& other) {
	return *this = *this % other;
}

gcufl::BigInt gcufl::BigInt::abs() const noexcept {
	gcufl::BigInt copy = *this;
	copy.sign = true;
	return copy;
}

gcufl::BigInt gcufl::BigInt::pow(gcufl::BigInt other) const {
	if (*this == 1 || other == 1)
		return *this;
	if (*this == -1)
		return other % 2
			? *this
			: -*this;
	if (!other)
		return gcufl::BigInt(1);
	if (other < 0) {
		if (!*this)
			throw std::runtime_error("Cannot divide by 0");
		return !other;
	}
	if (!*this)
		return !other;
	gcufl::BigInt result = *this;
	for (; other > 1; --other)
		result *= *this;
	return result;
}
