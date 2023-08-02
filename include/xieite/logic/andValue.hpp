#ifndef XIEITE_HEADER_LOGIC_ANDVALUE
#	define XIEITE_HEADER_LOGIC_ANDVALUE

#	include <concepts>

namespace xieite::logic {
	template<std::convertible_to<bool> Value>
	constexpr Value& andValue(Value& value1, Value& value2)
	noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>)) {
		return (static_cast<bool>(value1) ? value2 : value1);
	}

	template<std::convertible_to<bool> Value>
	constexpr const Value& andValue(const Value& value1, const Value& value2)
	noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>)) {
		return (static_cast<bool>(value1) ? value2 : value1);
	}
}

#endif