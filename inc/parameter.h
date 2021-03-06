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


typedef  uint16_t *  Global_ADC_Phase_t ;


/*
 * variables
 */
extern uint8_t TaskRdy;     // flag for background task to sync w/ timer refrence


// how many ADCs can be saved in a single (60deg) commutation sector (how many PWM ISR per sector? depends on motor speed and PWM freq.)
#define ADC_PHASE_BUF_SZ  8  // make this power of 2 so modulus can be used 


extern Global_ADC_Phase_t Global_ADC_PhaseABC_ptr[];  // pointers to ADC phase buffers

extern uint8_t BackEMF_Sample_Index;


/*
 * prototypes
 */

void BLDC_Spd_inc(void); // should go away
void BLDC_Spd_dec(void);// should go away

uint16_t BLDC_PWMDC_Plus(void);
uint16_t BLDC_PWMDC_Minus(void);

void BLDC_Stop(void);
void BLDC_Step(void);
void BLDC_Update(void);

// presently is in main.c .. header?
void TIM3_setup(uint16_t u16period);


#endif // PARAMETER_H
