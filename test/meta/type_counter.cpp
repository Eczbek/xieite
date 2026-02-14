#include <xte/meta/type_counter.hpp>

static_assert(xte::type_counter<int> == 0);
static_assert(xte::type_counter<char> == 1);
static_assert(xte::type_counter<void> == 2);
static_assert(xte::type_counter<int> == 0);
