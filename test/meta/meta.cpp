#include <xte/meta/meta.hpp>
#include <xte/meta/type.hpp>

struct A {};

static_assert(^^int == xte::meta::return_type_of(^^int()));
static_assert(^^int == xte::meta::return_type_of(^^xte::member_type<A, int()>));
