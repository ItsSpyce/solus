#pragma once

#include "SKSEMenuFramework.h"

namespace solus::ui
{
  class UIManager
  {
  public:
    void init() noexcept
    {
      if (is_initialized_)
      {
        logger::info("UIManager is already initialized.");
        return;
      }

      if (!SKSEMenuFramework::IsInstalled())
      {
        logger::critical("SKSEMenuFramework is not installed. Cannot initialize UIManager.");
        return;
      }
    }

  private:
    bool is_initialized_ = false;
  };
}