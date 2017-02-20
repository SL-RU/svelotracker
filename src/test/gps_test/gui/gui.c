#include "gui.h"

MakiseGUI    *mGui;
MHost        *host;
MakiseGUI    Gu;
MakiseBuffer Bu;
MakiseDriver Dr;
MHost        hs;
MContainer   co;
uint32_t     sb[3920] = {0}; 
uint32_t     bb[9600] = {0};


void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi == &ILI9340_SPI)
	ili9340_spi_txhalfcplt(mGui->driver);
}
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi == &ILI9340_SPI)
	ili9340_spi_txcplt(mGui->driver);
}

void gui_predraw(MakiseGUI * g)
{
    makise_g_host_call(host, M_G_CALL_PREDRAW);
}
void gui_draw(MakiseGUI* gui)
{
    for (uint32_t i = 0; i < 16; i++) {
	
	makise_d_rect_filled(mGui->buffer, i * 10, 0, 10, 10, i, i);
    }
    makise_g_host_call(host, M_G_CALL_DRAW);
}


MakiseGUI* gui_init()
{
    //malloc structures
    MakiseGUI    * gu = &Gu;
    MakiseBuffer * bu = &Bu;
    MakiseDriver * dr = &Dr;
    host = &hs;
    host->host = &co;
    host->host->gui = gu;

    //init driver structure
    ili9340_driver(dr);
    //malloc small buffer
    dr->buffer = sb;
    printf("%d\n", (uint32_t)(dr->size));
    //init gui struct

    uint32_t sz = makise_init(gu, dr, bu);
    //malloc big buffer
    bu->buffer = bb;//malloc(sz);
    memset(bu->buffer, 0, sz);
    printf("%d\n", (uint32_t)(sz));    
    
    mGui = gu;
    ili9340_init(gu);
    makise_start(gu);

    mGui->predraw = &gui_predraw;
    mGui->draw = &gui_draw;
    return mGui;
}
