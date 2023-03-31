using static Asciigine.Utils;
using Asciigine.Core;
using static Asciigine.Renderer;

namespace Asciigine;

public class Pixel
{
    public Vector Pos = new();
    public char p;

    public Pixel()
    {
    }

    public Pixel(Vector pos, char p)
    {
        this.Pos = pos;
        this.p = p;
    }
    public static Pixel ToPixel(Vector pos, char pix) => new Pixel(pos, pix);
}

public class Buffer
{
    #region Initializers

    #region Constructors
    public static Vector GetSize() => CurrBuffSize;
    public static Buffer ToBuffer(Pixel pix) => new Buffer(pix.Pos, pix.p);
    public Buffer()
    {
    }
    public Buffer(Vector pos, char pix) => Frame.Add(new Pixel(pos, pix));
    public Buffer(List<Pixel> pixels) => this.Frame = pixels;

    #endregion

    #region Variables

    #region Buffer

    public static Vector CurrBuffSize = new(Window.GetSize());
    public List<Pixel> Frame = new();

    #endregion

    #endregion

    #endregion

    public static void SetSize(int? x, int? y)
    {
        if (x == null) CurrBuffSize.x = Window.GetSize()[0];
        if (y == null) CurrBuffSize.y = Window.GetSize()[1];
        CurrBuffSize.x = x.Value;
        CurrBuffSize.y = y.Value;
    }
}