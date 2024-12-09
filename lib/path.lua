local match = require('match')
local stringsplit = require('stringsplit')

local os = _G.os.getenv('OS')
---@type boolean
local iswindows = match(os)(
  { 'Windows_NT', true },
  { false }
)
---@type string
local dirsep = iswindows and '\\' or '/'

local charcodes = {
  [' '] = 32,
  ['!'] = 33,
  ['"'] = 34,
  ['#'] = 35,
  ['$'] = 36,
  ['%'] = 37,
  ['&'] = 38,
  ["'"] = 39,
  ['('] = 40,
  [')'] = 41,
  ['*'] = 42,
  ['+'] = 43,
  [','] = 44,
  ['-'] = 45,
  ['.'] = 46,
  ['/'] = 47,
  ['0'] = 48,
  ['1'] = 49,
  ['2'] = 50,
  ['3'] = 51,
  ['4'] = 52,
  ['5'] = 53,
  ['6'] = 54,
  ['7'] = 55,
  ['8'] = 56,
  ['9'] = 57,
  [':'] = 58,
  [';'] = 59,
  ['<'] = 60,
  ['='] = 61,
  ['>'] = 62,
  ['?'] = 63,
  ['@'] = 64,
  ['A'] = 65,
  ['B'] = 66,
  ['C'] = 67,
  ['D'] = 68,
  ['E'] = 69,
  ['F'] = 70,
  ['G'] = 71,
  ['H'] = 72,
  ['I'] = 73,
  ['J'] = 74,
  ['K'] = 75,
  ['L'] = 76,
  ['M'] = 77,
  ['N'] = 78,
  ['O'] = 79,
  ['P'] = 80,
  ['Q'] = 81,
  ['R'] = 82,
  ['S'] = 83,
  ['T'] = 84,
  ['U'] = 85,
  ['V'] = 86,
  ['W'] = 87,
  ['X'] = 88,
  ['Y'] = 89,
  ['Z'] = 90,
  ['['] = 91,
  ['\\'] = 92,
  [']'] = 93,
  ['^'] = 94,
  ['_'] = 95,
  ['`'] = 96,
  ['a'] = 97,
  ['b'] = 98,
  ['c'] = 99,
  ['d'] = 100,
  ['e'] = 101,
  ['f'] = 102,
  ['g'] = 103,
  ['h'] = 104,
  ['i'] = 105,
  ['j'] = 106,
  ['k'] = 107,
  ['l'] = 108,
  ['m'] = 109,
  ['n'] = 110,
  ['o'] = 111,
  ['p'] = 112,
  ['q'] = 113,
  ['r'] = 114,
  ['s'] = 115,
  ['t'] = 116,
  ['u'] = 117,
  ['v'] = 118,
  ['w'] = 119,
  ['x'] = 120,
  ['y'] = 121,
  ['z'] = 122,
  ['{'] = 123,
  ['|'] = 124,
  ['}'] = 125,
  ['~'] = 126,
}

local function charcode(c)
  return charcodes[c]
end


local function isdirsep(c)
  if iswindows then
    return c == '/' or c == '\\'
  else
    return c == '/'
  end
end

---Returns the prefix of a path if it exists, otherwise nil
---@param path string
---@return string
local function getprefix(path)
  if iswindows then
    return path:match('^[A-Za-z]:')
  else
    return nil
  end
end

---Returns if the path is root or not
---@param path string
---@return boolean
local function isroot(path)
  if iswindows then
    return path:match('^%a:%\\$')
  else
    return path == dirsep
  end
end

---Returns if the path is absolute or not
---@param path string
---@return boolean
local function isabsolute(path)
  if iswindows then
    return isroot(path:sub(1, 3))
  else
    return charcode(path) == 47
  end
end

local function isrelative(path)
  return not isabsolute(path)
end

---Returns a table for path segments
---@param path string
---@return table<integer, string>
local function split(path)
  if iswindows then
    return stringsplit(path, '\\|/')
  else
    return stringsplit(path, '/')
  end
end

---Joins path segments into a single path string
---@param ... string
---@return string
local function join(...)
  local args = { ... }
  local parts = {}
  for _, part in ipairs(args) do
    for _, subpart in ipairs(split(part)) do
      if subpart == '..' then
        if isabsolute(args[1]) then
          -- Don't remove the prefix
          if #parts > 1 then
            table.remove(parts)
          end
        else
          table.remove(parts)
        end
      elseif subpart ~= '.' then
        table.insert(parts, subpart)
      end
    end
  end

  return table.concat(parts, dirsep)
end

---Returns the extension of the path if it exists, otherwise nil
---@param path string
---@return string|nil
local function getext(path)
  return path:match('%.([^%.]+)$')
end

---Returns the parent directory
---@param path string
---@return string
local function parent(path)
  local parts = {}
  for part in split(path) do
    table.insert(parts, part)
  end
  table.remove(parts)
  return join(table.unpack(parts))
end

---Resolves a path to an absolute path
---@param path string
---@return string
local function resolve(path)
  local parts = {}
  for part in split(path) do
    if part == '..' then
      table.remove(parts)
    elseif part ~= '.' then
      table.insert(parts, part)
    end
  end
  return join(table.unpack(parts), dirsep)
end

return {
  getprefix = getprefix,
  split = split,
  join = join,
  resolve = resolve,
  isabsolute = isabsolute,
  isrelative = isrelative,
  isroot = isroot,
  getext = getext,
  parent = parent,
  dirsep = dirsep,
  setiswindows = setiswindows
}
