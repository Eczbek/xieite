#include <xte/data/array.hpp>
#include <xte/data/non_copyable.hpp>
#include <xte/data/non_movable.hpp>
#include <xte/trait/is_brace_constructible.hpp>
#include <xte/trait/is_brace_constructible_noex.hpp>
#include <xte/trait/is_constructible.hpp>
#include <xte/trait/is_constructible_noex.hpp>
#include <xte/trait/is_implicit_constructible_noex.hpp>
#include <xte/trait/is_implicit_copy_constructible.hpp>
#include <xte/trait/is_implicit_copy_constructible_noex.hpp>
#include <xte/trait/is_implicit_move_constructible_noex.hpp>
#include <xte/util/as_lvalue.hpp>
#include <xte/util/as_xvalue.hpp>
#include <xte/util/number_types.hpp>
#include <iterator>
#include <ranges>
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

// Default constructor
static_assert(xte::is_implicit_constructible_noex<xte::array<int>>);
static_assert(xte::is_implicit_constructible_noex<xte::array<non_constructible>>);
static_assert(xte::is_implicit_constructible_noex<xte::array<non_default_constructible>>);
static_assert(xte::is_implicit_constructible_noex<xte::array<xte::non_copyable>>);
static_assert(xte::is_implicit_constructible_noex<xte::array<xte::non_movable>>);
static_assert(xte::is_implicit_constructible_noex<xte::array<throwing_default_constructor>>);
static_assert(xte::is_brace_constructible_noex<xte::array<int>>);
static_assert(xte::is_brace_constructible_noex<xte::array<non_constructible>>);
static_assert(xte::is_brace_constructible_noex<xte::array<non_default_constructible>>);
static_assert(xte::is_brace_constructible_noex<xte::array<xte::non_copyable>>);
static_assert(xte::is_brace_constructible_noex<xte::array<xte::non_movable>>);
static_assert(xte::is_brace_constructible_noex<xte::array<throwing_default_constructor>>);
static_assert(xte::array<int>().data() == nullptr);
static_assert(xte::array<int>().size() == 0);
static_assert(xte::array<int>().capacity() == 0);
static_assert((xte::array<int> {}).data() == nullptr);
static_assert((xte::array<int> {}).size() == 0);
static_assert((xte::array<int> {}).capacity() == 0);

// Copy constructor
static_assert(xte::is_implicit_copy_constructible<xte::array<int>>);
static_assert(!xte::is_implicit_copy_constructible<xte::array<non_constructible>>);
static_assert(xte::is_implicit_copy_constructible<xte::array<non_default_constructible>>);
static_assert(!xte::is_implicit_copy_constructible<xte::array<xte::non_copyable>>);
static_assert(xte::is_implicit_copy_constructible<xte::array<xte::non_movable>>);
static_assert(!xte::is_implicit_copy_constructible_noex<xte::array<int>>);
static_assert(auto(xte::as_lvalue(xte::array<int>())).data() == nullptr);
static_assert(auto(xte::as_lvalue(xte::array<int>())).size() == 0);
static_assert(auto(xte::as_lvalue(xte::array<int>())).capacity() == 0);
static_assert(auto(xte::as_lvalue(xte::array<int> { 1, 2, 3 })).data() != nullptr);
static_assert(auto(xte::as_lvalue(xte::array<int> { 1, 2, 3 })).size() == 3);
static_assert(auto(xte::as_lvalue(xte::array<int> { 1, 2, 3 })).capacity() >= 3);
static_assert(auto(xte::as_lvalue(xte::array<int> { 1, 2, 3 }))[0] == 1);
static_assert(auto(xte::as_lvalue(xte::array<int> { 1, 2, 3 }))[1] == 2);
static_assert(auto(xte::as_lvalue(xte::array<int> { 1, 2, 3 }))[2] == 3);

// Move constructor
static_assert(xte::is_implicit_move_constructible_noex<xte::array<int>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<non_constructible>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<non_default_constructible>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<xte::non_copyable>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<xte::non_movable>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<throwing_default_constructor>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<throwing_copy_constructor>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<throwing_move_constructor>>);
static_assert(xte::is_implicit_move_constructible_noex<xte::array<throwing_copy_and_move_constructor>>);
static_assert(auto(xte::as_xvalue(xte::array<int>())).data() == nullptr);
static_assert(auto(xte::as_xvalue(xte::array<int>())).size() == 0);
static_assert(auto(xte::as_xvalue(xte::array<int>())).capacity() == 0);
static_assert(auto(xte::as_xvalue(xte::array<int> { 1, 2, 3 })).data() != nullptr);
static_assert(auto(xte::as_xvalue(xte::array<int> { 1, 2, 3 })).size() == 3);
static_assert(auto(xte::as_xvalue(xte::array<int> { 1, 2, 3 })).capacity() >= 3);
static_assert(auto(xte::as_xvalue(xte::array<int> { 1, 2, 3 }))[0] == 1);
static_assert(auto(xte::as_xvalue(xte::array<int> { 1, 2, 3 }))[1] == 2);
static_assert(auto(xte::as_xvalue(xte::array<int> { 1, 2, 3 }))[2] == 3);

// Initializer-list constructor
static_assert(xte::is_brace_constructible<xte::array<int>, int>);
static_assert(!xte::is_brace_constructible<xte::array<non_constructible>, non_constructible>);
static_assert(xte::is_brace_constructible<xte::array<non_default_constructible>, non_default_constructible>);
static_assert(xte::is_brace_constructible<xte::array<xte::non_copyable>, xte::non_copyable>);
static_assert(xte::is_brace_constructible<xte::array<xte::non_movable>, xte::non_movable>);
static_assert(xte::is_brace_constructible<xte::array<throwing_default_constructor>, throwing_default_constructor>);
static_assert(xte::is_brace_constructible<xte::array<throwing_copy_constructor>, throwing_copy_constructor>);
static_assert(xte::is_brace_constructible<xte::array<throwing_move_constructor>, throwing_move_constructor>);
static_assert(xte::is_brace_constructible<xte::array<throwing_copy_and_move_constructor>, throwing_copy_and_move_constructor>);
static_assert(!xte::is_brace_constructible_noex<xte::array<int>, int>);
static_assert(!noexcept(xte::array { 1, 2, 3 }));
static_assert((xte::array<int> { 1, 2, 3 }).data() != nullptr);
static_assert((xte::array<int> { 1, 2, 3 }).size() == 3);
static_assert((xte::array<int> { 1, 2, 3 }).capacity() >= 3);
static_assert((xte::array<int> { 1, 2, 3 })[0] == 1);
static_assert((xte::array<int> { 1, 2, 3 })[1] == 2);
static_assert((xte::array<int> { 1, 2, 3 })[2] == 3);
static_assert((xte::array { 1, 2, 3 }).data() != nullptr);
static_assert((xte::array { 1, 2, 3 }).size() == 3);
static_assert((xte::array { 1, 2, 3 }).capacity() >= 3);
static_assert((xte::array { 1, 2, 3 })[0] == 1);
static_assert((xte::array { 1, 2, 3 })[1] == 2);
static_assert((xte::array { 1, 2, 3 })[2] == 3);

// Range copy constructor
static_assert(xte::is_constructible<xte::array<int>, std::from_range_t, std::vector<int>&>);
static_assert(!xte::is_constructible<xte::array<non_constructible>, std::from_range_t, std::vector<non_constructible>&>);
static_assert(xte::is_constructible<xte::array<non_default_constructible>, std::from_range_t, std::vector<non_default_constructible>&>);
static_assert(!xte::is_constructible<xte::array<xte::non_copyable>, std::from_range_t, std::vector<xte::non_copyable>&>);
static_assert(xte::is_constructible<xte::array<xte::non_movable>, std::from_range_t, std::vector<xte::non_movable>&>);
static_assert(!xte::is_constructible_noex<xte::array<int>, std::from_range_t, std::vector<int>&>);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int>()))).data() == nullptr);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int>()))).size() == 0);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int>()))).capacity() == 0);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int> { 1, 2, 3 }))).data() != nullptr);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int> { 1, 2, 3 }))).size() == 3);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int> { 1, 2, 3 }))).capacity() >= 3);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int> { 1, 2, 3 })))[0] == 1);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int> { 1, 2, 3 })))[1] == 2);
static_assert((xte::array<int>(std::from_range, xte::as_lvalue(std::vector<int> { 1, 2, 3 })))[2] == 3);

// Range move constructor
static_assert(xte::is_constructible<xte::array<int>, std::from_range_t, std::vector<int>>);
static_assert(!xte::is_constructible<xte::array<non_constructible>, std::from_range_t, std::vector<non_constructible>>);
static_assert(xte::is_constructible<xte::array<non_default_constructible>, std::from_range_t, std::vector<non_default_constructible>>);
static_assert(xte::is_constructible<xte::array<xte::non_copyable>, std::from_range_t, std::vector<xte::non_copyable>>);
static_assert(xte::is_constructible<xte::array<xte::non_movable>, std::from_range_t, std::vector<xte::non_movable>>);
static_assert(!xte::is_constructible_noex<xte::array<int>, std::from_range_t, std::vector<int>>);
static_assert((xte::array<int>(std::from_range, std::vector<int>())).data() == nullptr);
static_assert((xte::array<int>(std::from_range, std::vector<int>())).size() == 0);
static_assert((xte::array<int>(std::from_range, std::vector<int>())).capacity() == 0);
static_assert((xte::array<int>(std::from_range, std::vector<int> { 1, 2, 3 })).data() != nullptr);
static_assert((xte::array<int>(std::from_range, std::vector<int> { 1, 2, 3 })).size() == 3);
static_assert((xte::array<int>(std::from_range, std::vector<int> { 1, 2, 3 })).capacity() >= 3);
static_assert((xte::array<int>(std::from_range, std::vector<int> { 1, 2, 3 }))[0] == 1);
static_assert((xte::array<int>(std::from_range, std::vector<int> { 1, 2, 3 }))[1] == 2);
static_assert((xte::array<int>(std::from_range, std::vector<int> { 1, 2, 3 }))[2] == 3);

// Delegating range move constructor
static_assert(xte::is_constructible_noex<xte::array<int>, std::from_range_t, xte::array<int>>);
static_assert(xte::is_constructible_noex<xte::array<non_constructible>, std::from_range_t, xte::array<non_constructible>>);
static_assert(xte::is_constructible_noex<xte::array<non_default_constructible>, std::from_range_t, xte::array<non_default_constructible>>);
static_assert(xte::is_constructible_noex<xte::array<xte::non_copyable>, std::from_range_t, xte::array<xte::non_copyable>>);
static_assert(xte::is_constructible_noex<xte::array<xte::non_movable>, std::from_range_t, xte::array<xte::non_movable>>);
static_assert(xte::is_constructible_noex<xte::array<throwing_default_constructor>, std::from_range_t, xte::array<throwing_default_constructor>>);
static_assert(xte::is_constructible_noex<xte::array<throwing_copy_constructor>, std::from_range_t, xte::array<throwing_copy_constructor>>);
static_assert(xte::is_constructible_noex<xte::array<throwing_move_constructor>, std::from_range_t, xte::array<throwing_move_constructor>>);
static_assert(xte::is_constructible_noex<xte::array<throwing_copy_and_move_constructor>, std::from_range_t, xte::array<throwing_copy_and_move_constructor>>);

// Iterator pair constructor
static_assert(xte::is_constructible<xte::array<int>, int*, int*>);
static_assert(!xte::is_constructible<xte::array<non_constructible>, non_constructible*, non_constructible*>);
static_assert(xte::is_constructible<xte::array<non_default_constructible>, non_default_constructible*, non_default_constructible*>);
static_assert(!xte::is_constructible<xte::array<xte::non_copyable>, xte::non_copyable*, xte::non_copyable*>);
static_assert(xte::is_constructible<xte::array<xte::non_movable>, xte::non_movable*, xte::non_movable*>);
static_assert(!xte::is_constructible_noex<xte::array<int>, int*, int*>);
consteval {
	static constexpr typename[:^^int[]:] data = { 1, 2, 3 };
	static_assert(xte::array<int>(std::begin(data), std::begin(data)).data() == nullptr);
	static_assert(xte::array<int>(std::begin(data), std::begin(data)).size() == 0);
	static_assert(xte::array<int>(std::begin(data), std::begin(data)).capacity() == 0);
	static_assert(xte::array<int>(std::end(data), std::end(data)).data() == nullptr);
	static_assert(xte::array<int>(std::end(data), std::end(data)).size() == 0);
	static_assert(xte::array<int>(std::end(data), std::end(data)).capacity() == 0);
	static_assert(xte::array<int>(std::begin(data), std::end(data)).data() != nullptr);
	static_assert(xte::array<int>(std::begin(data), std::end(data)).size() == 3);
	static_assert(xte::array<int>(std::begin(data), std::end(data)).capacity() >= 3);
	static_assert(xte::array<int>(std::begin(data), std::end(data))[0] == 1);
	static_assert(xte::array<int>(std::begin(data), std::end(data))[1] == 2);
	static_assert(xte::array<int>(std::begin(data), std::end(data))[2] == 3);
}

// Default-fill constructor
static_assert(xte::is_constructible<xte::array<int>, xte::uz>);
static_assert(!xte::is_constructible<xte::array<non_constructible>, xte::uz>);
static_assert(!xte::is_constructible<xte::array<non_default_constructible>, xte::uz>);
static_assert(xte::is_constructible<xte::array<xte::non_copyable>, xte::uz>);
static_assert(xte::is_constructible<xte::array<xte::non_movable>, xte::uz>);
static_assert(!xte::is_constructible_noex<xte::array<int>, xte::uz>);
static_assert(xte::array<int>(0).data() == nullptr);
static_assert(xte::array<int>(0).size() == 0);
static_assert(xte::array<int>(0).capacity() == 0);
static_assert(xte::array<int>(3).data() != nullptr);
static_assert(xte::array<int>(3).size() == 3);
static_assert(xte::array<int>(3).capacity() >= 3);
static_assert(xte::array<int>(3)[0] == 0);
static_assert(xte::array<int>(3)[1] == 0);
static_assert(xte::array<int>(3)[2] == 0);

// Copy-fill constructor
static_assert(xte::is_constructible<xte::array<int>, xte::uz, int>);
static_assert(!xte::is_constructible<xte::array<non_constructible>, xte::uz, non_constructible>);
static_assert(xte::is_constructible<xte::array<non_default_constructible>, xte::uz, non_default_constructible>);
static_assert(!xte::is_constructible<xte::array<xte::non_copyable>, xte::uz, xte::non_copyable>);
static_assert(xte::is_constructible<xte::array<xte::non_movable>, xte::uz>);
static_assert(!xte::is_constructible_noex<xte::array<int>, xte::uz, int>);
static_assert(xte::array<int>(0, 9).data() == nullptr);
static_assert(xte::array<int>(0, 9).size() == 0);
static_assert(xte::array<int>(0, 9).capacity() == 0);
static_assert(xte::array<int>(3, 9).data() != nullptr);
static_assert(xte::array<int>(3, 9).size() == 3);
static_assert(xte::array<int>(3, 9).capacity() >= 3);
static_assert(xte::array<int>(3, 9)[0] == 9);
static_assert(xte::array<int>(3, 9)[1] == 9);
static_assert(xte::array<int>(3, 9)[2] == 9);
