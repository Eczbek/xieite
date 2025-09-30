#include <xte/preproc/scan.hpp>

#define TRUE() true

static_assert(XTE_SCAN(TRUE XTE_SCAN() ()));
