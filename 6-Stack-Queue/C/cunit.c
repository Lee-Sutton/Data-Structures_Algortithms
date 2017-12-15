#include <cunit.h>
#include <memory.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void assertTrue(int statement, const char *message) {
    if (statement)
        pass_(message);
    else
        fail_(message);
}

void assertFalse(int statement, const char *message) {
    if (!statement)
        pass_(message);
    else
        fail_(message);
}

void assertStringEq(
        const char *first_string,
        const char *second_string,
        const char *message) {
    if (strcmp(first_string, second_string) == 0)
        pass_(message);
    else
        failed_string_compare_(first_string, second_string);

}

/*
*******************************************************************************
 * Static methods
*******************************************************************************
 */


static void pass_(const char *message) {
    printf("%s[PASS] %s%s\n",
           ANSI_COLOR_GREEN, ANSI_COLOR_RESET, message);

}

static void fail_(const char *message) {
    printf("%s[FAIL] %s%s\n",
           ANSI_COLOR_RED, ANSI_COLOR_RESET, message);
}

static void failed_string_compare_(
        const char *first_string,
        const char *second_string) {

    printf("%s[FAIL]%s %s != %s\n",
           ANSI_COLOR_RED,
           ANSI_COLOR_RESET,
           first_string,
           second_string);
}