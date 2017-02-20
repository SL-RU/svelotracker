#ifndef GUI_H
#define GUI_H
#include "makise.h"
#include "makise_gui.h"
#include "makise_e.h"
#include "spi.h"
#include "gpio.h"
#include "controls_595.h"
#include <stdio.h>
#include <string.h>

#include "gui_custom.h"

extern MHost     *host;
extern MakiseGUI *mGui;
MakiseGUI* gui_init();

#endif
