/*
 * Copyright (C) 2000-2012 Free Software Foundation, Inc.
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

#ifndef _PARSER_AUX_H
#define _PARSER_AUX_H

#define DER_LEN 16

/***************************************/
/*  Functions used by ASN.1 parser     */
/***************************************/
asn_node_t _asn1_add_static_node (unsigned int type);

asn_node_t
_asn1_set_value (asn_node_t node, const void *value, unsigned int len);

asn_node_t _asn1_set_value_m (asn_node_t node, void *value, unsigned int len);

asn_node_t
_asn1_set_value_octet (asn_node_t node, const void *value, unsigned int len);

asn_node_t
_asn1_append_value (asn_node_t node, const void *value, unsigned int len);

asn_node_t _asn1_set_name (asn_node_t node, const char *name);

asn_node_t _asn1_cpy_name (asn_node_t dst, asn_node_t src);

asn_node_t _asn1_set_right (asn_node_t node, asn_node_t right);

asn_node_t _asn1_get_last_right (asn_node_t node);

void _asn1_remove_node (asn_node_t node);

void _asn1_delete_list (void);

void _asn1_delete_list_and_nodes (void);

char *_asn1_ltostr (long v, char *str);

asn_node_t _asn1_find_up (asn_node_t node);

int _asn1_change_integer_value (asn_node_t node);

int _asn1_expand_object_id (asn_node_t node);

int _asn1_type_set_config (asn_node_t node);

int _asn1_check_identifier (asn_node_t node);

int _asn1_set_default_tag (asn_node_t node);

/******************************************************************/
/* Function : _asn1_get_right                                     */
/* Description: returns the element pointed by the RIGHT field of */
/*              a NODE_ASN element.                               */
/* Parameters:                                                    */
/*   node: NODE_ASN element pointer.                              */
/* Return: field RIGHT of NODE.                                   */
/******************************************************************/
inline static asn_node_t
_asn1_get_right (asn_node_t node)
{
  if (node == NULL)
    return NULL;
  return node->right;
}

/******************************************************************/
/* Function : _asn1_set_down                                      */
/* Description: sets the field DOWN in a NODE_ASN element.        */
/* Parameters:                                                    */
/*   node: element pointer.                                       */
/*   down: pointer to a NODE_ASN element that you want be pointed */
/*          by NODE.                                              */
/* Return: pointer to *NODE.                                      */
/******************************************************************/
inline static asn_node_t
_asn1_set_down (asn_node_t node, asn_node_t down)
{
  if (node == NULL)
    return node;
  node->down = down;
  if (down)
    down->left = node;
  return node;
}

/******************************************************************/
/* Function : _asn1_get_down                                      */
/* Description: returns the element pointed by the DOWN field of  */
/*              a NODE_ASN element.                               */
/* Parameters:                                                    */
/*   node: NODE_ASN element pointer.                              */
/* Return: field DOWN of NODE.                                    */
/******************************************************************/
inline static asn_node_t
_asn1_get_down (asn_node_t node)
{
  if (node == NULL)
    return NULL;
  return node->down;
}

/******************************************************************/
/* Function : _asn1_get_name                                      */
/* Description: returns the name of a NODE_ASN element.           */
/* Parameters:                                                    */
/*   node: NODE_ASN element pointer.                              */
/* Return: a null terminated string.                              */
/******************************************************************/
inline static char *
_asn1_get_name (asn_node_t node)
{
  if (node == NULL)
    return NULL;
  return node->name;
}

/******************************************************************/
/* Function : _asn1_mod_type                                      */
/* Description: change the field TYPE of an NODE_ASN element.     */
/*              The new value is the old one | (bitwise or) the   */
/*              paramener VALUE.                                  */
/* Parameters:                                                    */
/*   node: NODE_ASN element pointer.                              */
/*   value: the integer value that must be or-ed with the current */
/*          value of field TYPE.                                  */
/* Return: NODE pointer.                                          */
/******************************************************************/
inline static asn_node_t
_asn1_mod_type (asn_node_t node, unsigned int value)
{
  if (node == NULL)
    return node;
  node->type |= value;
  return node;
}

#endif
