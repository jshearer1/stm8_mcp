/**
  ******************************************************************************
  * @file parameter.h
  * @brief  
  * @author
  * @version 
  * @date    
  ******************************************************************************
  *
  * BLAH BLAH BLAH
  *
  * <h2><center>&copy; COPYRIGHT 2112 asdf</center></h2>
  ******************************************************************************
  */
#ifndef PARAMETER_H
#define PARAMETER_H


/*
 * defines
 */

//#define CLOCK_16

#define PWM_8K


#define COMM_TIME_KLUDGE_DELAYS 


//#define BLDC_CT_SCALE  2
//#define BLDC_CT_SCALE  4
#define BLDC_CT_SCALE  8
//#define BLDC_CT_SCALE  16
//#define BLDC_CT_SCALE  32



#ifdef SADFASDF
// #define TIM3_RATE_MODULUS   4
#else
 #define TIM3_RATE_MODULUS   1
#endif

// 1/8000  = 0.000125 = 12.5 * 10^(-5)
// 1/12000 = 0.000083 = 8.3 * 10^(-5) 

// With TIM2 prescale value of 1, period TIM2 == period fMaster
// @8Mhz, fMASTER period == 0.000000125 S
// fMASTER * TIM1_PS = 0.125us * 4 = 0.5us

// @8k:
//  0.000125 / 0.5 us = 250 counts

// @12k:
//  0.000083 / 0.5 us  = 166.67 counts


#ifdef PWM_8K
  #define TIM2_PWM_PD    250   // 125uS 
#else // 12kHz
  #define TIM2_PWM_PD    166   //  83uS 
#endif


#define LED  0


/*
 * Types
 */
typedef  enum {
  BLDC_OFF,
  BLDC_RAMPUP,
  BLDC_ON
} BLDC_STATE_T;


/*
 * variables
 */
extern uint8_t TaskRdy;     // flag for background task to sync w/ timer refrence

extern  uint16_t global_uDC;



/*
 * prototypes
 */
// these are in driver.c .. header?
void BLDC_Spd_inc(void);
void BLDC_Spd_dec(void);
void BLDC_Stop(void);
void BLDC_Step(void);
void BLDC_Update(void);

// presently is in main.c .. header?
void TIM3_setup(uint16_t u16period);


#endif // PARAMETER_H
