module;

#include <xieite/forward.hpp>

export module xieite:functors.Mixfix;

import std;
import :concepts.Invocable;
import :functors.Function;

export namespace xieite::functors {
	template<typename>
	struct Mixfix;

	template<typename Return, typename Argument>
	struct Mixfix<Return(Argument)>
	: xieite::functors::Function<Return(Argument)> {
		using xieite::functors::Function<Return(Argument)>::Function;

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr Return operator>(const xieite::functors::Mixfix<Return(Argument)>& mixfix, ArgumentReference&& argument) noexcept(false) {
			return mixfix(XIEITE_FORWARD(argument));
		}

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr Return operator<(ArgumentReference&& argument, const xieite::functors::Mixfix<Return(Argument)>& mixfix) noexcept(false) {
			return mixfix(XIEITE_FORWARD(argument));
		}
	};

	template<typename Return, typename LeftArgument, typename RightArgument>
	struct Mixfix<Return(LeftArgument, RightArgument)>
	: xieite::functors::Function<Return(LeftArgument, RightArgument)> {
	private:
		template<typename LeftArgumentReference>
		struct Intermediate {
		public:
			constexpr Intermediate(const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>& mixfix, LeftArgumentReference&& leftArgument) noexcept
			: mixfix(mixfix), leftArgument(XIEITE_FORWARD(leftArgument)) {}

			auto operator=(const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>&) = delete;

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr Return operator>(const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>&& intermediate, RightArgumentReference&& rightArgument) noexcept(false) {
				return intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument));
			}

		private:
			const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>& mixfix;
			LeftArgumentReference&& leftArgument;
		};

	public:
		using xieite::functors::Function<Return(LeftArgument, RightArgument)>::Function;

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference> operator<(LeftArgumentReference&& leftArgument, const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>& mixfix) noexcept {
			return xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument));
		}
	};
}

// `xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate` must only exist as a temporary
