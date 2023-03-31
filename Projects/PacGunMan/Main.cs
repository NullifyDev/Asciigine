using static Asciigine.Utils;
using Asciigine.Core;
using Asciigine;
using PacGunMan.maps;
using Buffer = Asciigine.Buffer;

namespace PacGunMan;

public class Main
{
    public void Run(string[] args)
    {
        Console.CursorVisible = false;
        Asciigine.MapBuilder map = new();
        var loadedMap = map.FromTxt("maps/TestMap.map");
        var player = new Player("player", new Vector(3, 5), '@');

        Layers.Current.Add(loadedMap, "map");
        Layers.Current.Add(Buffer.ToBuffer(Pixel.ToPixel(player.Position, player.model)), "player");
        Renderer.Render();
        Layers.Current.ListLayers();
        while (true)
        {
            switch (Console.ReadKey(true).Key)
            {
                case ConsoleKey.W:
                    player.Position.y -= 1;
                    Layers.Current.Update(new Buffer(player.Position, player.model),"player");
                    break;
                case ConsoleKey.S:
                    player.Position.y += 1;
                    Layers.Current.Update(new Buffer(player.Position, player.model),"player");
                    break;
                case ConsoleKey.A:
                    player.Position.x -= 1;
                    Layers.Current.Update(new Buffer(player.Position, player.model),"player");
                    break;
                case ConsoleKey.D:
                    player.Position.x += 1;
                    Layers.Current.Update(new Buffer(player.Position, player.model),"player");
                    break;
                case ConsoleKey.P:
                    Console.Clear();
                    Console.SetCursorPosition(0, 0);
                    Environment.Exit(0);
                    break;
                default:
                    break;
            }
            // Buffer.ListLayers();
            Renderer.Render();
        }
    }
}