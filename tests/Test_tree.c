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

#define ACT_NULL       0
#define ACT_CREATE     1
#define ACT_DELETE     2
#define ACT_WRITE      3
#define ACT_READ       4
#define ACT_VISIT      5
#define ACT_ENCODING   6
#define ACT_DECODING   7
#define ACT_PRINT_DER  8
#define ACT_EXPAND_ANY 9
#define ACT_DECODING_ELEMENT   10
#define ACT_EXPAND_OCTET       11
#define ACT_NUMBER_OF_ELEMENTS 12
#define ACT_DECODING_START_END 13
#define ACT_READ_DEFINITIONS   14
#define ACT_READ_TAG_CLASS     15

typedef struct{
  int action;
  char *par1;
  unsigned char *par2;
  int par3;
  int  errorNumber;
} test_type;


test_type test_array[]={

  {ACT_DELETE,"","",0,ASN1_ELEMENT_NOT_FOUND},

  /* Test: OBJECT IDENTIFIER  elements */
  {ACT_CREATE,"TEST_TREE.Sequence1",0,0,ASN1_SUCCESS},
  {ACT_WRITE,"int2","0",0,ASN1_SUCCESS},
  {ACT_WRITE,"oct","\x02\x01\x0a",3,ASN1_SUCCESS},
  {ACT_WRITE,"id","1 2 3 4 5",0,ASN1_VALUE_NOT_VALID},
  {ACT_WRITE,"id","2.5.29.2",0,ASN1_SUCCESS},
  {ACT_READ,"id","2.5.29.2",9,ASN1_SUCCESS},
  {ACT_WRITE,"any1","\x02\x01\x05",3,ASN1_SUCCESS},
  {ACT_READ_DEFINITIONS,"TEST_TREE.id-anyTest","2.5.29.1",9,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},
  {ACT_CREATE,"TEST_TREE.Sequence1",0,0,ASN1_SUCCESS},
  {ACT_DECODING,0,0,0,ASN1_SUCCESS},
  {ACT_DECODING_START_END,"id","START",7,ASN1_SUCCESS},
  {ACT_READ,"id","2.5.29.2",9,ASN1_SUCCESS},
  {ACT_EXPAND_ANY,"",NULL,0,ASN1_SUCCESS},
  {ACT_EXPAND_OCTET,"oct","id",0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},

  /* Test: CHOICE elements */
  {ACT_CREATE,"TEST_TREE.X520LocalityName",0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_WRITE,"","teletexString",0,ASN1_SUCCESS},
  {ACT_WRITE,"teletexString","PROVA",5,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},
  {ACT_CREATE,"TEST_TREE.X520LocalityName",0,0,ASN1_SUCCESS},
  {ACT_DECODING,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},

  /* Test: OPTIONAL elements */
  {ACT_CREATE,"TEST_TREE.DHParameter",0,0,ASN1_SUCCESS},
  {ACT_WRITE,"prime","1",0,ASN1_SUCCESS},
  {ACT_WRITE,"base","2",0,ASN1_SUCCESS},
  {ACT_WRITE,"privateValueLength",NULL,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},
  {ACT_CREATE,"TEST_TREE.DHParameter",0,0,ASN1_SUCCESS},
  {ACT_DECODING,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},

  /* Test: Integer */
  {ACT_CREATE,"TEST_TREE.AnyTest2",0,0,ASN1_SUCCESS},
  {ACT_WRITE,"","int",0,ASN1_SUCCESS},
  {ACT_WRITE,"int","0",0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_WRITE,"int","-1",0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_WRITE,"int","1",0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_WRITE,"int","2000000000",0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_WRITE,"int","-2000000000",0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_WRITE,"int","-20000000000",0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_WRITE,"int","20000000000",0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},

  /* Test: elements without names */
  {ACT_CREATE,"TEST_TREE.Sequence1",0,0,ASN1_SUCCESS},
  {ACT_WRITE,"int2","10",0,ASN1_SUCCESS},
  {ACT_WRITE,"seq","NEW",1,ASN1_SUCCESS},
  {ACT_WRITE,"seq.?LAST","1",0,ASN1_SUCCESS},
  {ACT_WRITE,"seq","NEW",1,ASN1_SUCCESS},
  {ACT_WRITE,"seq.?LAST","2",0,ASN1_SUCCESS},
  {ACT_WRITE,"any1",NULL,0,ASN1_SUCCESS},
  {ACT_NUMBER_OF_ELEMENTS,"seq","",2,ASN1_SUCCESS},
  {ACT_WRITE,"id","1.2.3.4",0,ASN1_SUCCESS},
  {ACT_WRITE,"oct","\x30\x03\x02\x01\x15",5,ASN1_SUCCESS},
  {ACT_ENCODING,"int2",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_ENCODING,"seq.?2",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_CREATE,"TEST_TREE.Sequence1",0,0,ASN1_SUCCESS},
  {ACT_DECODING_ELEMENT,"int2",0,0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_READ,"int2","\x0a",1,ASN1_SUCCESS},
  {ACT_CREATE,"TEST_TREE.Sequence1",0,0,ASN1_SUCCESS},
  {ACT_DECODING,0,0,0,ASN1_SUCCESS},
  {ACT_DECODING_START_END,"seq.?2","START",10,ASN1_SUCCESS},
  {ACT_EXPAND_OCTET,"oct","id",0,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},

  /* Test GeneralString */
  {ACT_CREATE,"TEST_TREE.Test3",0,0,ASN1_SUCCESS},
  {ACT_WRITE,"a","1234",0,ASN1_SUCCESS},
  {ACT_WRITE,"b","prova",5,ASN1_SUCCESS},
  {ACT_ENCODING,"",0,0,ASN1_SUCCESS},
  {ACT_PRINT_DER,0,0,0,ASN1_SUCCESS},
  {ACT_DELETE,"","",0,ASN1_SUCCESS},
  {ACT_CREATE,"TEST_TREE.Test3",0,0,ASN1_SUCCESS},
  {ACT_DECODING,0,0,0,ASN1_SUCCESS}, 
  {ACT_DECODING_ELEMENT,"b",0,0,ASN1_SUCCESS},
  {ACT_READ,"b","prova",5,ASN1_SUCCESS},
  {ACT_VISIT,"","",ASN1_PRINT_ALL,ASN1_SUCCESS},
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
  int errorCounter=0,testCounter=0,der_len;
  unsigned char value[1024],der[1024];
  int valueLen,tag=0,class=0;
  int k;
  int start,end;

  printf("\n\n/****************************************/\n");
  printf(    "/*     Test sequence : Test_tree        */\n");
  printf(    "/****************************************/\n\n");

  if(1)
    result=asn1_parser2tree("Test_tree.asn",&definitions,errorDescription);
  else
    result=asn1_array2tree(Test_tree_asn1_tab,&definitions,errorDescription);

  if(result!=ASN1_SUCCESS){
    libtasn1_perror(result);
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

  if(0){
    asn1_print_structure(out,definitions,"TEST_TREE",ASN1_PRINT_ALL);
    fprintf(out,"\n");
  }

  test=test_array;

  while(test->action != ACT_NULL){
    testCounter++;

    switch(test->action){
    case ACT_CREATE:
      result=asn1_create_element(definitions,test->par1,&asn1_element);
      break;
    case ACT_DELETE:
      result=asn1_delete_structure(&asn1_element);
      break;
    case ACT_WRITE:
      if((test->par2) && (!strcmp("DER",test->par2)))
	result=asn1_write_value(asn1_element,test->par1,der,der_len);
      else
	result=asn1_write_value(asn1_element,test->par1,test->par2,test->par3);
      break;
    case ACT_READ:
      valueLen=1024;
      result=asn1_read_value(asn1_element,test->par1,value,&valueLen);
      break;
    case ACT_READ_DEFINITIONS:
      valueLen=1024;
      result=asn1_read_value(definitions,test->par1,value,&valueLen);
      break;
    case ACT_READ_TAG_CLASS:
      /*
	result=asn1_read_value(asn1_element,test->par1,&tag,&class);
      */
      break;
    case ACT_ENCODING:
      result=asn1_der_coding(asn1_element,test->par1,der,&der_len,
			     errorDescription);
      break;
    case ACT_DECODING:
      result=asn1_der_decoding(&asn1_element,der,der_len,
			     errorDescription);
      break;
    case ACT_DECODING_ELEMENT:
      result=asn1_der_decoding_element(&asn1_element,test->par1,der,der_len,
			     errorDescription);
      break;
    case ACT_DECODING_START_END:
      result=asn1_der_decoding_startEnd(asn1_element,der,der_len,test->par1,
					&start,&end);
      break;
    case ACT_EXPAND_ANY:
      result=asn1_expand_any_defined_by(definitions,&asn1_element);
      break;
    case ACT_EXPAND_OCTET:
      result=asn1_expand_octet_string(definitions,&asn1_element,test->par1,
                                      test->par2);
      break;
    case ACT_VISIT:
      asn1_print_structure(out,asn1_element,test->par1,test->par3);
      fprintf(out,"\n");
      result=ASN1_SUCCESS;
      break;
    case ACT_PRINT_DER:
      printf("DER encoding len:%i\n",der_len);
      printf("DER encoding: ");
      for(k=0;k<der_len;k++)
	printf("%02x ",der[k]);
      printf("\n\n");
      result=ASN1_SUCCESS;
      break;
    case ACT_NUMBER_OF_ELEMENTS:
      result=asn1_number_of_elements(asn1_element,test->par1,&valueLen);
      break;
    default:
      break;
    }


    switch(test->action){
    case ACT_CREATE:
    case ACT_DELETE:
    case ACT_WRITE:
    case ACT_VISIT:
    case ACT_ENCODING:
    case ACT_DECODING:
    case ACT_PRINT_DER:
    case ACT_EXPAND_ANY:
    case ACT_EXPAND_OCTET:
      if(result != test->errorNumber){
	errorCounter++;
	printf("ERROR N. %d:\n",errorCounter);
	printf("  Action %d - %s - %s - %d\n",test->action,test->par1,
	       test->par2,test->par3);
	printf("  Error expected: %s\n",libtasn1_strerror(test->errorNumber));
	printf("  Error detected: %s\n\n",libtasn1_strerror(result));
      }
      break;
    case ACT_DECODING_ELEMENT:
      if(result != test->errorNumber){
	errorCounter++;
	printf("ERROR N. %d:\n",errorCounter);
	printf("  Action %d - %s - %s - %d\n",test->action,test->par1,
	       test->par2,test->par3);
	printf("  Error expected: %s\n",libtasn1_strerror(test->errorNumber));
	printf("  Error detected: %s\n",libtasn1_strerror(result));
	printf("  Error description : %s\n\n",errorDescription);
      }
      break;
    case ACT_NUMBER_OF_ELEMENTS:
      if((result != test->errorNumber) ||
	 (valueLen != test->par3)){
	errorCounter++;
	printf("ERROR N. %d:\n",errorCounter);
	printf("  Action %d - %s\n",test->action,test->par1);
	printf("  Error expected: %s - %d\n",libtasn1_strerror(test->errorNumber),
                                             test->par3);
	printf("\n  Error detected: %s - %d\n\n",libtasn1_strerror(result),
                                          valueLen);
      }
      break;
    case ACT_DECODING_START_END:
      if((result != test->errorNumber) ||
	 ((!strcmp(test->par2,"START")) && (start != test->par3)) ||
	 ((!strcmp(test->par2,"END")) && (end != test->par3)) ){
	errorCounter++;
	printf("ERROR N. %d:\n",errorCounter);
	printf("  Action %d - %s - %d\n",test->action,test->par1,
	                                 test->par3);
	printf("  Error expected: %s - %s - %d\n",libtasn1_strerror(test->errorNumber),
                                             test->par2,test->par3);
	printf("  Error detected: %s - %d - %d\n\n",libtasn1_strerror(result),
                                          start,end);
      }
      break;

    case ACT_READ_TAG_CLASS:
      if((result != test->errorNumber) || 
	 ((!strcmp(test->par2,"TAG")) && (tag != test->par3)) ||      
	 ((!strcmp(test->par2,"CLASS")) && (class != test->par3))){
	printf("ERROR N. %d:\n",errorCounter);
	printf("  Action %d - %s - %d\n",test->action,test->par1,
	                                 test->par3);
	printf("  Error expected: %s - %s - %d\n",libtasn1_strerror(test->errorNumber),
                                             test->par2,test->par3);
	printf("  Error detected: %s - %d - %d\n\n",libtasn1_strerror(result),
                                          tag,class);
      }

      break;

    case ACT_READ:
    case ACT_READ_DEFINITIONS:
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
	printf("  Error expected: %s - %d - ",libtasn1_strerror(test->errorNumber),
                                             test->par3);
	for(k=0;k<test->par3;k++)
	  printf("%02x",test->par2[k]); 
	printf("\n  Error detected: %s - %d - ",libtasn1_strerror(result),
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









