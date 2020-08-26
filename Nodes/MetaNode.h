#pragma once

#include <iostream>
#include <unordered_map>
#include <cstdint>

#include "Enums/ConstType.h"
#include "../token.h"

struct Meta {
	std::string name;

    ConstType constType;
    std::string value;

    void setValue(Token& token) {
        constType = token.constType;
        value = token.token;
    }
};

struct MetaNode {
    std::vector<Meta> meta;
    std::unordered_map<std::string, MetaNode> compoundMeta;
};