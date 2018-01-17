//
// Created by bill on 2017-10-02.
//


#include <iostream>
#include "nvx2parser.h"

size_t getFilesize2(const char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

bool nvx2parser::parseFile(char* filepath)
{
    size_t fsize = getFilesize2(filepath);

    int isOpen = open(filepath, O_RDONLY, 0);

    assert(isOpen != -1);

    mapData = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, isOpen, 0);

    assert(mapData != MAP_FAILED);

    this->readHdata();
    this->readPrimGrps();
    this->setupVertComponents();
    this->setupVB();


    return true;
}

void nvx2parser::readHdata()
{
    Nvx2Header* header = (Nvx2Header*)mapData;

    if (header->magic != NEBULA3_NVX2_MAGICNUMBER)
    {
        return;
    }

    this->numGroups = header->numGroups;
    this->numVertices = header->numVertices;
    this->numIndices = header->numIndices;
    this->numEdges = header->numEdges;
    this->vertexWidth = header->vertexWidth;
    this->vertexComponentMask = header->vertexComponentMask;
    this->groupDataSize = this->numGroups * 6 * sizeof(uint);

    this->vertexDataSize = this->numVertices * this->vertexWidth * sizeof(float);
    this->indexDataSize = this->numIndices * sizeof(int);
    this->groupDataPtr = header + 1;
    this->vertexDataPtr = ((u_char*)this->groupDataPtr) + this->groupDataSize;
    this->indexDataPtr = ((u_char*)this->vertexDataPtr) + this->vertexDataSize;
}

void nvx2parser::readPrimGrps()
{
    Nvx2Group* group = (Nvx2Group*) this->groupDataPtr;

    for (uint i = 0; i < (uint)this->numGroups; i++)
    {
        Nvx2primGrp primGroup;
        primGroup.numVertices = group->numVertices;
        primGroup.baseIndex = group->firstTriangle*3;
        primGroup.numIndices = group->numTriangles*3;
        this->prGrp.push_back(primGroup);
        group++;
    }
}

void nvx2parser::setupVertComponents()
{
    for (int i = 0; i < N2NumVertexComponents; ++i)
    {
        if(vertexComponentMask & (1 << i))
        {
            uint index = 0;
            vertexComponent::SemanticName  sem;
            vertexComponent::Format fmt;
            switch(1<<i)
            {
                case N2Coord:        sem = vertexComponent::Position;     fmt = vertexComponent::Float3; break; ////used
                case N2Normal:       sem = vertexComponent::Normal;       fmt = vertexComponent::Float3; break;
                case N2NormalB4N:    sem = vertexComponent::Normal;       fmt = vertexComponent::Byte4N; break; ////used
                case N2Uv0:          sem = vertexComponent::TexCoord1;    fmt = vertexComponent::Float2; index = 0; break; ////used
                case N2Uv0S2:        sem = vertexComponent::TexCoord1;    fmt = vertexComponent::Short2; index = 0; break;
                case N2Uv1:          sem = vertexComponent::TexCoord2;    fmt = vertexComponent::Float2; index = 1; break;
                case N2Uv1S2:        sem = vertexComponent::TexCoord2;    fmt = vertexComponent::Short2; index = 1; break;

                case N2Color:        sem = vertexComponent::Color;        fmt = vertexComponent::Float4; break;
                case N2ColorUB4N:    sem = vertexComponent::Color;        fmt = vertexComponent::UByte4N; break;
                case N2Tangent:      sem = vertexComponent::Tangent;      fmt = vertexComponent::Float3; break;
                case N2TangentB4N:   sem = vertexComponent::Tangent;      fmt = vertexComponent::Byte4N; break; ////used
                case N2Binormal:     sem = vertexComponent::Binormal;     fmt = vertexComponent::Float3; break;
                case N2BinormalB4N:  sem = vertexComponent::Binormal;     fmt = vertexComponent::Byte4N; break; ////used
                case N2Weights:      sem = vertexComponent::SkinWeights;  fmt = vertexComponent::Float4; break;
                case N2WeightsUB4N:  sem = vertexComponent::SkinWeights;  fmt = vertexComponent::UByte4N; break; ////used
                case N2JIndices:     sem = vertexComponent::SkinJIndices; fmt = vertexComponent::Float4; break;
                case N2JIndicesUB4:  sem = vertexComponent::SkinJIndices; fmt = vertexComponent::UByte4; break; ////used
                default:
                    __errordecl(neb, "Invalid Nebula2 vertexComponent in Nvx2StreamReader::SetupvertexComponents");
                    sem = vertexComponent::Position;
                    fmt = vertexComponent::Float3;
                    break;
            }
            this->vertexComponents.push_back(vertexComponent(sem, index, fmt));
        }
    }
}

void nvx2parser::setupVB()
{

//    for (int i = 0; i < numVertices; ++i)
//    {
//
//        for (int j = 0; j < vertexComponents.size(); ++j)
//        {
//            switch(vertexComponents[j].semName)
//            {
//                case vertexComponent::Position:
//                    nv2vert* vert;
//                    vert = (nv2vert*)vertexDataPtr;
//                    VB.push_back(vert->x);
//                    VB.push_back(vert->y);
//                    VB.push_back(vert->z);
//                    vertexDataPtr += sizeof(float)*3;
//                    break;
//                case vertexComponent::Normal:
//                    vert = (nv2vert*)vertexDataPtr;
//                    vertexDataPtr += sizeof(signed char)*4;
//                    break;
//                case vertexComponent::TexCoord1:
//                    vert = (nv2vert*)vertexDataPtr;
//                    VB.push_back(vert->x);
//                    VB.push_back(vert->y);
//                    std::cout << vert->x << " " <<vert->y << std::endl;
//                    vertexDataPtr += sizeof(float)*2;
//                    break;
//                case vertexComponent::Tangent:
//                    vert = (nv2vert*)vertexDataPtr;
//                    vertexDataPtr += sizeof(signed char)*4;
//                    break;
//                case vertexComponent::Binormal:
//                    vert = (nv2vert*)vertexDataPtr;
//                    vertexDataPtr += sizeof(unsigned char)*4;
//                    break;
//                case vertexComponent::Color:
//                    vert = (nv2vert*)vertexDataPtr;
//                    vertexDataPtr += sizeof(signed char)*4;
//                    break;
//                case vertexComponent::TexCoord2:
//                    vert = (nv2vert*)vertexDataPtr;
//                    vertexDataPtr += sizeof(signed char)*4;
//                    break;
//                case vertexComponent::SkinWeights:
//                    unsigned char* wahh;
//                    wahh = (unsigned char*)vertexDataPtr;
//                    Weights.push_back(wahh[0]);
//                    Weights.push_back(wahh[1]);
//                    Weights.push_back(wahh[2]);
//                    Weights.push_back(wahh[3]);
//
//                    vertexDataPtr += sizeof(unsigned char)*4;
//                    break;
//                case vertexComponent::SkinJIndices:
//                    unsigned char* jahh;
//                    jahh = (unsigned char*)vertexDataPtr;
//                    jInd.push_back(jahh[0]);
//                    jInd.push_back(jahh[1]);
//                    jInd.push_back(jahh[2]);
//                    jInd.push_back(jahh[3]);
//                    vertexDataPtr += sizeof(unsigned char)*4;
//                    break;
//            }
//        }
//    }
//    oVB = VB;
}