#ifndef XIEITE_HEADER_FUNCTIONS_INFIX
#	define XIEITE_HEADER_FUNCTIONS_INFIX

#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename, auto>
	struct OperatorInfix;

	template<typename Result, typename Parameter, xieite::concepts::Functional<Result(Parameter)> auto callback>
	struct OperatorInfix<Result(Parameter), callback> {
		constexpr Result operator>(const Parameter& argument) const {
			return callback(argument);
		}

		friend constexpr Result operator<(const Parameter& argument, const xieite::functions::OperatorInfix<Result(Parameter), callback>&) {
			return callback(argument);
		}
	};

	template<typename Result, typename LeftParameter, typename RightParameter, xieite::concepts::Functional<Result(LeftParameter, RightParameter)> auto callback>
	class OperatorInfix<Result(LeftParameter, RightParameter), callback> {
	private:
		class Intermediate {
		public:
			constexpr Intermediate(const LeftParameter& leftArgument) noexcept
			: leftArgument(leftArgument) {}

			constexpr Result operator>(const RightParameter& rightArgument) const {
				return callback(leftArgument, rightArgument);
			}

		private:
			const LeftParameter& leftArgument;
		};

	public:
		[[nodiscard]]
		friend constexpr xieite::functions::OperatorInfix<Result(LeftParameter, RightParameter), callback>::Intermediate operator<(const LeftParameter& leftArgument, const xieite::functions::OperatorInfix<Result(LeftParameter, RightParameter), callback>&) noexcept {
			return xieite::functions::OperatorInfix<Result(LeftParameter, RightParameter), callback>::Intermediate(leftArgument);
		}
	};
}

#endif
