#ifndef CUNIT_H
#define CUNIT_H

#include <stdio.h>

/**
 * Asserts that the input message is true
 * @param statement boolean statement that should be true
 * @param message message desribing the test case
 */
void assertTrue(int statement, const char *message);

/**
 * Asserts that the input message is false
 * @param statement boolean statement that should be true
 * @param message message desribing the test case
 */
void assertFalse(int statement, const char *message);

/**
 * @brief checks if the input strings are equal and prints descriptive
 * pass or fail message
 */
void assertStringEq(
        const char *first_string,
        const char *second_string,
        const char *message);

/**
 * Prints a pass message to the terminal
 * @param message passed in with the test case
 */
static void pass_(const char *message);

/**
 * Prints a failing message to the terminal
 * @param message passed in with the test case
 */
static void fail_(const char *message);

/**
 * @brief Prints descriptive message on the screen indicating that
 * the two strings are different
 */
static void failed_string_compare_(
        const char *first_string,
        const char *second_string);

#endif
