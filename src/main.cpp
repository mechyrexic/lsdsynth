#include "lsdsynth.hpp"
#include <lv2/atom/atom.h>
#include <lv2/urid/urid.h>
#include <lv2/midi/midi.h>
#include <lv2/core/lv2_util.h>
#include <lv2/atom/util.h>


/* internal core methods */
LV2_Handle instantiate (const struct LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features)
{
    
}

void connect_port (LV2_Handle instance, uint32_t port, void *data_location)
{
    
}

void activate (LV2_Handle instance)
{
    
}

void run (LV2_Handle instance, uint32_t sample_count)
{
    
}

void deactivate (LV2_Handle instance)
{
    
}

void cleanup (LV2_Handle instance)
{
    
}

const void* extension_data (const char *uri)
{
    return NULL;
}

/* descriptor */
LV2_Descriptor const descriptor =
{
    "https://github.com/mechycat/lsdsynth",
    instantiate,
    connect_port,
    activate /* or NULL */,
    run,
    deactivate /* or NULL */,
    cleanup,
    extension_data /* or NULL */
};

/* interface */
LV2_SYMBOL_EXPORT const LV2_Descriptor* lv2_descriptor (uint32_t index)
{
    if (index == 0) return &descriptor;
    else return NULL;
}
