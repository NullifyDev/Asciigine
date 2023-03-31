using Asciigine.Core;
using static Asciigine.Utils;
namespace Asciigine;
/// <summary>
/// TODO: Implement Interpreter that supports the Collision System. 
/// </summary>
public static class Map
{
    public static Dictionary<string, HashSet<MapBuilder>> Maps = new();
}

public class MapBuilder
{
    public Buffer FromTxt(string path)
    {
        Console.Clear();
        
        List<string> lineContents = Asciigine.Utils.ReadLns($"{Project.ProjectFolder}/{Project.ProjectName}/{path}");
        Buffer buffer = new();
        for (int y = 0; y < lineContents.Count(); y++)
        {
            for (int x = 0; x < lineContents[y].Length; x++)
            {
                if (lineContents[y][x] == ' ') continue;
                Pixel pixel = new();
                pixel.Pos.x = x;
                pixel.Pos.y = y;
                pixel.p = lineContents[y][x];
                buffer.Frame.Add(pixel);
            }
        }
        return buffer;
    }
}