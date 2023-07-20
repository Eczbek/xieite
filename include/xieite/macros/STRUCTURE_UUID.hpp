#ifndef XIEITE_HEADER_MACROS_STRUCTURE_UUID
#	define XIEITE_HEADER_MACROS_STRUCTURE_UUID

#	include <xieite/macros/COMPILER_TYPE.hpp>
#	include <xieite/macros/STRINGIFY.hpp>

#	define XIEITE_STRUCTURE_UUID(...)

#	if XIEITE_COMPILER_TYPE_MSVC
#		undef XIEITE_STRUCTURE_UUID
#		define XIEITE_STRUCTURE_UUID(value) \
			__declspec(XIEITE_INTERNAL_STRUCTURE_UUID(value))
#		define XIEITE_INTERNAL_STRUCTURE_UUID(value) \
			uuid(XIEITE_STRINGIFY(value))
#	endif

// Thanks to eightfold for original code

#endif
