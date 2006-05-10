/*
 *      Copyright (C) 2006 Free Software Foundation
 *      Copyright (C) 2002 Fabio Fiorina
 *
 * This file is part of LIBTASN1.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */


/******************************************************/
/* File: Test_encoding.c                              */
/* Description: Test writing values and DER encoding. */
/******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libtasn1.h"


unsigned char data[256];
int data_size = sizeof (data);


int
main (int argc, char *argv[])
{
  asn1_retCode result;
  ASN1_TYPE definitions = ASN1_TYPE_EMPTY;
  ASN1_TYPE asn1_element = ASN1_TYPE_EMPTY;
  char errorDescription[MAX_ERROR_DESCRIPTION_SIZE];
  unsigned char value[1024], der[1024];
  int valueLen, tag = 0, class = 0;
  int k;
  int start, end;
  const char *str_p = NULL;
  const char *treefile = getenv ("ASN1ENCODING");

  if (!treefile)
    treefile = "Test_encoding.asn";

  printf ("\n\n/****************************************/\n");
  printf ("/*     Test sequence : coding-decoding  */\n");
  printf ("/****************************************/\n\n");

  /* Check version */
  if (asn1_check_version ("0.3.3") == NULL)
    printf ("\nLibrary version check ERROR:\n actual version: %s\n\n",
	    asn1_check_version (NULL));

  result = asn1_parser2tree (treefile, &definitions, errorDescription);

  if (result != ASN1_SUCCESS)
    {
      libtasn1_perror (result);
      printf ("ErrorDescription = %s\n\n", errorDescription);
      exit (1);
    }

  result = asn1_create_element (definitions, "TEST_TREE.Koko", &asn1_element);
  if (result != ASN1_SUCCESS)
    {
      fprintf (stderr, "asn1_create_element(): ");
      libtasn1_perror (result);
      exit (1);
    }

  result = asn1_write_value (asn1_element, "seqint", "NEW", 1);
  if (result != ASN1_SUCCESS)
    {
      fprintf (stderr, "asn1_write_value(): seqint ");
      libtasn1_perror (result);
      exit (1);
    }

  result = asn1_write_value (asn1_element, "seqint.?LAST", "1234", 0);
  if (result != ASN1_SUCCESS)
    {
      fprintf (stderr, "asn1_write_value(): seqint.?LAST ");
      libtasn1_perror (result);
      exit (1);
    }

  result = asn1_write_value (asn1_element, "int", "\x0f\xff\x01", 3);
  if (result != ASN1_SUCCESS)
    {
      fprintf (stderr, "asn1_write_value(): int ");
      libtasn1_perror (result);
      exit (1);
    }

  result = asn1_write_value (asn1_element, "str", "string", 6);
  if (result != ASN1_SUCCESS)
    {
      fprintf (stderr, "asn1_write_value(): str ");
      libtasn1_perror (result);
      exit (1);
    }

  /* Clear the definition structures */
  asn1_delete_structure (&definitions);

  result = asn1_der_coding (asn1_element, "", data, &data_size, NULL);
  if (result != ASN1_SUCCESS)
    {
      fprintf (stderr, "Encoding error.\n");
      libtasn1_perror (result);
      exit (1);
    }

  result = asn1_der_decoding (&asn1_element, data, data_size, NULL);
  if (result != ASN1_SUCCESS)
    {
      fprintf (stderr, "Decoding error.\n");
      libtasn1_perror (result);
      exit (1);
    }


  printf ("Success\n");
  exit (0);
}
