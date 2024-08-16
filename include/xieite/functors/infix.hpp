#ifndef XIEITE_HEADER_FUNCTORS_INFIX
#	define XIEITE_HEADER_FUNCTORS_INFIX

#	include <concepts>
#	include "../concepts/functor.hpp"
#	include "../functors/function.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename>
	struct Infix;

	template<typename Return, typename Argument>
	struct Infix<Return(Argument)>
	: xieite::functors::Function<Return(Argument)> {
		using xieite::functors::Function<Return(Argument)>::Function;

		template<std::convertible_to<Argument> ArgumentReference>
		friend constexpr Return operator>(const xieite::functors::Infix<Return(Argument)>& infix, ArgumentReference&& argument) {
			return infix(XIEITE_FORWARD(argument));
		}

		template<std::convertible_to<Argument> ArgumentReference>
		friend constexpr Return operator<(ArgumentReference&& argument, const xieite::functors::Infix<Return(Argument)>& infix) {
			return infix(XIEITE_FORWARD(argument));
		}
	};

	template<typename Return, typename LeftArgument, typename RightArgument>
	struct Infix<Return(LeftArgument, RightArgument)>
	: xieite::functors::Function<Return(LeftArgument, RightArgument)> {
	private:
		template<typename LeftArgumentReference>
		struct Intermediate {
		public:
			constexpr Intermediate(const xieite::functors::Infix<Return(LeftArgument, RightArgument)>& infix, LeftArgumentReference&& leftArgument) noexcept
			: infix(infix), leftArgument(XIEITE_FORWARD(leftArgument)) {}

			constexpr auto operator=(const xieite::functors::Infix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgument>&) noexcept = delete;

			template<std::convertible_to<RightArgument> RightArgumentReference>
			friend constexpr Return operator>(xieite::functors::Infix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>&& intermediate, RightArgumentReference&& rightArgument) {
				return intermediate.infix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument));
			}

		private:
			const xieite::functors::Infix<Return(LeftArgument, RightArgument)>& infix;
			LeftArgumentReference&& leftArgument;
		};

	public:
		using xieite::functors::Function<Return(LeftArgument, RightArgument)>::Function;

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr xieite::functors::Infix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference> operator<(LeftArgumentReference&& leftArgument, const xieite::functors::Infix<Return(LeftArgument, RightArgument)>& infix) noexcept {
			return xieite::functors::Infix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>(infix, XIEITE_FORWARD(leftArgument));
		}
	};
}

#endif
