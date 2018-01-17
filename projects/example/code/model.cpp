//
// Created by bill on 2017-09-05.
//
#include <GL/glut.h>

#include "model.h"

fdVector convert_str(char* str)
{
    char* strtoken;
    strtoken = strtok(str, ",");

    float vec[4];

    int i = 0;
    while (strtoken != NULL)
    {
        vec[i] = stof(strtoken);
        strtoken = strtok (NULL, ",");
        i++;
    }

    return fdVector(vec[0], vec[1], vec[2], vec[3]);
}



model::model()
{

};

model::~model()
{

};
void model::calcBindTransB(joint* s_joint, fdMatrix transform)
{
    if (s_joint->parent != -1)
    {

        s_joint->transform = transform * s_joint->transform;

    } else
    {
        s_joint->transform = s_joint->transform;
    }
    for(int i = 0; i < s_joint->children.size(); i++)
    {
        calcBindTransB(&basePmultiplied[s_joint->children[i]], s_joint->transform);
    }

};

void model::calcBindInverseTrans(joint* s_joint, fdMatrix transform)
{
    if (s_joint->parent != -1)
    {
        fdMatrix inverse = s_joint->transform.makeminverse(s_joint->transform);
        s_joint->transform = ((transform * (inverse)));

    } else
    {
        s_joint->transform = s_joint->transform;
    }
    for(int i = 0; i < s_joint->children.size(); i++)
    {
        calcBindTransB(&offsetMatrix[s_joint->children[i]], s_joint->transform);
    }

};

void model::calcFinalMat()
{
    for (int i = 0; i < joints.size(); ++i)
    {
        finalMatrix.push_back(offsetMatrix[i].transform * joints[i].transform);
    }
}

void model::calcBindTrans(joint* s_joint, fdMatrix transform)
{


    if (s_joint->parent != -1)
    {

        s_joint->transform = transform * s_joint->transform;

    } else
    {
        s_joint->transform = s_joint->transform;
    }
    for(int i = 0; i < s_joint->children.size(); i++)
    {
        calcBindTrans(&joints[s_joint->children[i]], s_joint->transform);
    }

    fdMatrix temp = s_joint->transform.make_Tran();

//    glPushMatrix();
//    glLoadMatrixf(projectionMatrix *  viewMatrix.retMat());
//    glutWireSphere(0.02, 8, 8);
//    glPopMatrix();
//    if(s_joint->parent != -1 && s_joint->parent != 0)
//    {
//        glColor3f(3,2,1);
//        float startX = temp[3][0]*0.3;
//        float startY = temp[3][1]*0.3;
//        float startZ = temp[3][2]*0.3;
//        float endX = joints[s_joint->parent].transform[0][3]*0.3;
//        float endY = joints[s_joint->parent].transform[1][3]*0.3;
//        float endZ = joints[s_joint->parent].transform[2][3]*0.3;
//        glBegin(GL_LINES);
//        glVertex3f(startX, startY, startZ);
//        glVertex3f(endX, endY, endZ);
//        glEnd();
//    }
};

void model::move_joint(int joint, fdVector trans)
{

}

void model::rotate_joint(int joint, fdVector rot, fdVector trans)
{
    fdMatrix mat;
    mat = mat.quat_to_mat(rot);
    mat.set_Position(trans.get_X(), trans.get_Y(), trans.get_Z());
    //joints[joint].transform.set_Element(3, 0, 0);
    //joints[joint].transform.set_Element(3, 1, 0);
    //joints[joint].transform.set_Element(3, 2, 0);
    joints[joint].transform =  mat;


}

void model::parse_model(const char *filepath)
{
    TiXmlDocument doc(filepath);
    bool load_OK = doc.LoadFile();
    if (load_OK)
    {
        TiXmlHandle hDoc(&doc);
        TiXmlElement *pRoot, *pParm;
        pRoot = doc.FirstChildElement("Nebula3")->FirstChildElement("Model")->FirstChildElement("CharacterNodes")->FirstChildElement("CharacterNode");

        if(pRoot)
        {
            int nr_of_joints = 0;
            pParm = pRoot->FirstChildElement("Joint");
            while (pParm)
            {
                joint j;

                fdMatrix transform;

                j.name = pParm->Attribute("name");
                j.idx = stoi(pParm->Attribute("index"));
                j.parent = stoi(pParm->Attribute("parent"));
                j.position = convert_str((char*)pParm->Attribute("position"));
                j.rotation = convert_str((char*)pParm->Attribute("rotation"));
                j.scale = convert_str((char*)pParm->Attribute("scale"));

                transform = transform.quat_to_mat(j.rotation);

                transform.set_Position(j.position.get_X(), j.position.get_Y(), j.position.get_Z());

                j.transform = transform;

                pParm = pParm->NextSiblingElement("Joint");

                joints.push_back(j);
                baseP.push_back(j);
                basePmultiplied.push_back(j);
                offsetMatrix.push_back(j);
                finalMatrix.push_back(j.transform.makeminverse(j.transform));
                nr_of_joints++;
            }

            for(int i = nr_of_joints - 1; i > 0; i--)
            {
                joints[joints[i].parent].children.push_back(i);
                baseP[baseP[i].parent].children.push_back(i);
                basePmultiplied[basePmultiplied[i].parent].children.push_back(i);
                offsetMatrix[offsetMatrix[i].parent].children.push_back(i);

            }


        }
    }
    fdMatrix idMat;
    calcBindTransB(&basePmultiplied[0], idMat);
    //calcBindInverseTrans(&offsetMatrix[0], idMat);
    //calcFinalMat();
};

void model::reset()
{
    joints = baseP;
}
void model::setupAnim(char* filepath, char* nvx2)
{
    anim.setupAnim(filepath, nvx2);

}

void model::rotate_X()
{
    fdMatrix mat;
    mat.set_RotationX(0.00001);
    mrotation = mrotation * mat;
}

void model::rotate_Y()
{
    fdMatrix mat;
    mat.set_RotationY(0.1);
    mrotation = mrotation * mat;
}

void model::rotate_Z()
{
    fdMatrix mat;
    mat.set_RotationZ(0.1);
    mrotation = mrotation * mat;
}

void model::draw_model()
{


    fdMatrix idMat;
    fdMatrix rotX;
    rotX.set_RotationX(0.01);
    fdMatrix rotY;
    rotY.set_RotationY(0.01);
    fdMatrix rotZ;
    rotZ.set_RotationZ(0.02);
    //rotate_X();
    //joints[2].transform = joints[2].transform*rotX*rotX*rotY;
    //joints[10].transform = joints[10].transform*rotY*rotX;
    //joints[13].transform = joints[13].transform*rotY;
//    joints[14].transform = joints[14].transform*rotY;
//    baseP[14].transform = baseP[14].transform*rotZ;
    //baseP[0].transform = baseP[0].transform * mrotation;
    //joints[0].transform = joints[0].transform * mrotation;
    calcBindTrans(&joints[0], joints[0].transform);

};
