#include <xte/data/string_view.hpp>

static_assert(xte::string_view("abc").substr(0) == "abc");
static_assert(xte::string_view("abc").substr(1) == "bc");
static_assert(xte::string_view("abc").substr(2) == "c");
static_assert(xte::string_view("abc").substr(3) == "");
static_assert(xte::string_view("abc").substr(4) == "");
static_assert(xte::string_view("abc").substr(5) == "");
