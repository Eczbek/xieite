#ifndef XIEITE_HEADER__FUNCTORS__INFIX
#	define XIEITE_HEADER__FUNCTORS__INFIX

#	include <concepts>
#	include <functional>
#	include <type_traits>
#	include <utility>
#	include "../types/Placeholder.hpp"

namespace xieite::functors {
	template<typename>
	struct Infix;

	template<std::invocable<xieite::types::Placeholder> Functor>
	class Infix<Functor> {
	public:
		constexpr Infix(Functor&& callback) noexcept
		: callback(std::forward<Functor>(functor)) {}

		template<typename Argument>
		requires(std::invocable<Functor, Argument&&>)
		friend constexpr std::invoke_result_t<Functor, Argument&&> operator>(const xieite::functors::Infix<Functor>& infix, Argument&& argument) {
			return std::invoke(std::forward<Functor>(infix.callback), std::forward<Argument>(argument));
		}

		template<typename Argument>
		requires(std::invocable<Functor, Argument&&>)
		friend constexpr std::invoke_result_t<Functor, Argument&> operator<(Argument&& argument, const xieite::functors::Infix<Functor>& infix) {
			return std::invoke(std::forward<Functor>(infix.callback), std::forward<Argument>(argument));
		}

	private:
		Functor&& callback;
	};

	template<std::invocable<xieite::types::Placeholder, xieite::types::Placeholder> Functor>
	class Infix<Functor> {
	private:
		template<typename LeftArgument>
		class Intermediate {
		public:
			constexpr Intermediate(Functor&& callback, LeftArgument&& leftArgument) noexcept
			: callback(std::forward<Functor>(functor)), leftArgument(std::forward<LeftArgument>(leftArgument)) {}

			constexpr auto operator=(const xieite::functors::Infix<Functor>::Intermediate<LeftArgument>&) = delete;

			template<typename RightArgument>
			requires(std::invocable<Functor, LeftArgument, RightArgument&&>)
			friend constexpr std::invoke_result_t<Functor, LeftArgument, RightArgument&&> operator>(const xieite::functors::Infix<Functor>::Intermediate<LeftArgument>& infixIntermediate, RightArgument&& rightArgument) {
				return std::invoke(std::forward<Functor>(infixIntermediate.callback), std::forward<LeftArgument>(infixIntermediate.leftArgument), std::forward<RightArgument>(rightArgument));
			}

		private:
			Functor&& callback;
			LeftArgument&& leftArgument;
		};

	public:
		constexpr Infix(Functor&& callback) noexcept
		: callback(std::move(functor)) {}

		template<typename LeftArgument>
		requires(std::invocable<Functor, LeftArgument&&, xieite::types::Placeholder>)
		[[nodiscard]] friend constexpr xieite::functors::Infix<Functor>::Intermediate<LeftArgument&&> operator<(LeftArgument&& leftArgument, const xieite::functors::Infix<Functor>& infix) noexcept {
			return xieite::functors::Infix<Functor>::Intermediate<LeftArgument&&>(std::forward<Functor>(infix.callback), std::forward<LeftArgument>(leftArgument));
		}

	private:
		Functor&& callback;
	};

	template<typename Functor>
	xieite::functors::Infix(Functor&&) -> xieite::functors::Infix<Functor>;
}

#endif
