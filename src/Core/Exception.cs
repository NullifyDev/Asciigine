using static Asciigine.Utils;
namespace Asciigine.Exception;
public static class Throw
{
    public static void NoSuchProjectName(string name) => Crash($"[Asciigine]: NoSuchProjectName: The project named \"{name}\" has not been found");

    public static void ProjectNameMissing() => Crash($"[Asciigine]: ProjectNameMissing: Project name cannot be null");
    public static void NoTypeFound(string projectname) => Crash($"[Asciigine]: NoTypeFound: {projectname}: namespace/class is eiter missing or not matching");
    
    public static void DupeLayerName(string layername) => Crash($"[Asciigine]: DupeLayerName: Cannot have two or more of the same exact Layer names - {layername} already exists");
    
    public static void DupeProjName(string projectname) => Crash($"[Asciigine]: DupeProjName: Cannot have two or more of the same exact Project names - {projectname} already exists");
    public static void NoStartingPoint(string projectname) => Crash($"[Asciigine]: NoStartingPoint: Cannot start project - {projectname}.Run(string[] args) Not Found");
    public static void MainIsStatic(string projectname) => Crash($"[Asciigine]: MainIsStatic: {projectname}.Main.Run() should not and cannot be static. Please remove the \"Static\" Identifier");
}