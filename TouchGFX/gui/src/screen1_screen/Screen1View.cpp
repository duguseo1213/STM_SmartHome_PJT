#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern int state;
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{

    Screen1ViewBase::tearDownScreen();
    state=1;
}

void Screen1View::toggle_curtain()
{
	uint8_t str[] = "C\r\n";
	HAL_UART_Transmit(&huart3, str, sizeof(str), 100);
	HAL_UART_Transmit(&huart1, str, sizeof(str), 100);
	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
}


