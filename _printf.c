#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...)
{
    void *p_arg;
    char *s_arg;
    unsigned int u_arg;
    int d_arg, width, precision, padding, negative;
    char specifier;
    int printed;
    int i;
    int s_arg_len;
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;
    int result_count = 0;
    char hex_digits[] = "0123456789abcdef";
    char hex_digits_upper[] = "0123456789ABCDEF";
    char *hex_digit_array = hex_digits;
    int format_index = 0;
    va_list args;
    va_start(args, format);

    while (format[format_index] != '\0') {
        if (format[format_index] != '%') {
            buffer[buffer_index++] = *format++;
            result_count++;
            if (buffer_index == BUFFER_SIZE) {
                printed = write(STDOUT_FILENO, buffer, BUFFER_SIZE);
                buffer_index = 0;
            }
            continue;
        }

        specifier = *(++format);

        width = 0;
        precision = -1;
        padding = ' ';
        negative = 0;
        hex_digit_array = hex_digits;

        if (specifier == '-') {
            padding = '-';
            specifier = *(++format);
        }

        if (specifier == '0') {
            padding = '0';
            specifier = *(++format);
        }

        while (isdigit(specifier)) {
            width = 10 * width + (specifier - '0');
            specifier = *(++format);
        }

        if (specifier == '.') {
            specifier = *(++format);
            precision = 0;
            while (isdigit(specifier)) {
                precision = 10 * precision + (specifier - '0');
                specifier = *(++format);
            }
        }

        switch (specifier) {
            case 'c':
                buffer[buffer_index++] = va_arg(args, int);
                result_count++;
                break;
            case 's':
                s_arg = va_arg(args, char *);
                s_arg_len = strlen(s_arg);
                if (s_arg == NULL) {
                    s_arg = "(null)";
                }
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%*s", -width, s_arg);
                buffer_index += printed;
                result_count += printed;
                break;
            case '%':
                buffer[buffer_index++] = '%';
                result_count++;
                break;
            case 'd':
            case 'i':
                d_arg = va_arg(args, int);
                if (d_arg < 0) {
                    negative = 1;
                    d_arg = -d_arg;
                }
                printed = 0;
                do {
                    buffer[BUFFER_SIZE - (++printed) - buffer_index] = '0' + d_arg % 10;
                    d_arg /= 10;
                } while (d_arg != 0);
                if (negative) {
                    buffer[BUFFER_SIZE - (++printed) - buffer_index] = '-';
                }
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%*s", -width, buffer + BUFFER_SIZE - printed - buffer_index);
                buffer_index += printed;
                result_count += printed;
                break;
            case 'u':
                u_arg = va_arg(args, unsigned int);
                printed = 0;
                do {
                    buffer[BUFFER_SIZE - (++printed) - buffer_index] = '0' + u_arg % 10;
                    u_arg /= 10;
                } while (u_arg != 0);
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%*s", -width, buffer + BUFFER_SIZE - printed - buffer_index);
                buffer_index += printed;
                result_count += printed;
                break;
            case 'o':
                u_arg = va_arg(args, unsigned int);
                printed = 0;
                do {
                    buffer[BUFFER_SIZE - (++printed) - buffer_index] = '0' + (u_arg & 7);
                    u_arg >>= 3;
                } while (u_arg != 0);
                if (width > 0 && precision < 0 && (padding == '0')) {
                    precision = width - (buffer[BUFFER_SIZE - printed - buffer_index] == '0' ? 0 : 1);
                    width = 0;
                }
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%*.*s", -width, precision, buffer + BUFFER_SIZE - printed - buffer_index);
                buffer_index += printed;
                result_count += printed;
                break;
            case 'x':
                hex_digit_array = hex_digits;
                break;
            case 'X':
                if (specifier == 'X') {
                    hex_digit_array = hex_digits_upper;
                }
                u_arg = va_arg(args, unsigned int);
                printed = 0;
                do {
                    buffer[BUFFER_SIZE - (++printed) - buffer_index] = hex_digit_array[u_arg & 15];
                    u_arg >>= 4;
                } while (u_arg != 0);
                if (width > 0 && precision < 0 && (padding == '0')) {
                    precision = width - (buffer[BUFFER_SIZE - printed - buffer_index] == '0' ? 0 : 1);
                    width = 0;
                }
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%*.*s", -width, precision, buffer + BUFFER_SIZE - printed - buffer_index);
                buffer_index += printed;
                result_count += printed;
                break;
            case 'p':
                p_arg = va_arg(args, void *);
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%.*s0x%lx", precision, "0000000000000000", (unsigned long) p_arg);
                buffer_index += printed;
                result_count += printed;
                break;
            case 'b':
                u_arg = va_arg(args, unsigned int);
                printed = 0;
                do {
                    buffer[BUFFER_SIZE - (++printed) - buffer_index] = '0' + (u_arg & 1);
                    u_arg >>= 1;
                } while (u_arg != 0);
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%*s", -width, buffer + BUFFER_SIZE - printed - buffer_index);
                buffer_index += printed;
                result_count += printed;
                break;
            case 'S':
                s_arg = va_arg(args, char *);
                if (s_arg == NULL) {
                    s_arg = "(null)";
                }
                for (i = 0; s_arg[i] != '\0'; i++) {
                    if (s_arg[i] < 32 || s_arg[i] >= 127) {
                        printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "\\x%c%c", hex_digits_upper[(s_arg[i] >> 4) & 0xf], hex_digits_upper[s_arg[i] & 0xf]);
                        buffer_index += printed;
                        result_count += printed;
                    } else {
                        buffer[buffer_index++] = s_arg[i];
                    }
                }
                break;
            case 'r':
                s_arg = va_arg(args, char *);
                if (s_arg == NULL) {
                    s_arg = "(null)";
                }
                s_arg_len = strlen(s_arg);
                for (i = 0; i < s_arg_len; i++) {
                    buffer[BUFFER_SIZE - (s_arg_len - i) - buffer_index] = s_arg[i];
                }
                printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%.*s", width < 0 ? s_arg_len : width, buffer + BUFFER_SIZE - s_arg_len - buffer_index);
                buffer_index += printed;
                result_count += printed;
                break;
                case 'R':
                    s_arg = va_arg(args, char *);
                    if (s_arg == NULL) {
                        s_arg = "(null)";
                    }
                    for (i = 0; s_arg[i] != '\0'; i++) {
                        if ((s_arg[i] >= 'a' && s_arg[i] <= 'm') || (s_arg[i] >= 'A' && s_arg[i] <= 'M')) {
                            buffer[buffer_index++] = s_arg[i] + 13;
                        } else if ((s_arg[i] >= 'n' && s_arg[i] <= 'z') || (s_arg[i] >= 'N' && s_arg[i] <= 'Z')) {
                            buffer[buffer_index++] = s_arg[i] - 13;
                        } else {
                            buffer[buffer_index++] = s_arg[i];
                        }
                    }
                    printed = snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%.*s", width < 0 ? (int) strlen(s_arg) : (int) width, buffer);
                    buffer_index += printed; 
                    result_count += printed;
                    break;
                default:
                    buffer[buffer_index++] = format[format_index];
                    result_count++;
                    break;
        }
        format_index++;
    }
        write(STDOUT_FILENO, buffer, buffer_index);
        return (result_count);
}

