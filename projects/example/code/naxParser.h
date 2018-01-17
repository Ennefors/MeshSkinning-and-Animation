//
// Created by bill on 2017-09-18.
//
#include "naxfileformat.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>

#ifndef GSCEPT_LAB_ENV_NAXPARSER_H
#define GSCEPT_LAB_ENV_NAXPARSER_H


class naxParser
{
public:
    bool parseFile(char* filepath);
    nax3key* animKey;
    animGrp* animGrp1;
};


#endif //GSCEPT_LAB_ENV_NAXPARSER_H
