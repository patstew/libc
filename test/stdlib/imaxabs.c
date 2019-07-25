/*
 * Copyright © 2017 Embedded Artistry LLC.
 * License: MIT. See LICENSE file for details.
 */

#include "stdlib_tests.h"
#include <stdlib.h>

// Cmocka needs these
// clang-format off
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>
// clang-format on

#pragma mark - Private Functions -

static void imaxabs_test(void** state)
{
	assert_int_equal(imaxabs(0), 0);
	assert_int_equal(imaxabs(1), 1);
	assert_int_equal(imaxabs(-1), 1);
	assert_int_equal(imaxabs(INTMAX_MAX), INTMAX_MAX);
	assert_int_equal(imaxabs(-INTMAX_MAX), INTMAX_MAX);
	assert_int_equal(imaxabs(INTMAX_MIN), INTMAX_MIN);

	// We add one to prevent an overflow warning with -INTMAX_MIN
	assert_int_equal(imaxabs(-(INTMAX_MIN + 1)), (INTMAX_MIN + 1));
}

#pragma mark - Public Functions -

int imaxabs_tests(void)
{
	const struct CMUnitTest imaxabs_tests[] = {cmocka_unit_test(imaxabs_test)};

	return cmocka_run_group_tests(imaxabs_tests, NULL, NULL);
}
