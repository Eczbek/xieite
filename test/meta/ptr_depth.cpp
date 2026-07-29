#include <xte/meta/ptr_depth.hpp>

static_assert(xte::ptr_depth<int> == 0);
static_assert(xte::ptr_depth<int*> == 1);
static_assert(xte::ptr_depth<int**> == 2);
static_assert(xte::ptr_depth<int***> == 3);
static_assert(xte::ptr_depth<int* const* volatile* const volatile*&&> == 4);
