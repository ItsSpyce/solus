local skse = namespace {
  MessagingInterface = enum {
    kPostLoad = 0,
    kPostPostLoad = 1,
    kPreLoadGame = 2,
    kPostLoadGame = 3,
    kSaveGame = 4,
    kDeleteGame = 5,
    kInputLoaded = 6,
    kNewGame = 7,
    kDataLoaded = 8,
    kTotal = 9,
  },
}
