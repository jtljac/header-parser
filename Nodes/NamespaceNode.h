#pragma once

#include "Node.h"
#include "ContainerNode.h"

struct NamespaceNode : public Node, ContainerNode {
	std::unordered_map<std::string, NamespaceNode> namespaces;
};