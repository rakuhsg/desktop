#include "rawl.h"

#include <stdio.h>

enum LOG_LEVEL {
    LOG_INFO = 1,
    LOG_WARNING = 2,
    LOG_ERROR = 3,
    LOG_DEBUG = 4,
};

static inline void log_message(const char *message, int level) {
    const char *level_str;

    switch (level) {
        case LOG_INFO:
            level_str = "INFO";
            break;
        case LOG_WARNING:
            level_str = "WARNING";
            break;
        case LOG_ERROR:
            level_str = "ERROR";
            break;
        case LOG_DEBUG:
            level_str = "DEBUG";
            break;
        default:
            level_str = "?";
    }

    printf("[%s] %s\n", level_str, message);
}

inline void rw_log_info(const char *message) {
    log_message(message, LOG_INFO);
}

inline void rw_log_warning(const char *message) {
    log_message(message, LOG_WARNING);
}

inline void rw_log_error(const char *message) {
    log_message(message, LOG_ERROR);
}

inline void rw_log_debug(const char *message) {
    log_message(message, LOG_DEBUG);
}
