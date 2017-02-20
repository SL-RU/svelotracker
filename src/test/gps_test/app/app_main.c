#include "app_main.h"
#include "compass.h"
#include "i2c.h"

char* sample_string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
char* but_t[3] =
{
    "I2C",
    "start",
    "clear"
};

char out[9048] = {0};

MakiseStyle button_style =
{
    MC_White,
    &F_Arial24,
    0,
    //bg       font     border   double_border
    {MC_Black, MC_Gray, MC_Gray, 0},  //unactive
    {MC_Black, MC_White, MC_White, 0},//normal
    {MC_White, MC_Black, MC_White, 0}, //focused
    {MC_Green, MC_White, MC_White, 0}, //active
};
MakiseStyle text_style =
{
    MC_White,
    &F_Arial15,
    3,
    //bg       font     border   double_border
    {MC_Transparent, MC_White, MC_Transparent, 0},  //unactive
    {MC_Transparent, MC_White, MC_Transparent, 0},  //unactive
    {0, 0, 0, 0}, //focused
    {0, 0, 0, 0}, //active
};


MButton but[3];
MTextField tf;
MCompass comp;

uint32_t last_ch = 0;
void b_rem(MButton *b)
{
    memset(out, 0, 70);
    HAL_UART_Receive_DMA(&huart1, out, 70);
    last_ch = 0;
}
void b_st(MButton *b)
{
    HAL_UART_Transmit(&huart1, "$PSTMCOLD\r\l", 13, 1000);
}
uint8_t buf[1024] = {0};
void b_time(MButton *b)
{
    memset(out, 0, 70);
    strcat(out, "I2C devices ping test\n");
    uint8_t c = 0, a = 0;
    for(uint8_t i = 0; i < 127; i++)
    {
	if((a = HAL_I2C_IsDeviceReady(&hi2c1, i<<1, 4, 100)) == HAL_OK)
	{
	    c++;
	    sprintf(buf, "I2C device with address 0x%02x is %d\n", i, a);
	    strcat(out, buf);
	}
    }
    sprintf(buf, "TOTAL I2C devices: %d\n", c);
    strcat(out, buf);
    
}

void app_main_init()
{
    m_create_button(&but[0], host->host,
		    10, 10, 80, 30,
		    but_t[0],
		    &b_time, 0, 0,
		    &button_style);
    m_create_button(&but[1], host->host,
		    90, 10, 80, 30,
		    but_t[1],
		    &b_st, 0, 0,
		    &button_style);
    m_create_button(&but[2], host->host,
		    170, 10, 100, 30,
		    but_t[2],
		    &b_rem, 0, 0,
		    &button_style);

    gui_create_compass(&comp, host->host, 160, 120, 100, compass_get_angle());
    
    m_create_text_field(&tf, host->host, 
    			5, 50, 310, 150, 
    			out, 
    			&text_style); 
    /* HAL_UART_Receive_DMA(&huart1, out, 128); */
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    printf(out);
//    memset(out, 0, 70);
//    HAL_UART_Receive_DMA(&huart1, out, 70);
//    last_ch = 0;
}

void app_main_upd()
{
    uint32_t l;
//    if((l = strlen(out)) != last_ch)
//    {
//	printf(out);
//	last_ch = l;
//    }
//    printf("\n");
//    strcat(out, buf + last_ch);
    memset(buf, 0, 128);
}
