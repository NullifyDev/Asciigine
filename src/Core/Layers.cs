using static Asciigine.Utils;

namespace Asciigine.Core;
/// <summary>
/// Plan:
///     - Implement Remove Function to remove   the specified Layer
///     - Implement Move   Function to relocate the specified Layer into a different Layer Level
///
///     - Implement a Grouping System to place turn layers into one without cluttering the Layers List.
/// </summary>
public static class Layers
{
    public static class Previous
    {
        public static Dictionary<string, Buffer> Content = new();
        public static int Count = Content.Count;
        public static int GetLen() => Content.Count;
        
        public static void Update(Buffer layer, int pos)
        {
            pos -= 1;
            for (int i = 0; i < layer.Frame.Count; i++)
            {
                if (Content.Count > 0)
                {
                    if (!layer.Frame.Contains(Content.ElementAt(pos).Value.Frame[i]))
                    {
                        Console.SetCursorPosition(Content.ElementAt(pos).Value.Frame[i].Pos.x,
                            Content.ElementAt(pos).Value.Frame[i].Pos.y);
                        Out(" ");
                    }
                }
            }
            Content = Current.GetContent();
            if (Content.ElementAt(pos).Value! != layer) Layers.Current.GetContent().Values.ElementAt(pos).Frame = layer.Frame;
        }
        
        public static void ListLayers() 
        {
            Outln($"[Layers]");
            for(int i = Content.Count()-1; i > -1; i--)
            {
                if (i == 0) Outln($" └─[{i+1}] Name: {Content.Keys.ElementAt(i)}");
                else        Outln($" ├─[{i+1}] Name: {Content.Keys.ElementAt(i)}");
            }
        }

        public static Dictionary<string, Buffer> GetContent() => Content;
        public static void Add(Buffer layer, string name = "Nameless Layer", int? pos = null)
        {
            int duplicates = 1;
            for (int i = 0; i < Current.GetContent().Count(); i++)
            {
                if (name == Current.GetContent().ElementAt(i).Key) Exception.Throw.DupeLayerName(name);
            
                if (Current.GetContent().ToList()[i].Key.StartsWith(name))
                {
                    if (Current.GetContent().ToList()[i].Key.Remove(0, name.Length) != duplicates.ToString())
                    {
                        if (duplicates != 1) name += duplicates.ToString();
                    }
                }
            }

            if (pos == null || pos <= 0) pos = Count+1;
            var temp = new Dictionary<string, Buffer>();
            //if (pos <= 0) pos = 1;

            for (int i = 0; i < pos; i++)
            {
                if (i == pos - 1) temp.Add(name, layer);
                else temp.Add(Content.ElementAt(i).Key, Content.ElementAt(i).Value);
            }

            Content = temp;
        }
    }
    
    public static class Current
    {
        public static Dictionary<string, Buffer> Content = new();
        public static int Count = Content.Count;
        public static int GetLen() => Content.Count;
        public static Dictionary<string, Buffer> GetContent() => Content;

        public static void Update(Buffer layer, int pos)
        {
            pos -= 1;
            if (Content.ElementAt(pos).Value! != layer) Current.Content.Values.ElementAt(pos).Frame = layer.Frame;
        }
        public static void Update(Buffer layer, string name)
        {
            if (Content[name]! != layer) Content[name].Frame = layer.Frame;
        }
        public static void ListLayers() 
        {
            Console.CursorVisible = true;
            Outln($"[Layers]");
            for(int i = GetContent().Count()-1; i > -1; i--)
            {
                if (i == 0) Outln($" └─[{i+1}] Name: {GetContent().Keys.ElementAt(i)}");
                else        Outln($" ├─[{i+1}] Name: {GetContent().Keys.ElementAt(i)}");
            }
            Console.CursorVisible = false;
        }
        
        public static void Add(Buffer layer, string name = "Nameless Layer", int? pos = null)
        {
            /*int duplicates = 1;
            for (int i = 0; i < Current.Content.Count(); i++)
            {
                if (name == Current.Content.ToList()[i].Key) Exception.Throw.DupeLayerName(name);
            
                if (Current.Content.ToList()[i].Key.StartsWith(name))
                {
                    if (Current.Content.ToList()[i].Key.Remove(0, name.Length) != duplicates.ToString())
                    {
                        if (duplicates != 1) name += duplicates.ToString();
                    }
                }
            }*/
            if (pos == null || pos <= 0) pos = Count+1;
            var temp = new Dictionary<string, Buffer>();
            //if (pos <= 0) pos = 1;

            for (int i = 0; i < pos; i++)
            {
                if (i == pos - 1) temp.Add(name, layer);
                else temp.Add(Content.ElementAt(i).Key, Content.ElementAt(i).Value);
            }
            Content = temp;
        }
    }
}