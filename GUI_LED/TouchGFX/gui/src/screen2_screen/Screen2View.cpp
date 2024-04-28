#include <gui/screen2_screen/Screen2View.hpp>
#include "stm32f4xx_hal.h"
#include <stdlib.h>
#include <touchgfx/Color.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

int state;
int now_temp=77;
int select_temp=20;
Screen2View::Screen2View()
{

}

void Screen2View::temp_up()
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);

	uint8_t str[] = "0\r\n";
	HAL_UART_Transmit(&huart1, str, sizeof(str), 100);
	HAL_UART_Transmit(&huart3, str, sizeof(str), 100);
	select_temp++;

	Unicode::snprintf(TXBuffer, 15, "%d", select_temp);
	TX.invalidate();
	Unicode::snprintf(nowtempBuffer, 15, "%d", now_temp);
	nowtemp.invalidate();
}

void Screen2View::temp_down()
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
	uint8_t str[] = "1\r\n";
	HAL_UART_Transmit(&huart1, str, sizeof(str), 100);
	HAL_UART_Transmit(&huart3, str, sizeof(str), 100);
	select_temp--;


	 Unicode::snprintf(TXBuffer, 15, "%d", select_temp);
	 TX.invalidate();
	 Unicode::snprintf(nowtempBuffer, 15, "%d", now_temp);
	 nowtemp.invalidate();

	//TX.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AWFL));

}


void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
    state=0;
}

void Screen2View::changeAppearance()
{   //Color

}
