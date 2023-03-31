namespace MapLang;

public enum TokenType
{
    StringLit, NumberLit, Identifier, CharLit, LeftBracket, RightBracket, Comma, Colon,

    // Comments
    Hash, LessThan, MoreThan,
    
    EOL, EOF
}

public class Token
{
    public TokenType Type;
    public int Line;
    public object Lexeme = new Object();
    public object? Literal;

    public Token Add(TokenType type, object lexeme, int line, object? literal = null)
    {
        Token token = new();
        token.Type = type;
        token.Lexeme = lexeme;
        token.Line = line;
        token.Literal = literal;
        return token;
    }
}