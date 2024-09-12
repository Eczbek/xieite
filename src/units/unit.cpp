export module xieite:units.Operations;

import std;
import :containers.FixedString;
import :types.List;
import :types.Value;

template<double value, template<auto> typename Inverse_, auto operation_>
struct UnitOperation {
	using Inverse = Inverse_<value>;

	[[nodiscard]] static constexpr double operate(const double input) noexcept {
		return operation_(input, value);
	}
};

template<double>
struct UnitSubtract;

template<double>
struct UnitDivide;

template<double value>
struct UnitAdd
: UnitOperation<value, UnitSubtract, std::plus()> {};

template<double value>
struct UnitSubtract
: UnitOperation<value, UnitAdd, std::minus()> {};

template<double value>
struct UnitMultiply
: UnitOperation<value, UnitDivide, std::multiplies()> {};

template<double value>
struct UnitDivide
: UnitOperation<value, UnitMultiply, std::divides()> {};

template<xieite::containers::FixedString type, typename... Operations>
struct UnitValue {
	double value;

	template<template<auto, typename...> typename OtherUnitValue, typename... OtherOperations>
	[[nodiscard]] explicit(false) constexpr operator OtherUnitValue<type, OtherOperations...>() const noexcept {
		double result = this->value;
		(..., (result = Operations::operate(result)));
		xieite::types::List<OtherOperations...>::Reverse::apply([&result]<typename... ReversedOperations> {
			(..., (result = ReversedOperations::Inverse::operate(result)));
		});
		return OtherUnitValue<type, OtherOperations...>(result);
	}
};

export namespace xieite::units {
	template<xieite::containers::FixedString type, auto... operations>
	requires(((sizeof...(operations) % 2) == 0) && ([]<std::size_t... i>(std::index_sequence<i...>) {
		using List = xieite::types::List<xieite::types::Value<operations>...>;
		return std::convertible_to<typename List::At<i * 2>, char> && std::convertible_to<typename List::At<i * 2 + 1, double>;
	})(std::make_index_sequence<sizeof...(operations) / 2>()))
	using Unit = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
		using List = xieite::types::List<xieite::types::Value<operations>...>;
		return std::type_identity<UnitValue<type, decltype(([] {
			static constexpr char operation = static_cast<char>(List::template At<i * 2>::value);
			static constexpr double value = static_cast<double>(List::template At<i * 2 + 1>::value);
			if constexpr (operation == '+') {
				return UnitAdd<value>();
			} else if constexpr (operation == '-') {
				return UnitSubtract<value>();
			} else if constexpr (operation == '*') {
				return UnitMultiply<value>();
			} else if constexpr (operation == '/') {
				return UnitDivide<value>();
			} else {
				static_assert(false, "must use valid operator");
			}
		})())...>>();
	})(std::make_index_sequence<sizeof...(operations) / 2>()))::type;
}
