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
/* File: asn1Deoding.c                               */
/* Description: program to generate an ASN1 type from*/
/*              a DER coding.                        */   
/*****************************************************/

#include <stdio.h>
#include <string.h>
#include <libtasn1.h>
#include <malloc.h>
#include <config.h>

#ifdef HAVE_GETOPT_H
  #include <getopt.h>
#endif

char version_man[] = "asn1Decoding (GNU libasn1) " VERSION;

char help_man[] = "asn1Decoding generates an ASN1 type from a file\n"
                  "with ASN1 definitions and another one with a DER encoding.\n"
                  "\n"
                  "Usage: asn1Decoding [options] <file1> <file2> <type>\n"
                  " <file1> file with ASN1 definitions.\n"
                  " <file2> file with a DER coding.\n"
                  " <type>  ASN1 type name\n"
                  "\n"
#ifdef HAVE_GETOPT_H
                  "Operation modes:\n"
                  "  -h, --help    shows this message and exit.\n"
                  "  -v, --version shows version information and exit.\n"
                  "  -c, --check   checks the syntax only.\n";
#else
                  "Operation modes:\n"
                  "  -h    shows this message and exit.\n"
                  "  -v    shows version information and exit.\n"
                  "  -c    checks the syntax only.\n";
#endif



/********************************************************/
/* Function : main                                      */
/* Description:                                         */
/********************************************************/
int
main(int argc,char *argv[])
{

#ifdef HAVE_GETOPT_H
  static struct option long_options[] =
  {
    {"help",    no_argument,       0, 'h'},
    {"version", no_argument,       0, 'v'},
    {"check",   no_argument,       0, 'c'},
    {0, 0, 0, 0}
  };
#endif

 int option_result;
 int option_index = 0;
 char *inputFileAsnName=NULL;
 char *inputFileDerName=NULL; 
 char *typeName=NULL;
 char *varName=NULL;
 int checkSyntaxOnly=0;
 ASN1_TYPE definitions=ASN1_TYPE_EMPTY;
 ASN1_TYPE structure=ASN1_TYPE_EMPTY;
 char errorDescription[MAX_ERROR_DESCRIPTION_SIZE];
 int asn1_result=ASN1_SUCCESS;
 FILE *inputFile;
 unsigned char der[1024];
 int  der_len=0;
 char *dot_p,*char_p;

 opterr=0; /* disable error messages from getopt */

 printf("\n");

 while(1){

#ifdef HAVE_GETOPT_H
   option_result=getopt_long(argc,argv,"hvc",long_options,&option_index);
#else
   option_result=getopt(argc,argv,"hvc");
#endif

   if(option_result == -1) break;

   switch(option_result){
   case 'h':  /* HELP */
     printf("%s\n",help_man);
     exit(0);
     break;
   case 'v':  /* VERSION */
     printf("%s\n",version_man);
     exit(0);
     break;
   case 'c':  /* CHECK SYNTAX */
     checkSyntaxOnly = 1;
     break;
   case '?':  /* UNKNOW OPTION */
     fprintf(stderr,"asn1Decoding: option '%s' not recognized or without argument.\n\n",argv[optind-1]);
     printf("%s\n",help_man);

     exit(1);
     break;
   default:
     fprintf(stderr,"asn1Decoding: ?? getopt returned character code Ox%x ??\n",option_result);
   }
 }

 if(optind == argc){
   fprintf(stderr,"asn1Decoding: input file with ASN1 definitions missing.\n");
   fprintf(stderr,"              input file with DER coding missing.\n");
   fprintf(stderr,"              ASN1 type name missing.\n\n");
   printf("%s\n",help_man);

   exit(1);
 }

 if(optind == argc-1){
   fprintf(stderr,"asn1Decoding: input file with DER coding missing.\n\n");
   fprintf(stderr,"              ASN1 type name missing.\n\n");
   printf("%s\n",help_man);

   exit(1);
 }

 if(optind == argc-2){
   fprintf(stderr,"asn1Decoding: ASN1 type name missing.\n\n");
   printf("%s\n",help_man);

   exit(1);
 }

 inputFileAsnName=(char *)malloc(strlen(argv[optind])+1);
 strcpy(inputFileAsnName,argv[optind]);
 
 inputFileDerName=(char *)malloc(strlen(argv[optind+1])+1);
 strcpy(inputFileDerName,argv[optind+1]);
 
 typeName=(char *)malloc(strlen(argv[optind+2])+1);
 strcpy(typeName,argv[optind+2]);

 asn1_result=asn1_parser2tree(inputFileAsnName,&definitions,errorDescription);

 switch(asn1_result){
 case ASN1_SUCCESS:
   printf("Parse: done.\n");
   break;
 case ASN1_FILE_NOT_FOUND:
   printf("asn1Decoding: FILE %s NOT FOUND\n",inputFileAsnName);
   break;
 case ASN1_SYNTAX_ERROR: 
 case ASN1_IDENTIFIER_NOT_FOUND: 
 case ASN1_NAME_TOO_LONG:
   printf("asn1Decoding: %s\n",errorDescription);
   break;
 default:
   printf("libasn1 ERROR: %s\n",libtasn1_strerror(asn1_result));
 }

 if(asn1_result != ASN1_SUCCESS){
   free(inputFileAsnName);
   free(inputFileDerName);
   free(typeName);
   exit(1);
 }


 inputFile=fopen(inputFileDerName,"r");
 
 if(inputFile==NULL){
   printf("asn1Decoding: file '%s' not found\n",inputFileDerName);
   asn1_delete_structure(&definitions);

   free(inputFileAsnName);
   free(inputFileDerName);
   free(typeName);
   exit(1);
 }

 while(fscanf(inputFile,"%c",der+der_len) != EOF)
   der_len++;

 fclose(inputFile);

 /* varName creation */
 dot_p=typeName;
 char_p=typeName;
 while((char_p=strchr(char_p,'.'))){
   char_p++;
   dot_p=char_p;
 }
 
 /* varName= inputFileName after the last '.' */
 varName=(char *)malloc(strlen(typeName)-(dot_p-typeName)+1);
 strcpy(varName,dot_p);
    
 asn1_result=asn1_create_element(definitions,typeName,&structure,varName);
 if(asn1_result != ASN1_SUCCESS){
   printf("Structure creation: %s\n",libtasn1_strerror(asn1_result));
   asn1_delete_structure(&definitions);

   free(inputFileAsnName);
   free(inputFileDerName);
   free(typeName);   
   free(varName);   
   exit(1);
 }

 asn1_result=asn1_der_decoding(&structure,der,der_len,errorDescription);
 printf("\nDecoding: %s\n",libtasn1_strerror(asn1_result));
 if(asn1_result != ASN1_SUCCESS)
   printf("asn1Decoding: %s\n",errorDescription);

 printf("\nDECODING RESULT:\n");
 asn1_print_structure(stdout,structure,varName,ASN1_PRINT_NAME_TYPE_VALUE);


 asn1_delete_structure(&definitions);
 asn1_delete_structure(&structure);

 free(inputFileAsnName);
 free(inputFileDerName);
 free(typeName);
 free(varName);   

 if(asn1_result != ASN1_SUCCESS)
   exit(1);

 exit(0);
}





