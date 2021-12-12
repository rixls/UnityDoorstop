#include "config.h"

Config config;

void cleanup_config() {
#define FREE_NON_NULL(val)                                                     \
    if (val != NULL) {                                                         \
        free(val);                                                             \
        val = NULL;                                                            \
    }

    FREE_NON_NULL(config.target_assembly);
    FREE_NON_NULL(config.mono_dll_search_path_override);
    FREE_NON_NULL(config.clr_corlib_dir);
    FREE_NON_NULL(config.clr_runtime_coreclr_path);

#undef FREE_NON_NULL
}

void init_config_defaults() {
    config.enabled = FALSE;
    config.ignore_disabled_env = FALSE;
    config.redirect_output_log = FALSE;
    config.target_assembly = NULL;
    config.mono_dll_search_path_override = NULL;
    config.clr_corlib_dir = NULL;
    config.clr_runtime_coreclr_path = NULL;
}