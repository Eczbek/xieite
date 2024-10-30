export module xieite:big_int;

import std;
import :abs;
import :add_overflow;
import :bit_size;
import :dbl_mul;
import :dbl_uint;
import :is_arith;
import :neg;
import :split_bool;
import :ssize;
import :str_num_config;
import :sub_overflow;
import :try_unsigned;

export namespace xieite {
	template<std::unsigned_integral T = std::uint64_t>
	struct xieite::big_int<T> : std::type_identity<T> {
	public:
		template<std::integral U = int>
		explicit(false) constexpr xieite::big_int<T>(U value = 0) noexcept
		: neg(xieite::neg(value)) {
			xieite::try_unsigned<U> abs = xieite::abs(value);
			do {
				this->data.push_back(static_cast<T>(abs));
				if constexpr (sizeof(U) > sizeof(T)) {
					abs >>= xieite::bit_size<T>;
				} else {
					break;
				}
			} while (abs);
		}

		template<typename U>
		explicit constexpr xieite::big_int<T>(const xieite::big_int<U>& value) noexcept
		: neg(value.neg) {
			if constexpr (sizeof(T) == sizeof(U)) {
				this->data = value.data;
				return;
			}
			if constexpr (sizeof(T) > sizeof(U)) {
				std::size_t shift_bytes = sizeof(T);
				for (U limb : value.data) {
					if (shift_bytes >= sizeof(T)) {
						shift_bytes = 0;
						this->data.push_back(0);
					}
					this->data.back() |= limb << (shift_bytes * std::numeric_limits<unsigned char>::digits);
					shift_bytes += sizeof(U);
				}
				return;
			}
			for (U limb : value.data) {
				std::size_t shift_bytes = 0;
				do {
					this->data.push_back(static_cast<T>(limb >> (shift_bytes * std::numeric_limits<unsigned char>::digits)));
					shift_bytes += sizeof(T);
				} while (shift_bytes < sizeof(U));
			}
			this->trim();
		}

		template<std::ranges::input_range R>
		requires(std::same_as<std::ranges::range_value_t<R>, T>)
		explicit constexpr xieite::big_int<T>(R&& range, bool neg = false) noexcept
		: data(std::ranges::begin(range), std::ranges::end(range)), neg(neg) {
			this->trim();
		}

		explicit(false) constexpr xieite::big_int<T>(std::string_view str, xieite::ssize radix = 10, xieite::str_num_config config = {}) noexcept
		: neg(false) {
			*this = 0;
			if (!radix) {
				return;
			}
			const bool neg = config.neg.contains(str[0]);
			for (char c : str.remove_prefix(neg || config.pos.contains(str[0]))) {
				const std::size_t digit = config.digits.find(c);
				if (digit == std::string::npos) {
					break;
				}
				*this = *this * radix + digit;
			}
			this->neg = neg;
		}

		template<std::integral U>
		[[nodiscard]] explicit constexpr operator U() const noexcept {
			if constexpr (std::same_as<U, bool>) {
				return (this->data.size() > 1) || this->data[0];
			} else {
				U result = 0;
				std::size_t i = 0;
				std::size_t j = 0;
				while (j < xieite::bit_size<U>) {
					result |= static_cast<U>(this->data[i]) << j;
					++i;
					j += xieite::bit_size<T>;
				}
				return this->neg ? -result : result;
			}
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::big_int<T>& left, const xieite::big_int<T>& right) noexcept {
			if (left.neg != right.neg) {
				return right.neg <=> left.neg;
			}
			if (left.neg) {
				if (left.data.size() != right.data.size()) {
					return right.data.size() <=> left.data.size();
				} else {
					return std::lexicographical_compare_three_way(right.data.rbegin(), right.data.rend(), left.data.rbegin(), left.data.rend());
				}
			}
			if (left.data.size() != right.data.size()) {
				return left.data.size() <=> right.data.size();
			} else {
				return std::lexicographical_compare_three_way(left.data.rbegin(), left.data.rend(), right.data.rbegin(), right.data.rend());
			}
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::big_int<T>& left, U right) noexcept {
			return left <=> xieite::big_int<T>(right);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::big_int<T>& left, const xieite::big_int<T>& right) noexcept {
			return std::is_eq(left <=> right);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr bool operator==(const xieite::big_int<T>& left, U right) noexcept {
			return left == xieite::big_int<T>(right);
		}

		[[nodiscard]] constexpr xieite::big_int<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator+(const xieite::big_int<T>& augend, const xieite::big_int<T>& addend) noexcept {
			if (!augend) {
				return addend;
			}
			if (!addend) {
				return augend;
			}
			if (augend.neg != addend.neg) {
				return augend - (-addend);
			}
			std::vector<T> sum_data;
			bool carry = false;
			for (std::size_t i = 0; (i < augend.data.size()) || (i < addend.data.size()) || carry; ++i) {
				const T limb0 = (i < augend.data.size()) * augend.data[i];
				const T limb1 = (i < addend.data.size()) * addend.data[i];
				sum_data.push_back(limb0 + limb1 + carry);
				carry = xieite::add_overflow(limb0, limb1, carry);
			}
			return xieite::big_int<T>(sum_data, augend.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator+(const xieite::big_int<T>& augend, U addend) noexcept {
			return augend + xieite::big_int<T>(addend);
		}

		constexpr xieite::big_int<T>& operator+=(const xieite::big_int<T>& addend) noexcept {
			return *this = *this + addend;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator+=(U addend) noexcept {
			return *this += xieite::big_int<T>(addend);
		}

		constexpr xieite::big_int<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::big_int<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::big_int<T> operator-() const noexcept {
			return xieite::big_int<T>(this->data, !this->neg);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator-(const xieite::big_int<T>& minuend, const xieite::big_int<T>& subtrahend) noexcept {
			if (!subtrahend) {
				return minuend;
			}
			if (!minuend) {
				return -subtrahend;
			}
			if (minuend.neg != subtrahend.neg) {
				return minuend + (-subtrahend);
			}
			if (minuend.neg ? (minuend > subtrahend) : (minuend < subtrahend)) {
				return -(subtrahend - minuend);
			}
			if (minuend == subtrahend) {
				return 0;
			}
			std::vector<T> diff_data;
			bool borrow = false;
			for (std::size_t i = 0; (i < subtrahend.data.size()) || borrow; ++i) {
				const T limb = (i < subtrahend.data.size()) * subtrahend.data[i];
				diff_data.push_back(minuend.data[i] - limb - borrow);
				borrow = (i < (minuend.data.size() - 1)) && xieite::sub_overflow(minuend.data[i], limb, borrow);
			}
			return xieite::big_int<T>(diff_data, minuend.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator-(const xieite::big_int<T>& minuend, U subtrahend) noexcept {
			return minuend - xieite::big_int<T>(subtrahend);
		}

		constexpr xieite::big_int<T>& operator-=(const xieite::big_int<T>& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator-=(U subtrahend) noexcept {
			return *this -= xieite::big_int<T>(subtrahend);
		}

		constexpr xieite::big_int<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::big_int<T>& operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator*(const xieite::big_int<T>& multiplier, const xieite::big_int<T>& multiplicand) noexcept {
			if (!multiplier || !multiplicand) {
				return 0;
			}
			const bool same_sign = multiplier.neg == multiplicand.neg;
			if ((multiplier == 1) || (multiplier == -1)) {
				return same_sign ? multiplicand : -multiplicand;
			}
			if ((multiplicand == 1) || (multiplicand == -1)) {
				return same_sign ? multiplier : -multiplier;
			}
			if (multiplier.pow_of_2()) {
				if (same_sign) {
					return multiplicand.abs() << multiplier.log2();
				}
				return -(multiplicand.abs() << multiplier.log2());
			}
			if (multiplicand.pow_of_2()) {
				if (same_sign) {
					return multiplier.abs() << multiplicand.log2();
				}
				return -(multiplier.abs() << multiplicand.log2());
			}
			xieite::big_int<T> prod;
			for (std::size_t i = multiplier.data.size(); i--;) {
				if (!multiplier.data[i]) {
					continue;
				}
				for (std::size_t j = multiplicand.data.size(); j--;) {
					if (!multiplicand.data[j]) {
						continue;
					}
					const xieite::dbl_uint<T> prod = xieite::dbl_mul(multiplier.data[i], multiplicand.data[j]);
					prod += ((xieite::bit_int<T>(prod.upper) << xieite::bit_size<T>) | prod.lower) << (xieite::bit_int<T>(i) << std::bit_width(xieite::bit_size<T> - 1)) << (xieite::bit_int<T>(j) << std::bit_width(xieite::bit_size<T> - 1));
				}
			}
			prod.neg = multiplier.neg != multiplicand.neg;
			return prod;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator*(const xieite::big_int<T>& multiplier, U multiplicand) noexcept {
			return multiplier * xieite::big_int<T>(multiplicand);
		}

		constexpr xieite::big_int<T>& operator*=(const xieite::big_int<T>& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator*=(U multiplicand) noexcept {
			return *this *= xieite::big_int<T>(multiplicand);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator/(const xieite::big_int<T>& dividend, const xieite::big_int<T>& divisor) {
			if (!divisor) {
				throw std::out_of_range("must not divide by zero");
			}
			if ((dividend.data.size() < 2) && (divisor.data.size() < 2)) {
				return dividend.data[0] / divisor.data[0];
			}
			const bool same_sign = dividend.neg == divisor.neg;
			if ((divisor == 1) || (divisor == -1)) {
				return same_sign ? dividend : -dividend;
			}
			const xieite::big_int<T> dividend_abs = dividend.abs();
			const xieite::big_int<T> divisor_abs = divisor.abs();
			if (!dividend || (dividend_abs < divisor_abs)) {
				return 0;
			}
			if (dividend_abs == divisor_abs) {
				return xieite::split_bool(same_sign);
			}
			if (divisor.pow_of_2()) {
				if (same_sign) {
					return dividend_abs >> divisor.log2();
				}
				return -(dividend_abs >> divisor.log2());
			}
			xieite::big_int<T> rem;
			xieite::big_int<T> quot;
			rem.data.resize(dividend.data.size(), 0);
			quot.data.resize(dividend.data.size(), 0);
			for (std::size_t i = dividend.data.size(); i--;) {
				for (std::size_t j = xieite::bit_size<T>; j--;) {
					rem <<= 1;
					rem.data[0] |= (dividend.data[i] >> j) & 1;
					const bool bit = rem >= divisor_abs;
					rem -= divisor_abs * bit;
					quot.data[i] |= static_cast<T>(bit) << j;
				}
			}
			quot.neg = !same_sign;
			quot.trim();
			return quot;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator/(const xieite::big_int<T>& dividend, U divisor) {
			return dividend / xieite::big_int<T>(divisor);
		}

		constexpr xieite::big_int<T> operator/=(const xieite::big_int<T>& divisor) {
			return *this = *this / divisor;
		}

		template<std::integral U>
		constexpr xieite::big_int<T> operator/=(U divisor) {
			return *this /= xieite::big_int<T>(divisor);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator%(const xieite::big_int<T>& dividend, const xieite::big_int<T>& divisor) {
			if (!divisor) {
				throw std::out_of_range("must not take rem of division by zero");
			}
			const xieite::big_int<T> dividend_abs = dividend.abs();
			const xieite::big_int<T> divisor_abs = divisor.abs();
			if (!dividend || (divisor_abs == 1) || (dividend_abs == divisor_abs)) {
				return 0;
			}
			if (divisor_abs.pow_of_2()) {
				return (dividend_abs & (divisor_abs - 1)) * xieite::split_bool(!dividend.neg);
			}
			if (dividend_abs < divisor_abs) {
				return dividend;
			}
			xieite::big_int<T> rem;
			for (T limb : std::views::reverse(dividend.data)) {
				for (std::size_t j = xieite::bit_size<T>; j--;) {
					rem <<= 1;
					rem.data[0] |= (limb >> j) & 1;
					rem -= divisor_abs * (rem >= divisor_abs);
				}
			}
			rem.neg = dividend.neg;
			return rem;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator%(const xieite::big_int<T>& dividend, U divisor) {
			return dividend % xieite::big_int<T>(divisor);
		}

		constexpr xieite::big_int<T> operator%=(const xieite::big_int<T>& divisor) {
			return *this = *this % divisor;
		}

		template<std::integral U>
		constexpr xieite::big_int<T> operator%=(U divisor) {
			return *this %= xieite::big_int<T>(divisor);
		}

		[[nodiscard]] constexpr xieite::big_int<T> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator&(const xieite::big_int<T>& left, const xieite::big_int<T>& right) noexcept {
			return xieite::big_int<T>::bit_op(left, right, std::bit_and());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator&(const xieite::big_int<T>& left, U right) noexcept {
			return left & xieite::big_int<T>(right);
		}

		constexpr xieite::big_int<T>& operator&=(const xieite::big_int<T>& operand) noexcept {
			return *this = *this & operand;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator&=(U operand) noexcept {
			return *this &= xieite::big_int<T>(operand);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator|(const xieite::big_int<T>& left, const xieite::big_int<T>& right) noexcept {
			return xieite::big_int<T>::bit_op(left, right, std::bit_or());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator|(const xieite::big_int<T>& left, U right) noexcept {
			return left | xieite::big_int<T>(right);
		}

		constexpr xieite::big_int<T>& operator|=(const xieite::big_int<T>& operand) noexcept {
			return *this = *this | operand;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator|=(U operand) noexcept {
			return *this |= xieite::big_int<T>(operand);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator^(const xieite::big_int<T>& left, const xieite::big_int<T>& right) noexcept {
			return xieite::big_int<T>::bit_op(left, right, std::bit_xor());
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator^(const xieite::big_int<T>& left, U right) noexcept {
			return left ^ xieite::big_int<T>(right);
		}

		constexpr xieite::big_int<T>& operator^=(const xieite::big_int<T>& operand) noexcept {
			return *this = *this ^ operand;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator^=(U operand) noexcept {
			return *this ^= xieite::big_int<T>(operand);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator<<(const xieite::big_int<T>& left, const xieite::big_int<T>& right) noexcept {
			if (!left || !right) {
				return left;
			}
			if (right.neg) {
				return left >> -right;
			}
			const std::size_t data_shift = static_cast<std::size_t>(right) >> static_cast<std::size_t>(std::bit_width(xieite::bit_size<T>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(right) & (xieite::bit_size<T> - 1);
			auto result_data = std::vector<T>(data_shift, 0);
			result_data.insert(result_data.end(), left.data.begin(), left.data.end());
			if (bits_shift) {
				T carry = 0;
				for (std::size_t i = 0; i < left.data.size(); ++i) {
					result_data[i + data_shift] = (left.data[i] << bits_shift) | carry;
					carry = left.data[i] >> (xieite::bit_size<T> - bits_shift);
				}
				if (carry) {
					result_data.push_back(carry);
				}
			}
			return xieite::big_int<T>(result_data, left.neg);
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator<<(const xieite::big_int<T>& left, U right) noexcept {
			return left << xieite::big_int<T>(right);
		}

		constexpr xieite::big_int<T>& operator<<=(const xieite::big_int<T>& operand) noexcept {
			return *this = *this << operand;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator<<=(U operand) noexcept {
			return *this <<= xieite::big_int<T>(operand);
		}

		[[nodiscard]] friend constexpr xieite::big_int<T> operator>>(const xieite::big_int<T>& left, const xieite::big_int<T>& right) noexcept {
			if (!left || !right) {
				return left;
			}
			if (right.neg) {
				return left >> -right;
			}
			const std::size_t data_shift = static_cast<std::size_t>(right) >> static_cast<std::size_t>(std::bit_width(xieite::bit_size<T>) - 1);
			const std::size_t bits_shift = static_cast<std::size_t>(right) & (xieite::bit_size<T> - 1);
			if (data_shift >= left.data.size()) {
				return 0;
			}
			auto result_data = std::vector<T>(std::ranges::next(left.data.begin(), static_cast<xieite::ssize>(data_shift), left.data.end()), left.data.end());
			if (bits_shift) {
				T carry = 0;
				for (T& limb : std::views::reverse(result_data)) {
					carry = std::exchange(limb, (limb >> bits_shift) | carry) << (xieite::bit_size<T> - bits_shift);
				}
			}
			return xieite::big_int<T>(result_data, left.neg) - left.neg;
		}

		template<std::integral U>
		[[nodiscard]] friend constexpr xieite::big_int<T> operator>>(const xieite::big_int<T>& left, U right) noexcept {
			return left >> xieite::big_int<T>(right);
		}

		constexpr xieite::big_int<T>& operator>>=(const xieite::big_int<T>& operand) noexcept {
			return *this = *this >> operand;
		}

		template<std::integral U>
		constexpr xieite::big_int<T>& operator>>=(U operand) noexcept {
			return *this >>= xieite::big_int<T>(operand);
		}

		[[nodiscard]] constexpr xieite::big_int<T> abs() const noexcept {
			return xieite::big_int<T>(this->data);
		}

		[[nodiscard]] constexpr xieite::big_int<T> pow(xieite::bit_int<T> exp) const {
			if ((*this == 1) || (exp == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * xieite::split_bool(!!(exp & 1));
			}
			if (!*this || !exp) {
				if (exp.neg) {
					throw std::out_of_range("must not take power of zero to negative exponent");
				}
				return !exp;
			}
			xieite::big_int<T> base = *this;
			xieite::big_int<T> result = 1;
			while (exp > 1) {
				if (exp & 1) {
					result *= base;
					exp = (exp - 1) >> 1;
				} else {
					exp >>= 1;
				}
				base *= base;
			}
			return result * base;
		}

		template<std::integral U>
		[[nodiscard]] constexpr xieite::big_int<T> pow(U exp) const {
			return this->pow(xieite::bit_int<T>(exp));
		}

		[[nodiscard]] constexpr xieite::big_int<T> root(const xieite::big_int<T>& deg) const {
			if (this->neg) {
				throw std::out_of_range("must not take root of negative radicand");
			}
			if (!deg) {
				throw std::out_of_range("must not take root to zeroth degree");
			}
			if (*this == 1) {
				return *this;
			}
			if (deg.neg) {
				return 0;
			}
			xieite::big_int<T> foo = deg - 1;
			xieite::big_int<T> bar = *this;
			xieite::big_int<T> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.pow(foo)) / deg;
			}
			return baz;
		}

		template<std::integral U>
		[[nodiscard]] constexpr xieite::big_int<T> root(U deg) const {
			return this->root(xieite::bit_int<T>(deg));
		}

		[[nodiscard]] constexpr xieite::big_int<T> log(const xieite::big_int<T>& base) const {
			if (!base) {
				return 0;
			}
			if (this->neg) {
				throw std::out_of_range("must not take logarithm of negative anti-logarithm");
			}
			if (base == 1) {
				throw std::out_of_range("must not take logarithm to unary base");
			}
			if (base.neg) {
				throw std::out_of_range("must not take logarithm to neg base");
			}
			return this->log2() / base.log2();
		}

		template<std::integral U>
		[[nodiscard]] constexpr xieite::big_int<T> log(U base) const {
			return this->log(xieite::bit_int<T>(base));
		}

		[[nodiscard]] constexpr std::string str(xieite::ssize radix = 10, xieite::str_num_config config = {}) const noexcept {
			if (!*this || !radix) {
				return std::string(1, config.digits[0]);
			}
			std::string result;
			xieite::big_int<T> value = this->abs();
			if (radix == 1) {
				result = std::string(static_cast<std::size_t>(value), config.digits[1]);
			} else if (radix == -1) {
				result = config.digits[1];
				std::size_t length = static_cast<std::size_t>(value);
				while (--length) {
					result += config.digits[0];
					result += config.digits[1];
				}
			} else {
				do {
					xieite::ssize index = static_cast<xieite::ssize>(value % radix);
					value /= radix;
					if (index < 0) {
						index += radix;
						++value;
					}
					result.insert(0, 1, config.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < config.digits.size())]);
				} while (value);
			}
			if (*this < 0) {
				result.insert(0, 1, config.neg[0]);
			}
			return result;
		}

	private:
		std::vector<T> data;
		bool neg;

		[[nodiscard]] static constexpr xieite::big_int<T> bit_op(xieite::bit_int<T> left, xieite::big_int<T> right, auto fn) noexcept {
			const bool left_neg = left.neg;
			const bool right_neg = right.neg;
			left += left_neg;
			right += right_neg;
			xieite::big_int<T> result;
			result.data.clear();
			result.neg = static_cast<bool>(fn(left_neg, right_neg));
			for (std::size_t i = 0; (i < left.data.size()) || (i < right.data.size()); ++i) {
				const T limb = fn(
					(i < left.data.size())
						? (left_neg ? ~left.data[i] : left.data[i])
						: (std::numeric_limits<T>::max() * left_neg),
					(i < right.data.size())
						? (right_neg ? ~right.data[i] : right.data[i])
						: (std::numeric_limits<T>::max() * right_neg)
				);
				result.data.push_back(result.neg ? ~limb : limb);
			}
			return result - result.neg;
		}

		constexpr void trim() noexcept {
			std::size_t size = this->data.size();
			while ((size > 1) && !this->data.back()) {
				this->data.pop_back();
				--size;
			}
			if (!size) {
				this->data.push_back(0);
			}
			if (!*this) {
				this->neg = false;
			}
		}

		[[nodiscard]] constexpr bool pow_of_2() const noexcept {
			const xieite::big_int<T> abs = this->abs();
			return abs && !(abs & (abs - 1));
		}

		[[nodiscard]] constexpr xieite::big_int<T> log2() const noexcept {
			return xieite::big_int<T>(xieite::bit_size<T>) * (this->data.size() - 1) + std::bit_width(this->data.back()) - 1;
		}
	};
}
