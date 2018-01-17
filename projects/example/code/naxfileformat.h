//
// Created by bill on 2017-09-20.
//

#include <sys/types.h>

#ifndef GSCEPT_LAB_ENV_NAXFILEFORMAT_H
#define GSCEPT_LAB_ENV_NAXFILEFORMAT_H

#endif //GSCEPT_LAB_ENV_NAXFILEFORMAT_H

#pragma once

//------------------------------------------------------------------------------
/**
    @file naxfileformatstructs.h

    NAX file format structures.

    (C) 2009 Radon Labs GmbH
    (C) 2013-2016 Individual contributors, see AUTHORS file
*/

#pragma pack(push, 1)

#define NEBULA3_NAX3_MAGICNUMBER 'NA01'



    struct nax3key
    {
        float x, y, z, w;
    };

    struct Nax3Header
    {
        u_int magic;
        u_int numClips;
        u_int numKeys;
    };

    struct Nax3Clip
    {
        u_short numCurves;
        u_short startKeyIndex;
        u_short numKeys;
        u_short keyStride;
        u_short keyDuration;
        u_char preInfinityType;          // CoreAnimation::InfinityType::Code
        u_char postInfinityType;         // CoreAnimation::InfinityType::Code
        u_short numEvents;
        char name[50];                  // add up to 64 bytes size for Nax3Clip
    };

    struct Nax3AnimEvent
    {
        char name[47];
        char category[15];
        u_short keyIndex;
    };

    struct Nax3Curve
    {
        u_int firstKeyIndex;
        u_char isActive;                 // 0 or 1
        u_char isStatic;                 // 0 or 1
        u_char curveType;                // CoreAnimation::CurveType::Code
        u_char _padding;                 // padding byte
        float staticKeyX;
        float staticKeyY;
        float staticKeyZ;
        float staticKeyW;
    };

    struct animGrp
    {
        Nax3Curve* curve;
        Nax3Clip clip;
    };