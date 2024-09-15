# STM32L476RG GPIO Driver

## Overview

This project provides a custom General Purpose Input/Output (GPIO) driver for the STM32L476RG microcontroller. It is implemented in C based on the STM32L476RG reference manual and includes essential functionality to configure, read, and write to GPIO pins. The driver supports multiple pin modes, output types, pull-up/pull-down configurations, and interrupt handling.

### Key Features
- GPIO pin configuration (input, output, alternate function, analog).
- Speed and output type configuration.
- Pin-specific read/write operations.
- Port-wide read/write operations.
- Pin toggling.
- Interrupt handling for GPIO pins.
  
## Repository Structure

- **stm32l476xx.h**: Core definitions for the STM32L476xx family, including memory addresses for GPIO registers, clock management, and peripheral access【14†source】.
- **stm32l476xx_gpio.h**: GPIO-specific definitions and functions. It includes structures for pin configuration and functions for GPIO initialization, de-initialization, pin read/write operations, and interrupt handling【13†source】.
- **main.c**: This file contains the implementation of the GPIO driver, including initialization, de-initialization, pin read/write, and interrupt configurations. It provides the core functions for interacting with GPIO peripherals and controlling pin states dynamically.

## File Descriptions

### 1. `stm32l476xx.h`
This file provides the base address definitions and register layout for all peripherals in the STM32L476xx family, including the GPIO ports (GPIOA to GPIOI). It also defines macros for enabling and disabling the clocks to GPIO ports and other peripheral-related configurations.

Key components include:
- GPIO base addresses (`GPIOA_BASEADDR`, `GPIOB_BASEADDR`, etc.).
- Clock enable/disable macros (`GPIOA_PCLK_EN()`, `GPIOA_PCLK_DIS()`, etc.).
- Register structures for GPIO and RCC peripherals.

### 2. `stm32l476xx_gpio.h`
This file defines the GPIO driver and provides the following features:
- **GPIO_PinConfig_t**: Structure to define the configuration of individual GPIO pins.
- **GPIO_Handle_t**: Structure used to hold the pin configuration and the base address of the GPIO port.
- Functions for GPIO initialization, de-initialization, reading/writing pins, toggling pins, and handling interrupts.

Example API functions:
- `GPIO_Init(GPIO_Handle_t *pGPIOHandle)`: Initializes a GPIO pin with a specified configuration.
- `GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)`: Reads the input state from a specified GPIO pin.
- `GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)`: Sets the output state of a specified GPIO pin.
- `GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)`: Toggles the state of a specified GPIO pin.
  
### 3. `stm32l476xx_gpio.c`
This file contains the core logic for implementing GPIO control and interactions in the STM32L476RG microcontroller.

#### Key Functions:
- **GPIO_PCLK(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)**: Enables or disables the clock for the given GPIO port.
- **GPIO_Init(GPIO_Handle_t *pGPIOHandle)**: Initializes a GPIO pin with the specified mode, speed, pull-up/pull-down, and output type configurations.
- **GPIO_DeInit(GPIO_RegDef_t *pGPIOx)**: Resets the GPIO registers for the specified port.
- **GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)**: Reads the current value of a specific input pin.
- **GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)**: Writes a value to a specific output pin.
- **GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)**: Toggles the output state of a specific pin.
- **GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)**: Configures the IRQ (interrupt request) settings for a specific GPIO pin.
- **GPIO_IRQHandling(uint8_t PinNumber)**: Handles the interrupt triggered by a GPIO pin.

The `main.c` file serves as the main driver logic, allowing you to configure GPIO pins dynamically and interact with them through input/output operations.

## How to Use

1. **Clone the Repository**
   ```bash
   git clone https://github.com/yourusername/stm32l476rg_gpio_driver.git
   ```

2. **Include the Header Files**
   Ensure that `stm32l476xx.h` and `stm32l476xx_gpio.h` are included in your project, and the correct paths are set in your IDE or build system.

3. **Configure the GPIO Pin**
   Initialize the GPIO pin using `GPIO_Init` by configuring the pin mode, speed, output type, and other parameters using the `GPIO_PinConfig_t` structure.

   ```c
   GPIO_Handle_t gpioHandle;
   gpioHandle.pGPIOx = GPIOA;  // For GPIO port A
   gpioHandle.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;  // Pin 5
   gpioHandle.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;  // Output mode
   gpioHandle.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
   gpioHandle.GPIO_PinConfig.GPIO_PinOPtype = GPIO_OP_TYPE_PP;  // Push-pull
   GPIO_Init(&gpioHandle);
   ```

4. **Write to GPIO**
   After configuring the pin, you can set its output state using:
   ```c
   GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);  // Set pin 5
   ```

5. **Toggle a GPIO Pin**
   To toggle the state of a pin:
   ```c
   GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
   ```
