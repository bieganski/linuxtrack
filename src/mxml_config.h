#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>


/*
 * Version number...
 */

#define MXML_VERSION	""


/*
 * Inline function support...
 */

#define inline


/*
 * Long long support...
 */

#undef HAVE_LONG_LONG_INT


/*
 * Do we have the *printf() functions?
 */

#undef HAVE_SNPRINTF
#undef HAVE_VASPRINTF
#undef HAVE_VSNPRINTF


/*
 * Do we have the strXXX() functions?
 */

#undef HAVE_STRDUP
#undef HAVE_STRLCAT
#undef HAVE_STRLCPY


/*
 * Do we have threading support?
 */

#undef HAVE_PTHREAD_H


/*
 * Define prototypes for string functions as needed...
 */

#  ifndef HAVE_STRDUP
extern char	*_mxml_strdup(const char *);
#    define strdup _mxml_strdup
#  endif /* !HAVE_STRDUP */

#  ifndef HAVE_STRLCAT
extern size_t	_mxml_strlcat(char *, const char *, size_t);
#    define strlcat _mxml_strlcat
#  endif /* !HAVE_STRLCAT */

#  ifndef HAVE_STRLCPY
extern size_t	_mxml_strlcpy(char *, const char *, size_t);
#    define strlcpy _mxml_strlcpy
#  endif /* !HAVE_STRLCPY */

extern char	*_mxml_strdupf(const char *, ...);
extern char	*_mxml_vstrdupf(const char *, va_list);

#  ifndef HAVE_SNPRINTF
extern int	_mxml_snprintf(char *, size_t, const char *, ...);
#    define snprintf _mxml_snprintf
#  endif /* !HAVE_SNPRINTF */

#  ifndef HAVE_VSNPRINTF
extern int	_mxml_vsnprintf(char *, size_t, const char *, va_list);
#    define vsnprintf _mxml_vsnprintf
#  endif /* !HAVE_VSNPRINTF */
