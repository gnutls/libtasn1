/* A Bison parser, made by GNU Bison 1.875a.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse _asn1_yyparse
#define yylex   _asn1_yylex
#define yyerror _asn1_yyerror
#define yylval  _asn1_yylval
#define yychar  _asn1_yychar
#define yydebug _asn1_yydebug
#define yynerrs _asn1_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIG = 258,
     NUM = 259,
     IDENTIFIER = 260,
     OPTIONAL = 261,
     INTEGER = 262,
     SIZE = 263,
     OCTET = 264,
     STRING = 265,
     SEQUENCE = 266,
     BIT = 267,
     UNIVERSAL = 268,
     PRIVATE = 269,
     APPLICATION = 270,
     DEFAULT = 271,
     CHOICE = 272,
     OF = 273,
     OBJECT = 274,
     STR_IDENTIFIER = 275,
     BOOLEAN = 276,
     TRUE = 277,
     FALSE = 278,
     TOKEN_NULL = 279,
     ANY = 280,
     DEFINED = 281,
     BY = 282,
     SET = 283,
     EXPLICIT = 284,
     IMPLICIT = 285,
     DEFINITIONS = 286,
     TAGS = 287,
     BEGIN = 288,
     END = 289,
     UTCTime = 290,
     GeneralizedTime = 291,
     GeneralString = 292,
     FROM = 293,
     IMPORTS = 294,
     ENUMERATED = 295
   };
#endif
#define ASSIG 258
#define NUM 259
#define IDENTIFIER 260
#define OPTIONAL 261
#define INTEGER 262
#define SIZE 263
#define OCTET 264
#define STRING 265
#define SEQUENCE 266
#define BIT 267
#define UNIVERSAL 268
#define PRIVATE 269
#define APPLICATION 270
#define DEFAULT 271
#define CHOICE 272
#define OF 273
#define OBJECT 274
#define STR_IDENTIFIER 275
#define BOOLEAN 276
#define TRUE 277
#define FALSE 278
#define TOKEN_NULL 279
#define ANY 280
#define DEFINED 281
#define BY 282
#define SET 283
#define EXPLICIT 284
#define IMPLICIT 285
#define DEFINITIONS 286
#define TAGS 287
#define BEGIN 288
#define END 289
#define UTCTime 290
#define GeneralizedTime 291
#define GeneralString 292
#define FROM 293
#define IMPORTS 294
#define ENUMERATED 295




/* Copy the first part of user declarations.  */
#line 29 "ASN1.y"
 
#include <int.h> 
#include <errors.h>
#include <parser_aux.h>
#include <structure.h>


static FILE *file_asn1;            /* Pointer to file to parse */
static asn1_retCode result_parse;  /* result of the parser algorithm */
static node_asn *p_tree;        /* pointer to the root of the structure 
                            created by the parser*/     
static unsigned long lineNumber; /* line number describing the parser position 
                             inside the file */
static char lastToken[MAX_NAME_SIZE+1];  /* last token find in the file to 
					    parse before the 'parse error' */ 
extern char _asn1_identifierMissing[];
static const char *fileName;           /* file to parse */

int _asn1_yyerror (char *);
int _asn1_yylex(void);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 55 "ASN1.y"
typedef union YYSTYPE {
  unsigned int constant;
  char str[MAX_NAME_SIZE+1];
  node_asn* node;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 194 "ASN1.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 206 "ASN1.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  43
/* YYNRULES -- Number of rules. */
#define YYNRULES  98
/* YYNRULES -- Number of states. */
#define YYNSTATES  189

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,     2,    41,    45,    42,    51,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    48,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,    12,    14,    17,    20,    22,    24,    26,
      28,    30,    32,    36,    41,    43,    47,    49,    54,    56,
      59,    61,    63,    65,    69,    74,    76,    79,    82,    85,
      88,    91,    93,    97,    99,   104,   109,   117,   119,   121,
     123,   128,   136,   138,   142,   144,   147,   150,   154,   159,
     161,   165,   168,   174,   179,   182,   184,   187,   189,   191,
     193,   195,   197,   199,   201,   203,   205,   207,   209,   211,
     213,   215,   218,   220,   223,   226,   229,   231,   235,   240,
     244,   249,   254,   258,   263,   268,   270,   275,   279,   287,
     294,   299,   301,   303,   305,   308,   313,   317,   319
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      53,     0,    -1,    93,    31,    94,    32,     3,    33,    92,
      34,    -1,     4,    -1,    41,     4,    -1,    42,     4,    -1,
      54,    -1,    55,    -1,     4,    -1,     5,    -1,    56,    -1,
       5,    -1,    43,    56,    44,    -1,     5,    43,    56,    44,
      -1,    59,    -1,    60,    45,    59,    -1,    57,    -1,     5,
      43,     4,    44,    -1,    61,    -1,    62,    61,    -1,    13,
      -1,    14,    -1,    15,    -1,    46,     4,    47,    -1,    46,
      63,     4,    47,    -1,    64,    -1,    64,    29,    -1,    64,
      30,    -1,    16,    58,    -1,    16,    22,    -1,    16,    23,
      -1,    56,    -1,    67,    48,    56,    -1,     7,    -1,     7,
      49,    60,    50,    -1,     7,    43,    67,    44,    -1,     7,
      43,    57,    51,    51,    57,    44,    -1,    21,    -1,    35,
      -1,    36,    -1,     8,    43,    57,    44,    -1,     8,    43,
      57,    51,    51,    57,    44,    -1,    71,    -1,    43,    71,
      44,    -1,    37,    -1,    37,    72,    -1,     9,    10,    -1,
       9,    10,    72,    -1,     5,    43,     4,    44,    -1,    75,
      -1,    76,    45,    75,    -1,    12,    10,    -1,    12,    10,
      49,    76,    50,    -1,    40,    49,    76,    50,    -1,    19,
      20,    -1,     5,    -1,     5,    72,    -1,    68,    -1,    78,
      -1,    69,    -1,    70,    -1,    74,    -1,    77,    -1,    73,
      -1,    85,    -1,    79,    -1,    87,    -1,    88,    -1,    86,
      -1,    24,    -1,    80,    -1,    65,    80,    -1,    81,    -1,
      81,    66,    -1,    81,     6,    -1,     5,    82,    -1,    83,
      -1,    84,    45,    83,    -1,    11,    49,    84,    50,    -1,
      11,    18,    80,    -1,    11,    72,    18,    80,    -1,    28,
      49,    84,    50,    -1,    28,    18,    80,    -1,    28,    72,
      18,    80,    -1,    17,    49,    84,    50,    -1,    25,    -1,
      25,    26,    27,     5,    -1,     5,     3,    81,    -1,     5,
      19,    20,     3,    49,    62,    50,    -1,     5,     5,     3,
      49,    62,    50,    -1,     5,     7,     3,    56,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    91,    -1,     5,    49,
      62,    50,    -1,     5,    49,    50,    -1,    29,    -1,    30,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   117,   117,   130,   131,   134,   138,   139,   142,   143,
     146,   147,   150,   152,   157,   158,   162,   164,   169,   170,
     174,   175,   176,   179,   181,   185,   186,   187,   190,   192,
     193,   197,   198,   202,   203,   205,   206,   213,   216,   217,
     220,   222,   228,   229,   232,   233,   237,   238,   242,   247,
     248,   252,   253,   258,   264,   267,   269,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     287,   288,   293,   294,   297,   300,   303,   304,   308,   310,
     312,   317,   319,   321,   326,   330,   331,   336,   339,   343,
     348,   354,   355,   358,   359,   363,   366,   390,   391
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"::=\"", "NUM", "IDENTIFIER", "OPTIONAL", 
  "INTEGER", "SIZE", "OCTET", "STRING", "SEQUENCE", "BIT", "UNIVERSAL", 
  "PRIVATE", "APPLICATION", "DEFAULT", "CHOICE", "OF", "OBJECT", 
  "STR_IDENTIFIER", "BOOLEAN", "TRUE", "FALSE", "TOKEN_NULL", "ANY", 
  "DEFINED", "BY", "SET", "EXPLICIT", "IMPLICIT", "DEFINITIONS", "TAGS", 
  "BEGIN", "END", "UTCTime", "GeneralizedTime", "GeneralString", "FROM", 
  "IMPORTS", "ENUMERATED", "'+'", "'-'", "'('", "')'", "','", "'['", 
  "']'", "'|'", "'{'", "'}'", "'.'", "$accept", "definitions", "pos_num", 
  "neg_num", "pos_neg_num", "num_identifier", "pos_neg_identifier", 
  "constant", "constant_list", "obj_constant", "obj_constant_list", 
  "class", "tag_type", "tag", "default", "pos_neg_list", "integer_def", 
  "boolean_def", "Time", "size_def2", "size_def", "generalstring_def", 
  "octet_string_def", "bit_element", "bit_element_list", "bit_string_def", 
  "enumerated_def", "object_def", "type_assig_right", 
  "type_assig_right_tag", "type_assig_right_tag_default", "type_assig", 
  "type_assig_list", "sequence_def", "set_def", "choise_def", "any_def", 
  "type_def", "constant_def", "type_constant", "type_constant_list", 
  "definitions_id", "explicit_implicit", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    43,    45,    40,    41,    44,    91,    93,   124,   123,
     125,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    65,    65,    65,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    78,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    83,    84,    84,    85,    85,
      85,    86,    86,    86,    87,    88,    88,    89,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     8,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     3,     1,     4,     1,     2,
       1,     1,     1,     3,     4,     1,     2,     2,     2,     2,
       2,     1,     3,     1,     4,     4,     7,     1,     1,     1,
       4,     7,     1,     3,     1,     2,     2,     3,     4,     1,
       3,     2,     5,     4,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     2,     2,     1,     3,     4,     3,
       4,     4,     3,     4,     4,     1,     4,     3,     7,     6,
       4,     1,     1,     1,     2,     4,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     8,     9,    96,
      16,    18,     0,    97,    98,     0,     0,    95,    19,     0,
       0,     0,    17,     0,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     2,    94,    55,    33,     0,     0,     0,
       0,     0,    37,    69,    85,     0,    38,    39,    44,     0,
       0,    25,     0,    57,    59,    60,    63,    61,    62,    58,
      65,    70,    87,    64,    68,    66,    67,     0,     0,     0,
       0,     0,    42,    56,     0,     0,    46,     0,     0,     0,
      51,     0,    54,     0,     0,     0,     0,    45,     0,     0,
      20,    21,    22,     0,    26,    27,    71,     0,     3,     0,
       0,     6,     7,    90,     0,     0,     0,     3,     9,    31,
       0,     0,     0,     0,    14,     0,    47,    79,     0,    76,
       0,     0,     0,     0,     0,    82,     0,     0,     0,    49,
       0,    23,     0,     0,     4,     5,     0,     0,    43,     0,
      35,     0,     0,     0,     0,    34,    72,    75,     0,    78,
      80,     0,    84,    86,    81,    83,     0,     0,    53,    24,
      89,     0,    40,     0,     0,    32,     0,    12,    15,    74,
       0,    73,    77,    52,     0,    50,    88,     0,     0,    13,
      11,    29,    30,    10,    28,    48,     0,    36,    41
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,   101,   102,   103,    10,   184,   114,   115,    11,
      12,    93,    51,    52,   171,   111,    53,    54,    55,    72,
      73,    56,    57,   129,   130,    58,    59,    60,    61,    62,
     147,   119,   120,    63,    64,    65,    66,    25,    26,    27,
      28,     3,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -84
static const short yypact[] =
{
      18,   -32,    33,    15,     0,   -84,    90,   -84,    49,   -84,
     -84,   -84,     2,   -84,   -84,    11,    45,   -84,   -84,    57,
      50,    43,   -84,   100,    74,   -84,   -84,   -84,    10,    78,
     105,   113,   106,   -84,   -84,     5,   -31,   126,     8,   128,
      79,   120,   -84,   -84,   115,    12,   -84,   -84,     5,    95,
      96,   102,   118,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,    98,    23,   142,
     107,   140,   -84,   -84,    32,    20,     5,   118,   146,   134,
     108,   146,   -84,   132,   118,   146,   138,   -84,   155,   114,
     -84,   -84,   -84,   158,   -84,   -84,   -84,    63,   -84,   159,
     160,   -84,   -84,   -84,   116,   129,   122,   117,   -84,   -84,
     119,    38,   124,    23,   -84,    -3,   -84,   -84,    78,   -84,
      21,   118,   155,    30,   164,   -84,    51,   118,   130,   -84,
      62,   -84,   125,     4,   -84,   -84,    63,    -6,   -84,   123,
     -84,    23,    23,   127,    20,   -84,    13,   -84,   146,   -84,
     -84,    72,   -84,   -84,   -84,   -84,   171,   155,   -84,   -84,
     -84,     6,   -84,   131,   129,   -84,   133,   -84,   -84,   -84,
      17,   -84,   -84,   -84,   135,   -84,   -84,   129,   136,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   137,   -84,   -84
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
     -84,   -84,   -84,   -84,   -72,   -73,   -84,    34,   -84,   -12,
     -83,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   112,
     -14,   -84,   -84,    19,    64,   -84,   -84,   -84,   -49,    66,
     -84,    37,     3,   -84,   -84,   -84,   -84,   -84,   -84,   161,
     -84,   -84,   -84
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -9
static const short yytable[] =
{
      18,   110,   109,    96,     7,     8,     7,     8,     7,     8,
       7,     8,    74,    70,   133,    24,    70,     4,    75,   169,
      70,    98,   180,     1,    79,   112,    77,    98,   117,   170,
      84,    86,   137,     5,    87,   125,   107,   108,   162,   181,
     182,   143,   144,    19,    33,   163,     6,   145,    71,    20,
       9,    71,    17,   161,   160,    71,   176,    78,    99,   100,
      21,    85,   116,   113,    99,   100,   148,     7,     8,   165,
     166,   149,   150,    99,   100,   148,    23,    29,   155,    30,
     152,    31,   140,    35,   123,    36,   141,    37,   126,    38,
      39,   178,    16,    32,    22,    40,   148,    41,   183,    42,
      89,   154,    43,    44,   186,    24,    45,   157,    67,    90,
      91,    92,   158,    46,    47,    48,    68,   157,    49,    13,
      14,    18,   173,    35,    50,    36,    69,    37,    81,    38,
      39,    94,    95,     7,   108,    40,    76,    41,    80,    42,
      82,    83,    43,    44,    88,   104,    45,    97,    70,    18,
     105,   118,   121,    46,    47,    48,   127,   122,    49,   124,
     128,   131,   132,   134,   135,   136,   138,   142,    -8,   153,
     139,   167,   159,   156,   164,   174,   175,   179,   168,   185,
     187,   188,   177,   106,   146,   172,   151,     0,     0,    34
};

static const short yycheck[] =
{
      12,    74,    74,    52,     4,     5,     4,     5,     4,     5,
       4,     5,    43,     8,    97,     5,     8,    49,    49,     6,
       8,     4,     5,     5,    38,     5,    18,     4,    77,    16,
      18,    45,   105,     0,    48,    84,     4,     5,    44,    22,
      23,   113,    45,    32,    34,    51,    31,    50,    43,     4,
      50,    43,    50,   136,    50,    43,    50,    49,    41,    42,
       3,    49,    76,    43,    41,    42,    45,     4,     5,   141,
     142,    50,   121,    41,    42,    45,    33,     3,   127,     5,
      50,     7,    44,     5,    81,     7,    48,     9,    85,    11,
      12,   164,    43,    19,    44,    17,    45,    19,   170,    21,
       4,    50,    24,    25,   177,     5,    28,    45,     3,    13,
      14,    15,    50,    35,    36,    37,     3,    45,    40,    29,
      30,   133,    50,     5,    46,     7,    20,     9,    49,    11,
      12,    29,    30,     4,     5,    17,    10,    19,    10,    21,
      20,    26,    24,    25,    49,     3,    28,    49,     8,   161,
      43,     5,    18,    35,    36,    37,    18,    49,    40,    27,
       5,    47,     4,     4,     4,    49,    44,    43,    51,     5,
      51,    44,    47,    43,    51,     4,   157,    44,   144,    44,
      44,    44,    51,    71,   118,   148,   122,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     5,    53,    93,    49,     0,    31,     4,     5,    50,
      57,    61,    62,    29,    30,    94,    43,    50,    61,    32,
       4,     3,    44,    33,     5,    89,    90,    91,    92,     3,
       5,     7,    19,    34,    91,     5,     7,     9,    11,    12,
      17,    19,    21,    24,    25,    28,    35,    36,    37,    40,
      46,    64,    65,    68,    69,    70,    73,    74,    77,    78,
      79,    80,    81,    85,    86,    87,    88,     3,     3,    20,
       8,    43,    71,    72,    43,    49,    10,    18,    49,    72,
      10,    49,    20,    26,    18,    49,    72,    72,    49,     4,
      13,    14,    15,    63,    29,    30,    80,    49,     4,    41,
      42,    54,    55,    56,     3,    43,    71,     4,     5,    56,
      57,    67,     5,    43,    59,    60,    72,    80,     5,    83,
      84,    18,    49,    84,    27,    80,    84,    18,     5,    75,
      76,    47,     4,    62,     4,     4,    49,    57,    44,    51,
      44,    48,    43,    56,    45,    50,    81,    82,    45,    50,
      80,    76,    50,     5,    50,    80,    43,    45,    50,    47,
      50,    62,    44,    51,    51,    56,    56,    44,    59,     6,
      16,    66,    83,    50,     4,    75,    50,    51,    57,    44,
       5,    22,    23,    56,    58,    44,    57,    44,    44
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 120 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_DEFINITIONS|yyvsp[-5].constant);
                    _asn1_set_name(yyval.node,_asn1_get_name(yyvsp[-7].node));
                    _asn1_set_name(yyvsp[-7].node,"");
                    _asn1_set_right(yyvsp[-7].node,yyvsp[-1].node);
                    _asn1_set_down(yyval.node,yyvsp[-7].node);
      	   
		    p_tree=yyval.node;
		    }
    break;

  case 3:
#line 130 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 4:
#line 131 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 5:
#line 134 "ASN1.y"
    {strcpy(yyval.str,"-");
                       strcat(yyval.str,yyvsp[0].str);}
    break;

  case 6:
#line 138 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 7:
#line 139 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 8:
#line 142 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 9:
#line 143 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 10:
#line 146 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 11:
#line 147 "ASN1.y"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 12:
#line 150 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_CONSTANT); 
                                       _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);}
    break;

  case 13:
#line 152 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_CONSTANT);
	                               _asn1_set_name(yyval.node,yyvsp[-3].str); 
                                       _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);}
    break;

  case 14:
#line 157 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 15:
#line 158 "ASN1.y"
    {yyval.node=yyvsp[-2].node;
                                            _asn1_set_right(_asn1_get_last_right(yyvsp[-2].node),yyvsp[0].node);}
    break;

  case 16:
#line 162 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_CONSTANT); 
                                   _asn1_set_value(yyval.node,yyvsp[0].str,strlen(yyvsp[0].str)+1);}
    break;

  case 17:
#line 164 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_CONSTANT);
	                            _asn1_set_name(yyval.node,yyvsp[-3].str); 
                                    _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);}
    break;

  case 18:
#line 169 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 19:
#line 170 "ASN1.y"
    {yyval.node=yyvsp[-1].node;
                                                    _asn1_set_right(_asn1_get_last_right(yyvsp[-1].node),yyvsp[0].node);}
    break;

  case 20:
#line 174 "ASN1.y"
    {yyval.constant=CONST_UNIVERSAL;}
    break;

  case 21:
#line 175 "ASN1.y"
    {yyval.constant=CONST_PRIVATE;}
    break;

  case 22:
#line 176 "ASN1.y"
    {yyval.constant=CONST_APPLICATION;}
    break;

  case 23:
#line 179 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_TAG); 
                            _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);}
    break;

  case 24:
#line 181 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_TAG | yyvsp[-2].constant); 
                                _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);}
    break;

  case 25:
#line 185 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 26:
#line 186 "ASN1.y"
    {yyval.node=_asn1_mod_type(yyvsp[-1].node,CONST_EXPLICIT);}
    break;

  case 27:
#line 187 "ASN1.y"
    {yyval.node=_asn1_mod_type(yyvsp[-1].node,CONST_IMPLICIT);}
    break;

  case 28:
#line 190 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_DEFAULT); 
                                       _asn1_set_value(yyval.node,yyvsp[0].str,strlen(yyvsp[0].str)+1);}
    break;

  case 29:
#line 192 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_DEFAULT|CONST_TRUE);}
    break;

  case 30:
#line 193 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_DEFAULT|CONST_FALSE);}
    break;

  case 33:
#line 202 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_INTEGER);}
    break;

  case 34:
#line 203 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_INTEGER|CONST_LIST);
	                                 _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 35:
#line 205 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_INTEGER);}
    break;

  case 36:
#line 207 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_INTEGER|CONST_MIN_MAX);
                                         _asn1_set_down(yyval.node,_asn1_add_node(TYPE_SIZE)); 
                                         _asn1_set_value(_asn1_get_down(yyval.node),yyvsp[-1].str,strlen(yyvsp[-1].str)+1); 
                                         _asn1_set_name(_asn1_get_down(yyval.node),yyvsp[-4].str);}
    break;

  case 37:
#line 213 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_BOOLEAN);}
    break;

  case 38:
#line 216 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_TIME|CONST_UTC);}
    break;

  case 39:
#line 217 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_TIME|CONST_GENERALIZED);}
    break;

  case 40:
#line 220 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SIZE|CONST_1_PARAM);
	                              _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);}
    break;

  case 41:
#line 223 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SIZE|CONST_MIN_MAX);
	                              _asn1_set_value(yyval.node,yyvsp[-4].str,strlen(yyvsp[-4].str)+1);
                                      _asn1_set_name(yyval.node,yyvsp[-1].str);}
    break;

  case 42:
#line 228 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 43:
#line 229 "ASN1.y"
    {yyval.node=yyvsp[-1].node;}
    break;

  case 44:
#line 232 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_GENERALSTRING);}
    break;

  case 45:
#line 233 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_GENERALSTRING|CONST_SIZE);
	                            	  _asn1_set_down(yyval.node,yyvsp[0].node);}
    break;

  case 46:
#line 237 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_OCTET_STRING);}
    break;

  case 47:
#line 238 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_OCTET_STRING|CONST_SIZE);
                                           _asn1_set_down(yyval.node,yyvsp[0].node);}
    break;

  case 48:
#line 242 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_CONSTANT);
	                           _asn1_set_name(yyval.node,yyvsp[-3].str); 
                                    _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);}
    break;

  case 49:
#line 247 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 50:
#line 248 "ASN1.y"
    {yyval.node=yyvsp[-2].node;
                                                       _asn1_set_right(_asn1_get_last_right(yyvsp[-2].node),yyvsp[0].node);}
    break;

  case 51:
#line 252 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_BIT_STRING);}
    break;

  case 52:
#line 254 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_BIT_STRING|CONST_LIST);
                                _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 53:
#line 259 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_ENUMERATED|CONST_LIST);
                                _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 54:
#line 264 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_OBJECT_ID);}
    break;

  case 55:
#line 267 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_IDENTIFIER);
                                       _asn1_set_value(yyval.node,yyvsp[0].str,strlen(yyvsp[0].str)+1);}
    break;

  case 56:
#line 269 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_IDENTIFIER|CONST_SIZE);
                                       _asn1_set_value(yyval.node,yyvsp[-1].str,strlen(yyvsp[-1].str)+1);
                                       _asn1_set_down(yyval.node,yyvsp[0].node);}
    break;

  case 57:
#line 272 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 58:
#line 273 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 59:
#line 274 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 61:
#line 276 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 62:
#line 277 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 63:
#line 278 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 64:
#line 279 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 65:
#line 280 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 66:
#line 281 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 67:
#line 282 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 68:
#line 283 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 69:
#line 284 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_NULL);}
    break;

  case 70:
#line 287 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 71:
#line 288 "ASN1.y"
    {yyval.node=_asn1_mod_type(yyvsp[0].node,CONST_TAG);
                                               _asn1_set_right(yyvsp[-1].node,_asn1_get_down(yyval.node));
                                               _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 72:
#line 293 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 73:
#line 294 "ASN1.y"
    {yyval.node=_asn1_mod_type(yyvsp[-1].node,CONST_DEFAULT);
                                                       _asn1_set_right(yyvsp[0].node,_asn1_get_down(yyval.node));
						       _asn1_set_down(yyval.node,yyvsp[0].node);}
    break;

  case 74:
#line 297 "ASN1.y"
    {yyval.node=_asn1_mod_type(yyvsp[-1].node,CONST_OPTION);}
    break;

  case 75:
#line 300 "ASN1.y"
    {yyval.node=_asn1_set_name(yyvsp[0].node,yyvsp[-1].str);}
    break;

  case 76:
#line 303 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 77:
#line 304 "ASN1.y"
    {yyval.node=yyvsp[-2].node;
                                                _asn1_set_right(_asn1_get_last_right(yyvsp[-2].node),yyvsp[0].node);}
    break;

  case 78:
#line 308 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SEQUENCE);
                                              _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 79:
#line 310 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SEQUENCE_OF);
                                              _asn1_set_down(yyval.node,yyvsp[0].node);}
    break;

  case 80:
#line 312 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SEQUENCE_OF|CONST_SIZE);
                                            _asn1_set_right(yyvsp[-2].node,yyvsp[0].node);
                                            _asn1_set_down(yyval.node,yyvsp[-2].node);}
    break;

  case 81:
#line 317 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SET);
                                     _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 82:
#line 319 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SET_OF);
                                     _asn1_set_down(yyval.node,yyvsp[0].node);}
    break;

  case 83:
#line 321 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_SET_OF|CONST_SIZE);
                                       _asn1_set_right(yyvsp[-2].node,yyvsp[0].node);
                                       _asn1_set_down(yyval.node,yyvsp[-2].node);}
    break;

  case 84:
#line 326 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_CHOICE);
                                             _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 85:
#line 330 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_ANY);}
    break;

  case 86:
#line 331 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_ANY|CONST_DEFINED_BY);
                                        _asn1_set_down(yyval.node,_asn1_add_node(TYPE_CONSTANT));
	                                _asn1_set_name(_asn1_get_down(yyval.node),yyvsp[0].str);}
    break;

  case 87:
#line 336 "ASN1.y"
    {yyval.node=_asn1_set_name(yyvsp[0].node,yyvsp[-2].str);}
    break;

  case 88:
#line 340 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_OBJECT_ID|CONST_ASSIGN);
                         _asn1_set_name(yyval.node,yyvsp[-6].str);  
                         _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 89:
#line 344 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_OBJECT_ID|CONST_ASSIGN|CONST_1_PARAM);
                         _asn1_set_name(yyval.node,yyvsp[-5].str);  
                         _asn1_set_value(yyval.node,yyvsp[-4].str,strlen(yyvsp[-4].str)+1);
                         _asn1_set_down(yyval.node,yyvsp[-1].node);}
    break;

  case 90:
#line 349 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_INTEGER|CONST_ASSIGN);
                         _asn1_set_name(yyval.node,yyvsp[-3].str);  
                         _asn1_set_value(yyval.node,yyvsp[0].str,strlen(yyvsp[0].str)+1);}
    break;

  case 91:
#line 354 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 92:
#line 355 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 93:
#line 358 "ASN1.y"
    {yyval.node=yyvsp[0].node;}
    break;

  case 94:
#line 359 "ASN1.y"
    {yyval.node=yyvsp[-1].node;
                                                          _asn1_set_right(_asn1_get_last_right(yyvsp[-1].node),yyvsp[0].node);}
    break;

  case 95:
#line 363 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_OBJECT_ID);
                                                          _asn1_set_down(yyval.node,yyvsp[-1].node);
                                                          _asn1_set_name(yyval.node,yyvsp[-3].str);}
    break;

  case 96:
#line 366 "ASN1.y"
    {yyval.node=_asn1_add_node(TYPE_OBJECT_ID);
                                                          _asn1_set_name(yyval.node,yyvsp[-2].str);}
    break;

  case 97:
#line 390 "ASN1.y"
    {yyval.constant=CONST_EXPLICIT;}
    break;

  case 98:
#line 391 "ASN1.y"
    {yyval.constant=CONST_IMPLICIT;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 1791 "ASN1.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 395 "ASN1.y"




const char *key_word[]={"::=","OPTIONAL","INTEGER","SIZE","OCTET","STRING"
                       ,"SEQUENCE","BIT","UNIVERSAL","PRIVATE","OPTIONAL"
                       ,"DEFAULT","CHOICE","OF","OBJECT","IDENTIFIER"
                       ,"BOOLEAN","TRUE","FALSE","APPLICATION","ANY","DEFINED"
                       ,"SET","BY","EXPLICIT","IMPLICIT","DEFINITIONS","TAGS"
                       ,"BEGIN","END","UTCTime","GeneralizedTime"
                       ,"GeneralString","FROM","IMPORTS","NULL","ENUMERATED"};
const int key_word_token[]={ASSIG,OPTIONAL,INTEGER,SIZE,OCTET,STRING
                       ,SEQUENCE,BIT,UNIVERSAL,PRIVATE,OPTIONAL
                       ,DEFAULT,CHOICE,OF,OBJECT,STR_IDENTIFIER
                       ,BOOLEAN,TRUE,FALSE,APPLICATION,ANY,DEFINED
                       ,SET,BY,EXPLICIT,IMPLICIT,DEFINITIONS,TAGS
                       ,BEGIN,END,UTCTime,GeneralizedTime
                       ,GeneralString,FROM,IMPORTS,TOKEN_NULL,ENUMERATED};

/*************************************************************/
/*  Function: _asn1_yylex                                    */
/*  Description: looks for tokens in file_asn1 pointer file. */
/*  Return: int                                              */
/*    Token identifier or ASCII code or 0(zero: End Of File) */
/*************************************************************/
int 
_asn1_yylex() 
{
  int c,counter=0,k,lastc;
  char string[MAX_NAME_SIZE+1]; /* will contain the next token */  

  while(1)
    {
    while((c=fgetc(file_asn1))==' ' || c=='\t' || c=='\n')
      if(c=='\n') lineNumber++;

    if(c==EOF){
      strcpy(lastToken,"End Of File");
      return 0;
    }

    if(c=='(' || c==')' || c=='[' || c==']' || 
       c=='{' || c=='}' || c==',' || c=='.' ||
       c=='+' || c=='|'){
      lastToken[0]=c;lastToken[1]=0;
      return c;
    }
    if(c=='-'){  /* Maybe the first '-' of a comment */
      if((c=fgetc(file_asn1))!='-'){
	ungetc(c,file_asn1);
	lastToken[0]='-';lastToken[1]=0;
	return '-';
      }
      else{ /* Comments */
	lastc=0;
	counter=0;
	/* A comment finishes at the next double hypen or the end of line */
	while((c=fgetc(file_asn1))!=EOF && c!='\n' &&
	      (lastc!='-' || (lastc=='-' && c!='-')))
	  lastc=c;
	if(c==EOF){
 	  strcpy(lastToken,"End Of File");
	  return 0;
	}
	else{
	  if(c=='\n') lineNumber++;
	  continue; /* next char, please! (repeat the search) */
	}
      }
    }
    string[counter++]=c;
    /* Till the end of the token */
    while(!((c=fgetc(file_asn1))==EOF || c==' '|| c=='\t' || c=='\n' || 
	     c=='(' || c==')' || c=='[' || c==']' || 
	     c=='{' || c=='}' || c==',' || c=='.'))
      {
	if(counter>=MAX_NAME_SIZE){
	  result_parse=ASN1_NAME_TOO_LONG;
	  return 0;
	}
	string[counter++]=c;
      }
    ungetc(c,file_asn1);
    string[counter]=0;
    strcpy(lastToken,string);

    /* Is STRING a number? */
    for(k=0;k<counter;k++) 
      if(!isdigit(string[k])) break;
    if(k>=counter)
      {
      strcpy(yylval.str,string);  
      return NUM; /* return the number */
      }
 
    /* Is STRING a keyword? */
    for(k=0;k<(sizeof(key_word)/sizeof(char*));k++)  
      if(!strcmp(string,key_word[k])) return key_word_token[k]; 
 
    /* STRING is an IDENTIFIER */
    strcpy(yylval.str,string);
    return IDENTIFIER;
    }
}


/*************************************************************/
/*  Function: _asn1_create_errorDescription                  */
/*  Description: creates a string with the description of the*/
/*    error.                                                 */
/*  Parameters:                                              */
/*    error : error to describe.                             */
/*    errorDescription: string that will contain the         */
/*                      description.                         */
/*************************************************************/
void
_asn1_create_errorDescription(int error,char *errorDescription)
{
  switch(error){
  case ASN1_SUCCESS: case ASN1_FILE_NOT_FOUND: 
    if (errorDescription!=NULL) errorDescription[0]=0;
    break;
  case ASN1_SYNTAX_ERROR:
    if (errorDescription!=NULL) {
	strcpy(errorDescription,fileName);
	strcat(errorDescription,":");
	_asn1_ltostr(lineNumber,errorDescription+strlen(fileName)+1);
	strcat(errorDescription,": parse error near '");
	strcat(errorDescription,lastToken);
	strcat(errorDescription,"'");
    }
    break;
  case ASN1_NAME_TOO_LONG:
    if (errorDescription!=NULL) {
       strcpy(errorDescription,fileName);
       strcat(errorDescription,":");
       _asn1_ltostr(lineNumber,errorDescription+strlen(fileName)+1);
       strcat(errorDescription,": name too long (more than ");
       _asn1_ltostr(MAX_NAME_SIZE,errorDescription+strlen(errorDescription));
       strcat(errorDescription," characters)");
    }
    break;
  case ASN1_IDENTIFIER_NOT_FOUND:
    if (errorDescription!=NULL) {
       strcpy(errorDescription,fileName);
       strcat(errorDescription,":");
       strcat(errorDescription,": identifier '");
       strcat(errorDescription,_asn1_identifierMissing);
       strcat(errorDescription,"' not found");
    }
    break;
  default:
    if (errorDescription!=NULL) errorDescription[0]=0;
    break;
  }

}


/**
  * asn1_parser2tree - function used to start the parse algorithm.
  * @file_name: specify the path and the name of file that contains ASN.1 declarations.
  * @definitions: return the pointer to the structure created from 
  *   "file_name" ASN.1 declarations.  
  * @errorDescription : return the error description or an empty string if success.
  * Description:
  *
  * Creates the structures needed to manage the definitions included in *FILE_NAME file.
  *
  * Returns:
  *
  * ASN1_SUCCESS\: the file has a correct syntax and every identifier is known.
  *
  * ASN1_ELEMENT_NOT_EMPTY\: *POINTER not ASN1_TYPE_EMPTY.
  *
  * ASN1_FILE_NOT_FOUND\: an error occured while opening FILE_NAME.
  *
  * ASN1_SYNTAX_ERROR\: the syntax is not correct.
  *
  * ASN1_IDENTIFIER_NOT_FOUND\: in the file there is an identifier that is not defined.
  * ASN1_NAME_TOO_LONG\: in the file there is an identifier whith more than MAX_NAME_SIZE characters.
  **/
asn1_retCode
asn1_parser2tree(const char *file_name,ASN1_TYPE *definitions,char *errorDescription){

  p_tree=ASN1_TYPE_EMPTY;

  if(*definitions != ASN1_TYPE_EMPTY)
    return ASN1_ELEMENT_NOT_EMPTY;

  *definitions=ASN1_TYPE_EMPTY;

  fileName = file_name;

  /* open the file to parse */
  file_asn1=fopen(file_name,"r");

  if(file_asn1==NULL){
    result_parse=ASN1_FILE_NOT_FOUND;
  }
  else{
    result_parse=ASN1_SUCCESS;

    lineNumber=1;
    yyparse();

    fclose(file_asn1);
    
    if(result_parse==ASN1_SUCCESS){ /* syntax OK */
      /* set IMPLICIT or EXPLICIT property */
      _asn1_set_default_tag(p_tree);
      /* set CONST_SET and CONST_NOT_USED */
      _asn1_type_set_config(p_tree);
      /* check the identifier definitions */
      result_parse=_asn1_check_identifier(p_tree);
      if(result_parse==ASN1_SUCCESS){ /* all identifier defined */
	/* Delete the list and keep the ASN1 structure */
	_asn1_delete_list();
	/* Convert into DER coding the value assign to INTEGER constants */
	_asn1_change_integer_value(p_tree);
	/* Expand the IDs of OBJECT IDENTIFIER constants */
	_asn1_expand_object_id(p_tree);

	*definitions=p_tree;
      }
      else /* some identifiers not defined */ 
	/* Delete the list and the ASN1 structure */
	_asn1_delete_list_and_nodes();
    }
    else  /* syntax error */
      /* Delete the list and the ASN1 structure */
      _asn1_delete_list_and_nodes();
  }

  if (errorDescription!=NULL) 
	_asn1_create_errorDescription(result_parse,errorDescription);

  return result_parse;
}


/**
  * asn1_parser2array - function that generates a C structure from an ASN1 file
  * @inputFileName: specify the path and the name of file that contains ASN.1 declarations.
  * @outputFileName: specify the path and the name of file that will contain the C vector definition.
  * @vectorName: specify the name of the C vector.
  * @errorDescription : return the error description or an empty string if success.
  * Description:
  *
  * Creates a file containing a C vector to use to manage the definitions included in
  * *INPUTFILENAME file. If *INPUTFILENAME is "/aa/bb/xx.yy" and OUTPUTFILENAME is NULL, the file created is "/aa/bb/xx_asn1_tab.c".
  * If VECTORNAME is NULL the vector name will be "xx_asn1_tab".
  *
  * Returns:
  *
  *  ASN1_SUCCESS\: the file has a correct syntax and every identifier is known. 
  *
  *  ASN1_FILE_NOT_FOUND\: an error occured while opening FILE_NAME.
  *
  *  ASN1_SYNTAX_ERROR\: the syntax is not correct.
  *
  *  ASN1_IDENTIFIER_NOT_FOUND\: in the file there is an identifier that is not defined.
  *  ASN1_NAME_TOO_LONG\: in the file there is an identifier whith more than MAX_NAME_SIZE characters.
  **/
int asn1_parser2array(const char *inputFileName,const char *outputFileName,
		      const char *vectorName,char *errorDescription){
  char *file_out_name=NULL;
  char *vector_name=NULL;
  const char *char_p,*slash_p,*dot_p;

  p_tree=NULL;

  fileName = inputFileName;
    
  /* open the file to parse */
  file_asn1=fopen(inputFileName,"r");

  if(file_asn1==NULL)
    result_parse=ASN1_FILE_NOT_FOUND;
  else{
    result_parse=ASN1_SUCCESS;

    lineNumber=1;
    yyparse();

    fclose(file_asn1);

    if(result_parse==ASN1_SUCCESS){ /* syntax OK */
      /* set IMPLICIT or EXPLICIT property */
      _asn1_set_default_tag(p_tree);
      /* set CONST_SET and CONST_NOT_USED */
      _asn1_type_set_config(p_tree);
      /* check the identifier definitions */
      result_parse=_asn1_check_identifier(p_tree);

      if(result_parse==ASN1_SUCCESS){ /* all identifier defined */

	/* searching the last '/' and '.' in inputFileName */
	char_p=inputFileName;
	slash_p=inputFileName;
	while((char_p=strchr(char_p,'/'))){
	  char_p++;
	  slash_p=char_p;
	}

	char_p=slash_p;
	dot_p=inputFileName+strlen(inputFileName);
	
	while((char_p=strchr(char_p,'.'))){
	  dot_p=char_p;
	  char_p++;
	}

	if(outputFileName == NULL){ 
	  /* file_out_name = inputFileName + _asn1_tab.c */
	  file_out_name=(char *)malloc(dot_p-inputFileName+1+
                                       strlen("_asn1_tab.c"));
	  memcpy(file_out_name,inputFileName,dot_p-inputFileName);
	  file_out_name[dot_p-inputFileName]=0;
	  strcat(file_out_name,"_asn1_tab.c");
	}
	else{
	  /* file_out_name = inputFileName */
	  file_out_name=(char *)malloc(strlen(outputFileName)+1);
	  strcpy(file_out_name,outputFileName);
	}

	if(vectorName == NULL){ 
	  /* vector_name = file name + _asn1_tab */
	  vector_name=(char *)malloc(dot_p-slash_p+1+
                                       strlen("_asn1_tab"));
	  memcpy(vector_name,slash_p,dot_p-slash_p);
	  vector_name[dot_p-slash_p]=0;
	  strcat(vector_name,"_asn1_tab");
	}
	else{
	  /* vector_name = vectorName */
	  vector_name=(char *)malloc(strlen(vectorName)+1);
	  strcpy(vector_name,vectorName);
	}

	/* Save structure in a file */
	_asn1_create_static_structure(p_tree,
                  file_out_name,vector_name);

	free(file_out_name);
	free(vector_name);
      } /* result == OK */
    }   /* result == OK */
     
    /* Delete the list and the ASN1 structure */
    _asn1_delete_list_and_nodes();    
  } /* inputFile exist */

  if (errorDescription!=NULL)
	_asn1_create_errorDescription(result_parse,errorDescription);

  return result_parse;
}


/*************************************************************/
/*  Function: _asn1_yyerror                                  */
/*  Description: function called when there are syntax errors*/
/*  Parameters:                                              */
/*    char *s : error description                            */
/*  Return: int                                              */
/*                                                           */
/*************************************************************/
int _asn1_yyerror (char *s)
{
  /* Sends the error description to the std_out */

#ifdef LIBTASN1_DEBUG_PARSER
  _libtasn1_log("_asn1_yyerror:%s:%d: %s (Last Token:'%s')\n",fileName,
               lineNumber,s,lastToken); 
#endif

  if(result_parse!=ASN1_NAME_TOO_LONG) 
    result_parse=ASN1_SYNTAX_ERROR;

  return 0;
}

















