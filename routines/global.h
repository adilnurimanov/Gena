/*
  Copyright (c) 2018, Dmitry D. Chernov
*/

#ifndef ZZ_GENA_GLOBAL_H_IG
#define ZZ_GENA_GLOBAL_H_IG

#include "internal/common.h"

/******************************************************************************/

/* Instantiation modes. */

#define GENA_USE_VALUE ZZ_GENA_VAL__    /* simple type, by value */
#define GENA_USE_POINTER ZZ_GENA_PTR__  /* simple type, by pointer */
#define GENA_USE_BUFFER ZZ_GENA_BUF__   /* buffer type (array or string) */
#define GENA_USE_ARRAY ZZ_GENA_REF__    /* reference-access type (array) */

/******************************************************************************/

/* Default assignment approaches. */

#define GENA_ASSIGN_NAIVE ZZ_GENA_ASSIGN_NAIVE
#define GENA_ASSIGN_MEMORY ZZ_GENA_ASSIGN_MEMORY
#define GENA_ASSIGN_STRING ZZ_GENA_ASSIGN_STRING

/******************************************************************************/

/* Default comparison approaches. */

#define GENA_COMPARE_NAIVE ZZ_GENA_COMPARE_NAIVE
#define GENA_COMPARE_MEMORY ZZ_GENA_COMPARE_MEMORY
#define GENA_COMPARE_STRING ZZ_GENA_COMPARE_STRING

/******************************************************************************/

/* User-available macros. */

#define GENA_APPLY_TYPESET( macro, typeset ) \
  macro typeset

/******************************************************************************/

#endif /* ZZ_GENA_GLOBAL_H_IG */
