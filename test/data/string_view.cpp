#include <xte/data/string_view.hpp>

static_assert(xte::string_view("abc").slice(0) == "abc");
static_assert(xte::string_view("abc").slice(1) == "bc");
static_assert(xte::string_view("abc").slice(2) == "c");
static_assert(xte::string_view("abc").slice(3) == "");
static_assert(xte::string_view("abc").slice(4) == "");
static_assert(xte::string_view("abc").slice(5) == "");
