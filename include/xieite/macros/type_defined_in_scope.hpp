#ifndef XIEITE_HEADER_MACROS_TYPE_DEFINED_IN_SCOPE
#	define XIEITE_HEADER_MACROS_TYPE_DEFINED_IN_SCOPE

#	include <concepts>

#	define XIEITE_TYPE_DEFINED_IN_SCOPE(...) (!::std::same_as<void(int(__VA_ARGS__)), void(int)>)

#endif
