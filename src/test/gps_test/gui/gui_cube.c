#include "gui_custom.h"

uint8_t _m_cube_draw   (MElement* b);
MFocusEnum _m_cube_focus  (MElement* b, MFocusEnum act);


void gui_create_cube(MCube *b, MContainer *c,
		     int32_t x, int32_t y, //position of center
		     double *pitch,
		     double *roll,
		     double *yaw)
{
    MElement *e = &b->el;
    e->gui = c->gui;

    e->data = b;

    e->draw = &_m_cube_draw;
    e->predraw = 0;
    e->update = 0;
    e->input = 0;
    e->focus = 0;
    e->free = 0;
    
    e->position.x  = x;
    e->position.y  = y;
    e->position.width  = 200;
    e->position.height = 200;

    e->enabled = 1;
    e->id = makise_g_newid();
    
    e->focus_prior = 0;
    
    makise_g_cont_add(c, e);

    b->pitch = pitch;
    b->roll = roll;
    b->yaw  = yaw;
    
    printf("Cube %d created\n", e->id);
}

uint8_t _m_cube_draw   (MElement* b)
{
    MCube *c = (MCube*)b->data;
    
    makise_d_line(b->gui->buffer,
		  c->x, c->y,
		  c->x + x, c->y + y,
		  MC_Blue);

    return M_OK;
}
