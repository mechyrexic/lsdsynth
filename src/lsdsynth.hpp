#include "lv2.h"

/* internal core methods */
LV2_Handle instantiate (const struct LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features);

void connect_port (LV2_Handle instance, uint32_t port, void *data_location);

void activate (LV2_Handle instance);

void run (LV2_Handle instance, uint32_t sample_count);

void deactivate (LV2_Handle instance);

void cleanup (LV2_Handle instance);

const void* extension_data (const char *uri);

/* interface */
LV2_SYMBOL_EXPORT const LV2_Descriptor* lv2_descriptor (uint32_t index);