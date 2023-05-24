#ifndef XIEITE_HEADER_FUNCTIONS_PREFIX
#	define XIEITE_HEADER_FUNCTIONS_PREFIX

#	include <functional>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename>
	struct Prefix;

	template<typename Result, typename RightParameter>
	class Prefix<Result(RightParameter)> final {
	public:
		constexpr Prefix(const xieite::concepts::Functional<Result(RightParameter)> auto& callback) noexcept
		: callback(callback) {}

		constexpr Result operator>(const RightParameter& rightArgument) const {
			return this->callback(rightArgument);
		}

	private:
		std::function<Result(RightParameter)> callback;
	};
}

#endif
