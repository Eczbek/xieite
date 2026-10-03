#include <xte/meta/wrap.hpp>
#include <xte/qual_traits.hpp>
#include <compare>

template<typename type>
constexpr bool test_same = xte::is_same<type, typename xte::wrap_type<type>::type>;

static_assert(test_same<int>);
static_assert(test_same<void>);
static_assert(test_same<char***&&>);
static_assert(test_same<int(decltype([]{})::*)(...) const volatile&& noexcept>);



static_assert([](int x) { return x; }(xte::wrap_value<0>()) == 0);
static_assert(xte::wrap_value<0>()() == 0);
static_assert(std::is_eq(xte::wrap_value<0>() <=> 0));
static_assert(xte::wrap_value<0>() == 0);
