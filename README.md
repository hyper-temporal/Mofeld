# Mofeld
The Mofeld is a desktop  editor for the Waldorf Blofeld synth.
Features list:   
- All Parameters Synchronization
- Synchronisation of each channels in multi mode
- wavetable editor
- Time Vs Frequency drawing approach for fast creation of new wavetables (automaticly goes to next/previous wave)
- modify global parameters
- easy doubleclic Save/ recall  operations for:  Arrangement > Instrument > Group_of_parameters (differentials)  

#Setup
Pre-Requisites
    an installed qt 4.7 4.8 qt Framework : https://doc.qt.io/archives/qt-4.8/, with qmake in the $PATH
    porting to 5.x should be easy, 6.x even more :)
    git clone https://github.com/thestk/rtmidi
#installation 
 git clone https://github.com/camillebassuel/Mofeld
  cd Mofeld  
  qmake  MOFELD.pro

#running
  execute the program (binary or .exe) with a bofeld plugged via USB
 


