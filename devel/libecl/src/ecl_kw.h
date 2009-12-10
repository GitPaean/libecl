#ifndef __ECL_KW_H__
#define __ECL_KW_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fortio.h>
#include <ecl_util.h>
#include <buffer.h>


typedef struct ecl_kw_struct      ecl_kw_type;

void          ecl_kw_fread_realloc_data(ecl_kw_type *ecl_kw, fortio_type *fortio);
ecl_type_enum ecl_kw_get_type(const ecl_kw_type *);
const char  * ecl_kw_get_str_type_ref(const ecl_kw_type *);
const char  * ecl_kw_get_header_ref(const ecl_kw_type *);
char        * ecl_kw_alloc_strip_header(const ecl_kw_type * );
ecl_kw_type * ecl_kw_alloc_empty();
void          ecl_kw_rewind(const ecl_kw_type * , fortio_type *);
bool          ecl_kw_fread_header(ecl_kw_type *, fortio_type *);
void          ecl_kw_set_header_name(ecl_kw_type * , const char * );
void          ecl_kw_set_header(ecl_kw_type  * , const char * , int , const char *);
void          ecl_kw_set_header_alloc(ecl_kw_type  * , const char * , int , const char *);
bool          ecl_kw_grdecl_fseek_kw(const char *  , bool  , bool  , FILE * );
bool          ecl_kw_fseek_kw(const char * , bool , bool , fortio_type *);
bool          ecl_kw_fseek_last_kw(const char * , bool  , fortio_type *);
void          ecl_kw_inplace_update_file(const ecl_kw_type * , const char * , int ) ;
void          ecl_kw_fskip(fortio_type *);
void          ecl_kw_alloc_data(ecl_kw_type  *);
void          ecl_kw_alloc_double_data(ecl_kw_type * ecl_kw , double * values);
void          ecl_kw_alloc_float_data(ecl_kw_type * ecl_kw , float * values);
bool          ecl_kw_fread_realloc(ecl_kw_type *, fortio_type *);
void          ecl_kw_fread(ecl_kw_type * , fortio_type * );
ecl_kw_type * ecl_kw_fscanf_alloc_grdecl_data(FILE * , int , ecl_type_enum );
void          ecl_kw_fprintf_grdecl(ecl_kw_type *  , FILE * );
ecl_kw_type * ecl_kw_fread_alloc(fortio_type *);
ecl_kw_type * ecl_kw_fscanf_alloc_parameter(FILE * , int );
void          ecl_kw_free_data(ecl_kw_type *);
void          ecl_kw_free(ecl_kw_type *);
void          ecl_kw_free__(void *);
ecl_kw_type * ecl_kw_alloc_copy (const ecl_kw_type *);
const void  * ecl_kw_copyc__(const void *);
//void        * ecl_kw_get_data_ref(const ecl_kw_type *);
void        * ecl_kw_alloc_data_copy(const ecl_kw_type * );
void          ecl_kw_memcpy(ecl_kw_type *, const ecl_kw_type *);
void          ecl_kw_get_memcpy_data(const ecl_kw_type *, void *);
void          ecl_kw_set_memcpy_data(ecl_kw_type * , const void *);
void          ecl_kw_fwrite(const ecl_kw_type *,  fortio_type *);
void          ecl_kw_iget(const ecl_kw_type *, int , void *);
void        * ecl_kw_iget_ptr(const ecl_kw_type *, int);
int           ecl_kw_get_size(const ecl_kw_type *);
bool          ecl_kw_header_eq(const ecl_kw_type *, const char *);
bool          ecl_kw_ichar_eq(const ecl_kw_type *, int , const char *);
ecl_kw_type * ecl_kw_alloc_complete(const char * ,  int , ecl_type_enum , const void * );
ecl_kw_type * ecl_kw_alloc_complete_shared(const char * ,  int , ecl_type_enum , void * );
void          ecl_kw_cfwrite(const ecl_kw_type *  , FILE *);
void          ecl_kw_cfread(ecl_kw_type *  , FILE *);
void          ecl_kw_fwrite_param(const char * , bool  , const char * ,  ecl_type_enum , int , void * );
void          ecl_kw_fwrite_param_fortio(fortio_type *, const char * ,  ecl_type_enum , int , void * );
void          ecl_kw_summarize(const ecl_kw_type * ecl_kw);
void          ecl_kw_fread_double_param(const char * , bool , double *);
float         ecl_kw_iget_as_float(const ecl_kw_type * ecl_kw , int i);
double        ecl_kw_iget_as_double(const ecl_kw_type * ecl_kw , int i);
void          ecl_kw_get_data_as_double(const ecl_kw_type *, double *);
bool          ecl_kw_equal(const ecl_kw_type *ecl_kw1, const ecl_kw_type *ecl_kw2);
ecl_kw_type * ecl_kw_alloc_scalar(const char *  , int  , ecl_type_enum  , double );
void          ecl_kw_fskip_data(ecl_kw_type *ecl_kw, fortio_type *fortio);
void          ecl_kw_fread_data(ecl_kw_type *ecl_kw, fortio_type *fortio);

void ecl_kw_fwrite_compressed(const ecl_kw_type * , FILE *);
void ecl_kw_fread_realloc_compressed(ecl_kw_type *  , FILE *);
ecl_kw_type * ecl_kw_fread_alloc_compressed(FILE * );

bool ecl_kw_is_grdecl_file(FILE * );
bool ecl_kw_is_kw_file(FILE * , bool );
void ecl_kw_inplace_sub(ecl_kw_type * , const ecl_kw_type * );
void ecl_kw_inplace_mul(ecl_kw_type * , const ecl_kw_type * );
void ecl_kw_inplace_add(ecl_kw_type * , const ecl_kw_type * );
void ecl_kw_inplace_div(ecl_kw_type * , const ecl_kw_type * );

void   ecl_kw_inplace_inv(ecl_kw_type * my_kw);
void   ecl_kw_scalar_init(ecl_kw_type * , double );
void   ecl_kw_scale(ecl_kw_type * , double );
void   ecl_kw_shift(ecl_kw_type * , double );
void   ecl_kw_element_sum(const ecl_kw_type * , void * );
void   ecl_kw_max_min(const ecl_kw_type * , void * , void *);
void * ecl_kw_get_void_ptr(const ecl_kw_type * ecl_kw);

double   ecl_kw_iget_as_double(const ecl_kw_type *  , int );

ecl_kw_type * ecl_kw_buffer_alloc(buffer_type * buffer);
void          ecl_kw_buffer_store(const ecl_kw_type * ecl_kw , buffer_type * buffer);



#define ECL_KW_IGET_TYPED_HEADER(type) type ecl_kw_iget_ ## type(const ecl_kw_type * , int);
ECL_KW_IGET_TYPED_HEADER(double);
ECL_KW_IGET_TYPED_HEADER(float);
ECL_KW_IGET_TYPED_HEADER(int);
#undef ECL_KW_IGET_TYPED_HEADER

#define ECL_KW_ISET_TYPED_HEADER(type) void ecl_kw_iset_ ## type(ecl_kw_type * , int , type );
ECL_KW_ISET_TYPED_HEADER(double);
ECL_KW_ISET_TYPED_HEADER(float);
ECL_KW_ISET_TYPED_HEADER(int);
#undef ECL_KW_ISET_TYPED_HEADER



#define ECL_KW_GET_TYPED_PTR_HEADER(type) type * ecl_kw_get_ ## type ## _ptr(const ecl_kw_type *);
ECL_KW_GET_TYPED_PTR_HEADER(double);
ECL_KW_GET_TYPED_PTR_HEADER(float);
ECL_KW_GET_TYPED_PTR_HEADER(int);
#undef ECL_KW_GET_TYPED_PTR_HEADER

#ifdef __cplusplus
}
#endif
#endif
