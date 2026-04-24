#include <xte/meta/end.hpp>

static_assert(!xte::end<int>);
static_assert(!xte::end<void>);
static_assert(!xte::end<char***&&>);
static_assert(!xte::end<int(decltype([] {})::*)(...) const volatile && noexcept>);
