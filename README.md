# Bird-Friendly Electrochromic Windows

To run the Object Classification code on the Raspberry Pi:
Hardware
- Hook up the input GPIO pins to a button and four switches
- Hook up the output GPIO pins to four LEDs (remember to add a resistor for each LED)
Software
- Clone the pylepton repository https://github.com/groupgets/pylepton
- Copy the code in Object Classification.py into pylepton_capture.py

Unfortunately, the Object Classification Subsystem is not integrated with the Controls Subsystem (non-existing). This requires further work, though it is basically just hooking up GPIO pins to the Controls Subsystem's GPIO pins. 
