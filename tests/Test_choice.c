#include <stdio.h>
#include <stdlib.h>
#include <libtasn1.h>

int
main (int argc, char** argv)
{
  int result = 0;
  asn1_node definitions = NULL, node1 = NULL, node2 = NULL;
  char errorDescription[ASN1_MAX_ERROR_DESCRIPTION_SIZE];

  char data[1024];
  int data_size = sizeof (data);

  /* Encode */
  result = asn1_parser2tree ("choice.asn", &definitions, errorDescription);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  result = asn1_create_element (definitions, "TEST.Choice0", &node1);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  result = asn1_write_value (node1, "", "choice1", 1);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  result = asn1_write_value (node1, "choice1", "choice2", 1);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  result = asn1_write_value (node1, "choice1.choice2", "int1", 1);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  result = asn1_write_value (node1, "choice1.choice2.int1", "1234", 0);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  result = asn1_der_coding (node1, "", data, &data_size, errorDescription);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  asn1_delete_structure (&node1);

  /* Decode */
  result = asn1_create_element (definitions, "TEST.Choice0", &node2);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

#if 0
  printf ("der:");
  for (i = 0; i < data_size; i++)
    printf ("%.2x ", (unsigned char) (data[i]));
  printf ("\n");
#endif

  result = asn1_der_decoding (&node2, data, data_size, errorDescription);
  if (result != ASN1_SUCCESS)
    {
      printf ("error in %d\n", __LINE__);
      exit (1);
    }

  asn1_delete_structure (&node2);
  asn1_delete_structure (&definitions);

  return 0;
}
