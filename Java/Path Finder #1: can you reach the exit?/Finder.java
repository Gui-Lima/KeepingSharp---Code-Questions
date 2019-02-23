import java.util.ArrayList;

public class Finder {

    public static class Graph{
        ArrayList[] g;
        private int nNodes;

        public Graph(int size){
            this.nNodes = size;
            this.g = new ArrayList[size];
            for(int i =0;i<size;i++){
                g[i] = new ArrayList<Integer>();
            }
        }

        public void addEdge(int i, int j){
            g[i].add(j);
            g[j].add(i);
        }

        private boolean bfs(int startingNode) {
            ArrayList<Integer> result = new ArrayList<Integer>();
            if(g[startingNode].isEmpty()){
                return false;
            }

            boolean[] visited = new boolean[nNodes];
            for(int i = 0;i<nNodes;i++){
                visited[i] = false;
            }

            visited[startingNode] = true;
            ArrayList<Integer> queue = new ArrayList<Integer>();
            queue.add(startingNode);

            while(!queue.isEmpty()){
                int s = queue.get(0);
                result.add(s);
                if(s == convertIJ(mazez.length-1, mazez.length-1)){
                    System.out.println("Achou");
                    return true;
                }
                System.out.println(s);
                queue.remove(queue.get(0));

                for (Object i : g[s]) {
                    if(!visited[(Integer) i]){
                        visited[(Integer) i] = true;
                        queue.add((Integer) i);
                    }
                }

            }
            return false;
        }

    }

    static String[][] mazez;
    static Graph g;

    public static void main(String[] args){
        String a = ".W.\n"+
                ".W.\n"+
                "...";
        pathFinder(a);
    }

    static boolean pathFinder(String maze) {
        if(maze.equals(".")){
            return true;
        }
        String[] mazeLines = maze.split("\n");
        mazez = new String[mazeLines.length][mazeLines.length];
        g = new Graph((mazeLines.length * mazeLines.length) + 1);

        for(int i =0;i<mazeLines.length;i++){
            for(int j = 0;j<mazeLines[i].length();j++){
                mazez[i][j] = String.valueOf(mazeLines[i].charAt(j));
            }
        }
        return makeGraph();
    }

    private static boolean makeGraph() {
        for(int i =0;i<mazez.length;i++){
            for(int j =0;j<mazez[i].length;j++){
                if(i < mazez.length - 1 && mazez[i+1][j].equals(".") && mazez[i][j].equals(".")){
                    g.addEdge(convertIJ(i,j), convertIJ(i+1, j));
                }
                if(j<mazez[i].length -1 && mazez[i][j+1].equals(".") && mazez[i][j].equals(".")){
                    g.addEdge(convertIJ(i,j), convertIJ(i,j +1));
                }

            }
        }
        printMazez();
        return g.bfs(1);
    }

    private static void printMazez() {
        for(int i =0;i<mazez.length;i++){
            for(int j=0;j<mazez.length;j++){
                System.out.print(mazez[i][j]);
            }
            System.out.println();
        }
    }

    private static int convertIJ(int x, int y) {
        int count = 1;
        for (int i = 0; i < mazez.length; i++) {
            for (int j = 0; j < mazez[i].length; j++) {
                if (i == x && j == y) {
                    return count;
                }
                count++;
            }
        }
        return count;
    }
}