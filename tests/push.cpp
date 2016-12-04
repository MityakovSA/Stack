#include "catch.hpp"
#include <stack.hpp>


SCENARIO("push() must add value to the top of the stack")
{
    GIVEN("Empty stack")
    {
        stack<int> s;
        WHEN("Adding an element")
        {
            s.push(0);
            THEN("push() must allocate memory for 5 elements and add value 0 to the top of the stack")
            {
                REQUIRE( ((s.size() == 5) && (s.count() == 1) && (s.pop() == 0)) == true );
            }
        }
    }
    GIVEN("Filled stack")
    {
        stack<int> s;
        s.push(0);
        s.push(1);
        WHEN("Adding an element")
        {
            s.push(2);
            THEN("Value 2 must be at the top of the stack and number of elements must be 3")
            {
                REQUIRE( ((s.count() == 3) && (s.pop() == 2)) == true );
            }
        }
    }
    GIVEN("Full stack")
    {
        stack<int> s;
        s.push(0);
        size_t size = s.size();
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        WHEN("Adding an element")
        {
            s.push(5);
            THEN("push() must reallocate memory by doubling previous and add value 5 to the top of the stack")
            {
                REQUIRE( ((s.size() == (size*2)) && (s.count() == 6) && (s.pop() == 5)) == true );
            }
        }
    }
}
