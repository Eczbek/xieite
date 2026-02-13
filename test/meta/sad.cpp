#include <xte/meta/sad.hpp>

static_assert(!xte::sad<int>);
static_assert(!xte::sad<void>);
static_assert(!xte::sad<char***&&>);
static_assert(!xte::sad<int(decltype([] {})::*)(...) const volatile && noexcept>);
