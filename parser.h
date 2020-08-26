#pragma once

#include "tokenizer.h"
#include "options.h"
#include "Nodes/FileNode.h"
#include "Nodes/type_node.h"
#include "Nodes/Enums/AccessControlType.h"
#include <string>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

enum class ScopeType
{
  kGlobal,
  kNamespace,
  kClass
};

class Parser : private Tokenizer
{
public:
  Parser(const Options& options);
  virtual ~Parser();

  // No copying of parser
  Parser(const Parser& other) = delete;
  Parser(Parser&& other) = delete;

  // Parses the given input
  bool Parse(const char* input);

  /// Returns the result of a previous parse
  std::string result() const { return std::string(buffer_.GetString(), buffer_.GetString() + buffer_.GetSize()); }

protected:
  /// Called to parse the next statement. Returns false if there are no more statements.
  bool ParseStatement();
  bool ParseDeclaration(Token &token);
  bool ParseDirective();
  bool SkipDeclaration(Token &token);
  bool ParseProperty(Token &token);
  bool ParseEnum(Token &token);
  bool ParseMacroMeta(MetaNode& node);
  bool ParseMetaSequence(MetaNode& node);

  void PushScope(const std::string& name, ScopeType scopeType, AccessControlType accessControlType);
  void PopScope();

  bool ParseNamespace();
  bool ParseAccessControl(const Token& token, AccessControlType& type);

  AccessControlType current_access_control_type() const { return topScope_->currentAccessControlType; }
  void WriteCurrentAccessControlType();

  void WriteAccessControlType(AccessControlType type);
  bool ParseClass(Token &token);
  bool ParseTemplate();
  bool ParseFunction(Token &token, const std::string& macroName);

  bool ParseComment(Node& theNode);

  bool ParseType();

  std::unique_ptr<TypeNode> ParseTypeNode();
  std::string ParseTypeNodeDeclarator();

  std::string ParseTypename();

  void WriteToken(const Token &token);
  bool ParseCustomMacro(Token & token, const std::string& macroName);

  ContainerNode& getCurrentContainer();

private:
  Options options_;
  FileNode nodes;
  NamespaceNode* currentNamespace = nullptr;
  ClassNode* currentClass = nullptr;
  rapidjson::StringBuffer buffer_;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer_;

  struct Scope
  {
    ScopeType type;
    std::string name;
    AccessControlType currentAccessControlType;
  };

  Scope scopes_[64];
  Scope *topScope_;

    bool ParseClassTemplateArgument();
};


