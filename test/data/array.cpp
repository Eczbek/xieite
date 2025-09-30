#include <xte/data/array.hpp>

static_assert(xte::array<int>().size() == 0uz);
static_assert(xte::array<int>().capacity() == 0uz);
static_assert(xte::array<int>().data() == nullptr);
