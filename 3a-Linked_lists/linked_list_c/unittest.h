#include <stdio.h>

/**
 * Assertion with message. Continues on failure
 */
void checkEqualM(int statement, const char* message)
{
    if (statement)
    {
        printf("[PASS] %s", message);
    }
    else
    {
        printf("[FAIL] %s", message);
    }
}

/**
 * Basic assert statement allows tests to continue if failed
 */
void checkEqual(int statement)
{
    if (statement)
    {
        printf("[PASS]");
    }
    else
    {
        printf("[FAIL]");
    }
}
