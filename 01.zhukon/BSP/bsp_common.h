#ifndef _BSP_COMMON_H
#define _BSP_COMMON_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "stm32f10x_conf.h"

#include "user.h"

#if SYSTEM_SUPPORT_UCOS
#include "includes.h"
#endif

typedef enum
{
    FALSE = 0, TRUE = 1
} bool;
#define HBYTE(a)               ((unsigned char)(((unsigned short)(a) >> 8) & 0xFF))
#define LBYTE(a)               ((unsigned char)((unsigned short)(a)& 0xff))
#define MAKEWORD(bLow,bHigh)   ((unsigned short)(((unsigned char)(bLow))|(((unsigned short)((unsigned char)(bHigh)))<<8)))

/***************************************************************************************************/

//硬币器，纸币器使用选择位,使用纸币器和硬币器，值为1；不使用，值为0
#define USE_COIN        0
//弹簧道连续出货和不连续出货版本选择，二选一;值为1，表示连续出货;值为2，表示不连续出货
#define HUOWU_Continue      1

/****************************************************************************************************/

#include "bsp_usart.h"
#include "bsp_gpio.h"
//#include "bsp_adc.h"
//#include "bsp_dma.h"
//#include "bsp_iic.h"
#include "bsp_zhibiqi.h"
#include "bsp_delay.h"
#include "bsp_timer.h"
#include "bsp_yingbiqi.h"

#if (USE_COIN == 1)     //使用硬币器和纸币器
#include "bsp_coin.h"
#endif

#define   Version_Year       "28"       // year
#define   Version_Month      "03"      // month
#define   Version_Day        "15"      // day


//位带操作
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08

#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)       //输出
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)       //输入

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)



unsigned short CRC16_isr(unsigned char *Dat, unsigned int len);
bool strLenCmp(char *cmd1, char *cmd2, u8 len);
bool strLenCpy(char *dst, char *src, u8 len);
u8 strLen(char *cmd);

void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);

extern char strtemp[100];         //打印缓存，用于输出打印信息


#endif  //_BSP_COMMON_H
