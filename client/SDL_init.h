#ifndef SDL_INIT_H
#define SDL_INIT_H


bool init_SDL();
void close_SDL();
bool loadFont();

SDL_Rect newRectangle( int x, int y, int w, int h );
SDL_Color newColour( int r, int b, int g );

#endif
