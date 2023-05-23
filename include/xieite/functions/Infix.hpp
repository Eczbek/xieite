#ifndef XIEITE_HEADER_FUNCTIONS_INFIX
#	define XIEITE_HEADER_FUNCTIONS_INFIX

namespace xieite::functions {
	template<typename Result, typename LeftParameter, typename RightParameter>
	class Infix {
	private:
		using Callback = Result(*)(LeftParameter, RightParameter);

	public:
		constexpr Infix(Callback callback) noexcept
		: callback(callback) {}

	private:
		class Bind {
		public:
			constexpr Bind(Callback callback, const LeftParameter& leftParameter) noexcept
			: callback(callback), leftParameter(leftParameter) {}

			constexpr Result operator()(const RightParameter& rightParameter) const noexcept {
				return this->callback(leftParameter, rightParameter);
			}

		private:
			Callback callback;
			const LeftParameter& leftParameter;
		};

		class Infixator {
		public:
			constexpr Infixator(const Bind& bind) noexcept
			: bind(bind) {}

			constexpr Result operator|(const RightParameter& rightParameter) const noexcept {
				return this->bind(rightParameter);
			}

		private:
			const Bind bind;
		};

		Callback callback;

		friend constexpr Infixator operator|(const LeftParameter& leftParameter, const Infix<Result, LeftParameter, RightParameter>& infix) noexcept {
			return Infixator(Bind(infix.callback, leftParameter));
		}
	};
}

#endif
