//
// Created by bill on 2017-09-20.
//

#ifndef GSCEPT_LAB_ENV_ANIMATION_H
#define GSCEPT_LAB_ENV_ANIMATION_H

#include "naxParser.h"
#include "nvx2parser.h"

class model;

class animation
{


public:
    naxParser parser;
    nvx2parser nvx2pars;
    float time_e = 0;
    int animClip;
    int frame = 0;



    void setupAnim(char* nax2, char* nvx2);
    bool playAnim(model* m, float dt);

    void animSkin(model* m);
};


#endif //GSCEPT_LAB_ENV_ANIMATION_H
