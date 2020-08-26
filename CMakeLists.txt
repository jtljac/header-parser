PROJECT(header-parser)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4)

SET(SOURCES
  "main.cc"
  "options.h"
  "token.h"
  "tokenizer.cc"
  "tokenizer.h"
  "parser.cc"
  "parser.h"
  "Nodes/type_node.h"
  "Nodes/FileNode.h"
  "Nodes/NamespaceNode.h"
  "Nodes/Enums/AccessControltype.h"
  "Nodes/NamespaceNode.h"
   "Nodes/FuncNode.h" "Nodes/Node.h" "Nodes/MetaNode.h" "Nodes/Enums/ConstType.h" "Nodes/EnumNode.h" "Nodes/BaseNode.h" "Nodes/PropNode.h" "Nodes/CustomMacroNode.h" "Nodes/ContainerNode.h")

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}/external/rapidjson/include"
	"${PROJECT_SOURCE_DIR}/external/tclap/include"
	)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR
   ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  add_definitions(-std=c++11)
endif()
ADD_EXECUTABLE(header-parser ${SOURCES} parser.cc parser.h main.h)
