#ifndef INPUTS_H
#define INPUTS_H 1
#include "controls_595.h"
#include <string.h>
#include "gui.h"

extern controls_595_ButtonState inputs_buttons[];
extern controls_595_OutputState inputs_outs[];

void inputs_init();
void inputs_input(uint32_t id,
		  uint8_t event,
		  uint32_t time);
void inputs_update();

#endif
