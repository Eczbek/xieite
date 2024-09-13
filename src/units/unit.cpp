export module xieite:units.Unit;

import std;
import :containers.FixedString;
// import :types.List;
import :types.Value;

template<typename... Types>
struct BootlegTypeList {
	template<std::size_t index, typename First, typename... Rest>
	static constexpr auto atHelper() noexcept {
		if constexpr (index > 0) {
			return atHelper<index - 1, Rest...>();
		} else {
			return std::type_identity<First>();
		}
	}

	template<std::size_t index>
	requires(index < sizeof...(Types))
	using At = decltype(BootlegTypeList<Types...>::atHelper<index, Types...>())::type;

	using Reverse = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
		return std::type_identity<BootlegTypeList<BootlegTypeList<Types...>::At<sizeof...(Types) - i - 1>...>>();
	})(std::index_sequence_for<Types...>()));

	static constexpr auto apply(auto callback) noexcept {
		return callback.template operator()<Types...>();
	}
};

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
struct UnitAdd {
	using Inverse = UnitSubtract<value>;

	[[nodiscard]] static constexpr double operate(const double input) noexcept {
		return input + value;
	}
};

template<double value>
struct UnitSubtract {
	using Inverse = UnitAdd<value>;

	[[nodiscard]] static constexpr double operate(const double input) noexcept {
		return input - value;
	}
};

template<double value>
struct UnitMultiply {
	using Inverse = UnitDivide<value>;

	[[nodiscard]] static constexpr double operate(const double input) noexcept {
		return input * value;
	}
};

template<double value>
struct UnitDivide {
	using Inverse = UnitMultiply<value>;

	[[nodiscard]] static constexpr double operate(const double input) noexcept {
		return input / value;
	}
};

template<xieite::containers::FixedString type, typename... Operations>
struct UnitValue {
	double value;

	template<template<auto, typename...> typename OtherUnitValue, typename... OtherOperations>
	[[nodiscard]] explicit(false) constexpr operator OtherUnitValue<type, OtherOperations...>() const noexcept {
		double result = this->value;
		(..., (result = Operations::operate(result)));
		BootlegTypeList<OtherOperations...>::Reverse::apply([&result]<typename... ReversedOperations> {
			(..., (result = ReversedOperations::Inverse::operate(result)));
		});
		return OtherUnitValue<type, OtherOperations...>(result);
	}
};

export namespace xieite::units {
	template<xieite::containers::FixedString type, auto... operations>
	requires(((sizeof...(operations) % 2) == 0) && ([]<std::size_t... i>(std::index_sequence<i...>) {
		using List = BootlegTypeList<xieite::types::Value<operations>...>;
		return (... && (std::convertible_to<typename List::At<i * 2>::value_type, char> && std::convertible_to<typename List::At<i * 2 + 1>::value_type, double>));
	})(std::make_index_sequence<sizeof...(operations) / 2>()))
	using Unit = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
		using List = BootlegTypeList<xieite::types::Value<operations>...>;
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

// TODO: Remove bootleg type list
