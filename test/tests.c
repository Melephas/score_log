#include <criterion/criterion.h>

#include "score/log.h"


Test(initialisation, interface) {
    const score_log_i log = score_get_log();
    cr_assert(log.init_stdout, "score_log_i.init_stdout set to NULL");
    cr_assert(log.init_file, "score_log_i.init_file set to NULL");

    cr_assert(log.debug, "score_log_i.debug set to NULL");
    cr_assert(log.info, "score_log_i.info set to NULL");
    cr_assert(log.warning, "score_log_i.warning set to NULL");
    cr_assert(log.error, "score_log_i.error set to NULL");
}

Test(logging, message_integrity) {
    cr_log_info("Entering logging::file");
    const score_log_i log = score_get_log();

    cr_log_info("Creating tmpfile");
    FILE *fp = tmpfile();

    cr_log_info("Initialising logging interface");
    log.init_file(score_log_level_debug, fp);

    cr_log_info("Logging message");
    log.info("Hello, World!");

    // Get exact length of file to allocate memory
    cr_log_info("Getting file length");
    fseek(fp, 0, SEEK_END);
    const int length = ftell(fp);
    cr_assert(length > 1, "Written file length is 0");
    cr_log_info("File length: %d", length);

    char *contents = malloc(length);

    cr_log_info("Reading file contents into buffer");
    rewind(fp);
    fread(contents, 1, length, fp);

    // Skip over additional log formatting, pointing at '|' initially so +2 needed to move to the start of the message
    const char* message_start = strchr(contents, '|') + 2;
    cr_assert(strcmp(message_start, "Hello, World!\n") == 0, "Unexpected string: '%s'", message_start);

    // Clean up memory
    free(contents);
}
