
// Generated from antlr/JSON.g4 by ANTLR 4.7.2


#include "JSONVisitor.h"

#include "JSONParser.h"


using namespace antlrcpp;
using namespace ajson;
using namespace antlr4;

JSONParser::JSONParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

JSONParser::~JSONParser() {
  delete _interpreter;
}

std::string JSONParser::getGrammarFileName() const {
  return "JSON.g4";
}

const std::vector<std::string>& JSONParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& JSONParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- JsonContext ------------------------------------------------------------------

JSONParser::JsonContext::JsonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JSONParser::JsonContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

tree::TerminalNode* JSONParser::JsonContext::NUMBER() {
  return getToken(JSONParser::NUMBER, 0);
}

JSONParser::ObjectContext* JSONParser::JsonContext::object() {
  return getRuleContext<JSONParser::ObjectContext>(0);
}

JSONParser::ArrayContext* JSONParser::JsonContext::array() {
  return getRuleContext<JSONParser::ArrayContext>(0);
}


size_t JSONParser::JsonContext::getRuleIndex() const {
  return JSONParser::RuleJson;
}

antlrcpp::Any JSONParser::JsonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitJson(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::JsonContext* JSONParser::json() {
  JsonContext *_localctx = _tracker.createInstance<JsonContext>(_ctx, getState());
  enterRule(_localctx, 0, JSONParser::RuleJson);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(15);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JSONParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(8);
        match(JSONParser::STRING);
        break;
      }

      case JSONParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(9);
        match(JSONParser::NUMBER);
        break;
      }

      case JSONParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(10);
        object();
        break;
      }

      case JSONParser::T__7: {
        enterOuterAlt(_localctx, 4);
        setState(11);
        array();
        break;
      }

      case JSONParser::T__0: {
        enterOuterAlt(_localctx, 5);
        setState(12);
        match(JSONParser::T__0);
        break;
      }

      case JSONParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(13);
        match(JSONParser::T__1);
        break;
      }

      case JSONParser::T__2: {
        enterOuterAlt(_localctx, 7);
        setState(14);
        match(JSONParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

JSONParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JSONParser::MemberContext *> JSONParser::ObjectContext::member() {
  return getRuleContexts<JSONParser::MemberContext>();
}

JSONParser::MemberContext* JSONParser::ObjectContext::member(size_t i) {
  return getRuleContext<JSONParser::MemberContext>(i);
}


size_t JSONParser::ObjectContext::getRuleIndex() const {
  return JSONParser::RuleObject;
}

antlrcpp::Any JSONParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::ObjectContext* JSONParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 2, JSONParser::RuleObject);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    match(JSONParser::T__3);
    setState(26);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JSONParser::STRING) {
      setState(18);
      member();
      setState(23);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JSONParser::T__4) {
        setState(19);
        match(JSONParser::T__4);
        setState(20);
        member();
        setState(25);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(28);
    match(JSONParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberContext ------------------------------------------------------------------

JSONParser::MemberContext::MemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JSONParser::MemberContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

JSONParser::JsonContext* JSONParser::MemberContext::json() {
  return getRuleContext<JSONParser::JsonContext>(0);
}


size_t JSONParser::MemberContext::getRuleIndex() const {
  return JSONParser::RuleMember;
}

antlrcpp::Any JSONParser::MemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitMember(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::MemberContext* JSONParser::member() {
  MemberContext *_localctx = _tracker.createInstance<MemberContext>(_ctx, getState());
  enterRule(_localctx, 4, JSONParser::RuleMember);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(JSONParser::STRING);
    setState(31);
    match(JSONParser::T__6);
    setState(32);
    json();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

JSONParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JSONParser::JsonContext *> JSONParser::ArrayContext::json() {
  return getRuleContexts<JSONParser::JsonContext>();
}

JSONParser::JsonContext* JSONParser::ArrayContext::json(size_t i) {
  return getRuleContext<JSONParser::JsonContext>(i);
}


size_t JSONParser::ArrayContext::getRuleIndex() const {
  return JSONParser::RuleArray;
}

antlrcpp::Any JSONParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::ArrayContext* JSONParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 6, JSONParser::RuleArray);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    match(JSONParser::T__7);
    setState(43);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JSONParser::T__0)
      | (1ULL << JSONParser::T__1)
      | (1ULL << JSONParser::T__2)
      | (1ULL << JSONParser::T__3)
      | (1ULL << JSONParser::T__7)
      | (1ULL << JSONParser::STRING)
      | (1ULL << JSONParser::NUMBER))) != 0)) {
      setState(35);
      json();
      setState(40);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JSONParser::T__4) {
        setState(36);
        match(JSONParser::T__4);
        setState(37);
        json();
        setState(42);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(45);
    match(JSONParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> JSONParser::_decisionToDFA;
atn::PredictionContextCache JSONParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN JSONParser::_atn;
std::vector<uint16_t> JSONParser::_serializedATN;

std::vector<std::string> JSONParser::_ruleNames = {
  "json", "object", "member", "array"
};

std::vector<std::string> JSONParser::_literalNames = {
  "", "'true'", "'false'", "'null'", "'{'", "','", "'}'", "':'", "'['", 
  "']'"
};

std::vector<std::string> JSONParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "STRING", "NUMBER", "WS"
};

dfa::Vocabulary JSONParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> JSONParser::_tokenNames;

JSONParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xe, 0x32, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x12, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x18, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1b, 
    0xb, 0x3, 0x5, 0x3, 0x1d, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x29, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x2c, 0xb, 0x5, 0x5, 0x5, 0x2e, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 
    0x8, 0x2, 0x2, 0x2, 0x37, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x20, 0x3, 0x2, 0x2, 0x2, 0x8, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x12, 0x7, 0xc, 0x2, 0x2, 0xb, 0x12, 0x7, 0xd, 0x2, 0x2, 
    0xc, 0x12, 0x5, 0x4, 0x3, 0x2, 0xd, 0x12, 0x5, 0x8, 0x5, 0x2, 0xe, 0x12, 
    0x7, 0x3, 0x2, 0x2, 0xf, 0x12, 0x7, 0x4, 0x2, 0x2, 0x10, 0x12, 0x7, 
    0x5, 0x2, 0x2, 0x11, 0xa, 0x3, 0x2, 0x2, 0x2, 0x11, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x11, 0xc, 0x3, 0x2, 0x2, 0x2, 0x11, 0xd, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0xe, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 0x10, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x3, 0x3, 0x2, 0x2, 0x2, 0x13, 0x1c, 0x7, 
    0x6, 0x2, 0x2, 0x14, 0x19, 0x5, 0x6, 0x4, 0x2, 0x15, 0x16, 0x7, 0x7, 
    0x2, 0x2, 0x16, 0x18, 0x5, 0x6, 0x4, 0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x18, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x14, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 
    0x8, 0x2, 0x2, 0x1f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 0xc, 
    0x2, 0x2, 0x21, 0x22, 0x7, 0x9, 0x2, 0x2, 0x22, 0x23, 0x5, 0x2, 0x2, 
    0x2, 0x23, 0x7, 0x3, 0x2, 0x2, 0x2, 0x24, 0x2d, 0x7, 0xa, 0x2, 0x2, 
    0x25, 0x2a, 0x5, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0x7, 0x2, 0x2, 0x27, 
    0x29, 0x5, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2b, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x2d, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0xb, 0x2, 0x2, 
    0x30, 0x9, 0x3, 0x2, 0x2, 0x2, 0x7, 0x11, 0x19, 0x1c, 0x2a, 0x2d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

JSONParser::Initializer JSONParser::_init;
