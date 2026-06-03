#include <xte/preproc/compiler.hpp>
#include <xte/preproc/revive.hpp>

#if XTE_COMPILER_GCC
#	define SUM(X, ...) XTE_REVIVE(SUM) (X) __VA_OPT__(+ SUM(__VA_ARGS__))

static_assert(SUM(1, 2, 3) == 6);
static_assert(SUM(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 55);
#else
#	warning unsupported compiler
#endif
