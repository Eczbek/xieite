#ifndef XIEITE_HEADER_FUNCTORS_INFIX
#	define XIEITE_HEADER_FUNCTORS_INFIX

#	include <concepts>
#	include "../concepts/functable.hpp"
#	include "../functors/function.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename>
	struct Infix;

	template<typename Return_, typename Argument_>
	struct Infix<Return_(Argument_)>
	: xieite::functors::Function<Return_(Argument_)> {
		using xieite::functors::Function<Return_(Argument_)>::Function;

		template<std::convertible_to<Argument_> ArgumentReference_>
		friend constexpr Return_ operator>(const xieite::functors::Infix<Return_(Argument_)>& infix, ArgumentReference_&& argument) {
			return infix(XIEITE_FORWARD(argument));
		}

		template<std::convertible_to<Argument_> ArgumentReference_>
		friend constexpr Return_ operator<(ArgumentReference_&& argument, const xieite::functors::Infix<Return_(Argument_)>& infix) {
			return infix(XIEITE_FORWARD(argument));
		}
	};

	template<typename Return_, typename LeftArgument_, typename RightArgument_>
	struct Infix<Return_(LeftArgument_, RightArgument_)>
	: xieite::functors::Function<Return_(LeftArgument_, RightArgument_)> {
	private:
		template<typename LeftArgumentReference_>
		struct Intermediate {
		public:
			constexpr Intermediate(const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>& infix, LeftArgumentReference_&& leftArgument) noexcept
			: infix(infix), leftArgument(XIEITE_FORWARD(leftArgument)) {}

			constexpr auto operator=(const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgument_>&) noexcept = delete;

			template<std::convertible_to<RightArgument_> RightArgumentReference_>
			friend constexpr Return_ operator>(xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgumentReference_>&& intermediate, RightArgumentReference_&& rightArgument) {
				return intermediate.infix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument));
			}

		private:
			const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>& infix;
			LeftArgumentReference_&& leftArgument;
		};

	public:
		using xieite::functors::Function<Return_(LeftArgument_, RightArgument_)>::Function;

		template<std::convertible_to<LeftArgument_> LeftArgumentReference_>
		[[nodiscard]] friend constexpr xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgumentReference_> operator<(LeftArgumentReference_&& leftArgument, const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>& infix) noexcept {
			return xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgumentReference_>(infix, XIEITE_FORWARD(leftArgument));
		}
	};
}

#endif
