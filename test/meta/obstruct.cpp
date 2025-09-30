#include <xte/meta/obstruct.hpp>

template<typename T>
void f(T, xte::obstruct<T>);

static_assert(requires { f(0, 0.0); });
