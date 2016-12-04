#include "catch.hpp"
#include <stack.hpp>


SCENARIO("count() must return number of elements in the stack")
{
    GIVEN("Empty stack")
    {
        stack<int> s;
        WHEN("Calling count()")
        {
            THEN("count() must return 0")
            {
                REQUIRE(s.count() == 0);
            }
        }
    }

    GIVEN("Filled stack")
    {
        stack<int> s;
        s.push(0);
        s.push(1);
        s.push(2);
        WHEN("Calling count()")
        {
            THEN("count() must return 3")
            {
                REQUIRE(s.count() == 3);
            }
        }
    }
}
