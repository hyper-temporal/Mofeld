# Mofeld
The Mofeld is a desktop  editor for the Waldorf Blofeld synth written in c++ and the qt framework.
It models the actual hardware and keep the state in sync between the hardware and the UI
It offers a bunch of features  like:
- wavetable editor
- two way synchronization
- access to multi mode features (the hidden message i had to reverse engineer :D )
- Time Vs Frequency drawing approach for fast creation of new wavetables (automaticly goes to next/previous wave)
- global state management, parameter constraints , pseudo random
- Save/ recall  operations for:  Arrangement > Instrument > Group_of_parameters (differentials)  

