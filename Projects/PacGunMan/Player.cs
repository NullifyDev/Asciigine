using Asciigine.Core;

namespace PacGunMan.maps;

public class Player
{
    public string name;
    public Vector Position;
    public char model;

    public Player(string name, Vector spawnLoc, char model)
    {
        this.name = name;
        this.Position = spawnLoc;
        this.model = model;
    }
}