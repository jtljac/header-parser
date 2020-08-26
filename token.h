#pragma once

#include <cstdint>
#include <string>
#include <array>

#include "Nodes/Enums/ConstType.h"

enum class TokenType
{
  kNone,
  kSymbol,
  kIdentifier,
  kConst
};



struct Token
{
	TokenType tokenType;
  std::size_t startPos;
  std::size_t startLine;
  std::string token;

  ConstType constType;
  union
  {
    bool boolConst;
    uint32_t uint32Const;
    int32_t int32Const;
    uint64_t uint64Const;
    int64_t int64Const;
    double realConst;
  };
  std::string stringConst;
};