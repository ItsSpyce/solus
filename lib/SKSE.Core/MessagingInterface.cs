namespace SKSE.Core;

public class MessagingInterface
{
  public enum MessageType
  {
    kPostLoad,
    kPostPostLoad,
    kPreLoadGame,
    kPostLoadGame,
    kSaveGame,
    kDeleteGame,
    kInputLoaded,
    kNewGame,
    kDataLoaded,
    kTotal,
  }

  public struct Message
  {
    public string Sender;
    public uint Type;
    public uint DataLen;
    public object Data;
  }
}