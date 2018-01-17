//
// Created by bill on 2017-10-02.
//

#ifndef GSCEPT_LAB_ENV_VERTECCOMPONENT_H
#define GSCEPT_LAB_ENV_VERTECCOMPONENT_H

#endif //GSCEPT_LAB_ENV_VERTECCOMPONENT_H

class vertexComponent
{
    public:

    enum SemanticName
    {
        Position = 0,
        Normal = 1,
        TexCoord1 = 2,
        Tangent = 3,
        Binormal = 4,
        Color = 5,
        TexCoord2 = 6,
        SkinWeights = 7,
        SkinJIndices = 8,

        Invalid,
    };

    enum Format
    {
        Float,      //> one-component float, expanded to (float, 0, 0, 1)
        Float2,     //> two-component float, expanded to (float, float, 0, 1)
        Float3,     //> three-component float, expanded to (float, float, float, 1)
        Float4,     //> four-component float
        UByte4,     //> four-component unsigned byte
        Byte4,		//> four-component signed byte
        Short2,     //> two-component signed short, expanded to (value, value, 0, 1)
        Short4,     //> four-component signed short
        UByte4N,    //> four-component normalized unsigned byte (value / 255.0f)
        Byte4N,		//> four-component normalized signed byte (value / 127.0f)
        Short2N,    //> two-component normalized signed short (value / 32767.0f)
        Short4N,    //> four-component normalized signed short (value / 32767.0f)
    };


    enum StrideType
    {
        PerVertex,
        PerInstance
    };

    vertexComponent(SemanticName semName, uint semIndex, Format format, uint streamIndex=0, StrideType strideType=PerVertex);
    uint GetByteSize() const;

    SemanticName semName;
    uint semIndex;
    Format format;
    StrideType strideType;
    uint stride;
    uint streamIndex;
    uint byteOffset;
};

inline vertexComponent::vertexComponent(SemanticName semName_, uint semIndex_, Format format_, uint streamIndex_, StrideType strideType_) :
        semName(semName_),
        semIndex(semIndex_),
        format(format_),
        strideType(strideType_),
        streamIndex(streamIndex_),
        byteOffset(0)
    {
        switch (this->format)
        {
            case Float:     {this->byteOffset = 4; break;}
            case Float2:    {this->byteOffset = 8; break;}
            case Float3:    {this->byteOffset = 12; break;}
            case Float4:    {this->byteOffset = 16; break;}
            case UByte4:    {this->byteOffset = 4; break;}
            case Byte4:		{this->byteOffset = 4; break;}
            case Short2:    {this->byteOffset = 4; break;}
            case Short4:    {this->byteOffset = 8; break;}
            case UByte4N:   {this->byteOffset = 4; break;}
            case Byte4N:	{this->byteOffset = 4; break;}
            case Short2N:   {this->byteOffset = 4; break;}
            case Short4N:   {this->byteOffset = 8; break;}
        }
    }

inline uint
vertexComponent::GetByteSize() const
{


    return 0;
}

