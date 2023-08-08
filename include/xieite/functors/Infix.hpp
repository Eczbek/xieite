#ifndef XIEITE_HEADER__FUNCTORS__INFIX
#	define XIEITE_HEADER__FUNCTORS__INFIX

#	include <concepts>
#	include "../functors/Argument.hpp"
#	include "../functors/Result.hpp"
#	include "../types/Placeholder.hpp"

namespace xieite::functors {
	template<typename>
	struct Infix;

	template<std::invocable<xieite::types::Placeholder> Callback>
	class Infix<Callback> {
	public:
		constexpr Infix(const Callback& callback = Callback()) noexcept
		: callback(callback) {}

		constexpr xieite::functors::Result<Callback> operator>(const xieite::functors::Argument<Callback, 0>& argument) const {
			return this->callback(argument);
		}

		friend constexpr xieite::functors::Result<Callback> operator<(const xieite::functors::Argument<Callback, 0>& argument, const xieite::functors::Infix<Callback>& infix) {
			return infix.callback(argument);
		}

	private:
		Callback callback;
	};

	template<std::invocable<xieite::types::Placeholder, xieite::types::Placeholder> Callback>
	class Infix<Callback> {
	public:
		constexpr Infix(const Callback& callback = Callback()) noexcept
		: callback(callback) {}

		[[nodiscard]]
		friend constexpr xieite::functors::Infix<Callback>::Intermediate operator<(const xieite::functors::Argument<Callback, 0>& leftArgument, const xieite::functors::Infix<Callback>& infix) noexcept {
			return xieite::functors::Infix<Callback>::Intermediate(infix.callback, leftArgument);
		}

	private:
		class Intermediate {
		public:
			constexpr Intermediate(const Callback& callback, const xieite::functors::Argument<Callback, 0>& leftArgument) noexcept
			: callback(callback), leftArgument(leftArgument) {}

			constexpr xieite::functors::Result<Callback> operator>(const xieite::functors::Argument<Callback, 1>& rightArgument) const {
				return this->callback(this->leftArgument, rightArgument);
			}
		
		private:
			Callback callback;
			xieite::functors::Argument<Callback, 0>& leftArgument;
		};

		Callback callback;
	};

	template<typename Callback>
	Infix(const Callback&) -> Infix<Callback>;
}

#endif
