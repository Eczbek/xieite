#include <xte/data/array.hpp>
#include <xte/data/string_view.hpp>

static_assert(xte::string_view("abc").subview(0) == "abc");
static_assert(xte::string_view("abc").subview(1) == "bc");
static_assert(xte::string_view("abc").subview(2) == "c");
static_assert(xte::string_view("abc").subview(3) == "");
static_assert(xte::string_view("abc").subview(4) == "");
static_assert(xte::string_view("abc").subview(5) == "");

static_assert(xte::string_view("abc abc abcd abc abcd").find("bcd") == 9);
static_assert(xte::string_view("abc abcd abcd abc abc").find_last("bcd") == 10);

static_assert(xte::string_view(xte::array { 'a', 'b', 'c' }) == "abc");
