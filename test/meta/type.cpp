#include <xte/meta/type.hpp>
#include <xte/qual_traits.hpp>

template<typename type>
constexpr bool test_same = xte::is_same<type, xte::type<type>>;

static_assert(test_same<int>);
static_assert(test_same<void>);
static_assert(test_same<char***&&>);
static_assert(test_same<int(decltype([]{})::*)(...) const volatile&& noexcept>);
