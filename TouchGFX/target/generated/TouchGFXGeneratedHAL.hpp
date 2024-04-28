/**
  ******************************************************************************
  * File Name          : TouchGFXGeneratedHAL.hpp
  ******************************************************************************
  * This file is generated by TouchGFX Generator 4.23.2. Please, do not edit!
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#ifndef TouchGFXGeneratedHAL_HPP
#define TouchGFXGeneratedHAL_HPP

#include <touchgfx/hal/HAL.hpp>

/**
 * @class TouchGFXGeneratedHAL
 *
 * @brief HAL implementation for TouchGFXGenerated.
 *
 * @sa HAL
 */
class TouchGFXGeneratedHAL : public touchgfx::HAL
{
public:
    /**
     * @fn TouchGFXGeneratedHAL::TouchGFXGeneratedHAL(touchgfx::DMA_Interface& dma, touchgfx::LCD& display, touchgfx::TouchController& tc, uint16_t width, uint16_t height) : touchgfx::HAL(dma, display, tc, width, height)
     *
     * @brief Constructor.
     *
     *        Constructor. Initializes members.
     *
     * @param [in,out] dma     Reference to DMA interface.
     * @param [in,out] display Reference to LCD interface.
     * @param [in,out] tc      Reference to Touch Controller driver.
     * @param width            Width of the display.
     * @param height           Height of the display.
     */
    TouchGFXGeneratedHAL(touchgfx::DMA_Interface& dma, touchgfx::LCD& display, touchgfx::TouchController& tc, uint16_t width, uint16_t height) :
        touchgfx::HAL(dma, display, tc, width, height)
    {
    }

    /**
     * @fn void TouchGFXGeneratedHAL::initialize();
     *
     * @brief This function is responsible for initializing the entire framework.
     *
     *        This function is responsible for initializing the entire framework.
     */
    virtual void initialize();

    /**
     * @fn virtual void TouchGFXGeneratedHAL::configureInterrupts();
     *
     * @brief Sets the DMA and LCD interrupt priorities.
     *
     *        Sets the DMA and LCD interrupt priorities.
     */
    virtual void configureInterrupts();

    /**
     * @fn virtual void TouchGFXGeneratedHAL::enableInterrupts();
     *
     * @brief Enables the DMA and LCD interrupts.
     *
     *        Enables the DMA and LCD interrupts.
     */
    virtual void enableInterrupts();

    /**
     * @fn virtual void TouchGFXGeneratedHAL::disableInterrupts();
     *
     * @brief Disables the DMA and LCD interrupts.
     *
     *        Disables the DMA and LCD interrupts.
     */
    virtual void disableInterrupts();

    /**
     * @fn virtual void TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
     *
     * @brief Configure the LCD controller to fire interrupts at VSYNC.
     *
     *        Configure the LCD controller to fire interrupts at VSYNC. Called automatically
     *        once TouchGFX initialization has completed.
     */
    virtual void enableLCDControllerInterrupt();

    /**
     * @fn virtual void TouchGFXGeneratedHAL::flushFrameBuffer();
     *
     * @brief This function is called whenever the framework has performed a complete draw.
     *
     * This specialization is only in place to keep compilers happy. Base impl. will call the
     * Rect version.
     * @see HAL::flushFrameBuffer
     */
    virtual void flushFrameBuffer()
    {
        HAL::flushFrameBuffer();
    }

    /**
     * @fn virtual void TouchGFXGeneratedHAL::flushFrameBuffer(const touchgfx::Rect& rect);
     *
     * @brief This function is called whenever the framework has performed a partial draw.
     *
     *        This function is called whenever the framework has performed a partial draw.
     *        On the STM32F7, make sure to clean and invalidate the data cache. This is to
     *        ensure that LTDC sees correct data when transferring to the display.
     *
     * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
     *
     * @see flushFrameBuffer().
     */
    virtual void flushFrameBuffer(const touchgfx::Rect& rect);

    /**
     *
     * @fn virtual void TouchGFXGeneratedHAL::blockCopy();
     *
     * This function performs a platform-specific memcpy, if supported by the hardware.
     *
     * @param [out] dest     Pointer to destination memory.
     * @param [in]  src      Pointer to source memory.
     * @param       numBytes Number of bytes to copy.
     *
     * @return true if the copy succeeded, false if copy was not performed.
     */
    virtual bool blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes);

    /**
     * @fn virtual void TouchGFXGeneratedHAL::beginFrame();
     *
     * @brief Called when beginning to rendering a frame.
     *
     *        Called when beginning to rendering a frame.
     *
     * @return true if rendering can begin, false otherwise.
     */
    virtual bool beginFrame();

    /**
     * @fn virtual void TouchGFXGeneratedHAL::endFrame();
     *
     * @brief Called when a rendering pass is completed.
     *
     *        Called when a rendering pass is completed.
     */
    virtual void endFrame();

protected:
    /**
     * @fn virtual uint16_t* TouchGFXGeneratedHAL::getTFTFrameBuffer() const;
     *
     * @brief Gets the frame buffer address used by the TFT controller.
     *
     *        Gets the frame buffer address used by the TFT controller.
     *
     * @return The address of the frame buffer currently being displayed on the TFT.
     */
    virtual uint16_t* getTFTFrameBuffer() const;

    /**
     * @fn virtual void TouchGFXGeneratedHAL::setTFTFrameBuffer(uint16_t* adr);
     *
     * @brief Sets the frame buffer address used by the TFT controller.
     *
     *        Sets the frame buffer address used by the TFT controller.
     *
     * @param [in,out] adr New frame buffer address.
     */
    virtual void setTFTFrameBuffer(uint16_t* adr);

};
#endif // TouchGFXGeneratedHAL_HPP

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
