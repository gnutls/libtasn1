/*
 *      Copyright (C) 2002 Fabio Fiorina
 *
 * This file is part of LIBASN1.
 *
 * LIBASN1 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * LIBASN1 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */


/*****************************************************/
/* File: Test_tree.c                                 */
/* Description: Test sequences for these functions:  */
/*     asn1_visit_tree,                              */   
/*     asn1_create_structure,                        */   
/*     asn1_delete_structure,                        */
/*     asn1_write_value,                             */   
/*     asn1_read_value,                              */   
/*****************************************************/

#include <stdio.h>
#include <string.h>
#include "libtasn1.h"

#include "Test_tree_asn1_tab.c"

#define ACT_NULL   0
#define ACT_CREATE 1
#define ACT_DELETE 2
#define ACT_WRITE  3
#define ACT_READ   4
#define ACT_VISIT  5

typedef struct{
  int action;
  char *par1;
  unsigned char *par2;
  int par3;
  int  errorNumber;
} test_type;


test_type test_array[]={
  {ACT_DELETE,"","",0,ASN1_ELEMENT_NOT_FOUND},
  {ACT_CREATE,"TEST_TREE.Sequence1","Seq",0,ASN1_SUCCESS},
  {ACT_WRITE,"Seq.int1","1",0,ASN1_SUCCESS},
  {ACT_READ,"Seq.int1","\x01",1,ASN1_SUCCESS},


  {ACT_VISIT,"Seq","",ASN1_PRINT_NAME_TYPE_VALUE,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},

  /* end */
  {ACT_NULL}

};


int 
main(int argc,char *argv[])
{
  asn1_retCode result;
  ASN1_TYPE definitions=ASN1_TYPE_EMPTY;
  ASN1_TYPE asn1_element=ASN1_TYPE_EMPTY;
  char errorDescription[MAX_ERROR_DESCRIPTION_SIZE];
  FILE *out;
  test_type *test;
  int errorCounter=0,testCounter=0;
  unsigned char value[1024];
  int valueLen;
  int k;

  printf("\n\n/****************************************/\n");
  printf(    "/*     Test sequence : Test_tree        */\n");
  printf(    "/****************************************/\n\n");

  if(0)
    result=asn1_parser2tree("Test_tree.asn",&definitions,errorDescription);
  else
    result=asn1_array2tree(Test_tree_asn1_tab,&definitions,errorDescription);

  if(result!=ASN1_SUCCESS){
    libasn1_perror(result);
    printf("ErrorDescription = %s\n\n",errorDescription);
    exit(1);
  }

  if(1)
    out=stdout;
  else
    out=fopen("Test_tree.out","w");

  if(out==NULL){
    printf("Output file ERROR\n");
    exit(1);
  }


  test=test_array;

  while(test->action != ACT_NULL){
    testCounter++;

    switch(test->action){
    case ACT_CREATE:
      result=asn1_create_element(definitions,test->par1,&asn1_element,
		 test->par2);
      break;
    case ACT_DELETE:
      result=asn1_delete_structure(&asn1_element);
      break;
    case ACT_WRITE:
      result=asn1_write_value(asn1_element,test->par1,test->par2,test->par3);
      break;
    case ACT_READ:
      result=asn1_read_value(asn1_element,test->par1,value,&valueLen);
      break;
    case ACT_VISIT:
      asn1_print_structure(out,asn1_element,test->par1,test->par3);
      fprintf(out,"\n");
      result=ASN1_SUCCESS;
      break;
    default:
      break;
    }


    switch(test->action){
    case ACT_CREATE:
    case ACT_DELETE:
    case ACT_WRITE:
    case ACT_VISIT:
      if(result != test->errorNumber){
	errorCounter++;
	printf("ERROR N. %d:\n",errorCounter);
	printf("  Action %d - %s - %s - %d\n",test->action,test->par1,
	       test->par2,test->par3);
	printf("  Error expected: %s\n",libasn1_strerror(test->errorNumber));
	printf("  Error detected: %s\n\n",libasn1_strerror(result));
      }
      break;

    case ACT_READ:

      for(k=0;k<valueLen;k++) 
	if(test->par2[k] != value[k]){
	  k=-1;
	  break;
	}

      if((result != test->errorNumber) ||
	 (valueLen != test->par3) ||
	 (k == -1)){
	errorCounter++;
	printf("ERROR N. %d:\n",errorCounter);
	printf("  Action %d - %s\n",test->action,test->par1);
	printf("  Error expected: %s - %d - ",libasn1_strerror(test->errorNumber),
                                             test->par3);
	for(k=0;k<test->par3;k++)
	  printf("%02x",test->par2[k]); 
	printf("\n  Error detected: %s - %d - ",libasn1_strerror(result),
                                          valueLen);
	for(k=0;k<valueLen;k++)
	  printf("%02x",value[k]);
	printf("\n\n");

      }

      break;
    default:
      break;
    }

    test++;
  }


  printf("Total tests : %d\n",testCounter);
  printf("Total errors: %d\n",errorCounter);


  /* Clear the definition structures */
  asn1_delete_structure(&definitions);


  if(out != stdout) fclose(out);

  exit(0);
}









