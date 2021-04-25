#include "Task.h"
#include "projdefs.h"
#include "FreeRTOS.h"
#include "portmacro.h"

//静态任务创建函数（需要自己指定任务栈）
#if( configSUPPORT_STATIC_ALLOCATION == 1 )

TaskHandle_t xTaskCreateStatic(	TaskFunction_t pxTaskCode,           //任务入口地址（函数名） 类型定义了一个指向任务函数的指针
					            const char * const pcName,           //指针 任务名称地址
					            const uint32_t ulStackDepth,         //任务栈大小，单位为字
					            void * const pvParameters,           //指向传入任务参数 （传入任务参数的地址，方便理解）
					            StackType_t * const puxStackBuffer,  //任务栈的起始地址
					            TCB_t * const pxTaskBuffer )         //任务控制块指针
{
	TCB_t *pxNewTCB;
	TaskHandle_t xReturen;
	
	if((pxTaskBuffer != NULL)&&(puxStackBuffer != NULL))
	{
		pxNewTCB = (TCB_t*) pxTaskBuffer;  //地址给pxNewTCB
		pxNewTCB->pxStack = (StackType_t *)puxStackBuffer; //任务栈的起始地址
	}
	
	return xReturen;
}


static void prvInitialiseNewTask( 	TaskFunction_t pxTaskCode,              //任务入口
									const char * const pcName,              //函数名
									const uint32_t ulStackDepth,            //任务栈大小
									void * const pvParameters,              //传递给任务的参数
									TaskHandle_t * const pxCreatedTask,     //*****任务句柄
									TCB_t *pxNewTCB )                       //任务控制块指针
{
	StackType_t *pxTopOfStack;
	UBaseType_t x;
	
	pxTopOfStack = pxNewTCB->pxStack + (ulStackDepth - (uint32_t)1);    //栈顶地址（栈向下增长，现在栈空，栈顶指向数组的最后一个元素（开辟内存的最高地址）
	pxTopOfStack = (StackType_t *) \
	               ( ( ( uint32_t ) pxTopOfStack ) & ( ~( ( uint32_t ) 0x0007 ) ) ); //向下做8字节对齐（宁愿舍点不用，保证M4地址访问不出问题）
	
	
	
	
}
#endif /* configSUPPORT_STATIC_ALLOCATION */

