#ifndef READ_CONFIGS_H
#define READ_COFIGS_H
#include "main.h"

bool readConfigs( engine * e );
bool readSystemCfg();
bool readColourCfg( std::vector< SDL_Colour* > * colours );
bool readControlCfg( engine * e );

#endif
