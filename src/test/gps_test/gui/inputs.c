#include "inputs.h"

controls_595_ButtonState inputs_buttons[] = {
    {1, 1, GPIOC, GPIO_PIN_0, 7, 0, 0, 0},
    {1, 2, GPIOC, GPIO_PIN_0, 6, 0, 0, 0},
    {1, 3, GPIOC, GPIO_PIN_0, 5, 0, 0, 0},
    {1, 4, GPIOC, GPIO_PIN_0, 4, 0, 0, 0},

    {1, 11, GPIOC, GPIO_PIN_1, 7, 0, 0, 0},
    {1, 12, GPIOC, GPIO_PIN_1, 6, 0, 0, 0},
    {1, 13, GPIOC, GPIO_PIN_1, 5, 0, 0, 0},
    {1, 14, GPIOC, GPIO_PIN_1, 4, 0, 0, 0},

};

controls_595_OutputState inputs_outs[] = {
    {1, 5, 0, 1},
    {1, 6, 1, 0},
    {1, 7, 2, 0},
    {1, 8, 3, 1},
};

void inputs_init()
{
    controls_595_init(inputs_buttons, 8, inputs_outs, 4, &inputs_input);
}

void inputs_update()
{
    controls_595_update();      
}

void inputs_input(uint32_t id,
		  uint8_t event,
		  uint32_t time)
{
    if(event & CONTROLS_ALL_CLICK)
    {
 	if(id == 3 &&
	   makise_g_host_input(host,
			       (MInputData){M_KEY_UP, M_INPUT_CLICK, time, 0})
	   == M_INPUT_NOT_HANDLED)
	    makise_g_cont_focus_prev(host->host);
	if(id == 1 &&
	   makise_g_host_input(host,
			       (MInputData){M_KEY_DOWN, M_INPUT_CLICK, time, 0})
	   == M_INPUT_NOT_HANDLED)
	    makise_g_cont_focus_next(host->host);
	if(id == 4 &&
	   makise_g_host_input(host,
			       (MInputData){M_KEY_RIGHT, M_INPUT_CLICK, time, 0})
	   == M_INPUT_NOT_HANDLED)
	    makise_g_cont_focus_next(host->host);
	if(id == 2 &&
	   makise_g_host_input(host,
			       (MInputData){M_KEY_LEFT, M_INPUT_CLICK, time, 0})
	   == M_INPUT_NOT_HANDLED)
	    makise_g_cont_focus_prev(host->host);
	if(id == 13)
	    makise_g_host_input(host,
				(MInputData){M_KEY_OK, M_INPUT_CLICK, time, 0});
    }
    if(event == CONTROLS_CLICK)
    {
	if(id == 12)
	    makise_g_cont_focus_prev(host->host);
	if(id == 11)
	    makise_g_cont_focus_next(host->host);
    } else if(event == CONTROLS_LONG_CLICK)
    {
	if(id == 11)
	    makise_g_host_input(host,
				(MInputData){M_KEY_TAB_NEXT, M_INPUT_CLICK, time, 0});
	if(id == 12)
	    makise_g_host_input(host,
				(MInputData){M_KEY_TAB_BACK, M_INPUT_CLICK, time, 0});
    }
	
    if(event & CONTROLS_ALL_PRESSING)
    {
	if(id == 3)
	    makise_g_host_input(host,
				(MInputData){M_KEY_UP, M_INPUT_PRESSING, time, 0});
	if(id == 1)
	    makise_g_host_input(host,
				(MInputData){M_KEY_DOWN, M_INPUT_PRESSING, time, 0});
	if(id == 4)
	    makise_g_host_input(host,
				(MInputData){M_KEY_RIGHT, M_INPUT_PRESSING, time, 0});
	if(id == 2) 
	    makise_g_host_input(host,
				(MInputData){M_KEY_LEFT, M_INPUT_PRESSING, time, 0});
    }

}
