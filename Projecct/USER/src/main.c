#include<rtthread.h>
#include"headfile.h"

#define LED0_priority 4
#define LED0_timeslices 5
static struct rt_thread led0_thread;//?????
ALIGN(RT_ALIGN_SIZE)
static rt_uint8_t rt_led0_thread_stack[1024];//???
static void led0_thread_entry(void* parameter);


#define LED1_priority 4
#define LED1_timeslices 5
static struct rt_thread led1_thread;//?????
ALIGN(RT_ALIGN_SIZE)
static rt_uint8_t rt_led1_thread_stack[1024];//???
static void led1_thread_entry(void* parameter);


static void led0_thread_entry(void *parameter)
{
	while(1)
	{
		gpio_set(A7,0);
		rt_thread_mdelay(100);
		gpio_set(A7,1);
		rt_thread_mdelay(100);
	}
}

static void led1_thread_entry(void *parameter)
{
	while(1)
	{
		gpio_set(A8,0);
		rt_thread_mdelay(1500);
		gpio_set(A8,1);
		rt_thread_mdelay(1500);
	}
}



int main(void) { 
	

	  gpio_init(B2,GPO,0,NOPULL);
		gpio_init(A7,GPO,1,NOPULL);
		gpio_init(A8,GPO,1,NOPULL);
	
		rt_thread_init(&led0_thread,                 //?????
                   "led0",                       //????,?shell??????
                   led0_thread_entry,            //??????
                   RT_NULL,                      //????????
                   &rt_led0_thread_stack[0],     //???????
                   sizeof(rt_led0_thread_stack), //?????
                   LED0_priority,                            //??????
                   LED0_timeslices);                          //?????
									 
		rt_thread_init(&led1_thread,                 //?????
                   "led1",                       //????,?shell??????
                   led1_thread_entry,            //??????
                   RT_NULL,                      //????????
                   &rt_led1_thread_stack[0],     //???????
                   sizeof(rt_led1_thread_stack), //?????
                   LED1_priority,                            //??????
                   LED1_timeslices);
                               
    rt_thread_startup(&led0_thread); 
		rt_thread_startup(&led1_thread);

		return 0;
}


