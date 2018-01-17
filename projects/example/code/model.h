//
// Created by bill on 2017-09-05.
//

#ifndef GSCEPT_LAB_ENV_SKELETONBUILD_H
#define GSCEPT_LAB_ENV_SKELETONBUILD_H
#include <tinyxml.h>
#include <vector>
#include "tdMathLibNew.h"
#include "animation.h"


struct joint
{
    std::string name;
    u_int idx;
    int parent;
    vector<int> children;
    fdVector position;
    fdVector scale;
    fdVector rotation;
    fdMatrix transform;
};

class model {
private:


public:
    model();
    ~model();

    animation anim;

    fdMatrix mrotation;

    vector<joint> joints;
    vector<joint> baseP;
    vector<joint> basePmultiplied;
    vector<joint> offsetMatrix;
    vector<fdMatrix> finalMatrix;

    void rotate_joint(int, fdVector, fdVector);
    void move_joint(int, fdVector);

    void rotate_X();
    void rotate_Y();
    void rotate_Z();

    void reset();
    void parse_model(const char*);
    void calcBindTrans(joint*, fdMatrix);
    void calcBindTransB(joint*, fdMatrix);
    void calcBindInverseTrans(joint*, fdMatrix);
    void calcFinalMat();


    void interpolate(fdMatrix, fdMatrix, float);
    void draw_model();
    void setupAnim(char* filepath, char*);
};


#endif //GSCEPT_LAB_ENV_SKELETONBUILD_H
