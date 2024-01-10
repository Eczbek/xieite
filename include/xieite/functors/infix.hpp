#ifndef XIEITE_HEADER_FUNCTORS_INFIX
#	define XIEITE_HEADER_FUNCTORS_INFIX

#	include <concepts>
#	include <functional>
#	include <memory>
#	include <type_traits>
#	include <utility>
#	include "../concepts/no_throw_invocable.hpp"
#	include "../types/placeholder.hpp"

namespace xieite::functors {
	template<typename>
	struct Infix;

	template<std::invocable<xieite::types::Placeholder> Functor>
	class Infix<Functor> {
	public:
		constexpr Infix(const Functor& callback) noexcept
		: callback(std::make_shared<Functor>(callback)) {}

		constexpr Infix(Functor& callback) noexcept
		: callback(std::make_shared<Functor>(callback)) {}

		constexpr Infix(Functor&& callback) noexcept
		: callback(std::make_shared<Functor>(std::move(callback))) {}

		template<typename Argument>
		requires(std::invocable<Functor, Argument&&>)
		friend constexpr std::invoke_result_t<Functor, Argument&&> operator>(const xieite::functors::Infix<Functor>& infix, Argument&& argument)
		noexcept(xieite::concepts::NoThrowInvocable<Functor, Argument&&>) {
			return std::invoke(std::forward<Functor>(*infix.callback), std::forward<Argument>(argument));
		}

		template<typename Argument>
		requires(std::invocable<Functor, Argument&&>)
		friend constexpr std::invoke_result_t<Functor, Argument&&> operator<(Argument&& argument, const xieite::functors::Infix<Functor>& infix)
		noexcept(xieite::concepts::NoThrowInvocable<Functor, Argument&&>) {
			return std::invoke(std::forward<Functor>(*infix.callback), std::forward<Argument>(argument));
		}

	private:
		std::shared_ptr<Functor> callback;
	};

	template<std::invocable<xieite::types::Placeholder, xieite::types::Placeholder> Functor>
	class Infix<Functor> {
	private:
		template<typename LeftArgument>
		class Intermediate {
		public:
			constexpr Intermediate(const std::shared_ptr<Functor> callback, LeftArgument leftArgument) noexcept
			: callback(callback), leftArgument(std::make_shared<LeftArgument>(leftArgument)) {}

			constexpr auto operator=(const xieite::functors::Infix<Functor>::Intermediate<LeftArgument>&) = delete;

			template<typename RightArgument>
			requires(std::invocable<Functor, LeftArgument, RightArgument&&>)
			friend constexpr std::invoke_result_t<Functor, LeftArgument, RightArgument&&> operator>(const xieite::functors::Infix<Functor>::Intermediate<LeftArgument>& infixIntermediate, RightArgument&& rightArgument)
			noexcept(xieite::concepts::NoThrowInvocable<Functor, LeftArgument, RightArgument&&>) {
				return std::invoke(std::forward<Functor>(*infixIntermediate.callback), std::forward<LeftArgument>(*infixIntermediate.leftArgument), std::forward<RightArgument>(rightArgument));
			}

		private:
			std::shared_ptr<Functor> callback;
			std::shared_ptr<LeftArgument> leftArgument;
		};

	public:
		constexpr Infix(const Functor& callback) noexcept
		: callback(std::make_shared<Functor>(callback)) {}

		constexpr Infix(Functor& callback) noexcept
		: callback(std::make_shared<Functor>(callback)) {}

		constexpr Infix(Functor&& callback) noexcept
		: callback(std::make_shared<Functor>(std::move(functor))) {}

		template<typename LeftArgument>
		requires(std::invocable<Functor, LeftArgument&&, xieite::types::Placeholder>)
		[[nodiscard]] friend constexpr xieite::functors::Infix<Functor>::Intermediate<LeftArgument&&> operator<(LeftArgument&& leftArgument, const xieite::functors::Infix<Functor>& infix) noexcept {
			return xieite::functors::Infix<Functor>::Intermediate<LeftArgument&&>(*infix.callback, std::forward<LeftArgument>(leftArgument));
		}

	private:
		std::shared_ptr<Functor> callback;
	};

	template<typename Functor>
	xieite::functors::Infix(Functor&&) -> xieite::functors::Infix<Functor>;
}

#endif
