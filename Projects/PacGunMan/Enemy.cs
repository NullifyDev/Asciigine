using Asciigine.Core;
namespace PacGunMan;

public class Enemy
{
    public string name;
    public Vector Position;
    public char model;

    public Enemy(string name, Vector spawnLoc, char model)
    {
        this.name = name;
        this.Position = spawnLoc;
        this.model = model;
    }
}