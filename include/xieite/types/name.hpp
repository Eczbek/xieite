#ifndef XIEITE_HEADER_TYPES_NAME
#	define XIEITE_HEADER_TYPES_NAME

#	include <string_view>
#	include "../macros/compiler_type.hpp"

#	if XIEITE_COMPILER_TYPE_GCC
#		include <string>
#		include "../containers/make_array.hpp"
#		include "../strings/between.hpp"

namespace XIEITE_DETAIL_NAMESPACE {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		static constexpr auto data = xieite::containers::makeArray<char, std::string_view(__PRETTY_FUNCTION__).size()>(std::string_view(__PRETTY_FUNCTION__));
		return xieite::strings::between(std::string_view(data.begin(), data.end()), "= ", ';');
	}
}

#	elif XIEITE_COMPILER_TYPE_LLVM
#		include "../strings/between.hpp"

namespace XIEITE_DETAIL_NAMESPACE {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		static constexpr auto data = xieite::containers::makeArray<char, std::string_view(__PRETTY_FUNCTION__).size()>(std::string_view(__PRETTY_FUNCTION__));
		return xieite::strings::between(std::string_view(data.begin(), data.end()), "= ", ']');
	}
}

#	elif XIEITE_COMPILER_TYPE_MSVC
#		include "../strings/after.hpp"
#		include "../strings/between.hpp"

namespace XIEITE_DETAIL_NAMESPACE {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		static constexpr auto data = xieite::containers::makeArray<char, std::string_view(__FUNCSIG__).size()>(std::string_view(__FUNCSIG__));
		return xieite::strings::between(xieite::strings::after(std::string_view(data.begin(), data.end()), "__cdecl"), '<', ">(");
	}
}

#	else
#		error "Compiler not supported"
#	endif

namespace xieite::types {
	template<typename Type>
	inline constexpr std::string_view name = XIEITE_DETAIL_NAMESPACE::name<Type>();
}

#endif
