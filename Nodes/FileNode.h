#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "Node.h"
#include "NamespaceNode.h"

struct FileNode : public ContainerNode {
	std::string filePath;
	std::vector<std::string> includes;
	std::unordered_map<std::string, NamespaceNode> namespaces;
};