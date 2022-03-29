#include "stddef.h"
#include "stdint.h"
#include "stdlib.h"
//#include "math.h"
#include "lsdsynth.h"



/* internal core methods */
LV2_Handle instantiate (const struct LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features)
{
    lsdsynth* m = (lsdsynth*) calloc (1, sizeof (lsdsynth));
    return m;
}

void connect_port (LV2_Handle instance, uint32_t port, void *data_location)
{
    lsdsynth* m = (lsdsynth*) instance;
    if (!m) return;

    switch (port)
    {
    case 0:
        m->audio_in_ptr = (float*) data_location;
        break;

    case 1:
        m->audio_out_ptr = (float*) data_location;
        break;

    case 2:
        m->amp_ptr = (float*) data_location;
        break;
    
    default:
        break;
    }
}

void activate (LV2_Handle instance)
{
    /* not needed here */
}

void run (LV2_Handle instance, uint32_t sample_count)
{
    lsdsynth* m = (lsdsynth*) instance;
    if (!m) return;
    if ((!m->audio_in_ptr) || (!m->audio_out_ptr) || (!m->amp_ptr)) return;

    for (uint32_t i = 0; i < sample_count; ++i)
    {
        m->audio_out_ptr[i] = m->audio_in_ptr[i] * *(m->amp_ptr);
    }
}

void deactivate (LV2_Handle instance)
{
    /* not needed here */
}

void cleanup (LV2_Handle instance)
{
    lsdsynth* m = (lsdsynth*) instance;
    if (!m) return;
    free (m);
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
const LV2_SYMBOL_EXPORT LV2_Descriptor* lv2_descriptor (uint32_t index)
{
    if (index == 0) return &descriptor;
    else return NULL;
}