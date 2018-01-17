//
// Created by bill on 2017-09-20.
//

#include "animation.h"
#include "model.h"

void animation::setupAnim(char* filepath, char* nvx2)
{
    parser.parseFile(filepath);
    nvx2pars.parseFile(nvx2);
}

bool animation::playAnim(model *m, float dt)
{
    time_e += dt;

    if(parser.animGrp1[animClip].clip.keyDuration - time_e < 0)
    {
        frame++;
        if(frame > parser.animGrp1[animClip].clip.numKeys - 1)
            frame = 0;

        time_e = time_e - parser.animGrp1[animClip].clip.keyDuration;
    }

    int prevF = frame > 0 ? frame - 1 : parser.animGrp1[animClip].clip.numKeys - 1;

    if(animClip == -1)
        return false;



    for (int i = 0; i < m->joints.size(); ++i) {

        nax3key r1 = parser.animKey[parser.animGrp1[animClip].curve[i*4+1].firstKeyIndex + parser.animGrp1[animClip].clip.keyStride * prevF];
        nax3key r2 = parser.animKey[parser.animGrp1[animClip].curve[i*4+1].firstKeyIndex + parser.animGrp1[animClip].clip.keyStride * frame];

        fdVector rotation1(r1.x, r1.y, r1.z, r1.w);
        fdVector rotation2(r2.x, r2.y, r2.z, r2.w);
        fdVector rotation = rotation.slerp(rotation1, rotation2, time_e/40);

        nax3key t1 = parser.animKey[parser.animGrp1[animClip].curve[i*4].firstKeyIndex + parser.animGrp1[animClip].clip.keyStride * prevF];
        nax3key t2 = parser.animKey[parser.animGrp1[animClip].curve[i*4].firstKeyIndex + parser.animGrp1[animClip].clip.keyStride * frame];

        fdVector translation1(t1.x, t1.y, t1.z);
        fdVector translation2(t2.x, t2.y, t2.z);

        fdVector trans = translation1.lerp(translation1, translation2, time_e/40);

        m->rotate_joint(i, rotation, trans);
    }
}

void animation::animSkin(model* m)
{
}