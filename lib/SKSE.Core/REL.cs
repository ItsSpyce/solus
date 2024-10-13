namespace SKSE.Core;

public static class Rel
{
  public class Version
  {
    private readonly ushort[] _version;

    public Version() { }
    public Version(ushort[] version) { }
    public Version(ushort major, ushort minor = 0, ushort sub = 0, ushort build = 0) { }
    public Version(string version) { }
  }
}