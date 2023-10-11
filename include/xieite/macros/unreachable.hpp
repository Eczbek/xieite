#ifndef XIEITE_HEADER_MACROS_UNREACHABLE
#	define XIEITE_HEADER_MACROS_UNREACHABLE

#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2023
#		include <utility>

#		define XIEITE_UNREACHABLE std::unreachable()
#	else
#		include "../macros/compiler.hpp"

#		if XIEITE_COMPILER_GCC || XIEITE_COMPILER_LLVM
#			define XIEITE_UNREACHABLE __builtin_unreachable()
#		elif XIEITE_COMPILER_MSVC
#			define XIEITE_UNREACHABLE __assume(false)
#		else
#			define XIEITE_UNREACHABLE static_cast<void>(0)
#		endif
#	endif

#endif

// Thanks to eightfold for original code
