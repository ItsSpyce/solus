#pragma once

#ifndef SOLUS_ENGINE_H
#define SOLUS_ENGINE_H

namespace solus
{
class SolusEngine
{
public:
  SolusEngine() = default;

  void Initialize();

  bool CanCompileTestScript();

private:
  sol::state lua_;
};

class SolusMod
{
public:
  struct SolusModInfo
  {
    const char* name;
    const char* author;
    const char* description;
    const char* version;
    const char* dependencies;
    const char* license;
    const char* url;
  };

  explicit SolusMod(const char* a_name) : name_(a_name)
  {
  }

private:
  const char* name_;
};
} // namespace solus
#endif // !SOLUS_ENGINE_H