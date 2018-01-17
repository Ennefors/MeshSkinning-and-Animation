//
// Created by bill on 2017-10-02.
//

#ifndef GSCEPT_LAB_ENV_NVX2PARSER_H
#define GSCEPT_LAB_ENV_NVX2PARSER_H

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>
#include <vector>
#include "vertexComponent.h"
#define NEBULA3_NVX2_MAGICNUMBER 'NVX2'


struct Nvx2Header
{
    uint magic;
    uint numGroups;
    uint numVertices;
    uint vertexWidth;
    uint numIndices;
    uint numEdges;
    uint vertexComponentMask;
};

struct Nvx2Group
{
    uint firstVertex;
    uint numVertices;
    uint firstTriangle;
    uint numTriangles;
    uint firstEdge;
    uint numEdges;
};

struct Nvx2primGrp
{
    uint baseVert;
    uint numVertices;
    uint baseIndex;
    uint numIndices;
};

struct nv2vertex
{
    float pos[4];

    float uv[2];

    signed char norm[4];

    signed char biNorm[4];

    signed char tang[4];

    unsigned char weight[4];

    unsigned char jInd[4];
};

struct nv2vert
{
    float x;
    float y;
    float z;
};


class nvx2parser {
public:
    std::vector<Nvx2primGrp> prGrp;
    std::vector<vertexComponent> vertexComponents;
    bool parseFile(char* filepath);
    void readHdata();
    void readPrimGrps();
    void setupVertComponents();

    void setupVB();
    void setupIB();
    Nvx2Header* animKey;
    Nvx2Group* animGrp1;

    std::vector<float> VB;
    std::vector<float> oVB;
    std::vector<unsigned char> Weights;
    std::vector<unsigned char> jInd;

    std::vector<nv2vertex> vertBuff;

    uint numGroups;
    uint numVertices;
    uint vertexWidth;
    uint numIndices;
    uint numEdges;
    uint vertexComponentMask;

    void* mapData;
    void* groupDataPtr;
    void* vertexDataPtr;
    void* indexDataPtr;
    u_int vertexDataSize;
private:
    enum N2VertexComponent
    {
        N2Coord        = (1<<0),      // 3 floats
        N2Normal       = (1<<1),      // 3 floats
        N2NormalB4N   = (1<<2),      // 4 unsigned bytes, normalized
        N2Uv0          = (1<<3),      // 2 floats
        N2Uv0S2        = (1<<4),      // 2 shorts, 4.12 fixed point
        N2Uv1          = (1<<5),      // 2 floats
        N2Uv1S2        = (1<<6),      // 2 shorts, 4.12 fixed point
        N2Uv2          = (1<<7),      // 2 floats
        N2Uv2S2        = (1<<8),      // 2 shorts, 4.12 fixed point
        N2Uv3          = (1<<9),      // 2 floats
        N2Uv3S2        = (1<<10),     // 2 shorts, 4.12 fixed point
        N2Color        = (1<<11),     // 4 floats
        N2ColorUB4N    = (1<<12),     // 4 unsigned bytes, normalized
        N2Tangent      = (1<<13),     // 3 floats
        N2TangentB4N  = (1<<14),     // 4 unsigned bytes, normalized
        N2Binormal     = (1<<15),     // 3 floats
        N2BinormalB4N = (1<<16),     // 4 unsigned bytes, normalized
        N2Weights      = (1<<17),     // 4 floats
        N2WeightsUB4N  = (1<<18),     // 4 unsigned bytes, normalized
        N2JIndices     = (1<<19),     // 4 floats
        N2JIndicesUB4  = (1<<20),     // 4 unsigned bytes

        N2NumVertexComponents = 21,
        N2AllComponents = ((1<<N2NumVertexComponents) - 1),
    };


    u_int groupDataSize;

    u_int indexDataSize;




};


#endif //GSCEPT_LAB_ENV_NVX2PARSER_H
