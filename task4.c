#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * write_buffered - writes a string to stdout, buffering as much as possible
 * @str: the string to write
 *
 * Return: the number of characters written, or -1 on error
 */
int write_buffered(char *str)
{
static char buffer[1024];
static size_t buf_len = 0;
int len = strlen(str);
int written = 0;
int total_written = 0;

/* write any remaining data from previous call */
if (buf_len > 0) {
written = write(STDOUT_FILENO, buffer, buf_len);
if (written < 0)
return -1;
total_written += written;
buf_len = 0;
}

/* buffer as much data as possible */
if ((size_t) len >= sizeof(buffer)) {
written = write(STDOUT_FILENO, str, len);
if (written < 0)
return -1;
total_written += written;
} else {
memcpy(buffer + buf_len, str, len);
buf_len += len;
}

/* write any remaining data that couldn't be buffered */
if (buf_len == sizeof(buffer)) {
written = write(STDOUT_FILENO, buffer, buf_len);
if (written < 0)
return -1;
total_written += written;
buf_len = 0;
}

return (total_written);
}
