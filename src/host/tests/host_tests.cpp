/**
 * \file   host_tests.cpp
 * \brief  Main executable automated tests.
 * \author Copyright (c) 2002-2008 Jason Perkins and the Premake project
 */

#include "premake.h"
#include "testing/testing.h"
extern "C" {
#include "host/host.h"
#include "base/base.h"
#include "script/script.h"
#include "objects/objects.h"
}

	
/**
 * Run the automated host tests.
 * \returns OKAY if all tests completed successfully.
 * \note    Also runs the tests for all dependencies, which for the host is everything.
 */
int host_tests()
{
	int z = OKAY;
	if (z == OKAY)  z = base_tests();
	if (z == OKAY)  z = script_tests();
	if (z == OKAY)  z = objects_tests();
	if (z == OKAY)  z = tests_run_suite("action");
	if (z == OKAY)  z = tests_run_suite("host");
	return z;
}
