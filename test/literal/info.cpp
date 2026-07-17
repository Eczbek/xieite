#include <xte/data/string_view.hpp>
#include <xte/literal/info.hpp>
#include <xte/math/approx_equal.hpp>

using namespace xte::literal::info;
static_assert([:123_info:] == 123);
static_assert(xte::approx_equal([:3.14159_info:], 3.14159));
static_assert([:"abc"_info:] == xte::string_view("abc"));
