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
/* File: asn1Parser.c                                */
/* Description: program to parse a file with ASN1    */
/*              definitions.                         */   
/*****************************************************/

#include <stdio.h>
#include <string.h>
#include <libtasn1.h>
#include <stdlib.h>
#include <config.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_GETOPT_H
  #include <getopt.h>
#endif

char version_man[] = "asn1Parser (GNU libasn1) " VERSION;

char help_man[] = "asn1Parser reads files with ASN1 definitions and\n"
                  "generates a C array to use with libtasn1 functions.\n"
                  "\n"
                  "Usage: asn1Parser [options] file\n"
                  "\n"
#ifdef HAVE_GETOPT_LONG
                  "Operation modes:\n"
                  "  -h, --help    shows this message and exit\n"
                  "  -v, --version shows version information and exit.\n"
                  "  -c, --check   checks the syntax only.\n"
                  "\n"
                  "Output:\n"
                  "  -o <file>, --output <file>  output file\n"
                  "  -n <name>, --name <name>    array name\n";
#else
                  "Operation modes:\n"
                  "  -h    shows this message and exit\n"
                  "  -v    shows version information and exit.\n"
                  "  -c    checks the syntax only.\n"
                  "\n"
                  "Output:\n"
                  "  -o <file>  output file\n"
                  "  -n <name>  array name\n";
#endif

/********************************************************/
/* Function : main                                      */
/* Description:                                         */
/********************************************************/
int
main(int argc,char *argv[])
{

#ifdef HAVE_GETOPT_LONG
  static struct option long_options[] =
  {
    {"help",    no_argument,       0, 'h'},
    {"version", no_argument,       0, 'v'},
    {"check",   no_argument,       0, 'c'},
    {"output",  required_argument, 0, 'o'},
    {"name",    required_argument, 0, 'n'},
    {0, 0, 0, 0}
  };
  int option_index = 0;
#endif

 int option_result;
 char *outputFileName=NULL;
 char *inputFileName=NULL;
 char *vectorName=NULL;
 int checkSyntaxOnly=0;
 ASN1_TYPE pointer=ASN1_TYPE_EMPTY;
 char errorDescription[MAX_ERROR_DESCRIPTION_SIZE];
 int parse_result=ASN1_SUCCESS;

 opterr=0; /* disable error messages from getopt */

 printf("\n");

 while(1){

#ifdef HAVE_GETOPT_LONG
   option_result=getopt_long(argc,argv,"hvco:n:",long_options,&option_index);
#else
   option_result=getopt(argc,argv,"hvco:n:");
#endif

   if(option_result == -1) break;

   switch(option_result){
   case 0:
#ifdef HAVE_GETOPT_LONG
     printf("option %s",long_options[option_index].name);
     if(optarg) printf(" with arg %s",optarg);
     printf("\n");
#endif
     break;
   case 'h':  /* HELP */
     printf("%s\n",help_man);

     if(outputFileName) free(outputFileName);
     if(vectorName) free(vectorName);
     exit(0);
     break;
   case 'v':  /* VERSION */
     printf("%s\n",version_man);

     if(outputFileName) free(outputFileName);
     if(vectorName) free(vectorName);
     exit(0);
     break;
   case 'c':  /* CHECK SYNTAX */
     checkSyntaxOnly = 1;
     break;
   case 'o':  /* OUTPUT */
     outputFileName=(char *)malloc(strlen(optarg)+1);
     strcpy(outputFileName,optarg);
     break;
   case 'n':  /* VECTOR NAME */
     vectorName=(char *)malloc(strlen(optarg)+1);
     strcpy(vectorName,optarg);
     break;
   case '?':  /* UNKNOW OPTION */
     fprintf(stderr,"asn1Parser: option '%s' not recognized or without argument.\n\n",argv[optind-1]);
     printf("%s\n",help_man);

     if(outputFileName) free(outputFileName);
     if(vectorName) free(vectorName);
     exit(1);
     break;
   default:
     fprintf(stderr,"asn1Parser: ?? getopt returned character code Ox%x ??\n",option_result);
   }

 }

 if(optind == argc){
   fprintf(stderr,"asn1Parser: input file name missing.\n\n");
   printf("%s\n",help_man);

   if(outputFileName) free(outputFileName);
   if(vectorName) free(vectorName);
   exit(1);
 }
 else{
   inputFileName=(char *)malloc(strlen(argv[optind])+1);
   strcpy(inputFileName,argv[optind]);
 }

 if(checkSyntaxOnly == 1){
   parse_result=asn1_parser2tree(inputFileName,&pointer,errorDescription);
   asn1_delete_structure(&pointer);
 }
 else /* C VECTOR CREATION */
   parse_result=asn1_parser2array(inputFileName,
                outputFileName,vectorName,errorDescription);

 switch(parse_result){
 case ASN1_SUCCESS:
   printf("Done.\n");
   break;
 case ASN1_FILE_NOT_FOUND:
   printf("asn1Parser: FILE %s NOT FOUND\n",inputFileName);
   break;
 case ASN1_SYNTAX_ERROR: 
 case ASN1_IDENTIFIER_NOT_FOUND: 
 case ASN1_NAME_TOO_LONG:
   printf("asn1Parser: %s\n",errorDescription);
   break;
 default:
   printf("libasn1 ERROR: %s\n",libtasn1_strerror(parse_result));
 }


 free(inputFileName);
 if(outputFileName) free(outputFileName);
 if(vectorName) free(vectorName);

 if(parse_result != ASN1_SUCCESS) exit(1);
 exit(0);
}







