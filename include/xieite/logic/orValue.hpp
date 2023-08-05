#ifndef XIEITE_HEADER__LOGIC__OR_VALUE
#	define XIEITE_HEADER__LOGIC__OR_VALUE

#	include <concepts>

namespace xieite::logic {
	template<std::convertible_to<bool> Value>
	[[nodiscard]]
	constexpr Value& orValue(Value& value1, Value& value2)
	noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>)) {
		return (static_cast<bool>(value1) ? value1 : value2);
	}

	template<std::convertible_to<bool> Value>
	[[nodiscard]]
	constexpr const Value& orValue(const Value& value1, const Value& value2)
	noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>)) {
		return (static_cast<bool>(value1) ? value1 : value2);
	}
}

#endif
