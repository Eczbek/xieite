#include <xte/trait/has_implicit_move_ctor.hpp>

struct A { explicit(false) A(A&&); };
struct B { explicit B(B&&); };

static_assert(xte::has_implicit_move_ctor<A>);
static_assert(not xte::has_implicit_move_ctor<B>);
