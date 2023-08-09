#ifndef XIEITE_HEADER__MACROS__STRUCTURE_UUID
#	define XIEITE_HEADER__MACROS__STRUCTURE_UUID

#	include "../macros/COMPILER_TYPE.hpp"
#	include "../macros/STRINGIFY.hpp"

#	if XIEITE__COMPILER_TYPE__MSVC
#		define XIEITE__STRUCTURE_UUID(value) __declspec(XIEITE_INTERNAL__STRUCTURE_UUID(value))
#		define XIEITE_INTERNAL__STRUCTURE_UUID(value) uuid(XIEITE__STRINGIFY(value))
#	else
#		define XIEITE__STRUCTURE_UUID(...)
#	endif

// Thanks to eightfold for original code

#endif
