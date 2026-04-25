

#include "str.hpp"
#include <iostream>

// This main function is just a placeholder to ensure the str.hpp file is included
// in the compilation. The OJ will test the str class implementation directly.
int main() {
    // Create some test cases to ensure the code compiles and works
    str s1;
    str s2('a');
    str s3("hello");
    str s4 = "world";
    
    // Test operator[]
    s4[0] = 'W';
    
    // Test len()
    std::cout << "Length of s3: " << s3.len() << std::endl;
    
    // Test slice()
    str s5 = s3.slice(1, 4);
    std::cout << "Slice of s3: " << s5 << std::endl;
    
    // Test join()
    std::vector<str> strs = {"1", "2", "3"};
    str separator(", ");
    str result = separator.join(strs);
    std::cout << "Joined string: " << result << std::endl;
    
    return 0;
}

// We need to provide an operator<< for str to work with cout
std::ostream& operator<<(std::ostream& os, const str& s) {
    if (s.len() > 0) {
        os << s.data;
    }
    return os;
}

