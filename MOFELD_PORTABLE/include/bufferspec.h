#ifndef BUFFERSPEC_H
#define BUFFERSPEC_H


class BufferSpec{
protected:
    const int _samplebitness;
    const int _length;
    const int _bitness;
public:

    BufferSpec(int sb,int l,int b)
        :_samplebitness(sb),_length(l),_bitness(b){}
};

#endif // BUFFERSPEC_H
