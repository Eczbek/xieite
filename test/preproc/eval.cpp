#include <xte/preproc/paren.hpp>
#include <xte/preproc/eval.hpp>

#define TRUE() true

static_assert(XTE_EVAL(TRUE XTE_PAREN XTE_PAREN XTE_PAREN XTE_PAREN XTE_PAREN()));
