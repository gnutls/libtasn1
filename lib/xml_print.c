/*
 *      Copyright (C) 2002  Fabio Fiorina
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
/* File: structure.c                                 */
/* Description: Functions to create and delete an    */
/*  ASN1 tree.                                       */
/*****************************************************/


#include <int.h>
#include <errors.h>
#include <structure.h>
#include "parser_aux.h"
#include "der.h"
#include <gstr.h>



static void* find_default_value( ASN1_TYPE x) {
ASN1_TYPE p = x;

  if ( x->value==NULL && x->type&CONST_DEFAULT) {
	if (x->down) {
		x=x->down;
		do {
			if ( type_field(x->type)==TYPE_DEFAULT) {
				if (type_field(p->type)==TYPE_BOOLEAN) {
					if (x->type & CONST_TRUE) return "TRUE";
					else return "FALSE";
				} else
				return x->value;
			}
			x = x->right;
		} while( x!=NULL);
	
	}
  }
  return NULL;
}


static int is_node_printable( ASN1_TYPE x) {
  switch( type_field( x->type)) {
        case TYPE_CONSTANT:
        case TYPE_TAG:
        case TYPE_SIZE:
	case TYPE_DEFAULT:
	   	return 0;
  }
  if (x->name==NULL) return 0;
  if (x->value==NULL && x->down==NULL) return 0;
//  else if (x->value==NULL && !(x->type&CONST_DEFAULT)) return 0;
  return 1;
}

/* returns true if the node is the only one printable in 
 * the level down of it.
 */
static int is_leaf( ASN1_TYPE p) {
ASN1_TYPE x;


  if (p==NULL) return 1;
  if (p->down==NULL) return 1;

  x = p->down;
  
  while( x!=NULL) {
     if (is_node_printable(x)) return 0;
     if (is_leaf(x)==0) return 0;
     x=x->right;
  }

  return 1;

}

/**
  * asn1_print_structure_xml - Prints on the standard output the structure's tree
  * @out: pointer to the output file (e.g. stdout).
  * @structure: pointer to the structure that you want to visit.
  * @name: an element of the structure
  * 
  * Prints on the standard output the structure's tree starting from the NAME element inside
  * the structure *POINTER. 
  **/
void
asn1_print_structure_xml(FILE *out,ASN1_TYPE structure,char *name,int mode)
{
  node_asn *p,*root;
  int k,indent=0,len,len2,len3;

//asn1_print_structure( out, structure, name, mode);  
  if(out==NULL) return;

  root=_asn1_find_node(structure,name);   

  if(root==NULL) return;

  p=root;
  while(p){
    if (is_node_printable(p) && p->name) {
		for(k=0;k<indent;k++)fprintf(out," ");
		fprintf(out,"<%s",p->name);
    }

    if(mode != ASN1_PRINT_NAME && is_node_printable(p)){
      switch(type_field(p->type)){
      case TYPE_DEFAULT:
	fprintf(out," type=\"DEFAULT\"");break;
      case TYPE_NULL:
	fprintf(out," type=\"NULL\"");break;
      case TYPE_IDENTIFIER:
	fprintf(out," type=\"IDENTIFIER\"");break;
      case TYPE_INTEGER:
	fprintf(out," type=\"INTEGER\"");break;
      case TYPE_ENUMERATED:
	fprintf(out," type=\"ENUMERATED\"");break;
      case TYPE_TIME:
	fprintf(out," type=\"TIME\"");break;
      case TYPE_BOOLEAN:
	fprintf(out," type=\"BOOLEAN\"");break;
      case TYPE_SEQUENCE:
	fprintf(out," type=\"SEQUENCE\"");break;
      case TYPE_BIT_STRING:
	fprintf(out," type=\"BIT STRING\"");break;
      case TYPE_OCTET_STRING:
	fprintf(out," type=\"OCTET STRING\"");break;
      case TYPE_SEQUENCE_OF:
	fprintf(out," type=\"SEQUENCE OF\"");break;
      case TYPE_OBJECT_ID:
	fprintf(out," type=\"OBJECT ID\"");break;
      case TYPE_ANY:
	fprintf(out," type=\"ANY\"");break;
      case TYPE_SET:
	fprintf(out," type=\"SET\"");break;
      case TYPE_SET_OF:
	fprintf(out," type=\"SET OF\"");break;
      case TYPE_CHOICE:
	fprintf(out," type=\"CHOICE\"");break;
      case TYPE_DEFINITIONS:
	fprintf(out," type=\"DEFINITIONS\"");break;
      default:
	break;
      }
    }

#if 0
    if(mode==ASN1_PRINT_ALL && is_node_printable(p)){
      if(p->type&0x1FFFFF00){
	fprintf(out," attr=\"");
	if(p->type & CONST_UNIVERSAL) fprintf(out,"UNIVERSAL,");
	if(p->type & CONST_PRIVATE) fprintf(out,"PRIVATE,");
	if(p->type & CONST_APPLICATION) fprintf(out,"APPLICATION,");
	if(p->type & CONST_EXPLICIT) fprintf(out,"EXPLICIT,");
	if(p->type & CONST_IMPLICIT) fprintf(out,"IMPLICIT,");
	if(p->type & CONST_TAG) fprintf(out,"TAG,");
	if(p->type & CONST_DEFAULT) fprintf(out,"DEFAULT,");
	if(p->type & CONST_TRUE) fprintf(out,"TRUE,");
	if(p->type & CONST_FALSE) fprintf(out,"FALSE,");
	if(p->type & CONST_LIST) fprintf(out,"LIST,");
	if(p->type & CONST_MIN_MAX) fprintf(out,"MIN_MAX,");
	if(p->type & CONST_OPTION) fprintf(out,"OPTION,");
	if(p->type & CONST_1_PARAM) fprintf(out,"1_PARAM,");
	if(p->type & CONST_SIZE) fprintf(out,"SIZE,");
	if(p->type & CONST_DEFINED_BY) fprintf(out,"DEF_BY,");
	if(p->type & CONST_GENERALIZED) fprintf(out,"GENERALIZED,");
	if(p->type & CONST_UTC) fprintf(out,"UTC,");
	if(p->type & CONST_SET) fprintf(out,"SET,");
	if(p->type & CONST_NOT_USED) fprintf(out,"NOT_USED,");
	if(p->type & CONST_ASSIGN) fprintf(out,"ASSIGNMENT,");
        fprintf(out, "\"");
      }
    }
#endif

    if (p->type==TYPE_BIT_STRING) {
     len2=-1;
     len=_asn1_get_length_der(p->value,&len2);
     fprintf(out," length=\"%i\"",(len-1)*8-(p->value[len2]));
    }

    if (is_node_printable(p)) fprintf(out,">");

    if(((mode == ASN1_PRINT_NAME_TYPE_VALUE) ||
       (mode == ASN1_PRINT_ALL)) && is_node_printable(p)){
      unsigned char* value;
      
      if (p->value==NULL) value=find_default_value(p);
      else value = p->value;

      switch(type_field(p->type)){

      case TYPE_DEFAULT:
	if(value) fprintf(out,"%s",value);
	break;
      case TYPE_IDENTIFIER:
	if(value) fprintf(out,"%s",value);
	break;
      case TYPE_INTEGER:
	if(value){
	  len2=-1;
	  len=_asn1_get_length_der(value,&len2);
	  fprintf(out,"0x");
	  for(k=0;k<len;k++) fprintf(out,"%02x",(value)[k+len2]);
	}
	break;
      case TYPE_ENUMERATED:
	if(value){
	  len2=-1;
	  len=_asn1_get_length_der(value,&len2);
	  fprintf(out,"0x");
	  for(k=0;k<len;k++) fprintf(out,"%02x",(value)[k+len2]);
	}
	break;
      case TYPE_TIME:
	if(value) fprintf(out,"%s",value);
	break;
      case TYPE_BOOLEAN:
	if(value){
	  if(value[0]=='T') fprintf(out,"TRUE");
	  else if(value[0]=='F') fprintf(out,"FALSE");
	}
	break;
      case TYPE_BIT_STRING:
	if(value){
//	  len2=-1;
//	  len=_asn1_get_length_der(value,&len2);
//	  fprintf(out,"value(%i):",(len-1)*8-(value[len2]));
	  fprintf(out,"0x");
	  for(k=1;k<len;k++) fprintf(out,"%02x",(value)[k+len2]);
	}
	break;
      case TYPE_OCTET_STRING:
	if(value){
	  len2=-1;
	  len=_asn1_get_length_der(value,&len2);
          fprintf(out, "0x");
	  for(k=0;k<len;k++) fprintf(out,"%02x",(value)[k+len2]);
	}
	break;
      case TYPE_OBJECT_ID:
	if(value) fprintf(out,"%s",value);
	break;
      case TYPE_ANY:
	if(value){
	  len3=-1;
	  len2=_asn1_get_length_der(value,&len3);
          fprintf(out, "0x");
	  for(k=0;k<len2;k++) fprintf(out,"%02x",(value)[k+len3]);
	}
	break;
      case TYPE_SET:
      case TYPE_SET_OF:
      case TYPE_CHOICE:
      case TYPE_DEFINITIONS:
      case TYPE_SEQUENCE_OF:
      case TYPE_SEQUENCE:
      case TYPE_NULL:
	break;
      default:
	break;
      }
    }

    if(p->down && is_node_printable(p)) {
      ASN1_TYPE x;
      p=p->down;
      indent+=2;
      x = p;
      do {
	      if (is_node_printable(x)) {
      		fprintf(out,"\n");
      		break;
      	      }
      	      x = x->right;
      } while( x!=NULL);
    }
    else if(p==root) {
      if (is_node_printable(p)) {
      	if(p->name) fprintf(out,"</%s>",p->name);
      	fprintf(out,"\n");
      }
      p=NULL;
      break;
    } else {
      if (is_node_printable(p)) {
	   if(p->name) fprintf(out,"</%s>",p->name);
           fprintf(out, "\n");
      }
      if(p->right)
      	p=p->right;
      else {
        while(1){
          ASN1_TYPE old_p;
          
          old_p = p;

	  p=_asn1_find_up(p);
	  indent-=2;
          if (is_node_printable(p)) {
	        if ( !is_leaf(p)) /* XXX */ for(k=0;k<indent;k++)fprintf(out, " ");

	        if(p->name) fprintf(out,"</%s>",p->name);
	        fprintf(out,"\n");
	  }
	  if(p==root) {
	    p=NULL;
	    break;
	  }
        
  	  if(p->right){
	    p=p->right;
	    break;
	  }
        } 
      }
    }
  }
}

