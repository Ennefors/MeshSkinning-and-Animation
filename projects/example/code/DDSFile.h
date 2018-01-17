//
// Created by bill on 2017-10-07.
//

#ifndef GSCEPT_LAB_ENV_DDSFILE_H
#define GSCEPT_LAB_ENV_DDSFILE_H


#include <sys/types.h>

class DDSFile {
#pragma once
//------------------------------------------------------------------------------
/**
    @class Image::DDSImage

    Implements a DirectDraw Surface image using the header specifications found at:
	DDS Header: http://msdn.microsoft.com/en-us/library/windows/desktop/bb943982(v=vs.85).aspx
	DDS Extended Header: http://msdn.microsoft.com/en-us/library/windows/desktop/bb943983(v=vs.85).aspx

    (C) 2012-2016 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
    class DdsImage
    {
    public:
        /// constructor
        DdsImage();
        /// destructor
        virtual ~DdsImage();

        /// loads dds image from raw data pointer
        void LoadFromRawData(u_char * ptr, uint size);

    private:

        /// unpacks raw data as DXT1, works on member data pointer
        void UnpackDXT1(u_char* src);
        /// decompresses block as DXT1
        void DecompressDXT1(uint x, uint y, u_char* src);

        /// unpacks raw data as DXT3, works on member data pointer
        void UnpackDXT3(u_char* src);
        /// decompresses block as DXT3
        void DecompressDXT3(uint x, uint y, u_char* src);

        /// unpacks raw data as DXT5, works on member data pointer
        void UnpackDXT5(u_char* src);
        /// decompresses block as DXT5
        void DecompressDXT5(uint x, uint y, u_char* src);

        struct DdsHeader
        {
            int size;
            int flags;
            int height;
            int width;
            int pitch;
            int depth;
            int mipCount;
            int reserved[11];
            int pixelFormatSize;
            int pixelFormatFlags;
            int fourCC;
            int bitCount;
            int redBitmask;
            int blueBitmask;
            int greenBitmask;
            int alphaBitmask;
            int caps1;
            int caps2;
            int caps3;
            int caps4;
            int reserved2;
        };

        struct DdsHeaderExtended
        {
            short format;
            short dimension;
            int flags;
            int size;
            int reserved;
        };

        DdsHeader header;
        DdsHeaderExtended extendedHeader;
    };

};


#endif //GSCEPT_LAB_ENV_DDSFILE_H
