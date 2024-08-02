#pragma once
#include <stdio.h>


typedef enum {
    score_log_level_debug,
    score_log_level_info,
    score_log_level_warning,
    score_log_level_error
} score_log_level;

/// Module interface
typedef struct {
    /* Utility functions */
    void (*init_stdout)(const score_log_level level);
    void (*init_file)(const score_log_level level, FILE *file);

    /* Logging functions */
    int (*debug)(const char *format, ...);
    int (*info)(const char *format, ...);
    int (*warning)(const char *format, ...);
    int (*error)(const char *format, ...);
} score_log_i;

score_log_i score_get_log(void);
