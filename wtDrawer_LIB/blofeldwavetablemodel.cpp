#include "blofeldwavetablemodel.h"

BlofeldWaveTableModel::BlofeldWaveTableModel()
{
    _signals.reserve(WT_WAVEMAX);
    for(int i(0);i<WT_WAVEMAX;i++ )
    {
        SignalReal s(WT_SAMPLESCOUNT);
        _signals.append(s );
    }
}
BlofeldWaveTableModel::BlofeldWaveTableModel(const BlofeldWaveTableModel &other)
{
    _signals.reserve(WT_WAVEMAX);
    for(int i(0);i<WT_WAVEMAX;i++ )
    {
        SignalReal s(*other.getSignal(i));
        _signals.append(s);
    }
}



QDataStream & operator << (QDataStream & out, const BlofeldWaveTableModel & Valeur)
{
    out << Valeur._wtName
        << Valeur._signals;

    return out;
}
QDataStream & operator >> (QDataStream & in, BlofeldWaveTableModel & Valeur)
{
    in  >> Valeur._wtName
        >> Valeur._signals;
}
