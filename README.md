# header-parser
Extracts information from an annotated C++ header and returns a struct containing relevant data for use in code generation tools.

[![Build Status](https://travis-ci.org/jtljac/header-parser.svg)](https://travis-ci.org/jtljac/header-parser)

# Why?
This fork was made to remove the dependancy on JSON, and to remove the extra step of converting to json data only to have to turn that json back into usable data. This will allow the code to be mounted as a library instead of being used as an extra tool.

# Example

Given the input file:

```cpp
#include <vector>

namespace test 
{
  TCLASS()
  class Foo : public Bar 
  {
  protected:
    TFUNC(Arg=3)
    bool ProtectedFunction(std::vector<int> args) const;

  public:
    TENUM()
    enum Enum
    {
      FirstValue,
      SecondValue = 3
    };

  public:
    TPROPERTY()
    int ThisIsAProperty;

    TPROPERTY()
    int ThisIsAArray[42];
  };
}
```

When ran with `header-parser example1.h -c TCLASS -e TENUM -f TFUNC -p TPROPERTY` produces the following output:

```json
[
    {
        "type": "include",
        "file": "vector"
    },
    {
        "type": "namespace",
        "name": "test",
        "members": [
            {
                "type": "class",
                "line": 5,
                "meta": {},
                "isstruct": false,
                "name": "Foo",
                "parents": [
                    {
                        "access": "public",
                        "name": {
                            "type": "literal",
                            "name": "Bar"
                        }
                    }
                ],
                "members": [
                    {
                        "type": "function",
                        "macro": "TFUNC",
                        "line": 9,
                        "meta": {
                            "Arg": 3
                        },
                        "access": "protected",
                        "returnType": {
                            "type": "literal",
                            "name": "bool"
                        },
                        "name": "ProtectedFunction",
                        "arguments": [
                            {
                                "type": {
                                    "type": "template",
                                    "name": "std::vector",
                                    "arguments": [
                                        {
                                            "type": "literal",
                                            "name": "int"
                                        }
                                    ]
                                },
                                "name": "args"
                            }
                        ],
                        "const": true
                    },
                    {
                        "type": "enum",
                        "line": 13,
                        "access": "public",
                        "meta": {},
                        "name": "Enum",
                        "members": [
                            {
                                "key": "FirstValue"
                            },
                            {
                                "key": "SecondValue",
                                "value": "3"
                            }
                        ]
                    },
                    {
                        "type": "property",
                        "line": 21,
                        "meta": {},
                        "access": "public",
                        "dataType": {
                            "type": "literal",
                            "name": "int"
                        },
                        "name": "ThisIsAProperty",
                        "elements": null
                    },
                    {
                        "type": "property",
                        "line": 24,
                        "meta": {},
                        "access": "public",
                        "dataType": {
                            "type": "literal",
                            "name": "int"
                        },
                        "name": "ThisIsAArray",
                        "elements": "42"
                    }
                ]
            }
        ]
    }
]
```
