#include <xte/meta/sad.hpp>

static_assert(not xte::sad<int>);
static_assert(not xte::sad<void>);
static_assert(not xte::sad<char***&&>);
static_assert(not xte::sad<int(decltype([] {})::*)(...) const volatile && noexcept>);
