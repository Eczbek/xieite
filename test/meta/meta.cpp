#include <xte/meta/meta.hpp>

struct A {};

static_assert(^^int == xte::meta::return_type_of(^^int(A::*)()));
