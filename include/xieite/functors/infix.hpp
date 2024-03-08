#ifndef XIEITE_HEADER_FUNCTORS_INFIX
#	define XIEITE_HEADER_FUNCTORS_INFIX

#	include <concepts>
#	include "../concepts/functable.hpp"
#	include "../functors/function.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename>
	struct Infix;

	template<typename Result, typename Argument>
	struct Infix<Result(Argument)>
	: xieite::functors::Function<Result(Argument)> {
		using xieite::functors::Function<Result(Argument)>::Function;

		template<std::convertible_to<Argument> ArgumentReference>
		friend constexpr Result operator>(const xieite::functors::Infix<Result(Argument)>& infix, ArgumentReference&& argument) {
			return infix(XIEITE_FORWARD(argument));
		}

		template<std::convertible_to<Argument> ArgumentReference>
		friend constexpr Result operator<(ArgumentReference&& argument, const xieite::functors::Infix<Result(Argument)>& infix) {
			return infix(XIEITE_FORWARD(argument));
		}
	};

	template<typename Result, typename LeftArgument, typename RightArgument>
	struct Infix<Result(LeftArgument, RightArgument)>
	: xieite::functors::Function<Result(LeftArgument, RightArgument)> {
	private:
		template<typename LeftArgumentReference>
		struct Intermediate {
		public:
			constexpr Intermediate(const xieite::functors::Infix<Result(LeftArgument, RightArgument)>& infix, LeftArgumentReference&& leftArgument) noexcept
			: infix(infix), leftArgument(XIEITE_FORWARD(leftArgument)) {}

			constexpr auto operator=(const xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgument>&) noexcept = delete;

			template<std::convertible_to<RightArgument> RightArgumentReference>
			friend constexpr Result operator>(xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>&& intermediate, RightArgumentReference&& rightArgument) {
				return intermediate.infix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument));
			}

		private:
			const xieite::functors::Infix<Result(LeftArgument, RightArgument)>& infix;
			LeftArgumentReference&& leftArgument;
		};

	public:
		using xieite::functors::Function<Result(LeftArgument, RightArgument)>::Function;

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference> operator<(LeftArgumentReference&& leftArgument, const xieite::functors::Infix<Result(LeftArgument, RightArgument)>& infix) noexcept {
			return xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>(infix, XIEITE_FORWARD(leftArgument));
		}
	};
}

#endif
