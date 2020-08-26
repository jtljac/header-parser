#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "FuncNode.h"
#include "PropNode.h"
#include "EnumNode.h"
#include "CustomMacroNode.h"

struct ClassNode;

struct ContainerNode {
	std::unordered_map<std::string, PropNode> members;
	std::unordered_map<std::string, FuncNode> functions;
	std::unordered_map<std::string, ClassNode> classes;
	std::unordered_map<std::string, EnumNode> enums;
	std::vector<CustomMacroNode> customMacros;
};

struct ClassNode : public Node, ContainerNode, MetaNode, BaseNode {
	bool isStruct;
};