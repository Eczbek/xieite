#ifndef XIEITE_HEADER_MACROS_UNREACHABLE
#	define XIEITE_HEADER_MACROS_UNREACHABLE

#	include <xieite/macros/STANDARD_LANGUAGE.hpp>

#	if XIEITE_STANDARD_LANGUAGE_CPP_2023
#		include <utility>

#		define XIEITE_UNREACHABLE std::unreachable()
#	else
#		include <xieite/macros/COMPILER_TYPE.hpp>

#		define XIEITE_UNREACHABLE static_cast<void>(0)

#		if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_LLVM
#			undef XIEITE_UNREACHABLE
#			define XIEITE_UNREACHABLE __builtin_unreachable()
#		endif

#		if XIEITE_COMPILER_TYPE_MSVC
#			undef XIEITE_UNREACHABLE
#			define XIEITE_UNREACHABLE __assume(false)
#		endif
#	endif

// Thanks to eightfold for original code

#endif
