#ifndef __RDEBUG_H
#define __RDEBUG_H

/**
 * For using printf add to CMakeLists.txt one of the next string
 *
 * -> add_definitions(-DRDEBUG_USE_SWO_PRINTF)
 *  OR
 * -> add_definitions(-DRDEBUG_USE_SEGGER_RTT)
 * OR
 * ->  add_definitions(-DRDEBUG_USE_UART1_PRINTF)
 *
 * and please-> add_definitions(-DUSE_FULL_ASSERT) for extended iformation about errors
 *
 * WARNING printf  %f e.q. double and float not work in FreeRTOS TASK
 * BE CAREFULL  USING printf(%f) can broken stack task
 *
 * if your want use printf  %f comment  -> # -specs=nosys.specs -specs=nano.specs  " in CmakeList.txt
 *
 * For printf %f  not in FreeRTOS task context add to  CMakeLists.txt in section COMMON_FLAGS-> -u_printf_float
 * -> SET(COMMON_FLAGS " -already_written_flags   -u_printf_float")
 *
 */

#endif
