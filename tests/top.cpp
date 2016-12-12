#include "catch.hpp"
#include <stack.hpp>


SCENARIO("top() must return the top element of the stack")
{
    GIVEN("Filled stack")
    {
        stack<int> s;
        s.push(0);
        s.push(1);
        s.push(2);
        WHEN("Calling top()")
        {
            THEN("top() must return 2")
            {
                REQUIRE(s.top() == 2);
            }
        }
    }
    GIVEN("Empty stack")
    {
        stack<int> s;
        WHEN("Calling top()")
        {
            THEN("top() throw exception which type is underflow_error")
            {
                REQUIRE_THROWS_AS(s.top(), std::underflow_error);
            }
        }
    }
}
