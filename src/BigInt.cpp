
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <gcufl/BigInt.hpp>
#include <span>
#include <stdexcept>
#include <vector>


gcufl::BigInt::BigInt(const gcufl::BigInt& other) noexcept
: digits(other.digits.begin(), other.digits.end()), sign(other.sign) {}

gcufl::BigInt::BigInt(std::span<const std::uint8_t> span, const bool sign) noexcept
: digits(span.rbegin(), span.rend()), sign(sign) {
	while (digits.size() > 1 && !digits.back())
		digits.pop_back();
	if (!digits.size()) {
		digits.push_back(0);
		this->sign = true;
	}
}

gcufl::BigInt& gcufl::BigInt::operator=(const gcufl::BigInt& other) noexcept {
	digits = other.digits;
	sign = other.sign;
	return *this;
}

gcufl::BigInt::operator bool() const noexcept {
	return *this != 0;
}

bool gcufl::BigInt::operator!() const noexcept {
	return !static_cast<bool>(*this);
}

bool gcufl::BigInt::operator==(const gcufl::BigInt& other) const noexcept {
	return sign == other.sign && digits == other.digits;
}

bool gcufl::BigInt::operator!=(const gcufl::BigInt& other) const noexcept {
	return !(*this == other);
}

bool gcufl::BigInt::operator>(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign)
		return sign;
	if (digits.size() != other.digits.size())
		return digits.size() < other.digits.size() != sign;
	for (std::size_t i = digits.size(); i--;)
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

gcufl::BigInt gcufl::BigInt::operator+() const noexcept {
	return *this;
}

gcufl::BigInt gcufl::BigInt::operator+(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign)
		return *this - (-other);
	gcufl::BigInt result;
	result.digits.clear();
	result.sign = sign;
	bool carry = false;
	const std::size_t digitsSize = digits.size();
	const std::size_t otherDigitsSize = other.digits.size();
	const std::size_t maxSize = std::max(digitsSize, otherDigitsSize);
	for (std::size_t i = 0; i < maxSize || carry; ++i) {
		int sum = carry;
		if (i < digitsSize)
			sum += digits[i];
		if (i < otherDigitsSize)
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
		copy.sign = !copy.sign;
	return copy;
}

gcufl::BigInt gcufl::BigInt::operator-(const gcufl::BigInt& other) const noexcept {
	if (sign != other.sign)
		return *this + (-other);
	if (sign && *this < other || !sign && *this > other)
		return -(other - *this);
	gcufl::BigInt result = *this;
	bool borrow = false;
	const std::size_t digitsSize = digits.size();
	const std::size_t otherDigitsSize = other.digits.size();
	for (std::size_t i = 0; i < otherDigitsSize || borrow; ++i) {
		int difference = 10 + digits[i] - borrow;
		if (i < otherDigitsSize)
			difference -= other.digits[i];
		borrow = i < digitsSize - 1 && difference < 10;
		result.digits[i] = difference % 10;
	}
	while (result.digits.size() > 1 && !result.digits.back())
		result.digits.pop_back();
	result.sign = result
		? result.sign != borrow
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
	const bool otherSign = other.sign;
	other.sign = true;
	std::vector<std::uint8_t> prefix;
	const std::size_t digitsSize = digits.size();
	const std::size_t otherDigitsSize = other.digits.size();
	for (std::size_t i = 0; i < digitsSize; ++i) {
		if (!digits[i])
			continue;
		for (std::size_t j = 0; j < otherDigitsSize; ++j) {
			if (!other.digits[j])
				continue;
			prefix.resize(i + j);
			gcufl::BigInt sum = digits[i] * other.digits[j];
			sum.digits.insert(sum.digits.begin(), prefix.begin(), prefix.end());
			result += sum;
		}
	}
	result.sign = sign == otherSign;
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
	const bool otherSign = other.sign;
	other.sign = true;
	if (abs() < other)
		return gcufl::BigInt(0);
	gcufl::BigInt difference;
	std::vector<std::uint8_t> result;
	for (std::size_t i = digits.size(); i--;) {
		if (!difference)
			difference.digits.clear();
		difference.digits.insert(difference.digits.begin(), digits[i]);
		int quotient = 0;
		for (; difference >= other; difference -= other)
			++quotient;
		result.push_back(quotient);
	}
	return gcufl::BigInt(result, sign == otherSign);
}

gcufl::BigInt& gcufl::BigInt::operator/=(const gcufl::BigInt& other) {
	return *this = *this / other;
}

gcufl::BigInt gcufl::BigInt::operator%(gcufl::BigInt other) const {
	const bool otherSign = other.sign;
	gcufl::BigInt result = *this;
	result.sign = other.sign = true;
	if (result == other)
		return gcufl::BigInt(0);
	if (!other)
		throw std::runtime_error("Cannot divide by 0");
	if (result < other)
		return *this;
	for (std::size_t i = digits.size(); i--;) {
		result.digits.insert(result.digits.begin(), digits[i]);
		for (; result >= other; result -= other);
	}
	if (otherSign != sign)
		++result;
	if (result)
		result.sign = otherSign;
	return result;
}

gcufl::BigInt& gcufl::BigInt::operator%=(const gcufl::BigInt& other) {
	return *this = *this % other;
}

gcufl::BigInt gcufl::BigInt::operator~() const noexcept {
	gcufl::BigInt result = *this + 1;
	if (result)
		result.sign = !sign;
	return result;
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
	gcufl::BigInt x = *this;
	gcufl::BigInt y = 1;
	while (other > 1) {
		if (other % 2) {
			y *= x;
			x *= x;
			other = (other - 1) / 2;
		} else {
			x *= x;
			other /= 2;
		}
	}
	return x * y;
}

gcufl::BigInt gcufl::BigInt::root(const gcufl::BigInt& other) const {
	if (*this < 0)
		throw std::runtime_error("Cannot find root of negative");
	gcufl::BigInt k1 = other - 1;
	gcufl::BigInt u = *this;
	gcufl::BigInt s = u + 1;
	while (u < s)  {
		s = u;
		u = (u * k1 + *this / u.pow(k1)) / other;
	}
	return s;
}
