/*
 *      Copyright (C) 2004, 2006 Free Software Foundation, Inc.
 *      Copyright (C) 2002 Fabio Fiorina
 *
 * This file is part of LIBTASN1.
 *
 * The LIBTASN1 library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

#ifndef INT_H
#define INT_H

#include <libtasn1.h>

#include <defines.h>

/*
#define LIBTASN1_DEBUG
#define LIBTASN1_DEBUG_PARSER
#define LIBTASN1_DEBUG_INTEGER
*/

#include <mem.h>

#define MAX_LOG_SIZE 1024 /* maximum number of characters of a log message */

/* Define used for visiting trees. */
#define UP     1
#define RIGHT  2
#define DOWN   3

/****************************************/
/* Returns the first 8 bits.            */
/* Used with the field type of node_asn */
/****************************************/
#define type_field(x)     (x&0xFF)

/* List of constants for field type of typedef node_asn  */
#define TYPE_CONSTANT ASN1_TYPE_CONSTANT
#define TYPE_IDENTIFIER ASN1_TYPE_IDENTIFIER
#define TYPE_INTEGER ASN1_TYPE_INTEGER
#define TYPE_BOOLEAN ASN1_TYPE_BOOLEAN
#define TYPE_SEQUENCE ASN1_TYPE_SEQUENCE
#define TYPE_BIT_STRING ASN1_TYPE_BIT_STRING
#define TYPE_OCTET_STRING ASN1_TYPE_OCTET_STRING
#define TYPE_TAG ASN1_TYPE_TAG
#define TYPE_DEFAULT ASN1_TYPE_DEFAULT
#define TYPE_SIZE ASN1_TYPE_SIZE
#define TYPE_SEQUENCE_OF ASN1_TYPE_SEQUENCE_OF
#define TYPE_OBJECT_ID ASN1_TYPE_OBJECT_ID
#define TYPE_ANY ASN1_TYPE_ANY
#define TYPE_SET ASN1_TYPE_SET
#define TYPE_SET_OF ASN1_TYPE_SET_OF
#define TYPE_DEFINITIONS ASN1_TYPE_DEFINITIONS
#define TYPE_TIME ASN1_TYPE_TIME
#define TYPE_CHOICE ASN1_TYPE_CHOICE
#define TYPE_IMPORTS ASN1_TYPE_IMPORTS
#define TYPE_NULL ASN1_TYPE_NULL
#define TYPE_ENUMERATED ASN1_TYPE_ENUMERATED
#define TYPE_GENERALSTRING ASN1_TYPE_GENERALSTRING

/***********************************************************************/
/* List of constants to better specify the type of typedef node_asn.   */
/***********************************************************************/
/*  Used with TYPE_TAG  */
#define CONST_UNIVERSAL   (1<<8)
#define CONST_PRIVATE     (1<<9)
#define CONST_APPLICATION (1<<10)
#define CONST_EXPLICIT    (1<<11)
#define CONST_IMPLICIT    (1<<12)

#define CONST_TAG         (1<<13)  /*  Used in ASN.1 assignement  */
#define CONST_OPTION      (1<<14)
#define CONST_DEFAULT     (1<<15)
#define CONST_TRUE        (1<<16)
#define CONST_FALSE       (1<<17)

#define CONST_LIST        (1<<18)  /*  Used with TYPE_INTEGER and TYPE_BIT_STRING  */
#define CONST_MIN_MAX     (1<<19)

#define CONST_1_PARAM     (1<<20)

#define CONST_SIZE        (1<<21)

#define CONST_DEFINED_BY  (1<<22)

#define CONST_GENERALIZED (1<<23)
#define CONST_UTC         (1<<24)

/* #define CONST_IMPORTS     (1<<25) */

#define CONST_NOT_USED    (1<<26)
#define CONST_SET         (1<<27)
#define CONST_ASSIGN      (1<<28)

#define CONST_DOWN        (1<<29)
#define CONST_RIGHT       (1<<30)

#endif /* INT_H */
