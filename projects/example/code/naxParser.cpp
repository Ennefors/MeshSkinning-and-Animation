//
// Created by bill on 2017-09-18.
//

#include "naxParser.h"

size_t getFilesize(const char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

bool naxParser::parseFile(char* filepath)
{
    size_t fsize = getFilesize(filepath);

    int isOpen = open(filepath, O_RDONLY, 0);

    assert(isOpen != -1);

    void* data = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, isOpen, 0);

    assert(data != MAP_FAILED);

    Nax3Header* header = (Nax3Header*)data;

    if (header->magic != NEBULA3_NAX3_MAGICNUMBER)
    {
        return false;
    }

    if (header->numClips > 0)
    {
        animGrp1 = new animGrp[header->numClips];
        data += sizeof(Nax3Header);

        for (int i = 0; i < header->numClips; ++i) 
        {
            Nax3Clip* clip = new Nax3Clip;
            clip = (Nax3Clip*)data;
            animGrp1[i].clip = *clip;
            animGrp1[i].curve = new Nax3Curve[clip->numCurves];
            data += sizeof(Nax3Clip);

            for (int j = 0; j < clip->numEvents; ++j)
            {
                data += sizeof(Nax3AnimEvent);
            }
            for (int k = 0; k < clip->numCurves; ++k)
            {
                Nax3Curve* curve = new Nax3Curve;
                curve = (Nax3Curve*)data;
                animGrp1[i].curve[k] = *curve;
                data += sizeof(Nax3Curve);
            }
        }
        animKey = (nax3key*)data;
    }
    //close(isOpen);
    return true;
}