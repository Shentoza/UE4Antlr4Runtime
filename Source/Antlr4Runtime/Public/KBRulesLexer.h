
// Generated from KBRulesLexer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  KBRulesLexer : public antlr4::Lexer {
public:
  enum {
    OPERATOR_LOGICAL_EQUALS = 1, OPERATOR_LTE = 2, OPERATOR_GTE = 3, OPERATOR_GT = 4, 
    OPERATOR_LT = 5, OPERATOR_NE = 6, OPERATOR_ASSIGN = 7, OPERATOR_ADD_ASSIGN = 8, 
    OPERATOR_MINUS_ASSIGN = 9, NUMBER_COMPARE = 10, NUMBER_ASSIGN = 11, 
    GENERIC_COMPARE = 12, GENERIC_ASSIGN = 13, COMPARE = 14, ASSIGN = 15, 
    EXPRESSION_START = 16, EXPRESSION_END = 17, INT = 18, FLOAT = 19, NUMBER = 20, 
    BOOLEAN = 21, RULE = 22, RESPONSE = 23, CONDITIONS = 24, REMEMBER = 25, 
    TRIGGER = 26, APPLYFACTS = 27, WORD = 28, VARIABLEIDENTIFIER = 29, MENTION = 30, 
    STRING = 31, WHITESPACE = 32, COMMENT = 33, NEWLINE = 34
  };

  KBRulesLexer(antlr4::CharStream *input);
  ~KBRulesLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

