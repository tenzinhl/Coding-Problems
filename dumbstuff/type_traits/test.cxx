#include <type_traits>
#include <iostream>

auto func2(char) -> int (*)()
{
    return nullptr;
}

enum color : int {
	red = -1,
	yellow = 15,
	green = 0,
	orange,
	NUMBER_OF_COLORS
};

class A {
public:
	static inline int c_int = 5;
};

int main()
{
    static_assert( std::is_invocable_v<int()> );
    static_assert( not std::is_invocable_v<int(), int> );
    static_assert( std::is_invocable_r_v<int, int()> );
    static_assert( not std::is_invocable_r_v<int*, int()> );
    static_assert( std::is_invocable_r_v<void, void(int), int> );
    static_assert( not std::is_invocable_r_v<void, void(int), void> );
    static_assert( std::is_invocable_r_v<int(*)(), decltype(func2), char> );
    static_assert( not std::is_invocable_r_v<int(*)(), decltype(func2), void> );
    
    std::cout << static_cast<int>(color::red) << std::endl;
    // IT EVALUATED TO TRUE??? Okay, yikes.
		std::cout << "class comparison evaluated to: " << (color::red == color::NUMBER_OF_COLORS) << std::endl;
		std::cout << "static_cast comparison evaluated to: " 
			<< (static_cast<int>(color::red) == static_cast<int>(color::NUMBER_OF_COLORS)) << std::endl;
		std::cout << A::c_int << std::endl;
		std::cout << "NUMBER_OF_COLORS > red: " << (color::NUMBER_OF_COLORS > color::red) << std::endl;
}
