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

#ifndef ERRORS_H
#define ERRORS_H


#include "int.h"
#include "errors_int.h"

#ifdef DEBUG
# ifdef __FILE__
#  ifdef __LINE__
#   define _libasn1_assert() fprintf(stderr, "LIBASN1_ASSERT: %s:%d\n", __FILE__,__LINE__);
#  else
#   define _libasn1_assert() 
#  endif
# else /* __FILE__ defined */
#  define _libasn1_assert() 
# endif
#else /* no debug */
# define _libasn1_assert() 
#endif

const char* libasn1_strerror(int error);
void libasn1_perror(int error);

#ifdef DEBUG
 void _libasn1_log( const char *fmt, ...);
#else
# define _libasn1_log ( ...)
#endif

#endif /* ERRORS_H */






