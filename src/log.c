#include "interface/score/log.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static FILE *writer = NULL;
static score_log_level min_level = score_log_level_debug;


static void init_stdout(const score_log_level level) {
    min_level = level;
    writer = stdout;
}

static void init_file(const score_log_level level, FILE *fp) {
    min_level = level;
    writer = fp;
}

static char* level_to_str(const score_log_level level) {
    switch (level) {
        case score_log_level_debug:
            return "DEBUG";
        case score_log_level_info:
            return "INFO";
        case score_log_level_warning:
            return "WARN";
        case score_log_level_error:
            return "ERROR";
        default:
            return NULL;
    }
}


static int log_generic(const score_log_level level, const char *format, va_list vlist) {
    // Check to see if logging at this level is allowed before doing anything expensive
    if (level < min_level) return 0;

    char time_str[1024] = { 0 };

    // Get current time as a string
    const time_t time_s = time(NULL);
    const struct tm *tm_time = gmtime(&time_s);
    strftime(time_str, sizeof(time_str), "%X", tm_time);

    // Calculate the length of the new format string + null terminator
    const int new_format_length = snprintf(NULL, 0, "[%s] %5s | %s\n", time_str, level_to_str(level), format) + 1;
    char* new_format = malloc(new_format_length);
    // Fill allocated memory with the new format string
    snprintf(new_format, new_format_length, "[%s] %5s | %s\n", time_str, level_to_str(level), format);

    // Format user supplied message and write it to the file
    const int ret = vfprintf(writer, new_format, vlist);

    // Tidy up memory allocations
    free(new_format);

    // Return number of characters written to the file
    return ret;
}

static int debug(const char *format, ...) {
    // Handle variadic arguments
    va_list vlist;
    va_start(vlist, format);

    // Log the actual message
    const int ret = log_generic(score_log_level_debug, format, vlist);

    // Clean up va_list stuff
    va_end(vlist);

    // Return number of characters written
    return ret;
}

static int info(const char *format, ...) {
    // Handle variadic arguments
    va_list vlist;
    va_start(vlist, format);

    // Log the actual message
    const int ret = log_generic(score_log_level_info, format, vlist);

    // Clean up va_list stuff
    va_end(vlist);

    // Return number of characters written
    return ret;
}

static int warning(const char *format, ...) {
    // Handle variadic arguments
    va_list vlist;
    va_start(vlist, format);

    // Log the actual message
    const int ret = log_generic(score_log_level_warning, format, vlist);

    // Clean up va_list stuff
    va_end(vlist);

    // Return number of characters written
    return ret;
}

static int error(const char *format, ...) {
    // Handle variadic arguments
    va_list vlist;
    va_start(vlist, format);

    // Log the actual message
    const int ret = log_generic(score_log_level_error, format, vlist);

    // Clean up va_list stuff
    va_end(vlist);

    // Return number of characters written
    return ret;
}

score_log_i score_get_log(void) {
    score_log_i ret = {
        .init_stdout = init_stdout,
        .init_file = init_file,

        .debug = debug,
        .info = info,
        .warning = warning,
        .error = error,
    };

    return ret;
}
