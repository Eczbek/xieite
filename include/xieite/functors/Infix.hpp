#ifndef XIEITE_HEADER__FUNCTORS__INFIX
#	define XIEITE_HEADER__FUNCTORS__INFIX

#	include <concepts>
#	include "../concepts/Functable.hpp"

namespace xieite::functors {
	template<typename, auto>
	struct Infix;

	template<typename Result, typename Argument, xieite::concepts::Functable<Result(Argument)> auto callback>
	struct Infix<Result(Argument), callback> {
		constexpr Result operator>(const Argument& argument) const {
			return callback(argument);
		}

		friend constexpr Result operator<(const Argument& argument, const xieite::functors::Infix<Result(Argument), callback>) {
			return callback(argument);
		}
	};

	template<typename Result, typename LeftArgument, typename RightArgument, xieite::concepts::Functable<Result(LeftArgument, RightArgument)> auto callback>
	class Infix<Result(LeftArgument, RightArgument), callback> {
	private:
		class Intermediate {
		public:
			constexpr Intermediate(const LeftArgument& leftArgument) noexcept
			: leftArgument(leftArgument) {}

			constexpr Result operator>(const RightArgument& rightArgument) const {
				return callback(this->leftArgument, rightArgument);
			}
		
		private:
			const LeftArgument& leftArgument;
		};

	public:
		[[nodiscard]] friend constexpr xieite::functors::Infix<Result(LeftArgument, RightArgument), callback>::Intermediate operator<(const LeftArgument& leftArgument, const xieite::functors::Infix<Result(LeftArgument, RightArgument), callback>) noexcept {
			return xieite::functors::Infix<Result(LeftArgument, RightArgument), callback>::Intermediate(leftArgument);
		}
	};
}

#endif
