#include "catch.hpp"
#include <stack.hpp>


SCENARIO("pop() must delete the top element of the stack")
{
    GIVEN("Filled stack")
    {
        stack<int> s;
        s.push(0);
        s.push(1);
        s.push(2);
        WHEN("Calling pop()")
        {
            s.pop();
            THEN("pop() must delete value 2 from the top")
            {
                REQUIRE(s.count() == 2);
                REQUIRE(s.top() == 1);
            }
        }
    }
    GIVEN("Empty stack")
    {
        stack<int> s;
        WHEN("Calling pop()")
        {
            s.pop();
            THEN("pop() must not do anything")
            {
                REQUIRE(s.count() == 0);
                REQUIRE_THROWS_AS(s.top(), std::underflow_error);
            }
        }
    }
}

