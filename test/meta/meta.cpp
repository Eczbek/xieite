#include <xte/data/string_view.hpp>
#include <xte/math/approx_equal.hpp>
#include <xte/math/parse_number.hpp>
#include <xte/meta/meta.hpp>
#include <meta>

using namespace xte::literal::info;
static_assert([:123_info:] == 123);
static_assert(xte::approx_equal([:3.14159_info:], 3.14159));
static_assert([:"abc"_info:] == xte::string_view("abc"));



template<auto...> struct tmpl {
	template<int> void f(...) noexcept {
		struct T {};
		static_assert(xte::meta::name_of(^^T) == "tmpl<>::f<0>(...)::T");
		static_assert(xte::meta::name_of(parent_of(^^T)) == "void tmpl<>::f<0>(...) noexcept");
		static_assert(xte::meta::name_of(template_of(parent_of(^^T))) == "tmpl<>::f<...>");
	}
};
template<int> void func_tmpl();
namespace ns {
	namespace {
		struct T {
			auto f() const volatile && noexcept {
				struct {} _;
				return _;
			}
		};
	}
}
template<char...> void operator""_literal() {
	struct T {};
	static_assert(xte::meta::name_of(^^T) == "operator\"\"_literal<'1', '2', '3'>()::T");
	static_assert(xte::meta::name_of(parent_of(^^T)) == "void operator\"\"_literal<'1', '2', '3'>()");
	static_assert(xte::meta::name_of(template_of(parent_of(^^T))) == "operator\"\"_literal<...>");
}
struct conv {
	template<typename T> operator T() {
		struct U {};
		static_assert(xte::meta::name_of(^^U) == "conv::operator ns::<anonymous>::T::f() const volatile &&::<unnamed>()::U");
		static_assert(xte::meta::name_of(parent_of(^^U)) == "conv::operator ns::<anonymous>::T::f() const volatile &&::<unnamed>()");
		static_assert(xte::meta::name_of(template_of(parent_of(^^U))) == "conv::operator <...>");
		return {};
	}
};
struct conv_conv {
	operator int() {
		struct inner {
			operator int() {
				struct hidden {};
				static_assert(xte::meta::name_of(^^hidden) == "conv_conv::operator int()::inner::operator int()::hidden");
				return 0;
			}
		};
		return static_cast<int>(inner());
	}
};
struct special {
	template<int = 0> special() {
		struct ctor {};
		static_assert(xte::meta::name_of(^^ctor) == "special::special<0>()::ctor");
		static_assert(xte::meta::name_of(parent_of(^^ctor)) == "special::special<0>()");
		static_assert(xte::meta::name_of(template_of(parent_of(^^ctor))) == "special::special<...>");
	}
	~special() {
		struct dtor {};
		static_assert(xte::meta::name_of(^^dtor) == "special::~special()::dtor");
		static_assert(xte::meta::name_of(parent_of(^^dtor)) == "special::~special() noexcept");
	}
};
template<typename T> void operator+(T, T) noexcept {
	struct add {};
	static_assert(xte::meta::name_of(^^add) == "operator+<main()::add>(main()::add, main()::add)::add");
	static_assert(xte::meta::name_of(parent_of(^^add)) == "void operator+<main()::add>(main()::add, main()::add) noexcept");
	static_assert(xte::meta::name_of(template_of(parent_of(^^add))) == "operator+<...>");
}
enum struct E {
	value = 1
};
struct obj {
	int x;
	int y[3];
};
struct arr {
	int a[2][2];
};
static_assert(xte::meta::name_of(^^int) == "int");
static_assert(xte::meta::name_of(^^int&) == "int&");
static_assert(xte::meta::name_of(^^int&&) == "int&&");
static_assert(xte::meta::name_of(^^int[]) == "int[]");
static_assert(xte::meta::name_of(^^int[5]) == "int[5]");
static_assert(xte::meta::name_of(^^const int) == "const int");
static_assert(xte::meta::name_of(^^volatile int) == "volatile int");
static_assert(xte::meta::name_of(^^volatile const int) == "const volatile int");
static_assert(xte::meta::name_of(^^int(&)[]) == "(int[])&");
static_assert(xte::meta::name_of(^^const int&) == "const int&");
static_assert(xte::meta::name_of(^^const int&&) == "const int&&");
static_assert(xte::meta::name_of(^^const int[]) == "const int[]");
static_assert(xte::meta::name_of(^^const int[5]) == "const int[5]");
static_assert(xte::meta::name_of(^^const int(&)[]) == "(const int[])&");
static_assert(xte::meta::name_of(^^int*) == "int*");
static_assert(xte::meta::name_of(^^int***) == "int***");
static_assert(xte::meta::name_of(^^int*&) == "int*&");
static_assert(xte::meta::name_of(^^int(*)[]) == "(int[])*");
static_assert(xte::meta::name_of(^^const int*) == "const int*");
static_assert(xte::meta::name_of(^^const int* volatile*) == "volatile (const int*)*");
static_assert(xte::meta::name_of(^^const int* const* const* const) == "const (const (const (const int*)*)*)");
static_assert(xte::meta::name_of(^^int()) == "int()");
static_assert(xte::meta::name_of(^^int(&)()) == "(int())&");
static_assert(xte::meta::name_of(^^int(*)()) == "(int())*");
static_assert(xte::meta::name_of(^^int(*[])()) == "(int())*[]");
static_assert(xte::meta::name_of(^^int(* const)()) == "const ((int())*)");
static_assert(xte::meta::name_of(^^::) == "::");
static_assert(xte::meta::name_of(^^decltype(nullptr)) == "std::nullptr_t");
static_assert(xte::meta::name_of(^^decltype(^^::)) == "std::meta::info");
static_assert(xte::meta::name_of(^^tmpl) == "tmpl<...>");
static_assert(xte::meta::name_of(^^tmpl<>) == "tmpl<>");
static_assert(xte::meta::name_of(^^tmpl<true, (tmpl<-5>()), 'h', '\t', '\0'>) == "tmpl<true, tmpl<-5>{}, 'h', '\\t', '\\x0'>");
static_assert(xte::meta::name_of(^^func_tmpl) == "func_tmpl<...>");
static_assert(xte::meta::name_of(^^func_tmpl<0>) == "void func_tmpl<0>()");
static_assert(xte::meta::name_of(^^E) == "E");
static_assert(xte::meta::name_of(^^E::value) == "E::value");
static_assert(xte::meta::name_of(std::meta::reflect_constant(nullptr)) == "nullptr");
static_assert(xte::meta::name_of(std::meta::reflect_constant(42)) == "42");
static_assert(xte::meta::name_of(std::meta::reflect_constant('a')) == "'a'");
static_assert(xte::approx_equal(xte::parse_number<double>(xte::meta::name_of(std::meta::reflect_constant(3.14159))), 3.14159));
static_assert(xte::meta::name_of(std::meta::reflect_constant(obj(0, {1,2,3}))) == "obj{0, [1, 2, 3]}");
static_assert(xte::meta::name_of(std::meta::reflect_constant(arr({ { 1, 2 }, { 3, 4 } }))) == "arr{[[1, 2], [3, 4]]}");
static_assert(xte::meta::name_of(std::meta::reflect_constant(^^int)) == "^^int");
static_assert(xte::meta::name_of(std::meta::reflect_constant(^^::)) == "^^::");
static_assert(xte::meta::name_of(std::meta::reflect_constant(std::meta::reflect_constant(std::meta::reflect_constant(42)))) == "^^(^^42)");
static_assert(xte::meta::name_of(std::meta::reflect_constant(E::value)) == "E::value");
static_assert(xte::meta::name_of(std::meta::reflect_constant(static_cast<E>(1))) == "E::value");
static_assert(xte::meta::name_of(std::meta::reflect_constant(static_cast<E>(2))) == "E{2}");
int main() {
	tmpl<>().template f<0>();
	123_literal;
	static_cast<decltype(ns::T().f())>(conv());
	static_assert(xte::meta::name_of(^^decltype(([] { return [] {}; })())) == "main()::<lambda>::operator()() const::<lambda>");
	struct add {}; add() + add();
}
