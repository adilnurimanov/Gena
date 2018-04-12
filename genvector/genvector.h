/*
  genvector - Generalized Vector
  Pseudo-templated, Cpp-like dynamic linear array for custom data types.
  Copyright (c) 2017, Dmitry D. Chernov
*/

#ifndef ZZ_GENA_GENVECTOR_H_IG
#define ZZ_GENA_GENVECTOR_H_IG

typedef void* gvec_h;

#include "gvec_internal.inc"

/******************************************************************************/

/* Instantiation macros. */

#ifndef GVEC_MODULAR_APPROACH

#define \
GVEC_INSTANTIATE( tpTypeInfo, tpSurname, tpPassBy, tpReturnBy ) \
  ZZ_GVEC_INSTANTIATE(tpTypeInfo,tpSurname,tpPassBy,tpReturnBy)

#define \
GVEC_INSTANTIATE_EX( tpTypeInfo, tpSurname, tpAssignBy, tpPassBy, tpReturnBy ) \
  ZZ_GVEC_INSTANTIATE_EX(tpTypeInfo,tpSurname,tpAssignBy,tpPassBy,tpReturnBy)

#else /* GVEC_MODULAR_APPROACH */

#define \
GVEC_C_DEFINE( tpTypeInfo, tpSurname, tpPassBy, tpReturnBy ) \
  ZZ_GVEC_C_DEFINE(tpTypeInfo,tpSurname,tpPassBy,tpReturnBy)

#define \
GVEC_C_DEFINE_EX( tpTypeInfo, tpSurname, tpAssignBy, tpPassBy, tpReturnBy ) \
  ZZ_GVEC_C_DEFINE_EX(tpTypeInfo,tpSurname,tpAssignBy,tpPassBy,tpReturnBy)

#define \
GVEC_H_DECLARE( tpTypeInfo, tpSurname, tpPassBy, tpReturnBy ) \
  ZZ_GVEC_H_DECLARE(tpTypeInfo,tpSurname,tpPassBy,tpReturnBy)

#define \
GVEC_H_DECLARE_EX( tpTypeInfo, tpSurname, tpAssignBy, tpPassBy, tpReturnBy ) \
  ZZ_GVEC_H_DECLARE_EX(tpTypeInfo,tpSurname,tpAssignBy,tpPassBy,tpReturnBy)

#endif /* GVEC_MODULAR_APPROACH */

/******************************************************************************/

/* General-purpose functions. */

extern gvec_h gvec_set( gvec_h handle, gvec_h source );
extern gvec_h gvec_copy( gvec_h handle );
extern void gvec_free( gvec_h handle );

extern void gvec_clear( gvec_h handle );
extern void gvec_reduce( gvec_h handle, size_t new_count );
extern void gvec_erase( gvec_h handle, size_t position, size_t count );
extern void gvec_pop( gvec_h handle );

extern void* gvec_at( gvec_h handle, size_t position );
extern void* gvec_front( gvec_h handle );
extern void* gvec_back( gvec_h handle );

extern size_t gvec_count( gvec_h handle );
extern size_t gvec_size( gvec_h handle );
extern gena_bool gvec_empty( gvec_h handle );

/******************************************************************************/

/* Pseudo-templated functions to be specialized at type instantiation. */
/* NOTE: Do not call this directly. Instead, use the instantiation macros. */

#define ZZ_GVEC_FUNCTIONS_LIST( Surname, TypeName, PassType, ReturnType ) \
\
extern gvec_##Surname##_h gvec_##Surname##_new( size_t min_count ); \
\
extern gena_bool gvec_##Surname##_assign( gvec_##Surname##_h* phandle, \
  size_t count, const PassType value ); \
\
extern gena_bool gvec_##Surname##_resize( gvec_##Surname##_h* phandle, \
  size_t new_count, const PassType value ); \
\
extern gena_bool gvec_##Surname##_reserve( gvec_##Surname##_h* phandle, \
  size_t min_count ); \
\
extern gena_bool gvec_##Surname##_shrink( gvec_##Surname##_h* phandle ); \
\
extern gena_bool gvec_##Surname##_insert( gvec_##Surname##_h* phandle, \
  size_t position, size_t count, const PassType value ); \
\
extern gena_bool gvec_##Surname##_push( gvec_##Surname##_h* phandle, \
  const PassType value ); \
\
extern TypeName* gvec_##Surname##_at( gvec_##Surname##_h handle, \
  size_t position ); \
\
extern ReturnType gvec_##Surname##_front( gvec_##Surname##_h handle ); \
\
extern ReturnType gvec_##Surname##_back( gvec_##Surname##_h handle ); \
\
ZZ_GENA_FUNCTIONS_LIST_END

/******************************************************************************/

/* Pseudo-templates. User-type management functions are defined there. */
#include "gvec_template.inc"

#endif /* ZZ_GENA_GENVECTOR_H_IG */
