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
    #region Initializations

    #region Constructors

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

    /*public static void Update(Buffer layer, string name)
    {
        for (int i = 0; i < Renderer.Layers.Values.ElementAt(); i++)
        {
            if (layer.Frame.Contains(Renderer.Layers[name].Frame[i])) {
                Console.SetCursorPosition(
                    Renderer.Layers[name].Frame[i].Pos.x,
                    Renderer.Layers[name].Frame[i].Pos.y
                );
                Out(" ");
            }
        }
        if (Renderer.Layers[name]! != layer) Renderer.Layers[name] = layer;
        
    }*/

    public static void Update(Buffer layer, int pos)
    {
        pos -= 1;
        for (int i = 0; i < layer.Frame.Count; i++)
        {
            if (PrevLayers.Count > 0)
            {
                if (!layer.Frame.Contains(PrevLayers.ElementAt(pos).Value.Frame[i]))
                {
                    Console.SetCursorPosition(PrevLayers.ElementAt(pos).Value.Frame[i].Pos.x,
                        PrevLayers.ElementAt(pos).Value.Frame[i].Pos.y);
                    Out(" ");
                }
            }
        }

        Renderer.PrevLayers = Renderer.Layers;
        if (Renderer.PrevLayers.ElementAt(pos).Value! != layer) Renderer.Layers.Values.ElementAt(pos).Frame = layer.Frame;
    }

    public static void ListLayers() 
    {
        Outln($"[Layers]");
        for(int i = Renderer.Layers.Count()-1; i > -1; i--)
        {
            if (i == 0) Outln($" └─[{i+1}] Name: {Renderer.Layers.Keys.ElementAt(i)}");
            else        Outln($" ├─[{i+1}] Name: {Renderer.Layers.Keys.ElementAt(i)}");
        }
    }

    public static Vector GetSize() => CurrBuffSize;
    public static Buffer ToBuffer(Pixel pix) => new Buffer(pix.Pos, pix.p);
    public static void Add(Buffer layer, string name = "Nameless Layer", int? pos = null)
    {
        int duplicates = 1;
        for (int i = 0; i < Renderer.Layers.Count(); i++)
        {
            if (name == Renderer.Layers.ToList()[i].Key) Exception.Throw.DupeLayerName(name);
            
            if (Renderer.Layers.ToList()[i].Key.StartsWith(name))
            {
                if (Renderer.Layers.ToList()[i].Key.Remove(0, name.Length) != duplicates.ToString())
                {
                    if (duplicates != 1) name += duplicates.ToString();
                }
            }
        }

        if (pos == null || pos <= 0) pos = Layers.Count()+1;
        var temp = new Dictionary<string, Buffer>();
        //if (pos <= 0) pos = 1;

        for (int i = 0; i < pos; i++)
        {
            if (i == pos - 1) temp.Add(name, layer);
            else temp.Add(Renderer.Layers.ElementAt(i).Key, Renderer.Layers.ElementAt(i).Value);
        }

        Renderer.Layers = temp;
    }
}