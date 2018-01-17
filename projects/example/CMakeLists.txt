#--------------------------------------------------------------------------
# example project
#--------------------------------------------------------------------------

PROJECT(example)
FILE(GLOB example_headers code/*.h)
FILE(GLOB example_sources code/*.cc)

SET(files_example ${example_headers} ${example_sources} code/model.cpp code/model.h code/naxParser.cpp code/naxParser.h code/naxfileformat.h code/animation.cpp code/animation.h code/nvx2parser.cpp code/nvx2parser.h code/vertexComponent.h code/textureResource.cpp code/textureResource.h code/DDSFile.cpp code/DDSFile.h)
SOURCE_GROUP("example" FILES ${files_example})

ADD_EXECUTABLE(example ${files_example})
TARGET_LINK_LIBRARIES(example core render tinyxml glut)
ADD_DEPENDENCIES(example core render)
