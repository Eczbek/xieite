#ifndef DETAIL_XIEITE_HEADER_META_MEMBER_OBJ_NAME
#	define DETAIL_XIEITE_HEADER_META_MEMBER_OBJ_NAME
#
#	include <cstddef>
#	include <memory>
#	include <string_view>
#	include <tuple>
#	include "../data/str_after_last.hpp"
#	include "../meta/fake_obj.hpp"
#	include "../meta/make_tuple.hpp"
#	include "../meta/obj_name.hpp"
#	include "../pp/diagnostic.hpp"

XIEITE_DIAGNOSTIC_PUSH_CLANG()
XIEITE_DIAGNOSTIC_OFF_CLANG("-Wundefined-var-template")

namespace xieite {
	template<typename Class, std::size_t idx>
	constexpr std::string_view member_obj_name = ([] static {
		std::string_view name = xieite::obj_name<std::addressof(std::get<0>(xieite::make_tuple(xieite::fake_obj<Class>)))>;
#	if XIEITE_COMPILER_TYPE_CLANG || XIEITE_COMPILER_TYPE_ICC
		return xieite::str_after_last(name, ".");
#	elif XIEITE_COMPILER_TYPE_GCC
		name = xieite::str_after_last(name, "::");
		return name.substr(0, name.size() - 1);
#	elif XIEITE_COMPILER_TYPE_MSVC
		return xieite::str_after_last(name, "->");
#	else
		return "???";
#	endif
	})();
}

XIEITE_DIAGNOSTIC_POP_CLANG()

#endif
