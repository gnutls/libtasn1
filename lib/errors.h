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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef ERRORS_H
#define ERRORS_H

#include "int.h"
#include "errors_int.h"

const char* libtasn1_strerror(int error);
void libtasn1_perror(int error);

#ifdef LIBTASN1_DEBUG
 void _libtasn1_log( const char *fmt, ...);
#else
# define _libtasn1_log _libtasn1_null_log
void _libtasn1_null_log( void*, ...);
#endif /* DEBUG */

#endif /* ERRORS_H */
