#ifndef XIEITE_HEADER__MACROS__UNREACHABLE
#	define XIEITE_HEADER__MACROS__UNREACHABLE

#	include "../macros/STANDARD_LANGUAGE.hpp"

#	if XIEITE__STANDARD_LANGUAGE__CPP_2023
#		include <utility>

#		define XIEITE__UNREACHABLE std::unreachable()
#	else
#		include "../macros/COMPILER_TYPE.hpp"

#		if XIEITE__COMPILER_TYPE__GCC || XIEITE__COMPILER_TYPE__LLVM
#			undef XIEITE__UNREACHABLE
#			define XIEITE__UNREACHABLE __builtin_unreachable()
#		elif XIEITE__COMPILER_TYPE__MSVC
#			undef XIEITE__UNREACHABLE
#			define XIEITE__UNREACHABLE __assume(false)
#		else
#			define XIEITE__UNREACHABLE static_cast<void>(0)
#		endif
#	endif

// Thanks to eightfold for original code

#endif
