/*
 * Copyright (C) 2019 Free Software Foundation, Inc.
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
/* Description: reproducer for endless loop with a single node  */
/****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libtasn1.h>

/* That translates to a single node with all pointers (right,left,down) set to NULL */
const asn1_static_node endless_asn1_tab[] = {
  { "TEST_TREE", 536875024, NULL },
  { NULL, 0, NULL }
};

int
main (int argc, char *argv[])
{
  int result, verbose = 0;
  asn1_node definitions = NULL;
  char errorDescription[ASN1_MAX_ERROR_DESCRIPTION_SIZE];

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

  if (verbose)
    printf ("Success\n");

  exit (EXIT_SUCCESS);
}
