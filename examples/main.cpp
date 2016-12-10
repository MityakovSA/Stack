#include <stack.hpp>
#include <iostream>


int main()
{
    stack<int> s;
    std::cout << s.empty() << std::endl;
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Inserting: " << i << std::endl;
        s.push(i);
    }
    std::cout << s.empty() << std::endl;
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Deleting: " << *s.top() << std::endl;
        s.pop();
        if (!s.empty()) std::cout << "Now top is: " << *s.top() << std::endl;
    }
    std::cout << s.empty() << std::endl;
    return 0;
}

