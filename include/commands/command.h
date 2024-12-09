#pragma once

#define CMD_SIGNATURE                                                 \
  const RE::SCRIPT_PARAMETER *param_info,                             \
      RE::SCRIPT_FUNCTION::ScriptData *script_data,                   \
      RE::TESObjectREFR *this_obj, RE::TESObjectREFR *containing_obj, \
      RE::Script *script_obj, RE::ScriptLocals *locals, double &,     \
      std::uint32_t &opcode_offset_ptr

namespace solus::commands {
class Command {
 public:
  explicit Command(const char *name) : name_(name) {}
  virtual ~Command() = default;
  Command(const Command &) = delete;
  Command(Command &&) = delete;
  Command &operator=(const Command &) = delete;
  Command &operator=(Command &&) = delete;

  void execute(CMD_SIGNATURE) { internal_execute(); }

 protected:
  virtual void internal_execute() = 0;

  const char *name_;
};
}  // namespace solus::commands