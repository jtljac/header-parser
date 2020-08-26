#pragma once

#include "Node.h"
#include "MetaNode.h"
#include "BaseNode.h"

struct EnumNode : public Node, MetaNode, BaseNode {
	bool isEnumClass;
};