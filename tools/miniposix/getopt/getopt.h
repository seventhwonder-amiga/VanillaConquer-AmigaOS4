/*
Copyright (C) 1997 Gregory Pietsch

[These files] are hereby placed in the public domain without restrictions. Just
give the author credit, don't claim you wrote it or prevent anyone else from
using it.
*/
#pragma once

#ifndef MINIPOSIX_GETOPT_H
#define MINIPOSIX_GETOPT_H
#ifndef _WIN32
#pragma message("this getopt.h implementation is for Windows only!")
#else

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* include files needed by this include file */

/* macros defined by this include file */
#define no_argument       0
#define required_argument 1
#define optional_argument 2

/* types defined by this include file */

/* GETOPT_LONG_OPTION_T: The type of long option */
typedef struct option
{
    const char* name; /* the name of the long option */
    int has_arg;      /* one of the above macros */
    int* flag;        /* determines if getopt_long() returns a
                * value for a long option; if it is
                * non-NULL, 0 is returned as a function
                * value and the value of val is stored in
                * the area pointed to by flag.  Otherwise,
                * val is returned. */
    int val;          /* determines the value to return if flag is
              * NULL. */
} option;

/* externally-defined variables */
extern char* optarg;
extern int optind;
extern int opterr;
extern int optopt;

/* function prototypes */
int getopt(int argc, char** argv, char* optstring);
int getopt_long(int argc, char** argv, const char* shortopts, const option* longopts, int* longind);
int getopt_long_only(int argc, char** argv, const char* shortopts, const option* longopts, int* longind);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WIN32 */

#endif /* MINIPOSIX_GETOPT_H */
