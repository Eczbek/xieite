#ifndef XIEITE_HEADER_TYPES_NAME
#	define XIEITE_HEADER_TYPES_NAME

#	include <string_view>
#	include "../macros/compiler.hpp"

#	if XIEITE_COMPILER_TYPE_GCC
#		include "../containers/make_array.hpp"
#		include "../strings/between.hpp"
#		include "../strings/replace.hpp"

namespace XIEITE_DETAIL_NAMESPACE {
	template<typename>
	[[nodiscard]] consteval std::string_view name() noexcept {
		static constexpr auto get = [string = std::string_view(__PRETTY_FUNCTION__)] -> std::string {
			return xieite::strings::replace(xieite::strings::between<std::string_view>(string, "= ", ';'), " >", '>');
		};
		static constexpr auto data = xieite::containers::makeArray<char, get().size()>(get());
		return std::string_view(data.begin(), data.end());
	}
}

#	elif XIEITE_COMPILER_TYPE_CLANG
#		include "../containers/make_array.hpp"
#		include "../strings/between.hpp"

namespace XIEITE_DETAIL_NAMESPACE {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		static constexpr auto get = [string = std::string_view(__PRETTY_FUNCTION__)] -> std::string_view {
			return xieite::strings::between<std::string_view>(string, "= ", ']');
		};
		static constexpr auto data = xieite::containers::makeArray<char, get().size()>(get());
		return std::string_view(data.begin(), data.end());
	}
}

#	elif XIEITE_COMPILER_TYPE_MSVC
#		include "../containers/make_array.hpp"
#		include "../strings/after.hpp"
#		include "../strings/between.hpp"

namespace XIEITE_DETAIL_NAMESPACE {
	template<typename>
	[[nodiscard]] constexpr std::string_view name() noexcept {
		static constexpr auto get = [string = std::string_view(__PRETTY_FUNCTION__)] -> std::string_view {
			return xieite::strings::between<std::string_view>(xieite::strings::after<std::string_view>(string, " __"), '<', ">(");
		};
		static constexpr auto data = xieite::containers::makeArray<char, get().size()>(get());
		return std::string_view(data.begin(), data.end());
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
