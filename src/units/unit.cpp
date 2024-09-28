export module xieite:units.Unit;

import std;
import :concepts.True;
import :containers.FixedString;
import :types.List;
import :types.Value;

export namespace xieite::units {
	template<xieite::containers::FixedString type, auto... operations>
	requires(xieite::types::List<xieite::types::Value<operations>...>::template Transform<2, []<typename Operation, typename Value> { return xieite::types::Value<std::convertible_to<Operation, char> && std::convertible_to<Value, double>>(); }>::all<[]<xieite::concepts::True> {}>)
	struct Unit {
	public:
		double value;

		template<auto... otherOperations>
		[[nodiscard]] explicit(false) constexpr operator Unit<type, otherOperations...>() const noexcept {
			double result = this->value;
			Unit::Wrap::apply([&result]<typename... Operations> {
				(..., (result = Operations().first(result)));
			});
			Unit<type, otherOperations...>::Wrap::Reverse::apply([&result]<typename... OtherOperations> {
				(..., (result = OtherOperations().second(result)));
			});
			return Unit<type, otherOperations...>(result);
		}

	private:
		using Wrap = xieite::types::List<xieite::types::Value<operations>...>::template Transform<2, []<typename Operation, typename Value> {
			static constexpr auto add = [](const double other) { return Value::value + other; };
			static constexpr auto subtract = [](const double other) { return Value::value - other; };
			static constexpr auto multiply = [](const double other) { return Value::value * other; };
			static constexpr auto divide = [](const double other) { return Value::value / other; };
			if constexpr (Operation::value == '+') {
				return std::make_pair(add, subtract);
			} else if constexpr (Operation::value == '-') {
				return std::make_pair(subtract, add);
			} else if constexpr (Operation::value == '*') {
				return std::make_pair(multiply, divide);
			} else if constexpr (Operation::value == '/') {
				return std::make_pair(divide, multiply);
			} else {
				static_assert(false, "must use valid operator");
			}
		}>;
	};
}
