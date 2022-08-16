/*
 * Copyright (C) 2019-2022 Free Software Foundation, Inc.
 *
 * This file is part of LIBTASN1.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/****************************************************************/
/* Description: run reproducers for several fixed issues        */
/****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libtasn1.h>

#include <int.h>

/* produces endless loop (fixed by d4b624b2):
 * The following translates into a single node with all pointers
 * (right,left,down) set to NULL. */
const asn1_static_node endless_asn1_tab[] = {
  {"TEST_TREE", 536875024, NULL},
  {NULL, 0, NULL}
};

/* produces memory leak (fixed by f16d1ff9):
 * 152 bytes in 1 blocks are definitely lost in loss record 1 of 1
 *    at 0x4837B65: calloc (vg_replace_malloc.c:762)
 *    by 0x4851C0D: _asn1_add_static_node (parser_aux.c:71)
 *    by 0x4853AAC: asn1_array2tree (structure.c:200)
 *    by 0x10923B: main (single_node.c:67)
 */
const asn1_static_node tab[] = {
  {"a", CONST_DOWN, ""},
  {"b", 0, ""},
  {"c", 0, ""},
  {NULL, 0, NULL}
};

int
main (int argc, char *argv[])
{
  int result, verbose = 0;
  asn1_node definitions = NULL;
  char errorDescription[ASN1_MAX_ERROR_DESCRIPTION_SIZE];
  char *out = errorDescription;
  int i;

  printf ("Header version %s library version %s\n",
	  ASN1_VERSION, asn1_check_version (NULL));

  if (!asn1_check_version (ASN1_VERSION))
    {
      printf ("asn1_check_version failure\n");
      exit (EXIT_FAILURE);
    }

  if (!asn1_check_version ("4.17.0"))
    {
      printf ("asn1_check_version(4.17.0) failure\n");
      exit (EXIT_FAILURE);
    }

  if (!asn1_check_version ("4.17"))
    {
      printf ("asn1_check_version(4.17) failure\n");
      exit (EXIT_FAILURE);
    }

  if (strcmp (ASN1_VERSION, asn1_check_version (NULL)) != 0)
    {
      printf ("header version mismatch library version\n");
      exit (EXIT_FAILURE);
    }

  i = ASN1_VERSION_MAJOR * 256 * 256 +
    ASN1_VERSION_MINOR * 256 + ASN1_VERSION_PATCH;

  snprintf (out, ASN1_MAX_ERROR_DESCRIPTION_SIZE - 1, "%d.%d.%d",
	    ASN1_VERSION_MAJOR, ASN1_VERSION_MINOR, ASN1_VERSION_PATCH);

  printf ("Header version %s number %x derived %x\n", out,
	  (unsigned) ASN1_VERSION_NUMBER, (unsigned) i);

  if (ASN1_VERSION_NUMBER != i)
    {
      printf ("header version number mismatch\n");
      exit (EXIT_FAILURE);
    }

  if (!asn1_check_version (out))
    {
      printf ("asn1_check_version(%s) failure\n", out);
      exit (EXIT_FAILURE);
    }

  if (strncmp (ASN1_VERSION, out, strlen (out)) != 0)
    {
      printf ("header version numbers mismatch library version\n");
      exit (EXIT_FAILURE);
    }

  if (argc > 1)
    verbose = 1;

  result = asn1_array2tree (endless_asn1_tab, &definitions, errorDescription);
  if (result != ASN1_SUCCESS)
    {
      asn1_perror (result);
      printf ("ErrorDescription = %s\n\n", errorDescription);
      exit (EXIT_FAILURE);
    }

  asn1_delete_structure (&definitions);

  definitions = NULL;
  result = asn1_array2tree (tab, &definitions, errorDescription);
  if (result != ASN1_SUCCESS)
    {
      asn1_perror (result);
      printf ("ErrorDescription = %s\n\n", errorDescription);
      exit (EXIT_FAILURE);
    }

  asn1_delete_structure (&definitions);

  if (verbose)
    printf ("Success\n");

  exit (EXIT_SUCCESS);
}
