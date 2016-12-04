#include "catch.hpp"
#include <stack.hpp>


SCENARIO("pop() must delete the top element of the stack and return its value")
{
    GIVEN("Filled stack")
    {
        stack<int> s;
        s.push(0);
        s.push(1);
        s.push(2);
        WHEN("Calling pop()")
        {
            THEN("pop() must delete value 2 from the top and return it")
            {
                REQUIRE( ((s.pop() == 2) && (s.count() == 2) && (s.pop() == 1)) == true );
            }
        }
    }
    GIVEN("Empty stack")
    {
        stack<int> s;
        WHEN("Calling pop()")
        {
            THEN("pop() must throw exception of the type underflow_error")
            {
                REQUIRE_THROWS_AS(s.pop(), std::underflow_error);
            }
        }
    }
}

