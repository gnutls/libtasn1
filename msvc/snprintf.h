#if defined _MSC_VER && _MSC_VER <= 1900
# include <stdarg.h>
# include <stdio.h>
# define snprintf c99_snprintf
# define vsnprintf c99_vsnprintf
__inline int
c99_vsnprintf (char *outBuf, size_t size, const char *format, va_list ap)
{
  int count = -1;

  if (size != 0)
    count = _vsnprintf_s (outBuf, size, _TRUNCATE, format, ap);
  if (count == -1)
    count = _vscprintf (format, ap);

  return count;
}

__inline int
c99_snprintf (char *outBuf, size_t size, const char *format, ...)
{
  int count;
  va_list ap;

  va_start (ap, format);
  count = c99_vsnprintf (outBuf, size, format, ap);
  va_end (ap);

  return count;
}

#endif
