#include <stack.hpp>


int main()
{
    try
    {
        stack<int> s;
        //std::cout << "Count = " << s.count() << std::endl;
        //std::cout << "Poped: " << s.pop() << std::endl;
        s.push(0);
        //std::cout << "Pushed: 0" << std::endl;
        //std::cout << "Count = " << s.count() << std::endl;
        for (int i = 1; i < 6; ++i)
        {
            s.push(i);
            //std::cout << "Pushed: " << i << std::endl;
            //std::cout << "Count = " << s.count() << std::endl;
        }
        for (int i = 0; i < 6; ++i)
        {
            std::cout << "Poped: " << s.pop() << std::endl;
            //std::cout << "Count = " << s.count() << std::endl;
        }
        //std::cout << "Count = " << s.count() << std::endl;
        //std::cout << "Poped: " << s.pop() << std::endl;
    }
    catch (std::underflow_error& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}

