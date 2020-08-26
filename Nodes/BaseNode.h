#pragma once

#include <iostream>
#include <vector>

#include "Enums/AccessControlType.h"

struct Base {
	AccessControlType access;
	std::string base;
};

struct BaseNode {
	std::vector<Base> bases;
};