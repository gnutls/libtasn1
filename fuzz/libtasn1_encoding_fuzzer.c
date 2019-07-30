/*
 * Copyright(c) 2019 Free Software Foundation, Inc.
 *
 * This file is part of libtasn1.
 *
 * Libtasn1 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Libtasn1 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libtasn1.  If not, see <https://www.gnu.org/licenses/>.
 *
 * This fuzzer is testing the combination of asn1_parser2tree(),
 * asn1_create_element(), asn1_write_value(), asn1_der_coding() and
 * asn1_der_decoding() with arbitrary input data.
 *
 * This is a test for robustness, not for functionality.
 */

#include <config.h>

#include <assert.h> // assert
#include <stdlib.h> // malloc, free
#include <string.h> // strcmp, memcpy

#include "libtasn1.h"
#include "fuzzer.h"

static const uint8_t *g_data;
static size_t g_size;

#if defined HAVE_DLFCN_H && defined HAVE_FMEMOPEN
#include <dlfcn.h>
#ifdef RTLD_NEXT /* Not defined e.g. on CygWin */

FILE *fopen(const char *pathname, const char *mode) {
  FILE * (*libc_fopen)(const char *, const char *) =
    (FILE * (*)(const char *, const char *)) dlsym(RTLD_NEXT, "fopen");

  if (!strcmp(pathname, "pkix.asn"))
    return fmemopen((void *) g_data, g_size, mode);

  return libc_fopen(pathname, mode);
}
#endif
#endif

uint8_t der[256];

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
	char errorDescription[ASN1_MAX_ERROR_DESCRIPTION_SIZE];
	asn1_node definitions = NULL;
	asn1_node asn1_element = NULL;
	uint8_t *value = NULL, *value0 = NULL;

	if (size > 2048) // same as max_len = 1000 in .options file
		return 0;

	g_data = data;
	g_size = size;

	int rc = asn1_parser2tree("pkix.asn", &definitions, errorDescription);
	if (rc != ASN1_SUCCESS)
		return 0;

	rc = asn1_create_element(definitions, "TEST_TREE.Koko", &asn1_element);
	if (rc != ASN1_SUCCESS)
		goto out;

	size_t vlen = size <= 32 ? size : 32;
	value = malloc(vlen);
	assert(value);
	memcpy(value, data, vlen);

	size_t vlen0 = vlen ? vlen - 1 : 0;
	value0 = malloc(vlen0 + 1);
	assert(value0);
	memcpy(value0, data, vlen0);
	value0[vlen0] = 0;

	asn1_write_value(asn1_element, "seqint", value0, 0);
	asn1_write_value(asn1_element, "seqint", value, vlen);
	asn1_write_value(asn1_element, "seqint.?LAST", value0, 0);
	asn1_write_value(asn1_element, "seqint.?LAST", value, vlen);
	asn1_write_value(asn1_element, "int", value0, 0);
	asn1_write_value(asn1_element, "int", value, vlen);
	asn1_write_value(asn1_element, "str", value0, 0);
	asn1_write_value(asn1_element, "str", value, vlen);
	asn1_write_value(asn1_element, "a", value0, 0);
	asn1_write_value(asn1_element, "a", value, vlen);
	asn1_write_value(asn1_element, "b", value0, 0);
	asn1_write_value(asn1_element, "b", value, vlen);
	asn1_write_value(asn1_element, "c", value0, 0);
	asn1_write_value(asn1_element, "c", value, vlen);
	asn1_write_value(asn1_element, "exp", value0, 0);
	asn1_write_value(asn1_element, "exp", value, vlen);

	asn1_delete_structure(&definitions);

	int der_size = sizeof(der);
	if (asn1_der_coding(asn1_element, "", der, &der_size, NULL) != ASN1_SUCCESS)
		goto out;

	asn1_der_decoding(&asn1_element, der, der_size, NULL);

out:
	asn1_delete_structure(&asn1_element);
	asn1_delete_structure(&definitions);
	free(value0);
	free(value);
	return 0;
}
