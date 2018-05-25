//
//  bigsplines_init.c
//  
//
//  Created by Nathaniel E. Helwig on 5/23/18.
//

#include <R_ext/RS.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
 Check these declarations against the C/Fortran source code.
 */

/* .Fortran calls */
extern void F77_NAME(cubker)(void *, void *, void *, void *, void *);
extern void F77_NAME(cubkersym)(void *, void *, void *);
extern void F77_NAME(cubkerz)(void *, void *, void *, void *, void *);
extern void F77_NAME(cubkerzsym)(void *, void *, void *);
extern void F77_NAME(linker)(void *, void *, void *, void *, void *);
extern void F77_NAME(linkersym)(void *, void *, void *);
extern void F77_NAME(nomker)(void *, void *, void *, void *, void *, void *);
extern void F77_NAME(nomkersym)(void *, void *, void *, void *);
extern void F77_NAME(ordker)(void *, void *, void *, void *, void *, void *);
extern void F77_NAME(ordkermon)(void *, void *, void *, void *, void *);
extern void F77_NAME(ordkersym)(void *, void *, void *, void *);
extern void F77_NAME(perker)(void *, void *, void *, void *, void *);
extern void F77_NAME(perkersym)(void *, void *, void *);
extern void F77_NAME(sumfreq)(void *, void *, void *, void *, void *, void *);
extern void F77_NAME(tpsker)(void *, void *, void *, void *, void *, void *);
extern void F77_NAME(tpskersym)(void *, void *, void *, void *);

static const R_FortranMethodDef FortranEntries[] = {
    {"cubker",     (DL_FUNC) &F77_NAME(cubker),     5},
    {"cubkersym",  (DL_FUNC) &F77_NAME(cubkersym),  3},
    {"cubkerz",    (DL_FUNC) &F77_NAME(cubkerz),    5},
    {"cubkerzsym", (DL_FUNC) &F77_NAME(cubkerzsym), 3},
    {"linker",     (DL_FUNC) &F77_NAME(linker),     5},
    {"linkersym",  (DL_FUNC) &F77_NAME(linkersym),  3},
    {"nomker",     (DL_FUNC) &F77_NAME(nomker),     6},
    {"nomkersym",  (DL_FUNC) &F77_NAME(nomkersym),  4},
    {"ordker",     (DL_FUNC) &F77_NAME(ordker),     6},
    {"ordkermon",  (DL_FUNC) &F77_NAME(ordkermon),  5},
    {"ordkersym",  (DL_FUNC) &F77_NAME(ordkersym),  4},
    {"perker",     (DL_FUNC) &F77_NAME(perker),     5},
    {"perkersym",  (DL_FUNC) &F77_NAME(perkersym),  3},
    {"sumfreq",    (DL_FUNC) &F77_NAME(sumfreq),    6},
    {"tpsker",     (DL_FUNC) &F77_NAME(tpsker),     6},
    {"tpskersym",  (DL_FUNC) &F77_NAME(tpskersym),  4},
    {NULL, NULL, 0}
};

void R_init_bigsplines(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, NULL, FortranEntries, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
