/* SPDX-License-Identifier: BSD-3-Clause
* Copyright (c) 2024 Nokia
*/

#ifndef EXPORT_RESULT_H
#define EXPORT_RESULT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <odp/helper/odph_api.h>

typedef struct {
	/** Export results or no */
	odp_bool_t is_export;
} test_common_options_t;

/**
* Parse test options.
*
* Parse commonly used universal test options.
*
* Exports test results into current working directory as <test>_output.csv by default.
* Optional argument should be full path including filename.
*
* Returns new argument count. Original argument count decremented by the number of removed
* helper options.
*/
int test_common_parse_options(int argc, char *argv[]);

/**
* Get test options
*
* Return used test options. test_common_parse_options() must be called before
* using this function. Opens file for writing
*
* Returns 0 on success, -1 on failure
*/
int test_common_options(test_common_options_t *options, const char *filename);

/**
* Export test results
*
* Only call this function after test_common_options() returns is_export = true.
*
* Lines should be separated by "\n" and the first line should contain the column headers.
* Columns are separated by commas (,) i.e.:
* Function name,Average CPU cycles per function call
* odp_buffer_from_event,0.366660
* odp_buffer_from_event_multi,11.889800
* ...
* odp_event_flow_id_set,3.555640
*
* Returns 0 on success, -1 on failure
*/
int test_common_write(const char *fmt, ...);

/**
 * Terminate writing
 *
 * Called after last write. Do not call test_common_write after calling this.
 *
 * Returns 0 on success, -1 on failure
 */
int test_common_write_term(void);

#ifdef __cplusplus
}
#endif

#endif
