#include "compass.h"

uint8_t compass_register_read(uint8_t reg)
{
    uint8_t result = 0;
    HAL_I2C_Master_Transmit(&COMPASS_I2C, COMPASS_I2C_ADDR, &reg,    1, 100);
    HAL_I2C_Master_Receive(&COMPASS_I2C,  COMPASS_I2C_ADDR, &result, 1, 100);
    return result;
}
void compass_register_write(uint8_t reg, uint8_t data)
{
    uint8_t d[] = {reg, data};
    HAL_I2C_Master_Transmit(&COMPASS_I2C, COMPASS_I2C_ADDR, d, 2, 100);
}


uint16_t lsm303_read_pos(uint8_t reg)
{
    uint8_t r[2] = {0};
    HAL_I2C_Master_Transmit(&hi2c1, 0x3a, &reg, 1, 100);
    HAL_I2C_Master_Receive(&hi2c1, 0x3a, r, 1, 100);
    reg += 1;
    HAL_I2C_Master_Transmit(&hi2c1, 0x3a, &reg, 1, 100);
    HAL_I2C_Master_Receive(&hi2c1, 0x3a, r + 1, 1, 100);
    return (uint16_t)(r[0] | (r[1] << 8));
}

float ang = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
//    printf("GPIO 12 EXTI\n");

    double x = (double)lsm303_read_pos(LSM303_OUT_X_L_M);
    double y = (double)lsm303_read_pos(LSM303_OUT_Y_L_M);
    double z = (double)lsm303_read_pos(LSM303_OUT_Z_L_M);

    double
	pitch = atan2(x, sqrt(y*y + z*z)),
	roll  = atan2(-y, -z),
	yaw   = atan2(z, sqrt(x*x + y*y));

    float headX;
    float headY;
    float cos_roll;
    float sin_roll;
    float cos_pitch;
    float sin_pitch;


    ang = pitch;

    // Declination correction (if supplied)
    /* if( fabs(_declination) > 0.0 ) */
    /* { */
        /* heading = heading + _declination; */
        /* if (heading > M_PI)    // Angle normalization (-180 deg, 180 deg) */
        /*     heading -= (2.0 * M_PI); */
        /* else if (heading < -M_PI) */
        /*     heading += (2.0 * M_PI); */
//    }

    // Optimization for external DCM use. Calculate normalized components
//    heading_x = cos(heading);
//    heading_y = sin(heading);
    
//    printf("%f\n", ang);
}

void compass_init()
{
//  Magnetometer data-ready signal on INT1 enable
    compass_register_write(LSM303_CTRL3, 0b11001010);
    compass_register_write(LSM303_CTRL4, 0b00000000);
    
/* CTRL5 register description */
/*  TEMP_EN Temperature sensor enable. Default value: 0 */
/* (0: temperature sensor disabled; 1: temperature sensor enabled) */
/* M_RES [1:0] Magnetic resolution selection. Default value: 00 */
/* (00: low resolution, 11: high resolution) */
/* M_ODR [2:0] Magnetic data rate selection. Default value: 110 */
/* Refer to Table 47 */
/* LIR2 Latch interrupt request on INT2_SRC register, with INT2_SRC register cleared by */
/* reading INT2_SRC itself. Default value: 0. */
/* (0: interrupt request not latched; 1: interrupt request latched) */
/* LIR1 Latch interrupt request on INT1_SRC register, with INT1_SRC register cleared by */
/* reading INT1_SRC itself. Default value: 0. */
/* (0: interrupt request not latched; 1: interrupt request latched) */
    compass_register_write(LSM303_CTRL5, 0b01110000);
    
/* CTRL6 register description */
/* MFS [1:0] */
/* Magnetic full-scale selection. Default value: 01 */
/* Refer to Table 50 */
    compass_register_write(LSM303_CTRL6, 0x20);
    
/* CTRL7 register description */
/* AHPM[1:0] High-pass filter mode selection for acceleration data. Default value: 00 */
/* Refer to Table 53 */
/* AFDS Filtered acceleration data selection. Default value: 0 */
/* (0: internal filter bypassed; 1: data from internal filter sent to output register and FIFO) */
/* T_ONLY Temperature sensor only mode. Default value: 0 */
/* If this bit is set to ‘1’, the temperature sensor is on while the magnetic sensor is off. */
/* MLP Magnetic data low-power mode. Default value: 0 */
/* If this bit is ‘1’, the M_ODR [2:0] is set to 3.125 Hz independently from the MODR set- */
/* tings. Once the bit is set to ‘0’, the magnetic data rate is configured by the MODR bits */
/* in the CTRL5 (24h) register. */
/* MD[1:0] Magnetic sensor mode selection. Default 10 */
/* Refer to Table 54 */
    compass_register_write(LSM303_CTRL7, 0b00);


    printf("acc %d\n", compass_register_read(LSM303_WHO_AM_I));
//    HAL_I2C_Master_Transmit(&hi2c1, 0x3a, &reg, 1, 100);

    lsm303_read_pos(LSM303_OUT_X_L_M);

    
    for (int i = 0; i < 100; i++) {
	
    
//    lsm303_read();

//    HAL_Delay(200);
    }
}

float* compass_get_angle()
{
    return &ang;
}