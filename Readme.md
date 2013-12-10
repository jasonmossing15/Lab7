# Sensors Library

This library deals with interfacing the sensors on the ECE382 Robot.

## Description

There are 4 functions within the header:
 - `initializeADC10();`
 - `getLeftSensorValue();`
 - `getCenterSensorValue();`
 - `getRightSensorValue();`
The first function initializes the msp430 to read values from the three sensors by selecting the correct input pins. It also divides the clock in order to prevent loading.
The other 3 functions return the appropriate ATD value. Here is the code that it uses:
```
//clearing ENC and INCH bits enable changing to the proper settings.
ADC10CTL0 &= ~ENC;
ADC10CTL0 &= ~(INCH3|INCH2|INCH1|INCH0);
ADC10 |= INCH_X; //X is the appropriate input

//sample and conversion
ADC10CTL0 |= ENC + ADC10SC;
__bis_SR_register(CPUOFF + GIE);

return ADC10MEM;
```

## Documentation and License

Anyone is allowed to use this code as long as you document it. 
