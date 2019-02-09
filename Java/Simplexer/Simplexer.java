import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Simplexer implements Iterator<Token> {

    public List<Token> list;
    public int size;
    public int atual;
    String input;
    String intPattern = "(\\d+)";
    String boolPattern = "(true)|(false)";
    String strPattern = "(\".*\")";
    String oprPattern = "(\\+)|(-)|(\\*)|(/)|(%)|(\\()|(\\))|(=)";
    String kwPattern = "if|else|for|while|return|func|break";
    String whiteSpacePattern = "\\s+";
    String idePattern = "[A-Za-z0-9_$]+";
    Pattern bigPattern = Pattern.compile("(\\d+)|(true)|(false)|(\".*\")|(\\+)|(-)|(\\*)|(/)|(%)|(\\()|(\\))|(=)|(if)|(else)|(for)|(while)|(return)|(func)|(break)|\\s+|[A-Za-z0-9_$]+");


    public static void main(String[] args){
        Simplexer s = new Simplexer(null);
        List<Token> ts = s.list;
        List<Token> tokens = new ArrayList<>();
        s.forEachRemaining(tokens::add);
        for(int i =0;i<tokens.size();i++){
            System.out.println(tokens.get(i).text + " " + tokens.get(i).type);
        }
    }

    public Simplexer(String buffer) {
        if(buffer == null){
            buffer = "";
        }
        this.input = buffer;
        this.size = 0;
        this.atual = 0;
        this.list = new ArrayList<Token>();
        makeTokenList();
    }


    private void makeTokenList() {
        Matcher matcher = this.bigPattern.matcher(this.input);
        while(matcher.find()){
            if(matcher.group().matches(intPattern)){
                this.list.add(new Token(matcher.group(), "integer"));
            }
            else if(matcher.group().matches(boolPattern)){
                this.list.add(new Token(matcher.group(), "boolean"));
            }
            else if(matcher.group().matches(strPattern)){
                this.list.add(new Token(matcher.group(), "string"));
            }
            else if(matcher.group().matches(oprPattern)){
                this.list.add(new Token(matcher.group(), "operator"));
            }
            else if(matcher.group().matches(kwPattern)){
                this.list.add(new Token(matcher.group(), "keyword"));
            }
            else if(matcher.group().matches(whiteSpacePattern)){
                this.list.add(new Token(matcher.group(), "whitespace"));
            }
            else if(matcher.group().matches(idePattern)){
                this.list.add(new Token(matcher.group(), "identifier"));
            }
            this.size++;
        }
    }

    @Override
    public boolean hasNext() {
        if(this.atual >= this.list.size()){
            return false;
        }
        return true;
    }

    @Override
    public Token next() throws NoSuchElementException{
        if(this.atual >= this.list.size()){
            throw new NoSuchElementException();
        }
        Token t = this.list.get(atual);
        this.atual++;
        return t;
    }

    @Override
    public void remove() {

    }
}