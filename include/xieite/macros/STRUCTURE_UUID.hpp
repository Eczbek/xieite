#ifndef XIEITE_HEADER_MACROS_STRUCTURE_UUID
#	define XIEITE_HEADER_MACROS_STRUCTURE_UUID

#	include "../macros/COMPILER_TYPE.hpp"
#	include "../macros/STRINGIFY.hpp"

#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_STRUCTURE_UUID(value) __declspec(XIEITE_INTERNAL_STRUCTURE_UUID(value))
#		define XIEITE_INTERNAL_STRUCTURE_UUID(value) uuid(XIEITE_STRINGIFY(value))
#	else
#		define XIEITE_STRUCTURE_UUID(...)
#	endif

// Thanks to eightfold for original code

#endif
