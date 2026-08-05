#include <xte/data/array.hpp>
#include <xte/data/non_copyable.hpp>
#include <xte/data/non_movable.hpp>
#include <xte/preproc/template.hpp>
#include <xte/trait/is_assignable.hpp>
#include <xte/trait/is_assignable_noex.hpp>
#include <xte/util/as_lvalue.hpp>
#include <vector>

struct non_constructible {
	non_constructible() = delete;
	non_constructible(const non_constructible&) = delete;
	non_constructible(non_constructible&&) = delete;
};

struct non_default_constructible {
	constexpr non_default_constructible(int) noexcept {}
};

struct throwing_default_constructor {
	constexpr throwing_default_constructor() noexcept(false) {}
};

struct throwing_copy_constructor {
	throwing_copy_constructor() = default;
	constexpr throwing_copy_constructor(const throwing_copy_constructor&) noexcept(false) {}
	throwing_copy_constructor(throwing_copy_constructor&&) = default;
};

struct throwing_move_constructor {
	throwing_move_constructor() = default;
	throwing_move_constructor(const throwing_move_constructor&) = default;
	constexpr throwing_move_constructor(throwing_move_constructor&&) noexcept(false) {}
};

struct throwing_copy_and_move_constructor {
	throwing_copy_and_move_constructor() = default;
	constexpr throwing_copy_and_move_constructor(const throwing_copy_and_move_constructor&) noexcept(false) {}
	constexpr throwing_copy_and_move_constructor(throwing_copy_and_move_constructor&&) noexcept(false) {}
};

consteval {
	XTE_TEMPLATE {
		// Copy assignment to rvalue
		static_assert(!xte::is_assignable<xte::array<int>, xte::array<int>&>);
		static_assert(!xte::is_assignable<xte::array<int>, typename[:^^int[3]:]&>);
		static_assert(!xte::is_assignable<xte::array<int>, std::vector<int>&>);

		// Move assignment to rvalue
		static_assert(!xte::is_assignable<xte::array<int>, xte::array<int>>);
		static_assert(!xte::is_assignable<xte::array<int>, int[3]>);
		static_assert(!xte::is_assignable<xte::array<int>, std::vector<int>>);

		// Copy assignment
		static_assert(xte::is_assignable<xte::array<int>&, xte::array<int>&>);
		static_assert(!xte::is_assignable<xte::array<non_constructible>&, xte::array<non_constructible>&>);
		static_assert(xte::is_assignable<xte::array<non_default_constructible>&, xte::array<non_default_constructible>&>);
		static_assert(!xte::is_assignable<xte::array<xte::non_copyable>&, xte::array<xte::non_copyable>&>);
		static_assert(xte::is_assignable<xte::array<xte::non_movable>&, xte::array<xte::non_movable>&>);
		static_assert(!xte::is_assignable_noex<xte::array<int>&, xte::array<int>&>);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array<int>())).data() == nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array<int>())).size() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array<int>())).capacity() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array { 1, 2, 3 })).data() != nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array { 1, 2, 3 })).size() == 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array { 1, 2, 3 })).capacity() >= 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array { 1, 2, 3 }))[0] == 1);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array { 1, 2, 3 }))[1] == 2);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(xte::array { 1, 2, 3 }))[2] == 3);

		// Move assignment
		static_assert(xte::is_assignable_noex<xte::array<int>&, xte::array<int>>);
		static_assert(xte::is_assignable_noex<xte::array<non_constructible>&, xte::array<non_constructible>>);
		static_assert(xte::is_assignable_noex<xte::array<non_default_constructible>&, xte::array<non_default_constructible>>);
		static_assert(xte::is_assignable_noex<xte::array<xte::non_copyable>&, xte::array<xte::non_copyable>>);
		static_assert(xte::is_assignable_noex<xte::array<xte::non_movable>&, xte::array<xte::non_movable>>);
		static_assert(xte::is_assignable_noex<xte::array<throwing_default_constructor>&, xte::array<throwing_default_constructor>>);
		static_assert(xte::is_assignable_noex<xte::array<throwing_copy_constructor>&, xte::array<throwing_copy_constructor>>);
		static_assert(xte::is_assignable_noex<xte::array<throwing_move_constructor>&, xte::array<throwing_move_constructor>>);
		static_assert(xte::is_assignable_noex<xte::array<throwing_copy_and_move_constructor>&, xte::array<throwing_copy_and_move_constructor>>);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array<int>()).data() == nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array<int>()).size() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array<int>()).capacity() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array { 1, 2, 3 }).data() != nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array { 1, 2, 3 }).size() == 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array { 1, 2, 3 }).capacity() >= 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array { 1, 2, 3 })[0] == 1);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array { 1, 2, 3 })[1] == 2);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::array { 1, 2, 3 })[2] == 3);

		// Range copy assignment
		static_assert(xte::is_assignable<xte::array<int>&, std::vector<int>&>);
		static_assert(!xte::is_assignable<xte::array<non_constructible>&, std::vector<non_constructible>&>);
		static_assert(xte::is_assignable<xte::array<non_default_constructible>&, std::vector<non_default_constructible>&>);
		static_assert(!xte::is_assignable<xte::array<xte::non_copyable>&, std::vector<xte::non_copyable>&>);
		static_assert(xte::is_assignable<xte::array<xte::non_movable>&, std::vector<xte::non_movable>&>);
		static_assert(!xte::is_assignable_noex<xte::array<int>&, std::vector<int>&>);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int>())).data() == nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int>())).size() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int>())).capacity() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int> { 1, 2, 3 })).data() != nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int> { 1, 2, 3 })).size() == 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int> { 1, 2, 3 })).capacity() >= 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int> { 1, 2, 3 }))[0] == 1);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int> { 1, 2, 3 }))[1] == 2);
		static_assert((xte::as_lvalue(xte::array<int>()) = xte::as_lvalue(std::vector<int> { 1, 2, 3 }))[2] == 3);

		// Range move assigment
		static_assert(xte::is_assignable<xte::array<int>&, std::vector<int>>);
		static_assert(!xte::is_assignable<xte::array<non_constructible>&, std::vector<non_constructible>>);
		static_assert(xte::is_assignable<xte::array<non_default_constructible>&, std::vector<non_default_constructible>>);
		static_assert(xte::is_assignable<xte::array<xte::non_copyable>&, std::vector<xte::non_copyable>>);
		static_assert(xte::is_assignable<xte::array<xte::non_movable>&, std::vector<xte::non_movable>>);
		static_assert(!xte::is_assignable_noex<xte::array<int>&, std::vector<int>>);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int>()).data() == nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int>()).size() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int>()).capacity() == 0);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int> { 1, 2, 3 }).data() != nullptr);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int> { 1, 2, 3 }).size() == 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int> { 1, 2, 3 }).capacity() >= 3);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int> { 1, 2, 3 })[0] == 1);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int> { 1, 2, 3 })[1] == 2);
		static_assert((xte::as_lvalue(xte::array<int>()) = std::vector<int> { 1, 2, 3 })[2] == 3);
	}
}
