#ifndef DETAIL_XTE_HEADER_DATA_INIT_LIST
#	define DETAIL_XTE_HEADER_DATA_INIT_LIST
#
#	include "../util/address.hpp"
#	include "../util/lvalue.hpp"
#	include "../util/xvalue.hpp"
#	include <initializer_list>

namespace DETAIL_XTE {
	template<typename T>
	struct init_list {
	private:
		T* ptr;

	public:
		[[nodiscard]] explicit(false) constexpr init_list(T&& x) noexcept
		: ptr(xte::address(x)) {}

		[[nodiscard]] explicit(false) constexpr init_list(const T& x) noexcept
		: ptr(xte::address(xte::lvalue(auto(x)))) {}

		[[nodiscard]] explicit(false) constexpr operator T&&() const && noexcept {
			return xte::xvalue(*this->ptr);
		}
	};
}

namespace xte {
	template<typename T>
	using init_list = std::initializer_list<DETAIL_XTE::init_list<T>>;
}

#endif
