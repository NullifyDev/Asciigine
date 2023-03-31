namespace Asciigine.Core;

public class Vector
{
    public int x;
    public int y;

    public Vector() {}

    public Vector(int[] pos)
    {
        x = pos[0];
        y = pos[1];
    }

    public Vector(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
}