// ArduinoJson - https://arduinojson.org
// Copyright Benoit Blanchon 2014-2021
// MIT License

#pragma once

#include <ArduinoJson/Namespace.hpp>
#include <ArduinoJson/Strings/StoragePolicy.hpp>

namespace ARDUINOJSON_NAMESPACE {

class StringMover {
 public:
  StringMover(char* ptr) : _writePtr(ptr) {}

  void startString() {
    _startPtr = _writePtr;
  }

  const char* save() const {
    _writePtr[0] = 0;  // terminator
    return _startPtr;
  }

  void append(char c) {
    *_writePtr++ = c;
  }

  bool isValid() const {
    return true;
  }

  const char* c_str() const {
    _writePtr[0] = 0;  // terminator
    return _startPtr;
  }

  size_t size() const {
    return size_t(_writePtr - _startPtr);
  }

  typedef storage_policies::store_by_address storage_policy;

 private:
  char* _writePtr;
  char* _startPtr;
};
}  // namespace ARDUINOJSON_NAMESPACE
