/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		GPIO
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴LPC546XX_config.h�ļ��ڰ汾�궨��
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/

#ifndef _LPC546XX_gpio_h
#define _LPC546XX_gpio_h

//-------------------------------------------------------------------------------------------------------------------
//  @brief                      �����������λ����   ʹ�÷�����51���ƣ����Լ򵥵Ĳ���IO��
//  @param      Y               Yȡֵ��Χ 0-31
//  Sample usage:               P0(0) = 1;    P000����ߵ�ƽ��ǰ��P000����Ϊ���ģʽ��      
//                              dat = P0(31); ��ȡP031��ƽ��ǰ��P031����Ϊ����ģʽ��
//  @Note                       P000 = ~P000;��������ǲ���ʵ�ֵ�  ��תIO��ʹ��gpio_toggle����
//-------------------------------------------------------------------------------------------------------------------  
#define P0(Y)             GPIO->B[0][Y]
#define P1(Y)             GPIO->B[1][Y]



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_PIN        ������������Ĵ���8λ(�ֽ�)��ַ
//  @param      X               Xȡֵ��Χ 0��P0   1��P1
//  @param      Y               Yȡֵ��Χ 0��00-07����   1��08-15����
//                                        2��16-23����   3��24-31����
//  Sample usage:               GPIO_PIN(0,0) = 0XFF;   P000-P007�˸���������ߵ�ƽ ǰ����IO����Ϊ���ģʽ
//                              dat = GPIO_PIN(0,0);    ��ȡP000-P007�˸����ŵ�ƽ   ǰ����IO����Ϊ����ģʽ
//  @Note                       GPIO_PIN(0,0) = ~GPIO_PIN(0,0);��������ǲ���ʵ�ֵ�  8λIO��ת��ʹ��GPIO_NOT�궨��
//-------------------------------------------------------------------------------------------------------------------  
#define GPIO_PIN(X,Y)   (*((uint8 *)((uint32)(&(GPIO->PIN[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_DIR        �������ŷ���Ĵ���8λ(�ֽ�)��ַ
//  @param      X               Xȡֵ��Χ 0��P0   1��P1
//  @param      Y               Yȡֵ��Χ 0��00-07����   1��08-15����
//                                        2��16-23����   3��24-31����
//  Sample usage:               GPIO_DIR(0,0) = 0XFF;    P000-P007����Ϊ���ģʽ
//                              GPIO_DIR(0,0) = 0X00;    P000-P007����Ϊ����ģʽ
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_DIR(X,Y)   (*((uint8 *)((uint32)(&(GPIO->DIR[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_SET        ����������һ�Ĵ���8λ(�ֽ�)��ַ
//  @param      X               Xȡֵ��Χ 0��P0   1��P1
//  @param      Y               Yȡֵ��Χ 0��00-07����   1��08-15����
//                                        2��16-23����   3��24-31����
//  Sample usage:               GPIO_SET(0,0) = 0XFF;    P000-P007����ߵ�ƽ ǰ����IO����Ϊ���ģʽ
//                              GPIO_SET(0,0) = 0X00;    ��Ч
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_SET(X,Y)   (*((uint8 *)((uint32)(&(GPIO->SET[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_CLR        ������������Ĵ���8λ(�ֽ�)��ַ
//  @param      X               Xȡֵ��Χ 0��P0   1��P1
//  @param      Y               Yȡֵ��Χ 0��00-07����   1��08-15����
//                                        2��16-23����   3��24-31����
//  Sample usage:               GPIO_CLR(0,0) = 0XFF;    P000-P007����͵�ƽ ǰ����IO����Ϊ���ģʽ
//                              GPIO_CLR(0,0) = 0X00;    ��Ч
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_CLR(X,Y)   (*((uint8 *)((uint32)(&(GPIO->CLR[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_NOT        ��������ȡ���Ĵ���8λ(�ֽ�)��ַ
//  @param      X               Xȡֵ��Χ 0��P0   1��P1
//  @param      Y               Yȡֵ��Χ 0��00-07����   1��08-15����
//                                        2��16-23����   3��24-31����
//  Sample usage:               GPIO_NOT(0,0) = 0XFF;    P000-P007�����ת ǰ����IO����Ϊ���ģʽ
//                              GPIO_NOT(0,0) = 0X00;    ��Ч
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_NOT(X,Y)   (*((uint8 *)((uint32)(&(GPIO->NOT[X])) + Y)))


void  gpio_init  (PIN_enum pin, GPIODIR_enum dir, uint8 dat, uint32 pull);
void  gpio_pull_set(PIN_enum pin, uint8 pull);
void  gpio_set   (PIN_enum pin, uint8 dat);
void  gpio_dir   (PIN_enum pin, GPIODIR_enum dir);
uint8 gpio_get   (PIN_enum pin);
void  gpio_toggle(PIN_enum pin);






#endif

