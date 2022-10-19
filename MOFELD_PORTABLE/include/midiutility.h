#ifndef MIDIUTILITY_H
#define MIDIUTILITY_H
#include <QString>

class MidiUtility
{
public:
    MidiUtility();
    static QString getNoteName(int notnum12)
    {
        switch(notnum12)
        {
        case 0: return "C"; break;
        case 1: return "C#"; break;
        case 2: return "D"; break;
        case 3: return "D#"; break;
        case 4: return "E"; break;
        case 5: return "F"; break;
        case 6: return "F#"; break;
        case 7: return "G"; break;
        case 8: return "G#"; break;
        case 9: return "A"; break;
        case 10: return "A#"; break;
        case 11: return "B"; break;
        default:break;
        }
    }
    static QString getNoteFullName(int notnum)
    {
        int note = notnum%12;
        int oct = notnum/12;

        return getNoteName(note) + QString::number(oct-2);

    }


};

#endif // MIDIUTILITY_H
