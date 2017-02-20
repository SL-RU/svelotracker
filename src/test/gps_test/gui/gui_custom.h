#ifndef GUI_CUSTOM_H
#define GUI_CUSTOM_H
#include "gui.h"
#include <math.h>

//compass element
typedef struct {
    MakiseGUI *gui;
    MElement el;

    float *angle;

    int32_t x;
    int32_t y;
    uint32_t r;

} MCompass;

void gui_create_compass(MCompass *b, MContainer *c,
			int32_t x, int32_t y, //position of center
			uint32_t r, //radius
			float *angle);


#endif