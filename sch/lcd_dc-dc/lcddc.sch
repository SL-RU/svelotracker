EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:PSU
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L NCP1529 U1
U 1 1 583AFA04
P 4400 3050
F 0 "U1" H 4400 2900 60  0000 C CNN
F 1 "NCP1529" H 4400 3150 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 4400 3050 60  0001 C CNN
F 3 "" H 4400 3050 60  0000 C CNN
	1    4400 3050
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L1
U 1 1 583AFAFD
P 5550 3050
F 0 "L1" V 5500 3050 50  0000 C CNN
F 1 "INDUCTOR" V 5650 3050 50  0000 C CNN
F 2 "lcd_dc-dc:CDRH2D14" H 5550 3050 50  0001 C CNN
F 3 "" H 5550 3050 50  0000 C CNN
	1    5550 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5100 3050 5250 3050
$Comp
L R R2
U 1 1 583AFBCC
P 5950 3200
F 0 "R2" V 6030 3200 50  0000 C CNN
F 1 "R" V 5950 3200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5880 3200 50  0001 C CNN
F 3 "" H 5950 3200 50  0000 C CNN
	1    5950 3200
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 583AFBF1
P 6150 3200
F 0 "C2" H 6175 3300 50  0000 L CNN
F 1 "18p" H 6175 3100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6188 3050 50  0001 C CNN
F 3 "" H 6150 3200 50  0000 C CNN
	1    6150 3200
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 583AFC16
P 6600 3350
F 0 "C3" H 6625 3450 50  0000 L CNN
F 1 "C" H 6625 3250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6638 3200 50  0001 C CNN
F 3 "" H 6600 3350 50  0000 C CNN
	1    6600 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3050 6900 3050
Connection ~ 5950 3050
$Comp
L R R3
U 1 1 583AFC69
P 5950 3600
F 0 "R3" V 6030 3600 50  0000 C CNN
F 1 "R" V 5950 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5880 3600 50  0001 C CNN
F 3 "" H 5950 3600 50  0000 C CNN
	1    5950 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3400 6150 3400
Wire Wire Line
	5100 3400 5100 3200
Wire Wire Line
	5950 3350 5950 3450
Wire Wire Line
	6150 3400 6150 3350
Connection ~ 5950 3400
Connection ~ 6150 3050
Wire Wire Line
	6600 3750 6600 3500
Wire Wire Line
	3100 3750 6900 3750
Wire Wire Line
	3600 3750 3600 3150
Wire Wire Line
	3600 3150 3650 3150
Connection ~ 5950 3750
Wire Wire Line
	6600 2950 6600 3200
$Comp
L C C1
U 1 1 583B0057
P 3250 3250
F 0 "C1" H 3275 3350 50  0000 L CNN
F 1 "C" H 3275 3150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3288 3100 50  0001 C CNN
F 3 "" H 3250 3250 50  0000 C CNN
	1    3250 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2950 3650 2950
Connection ~ 3600 3750
$Comp
L GND #PWR01
U 1 1 583B00EC
P 5050 3800
F 0 "#PWR01" H 5050 3550 50  0001 C CNN
F 1 "GND" H 5050 3650 50  0000 C CNN
F 2 "" H 5050 3800 50  0000 C CNN
F 3 "" H 5050 3800 50  0000 C CNN
	1    5050 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3800 5050 3750
Connection ~ 5050 3750
$Comp
L +3.3V #PWR02
U 1 1 583B0220
P 3250 2850
F 0 "#PWR02" H 3250 2700 50  0001 C CNN
F 1 "+3.3V" H 3250 2990 50  0000 C CNN
F 2 "" H 3250 2850 50  0000 C CNN
F 3 "" H 3250 2850 50  0000 C CNN
	1    3250 2850
	1    0    0    -1  
$EndComp
Connection ~ 3250 2950
$Comp
L +1V8 #PWR03
U 1 1 583B0261
P 6600 2950
F 0 "#PWR03" H 6600 2800 50  0001 C CNN
F 1 "+1V8" H 6600 3090 50  0000 C CNN
F 2 "" H 6600 2950 50  0000 C CNN
F 3 "" H 6600 2950 50  0000 C CNN
	1    6600 2950
	1    0    0    -1  
$EndComp
Connection ~ 6600 3050
$Comp
L CONN_01X02 P2
U 1 1 583B02D5
P 7100 3350
F 0 "P2" H 7100 3500 50  0000 C CNN
F 1 "CONN_01X02" V 7200 3350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 7100 3350 50  0001 C CNN
F 3 "" H 7100 3350 50  0000 C CNN
	1    7100 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3750 6900 3400
Connection ~ 6600 3750
Wire Wire Line
	6900 3050 6900 3300
$Comp
L Q_NMOS_GSD Q1
U 1 1 583B1C2E
P 2800 3550
F 0 "Q1" H 3100 3600 50  0000 R CNN
F 1 "Q_NMOS_GSD" H 3450 3500 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3000 3650 50  0001 C CNN
F 3 "" H 2800 3550 50  0000 C CNN
	1    2800 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2850 3250 3100
Wire Wire Line
	2900 3350 2900 3300
Wire Wire Line
	2900 3300 3100 3300
Wire Wire Line
	3100 3300 3100 3750
Wire Wire Line
	3250 3400 3250 3750
Connection ~ 3250 3750
$Comp
L CONN_01X04 P1
U 1 1 583B272B
P 2100 3300
F 0 "P1" H 2100 3550 50  0000 C CNN
F 1 "CONN_01X04" V 2200 3300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 2100 3300 50  0001 C CNN
F 3 "" H 2100 3300 50  0000 C CNN
	1    2100 3300
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 3250 2400 3750
Wire Wire Line
	2400 3750 2900 3750
Wire Wire Line
	2600 3550 2550 3550
Wire Wire Line
	2550 3550 2550 3350
Wire Wire Line
	3100 3250 3100 2950
Wire Wire Line
	2300 3150 2550 3150
Wire Wire Line
	2550 3150 2550 2500
Wire Wire Line
	2550 2500 5150 2500
Wire Wire Line
	5150 2500 5150 2950
Wire Wire Line
	5150 2950 5100 2950
$Comp
L R_Small R1
U 1 1 583B2A4C
P 2550 3650
F 0 "R1" H 2580 3670 50  0000 L CNN
F 1 "R_Small" H 2580 3610 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 2550 3650 50  0001 C CNN
F 3 "" H 2550 3650 50  0000 C CNN
	1    2550 3650
	1    0    0    -1  
$EndComp
Connection ~ 2550 3550
Connection ~ 2550 3750
Wire Wire Line
	2300 3450 2450 3450
Wire Wire Line
	2550 3350 2300 3350
Wire Wire Line
	2400 3250 2300 3250
Wire Wire Line
	3100 3250 2450 3250
Wire Wire Line
	2450 3250 2450 3450
$EndSCHEMATC
