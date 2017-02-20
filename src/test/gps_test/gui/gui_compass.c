#include "gui_custom.h"

uint8_t _m_compass_draw   (MElement* b);
MInputResultEnum _m_compass_input  (MElement* b, MInputData data);
MFocusEnum _m_compass_focus  (MElement* b, MFocusEnum act);


void gui_create_compass(MCompass *b, MContainer *c,
			int32_t x, int32_t y, //position of center
			uint32_t r, //radius
			float *angle)
{
    MElement *e = &b->el;
    e->gui = c->gui;

    e->data = b;

    e->draw = &_m_compass_draw;
    e->predraw = 0;
    e->update = 0;
    e->input = 0;
    e->focus = 0;
    e->free = 0;
    
    e->position.x  = x - r;
    e->position.y  = y - r;
    e->position.width  = r * 2;
    e->position.height = r * 2;

    e->enabled = 1;
    e->id = makise_g_newid();
    
    e->focus_prior = 0;
    
    b->x = x;
    b->y = y;
    b->r = r;
    b->angle = angle;
    
    makise_g_cont_add(c, e);
    
    printf("Compass %d created\n", e->id);
}

uint8_t _m_compass_draw   (MElement* b)
{
    MCompass *c = (MCompass*)b->data;
    
    makise_d_circle(b->gui->buffer,
		    c->x, c->y, c->r,
		    MC_White);
		    
    makise_d_char(b->gui->buffer, 'S', c->x, c->y + c->r, &F_Arial15, MC_Red);
    makise_d_char(b->gui->buffer, 'N', c->x, c->y - c->r, &F_Arial15, MC_Red);

    int32_t x = (int32_t)(c->r * cos(*c->angle));
    int32_t y = (int32_t)(c->r * sin(*c->angle));
    makise_d_line(b->gui->buffer, c->x, c->y, c->x + x, c->y + y, MC_Blue);
    
    //printf("Compass %d dr\n", b->id);
    return M_OK;
}
