#include <xte/meta/type.hpp>
#include <xte/trait/is_same.hpp>

template<typename T>
constexpr bool test_same = xte::is_same<T, xte::type<T>>;

static_assert(test_same<int>);
static_assert(test_same<void>);
static_assert(test_same<char***&&>);
static_assert(test_same<int(decltype([] {})::*)(...) const volatile && noexcept>);
