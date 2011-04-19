#include "read_configs.h"
bool read_configs()
{
	readSystemCfg();
	readColourCfg();
	readControlCfg();
}

void readColourCfg()
{

}

void readSystemCfg()
{

}

void readControlCfg()
{

}
/*
void readConfig()
{
    char hodler[256];
    string temp = "";
    fstream config;
    config.open( "config.cfg" );
    while(temp != "end")
    {
        config.getline(hodler, 256);
        temp = hodler;
        process_input_moar(temp);
    }
}

void readColours()
{
    char hodler[256];
    string temp = "";
    fstream config;
    config.open( "colours.cfg" );
    int blue, green, red;

    config.getline(hodler, 256);
    temp = hodler;
    int x = 8;
    while(temp != "end")
    {
        config.getline(hodler, 256);
        red = atoi(hodler);
        config.getline(hodler, 256);
        green = atoi(hodler);
        config.getline(hodler, 256);
        blue = atoi(hodler);
        config.getline(hodler, 256);
        temp = hodler;
		SDL_Color * c = new SDL_Color;
		c->r = red;
		c->b = blue;
		c->g = green;
		vColors.push_back(c);
    }
}
*/

