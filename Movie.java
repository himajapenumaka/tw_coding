import java.util.Arrays;

public class Movie {

    private String title, studio, rating;
    public Movie(String title, String studio, String rating){
        this.title= title;
        this.studio= studio;
        this.rating= rating;
    }

    public Movie(String title, String studio){
        this.title= title;
        this.studio= studio;
        this.rating= "PG";
    }

    public String getRating() {
        return this.rating;
    }

    public String getStudio(){
        return this.studio;
    }

    public String getTitle(){
        return this.title;
    }

    public Movie[] getPg(Movie[] movies){
        Movie result[]= new Movie[movies.length];
        int k=0;
        for(Movie m: movies){
            if(m.getRating().contains("PG"))
                result[k++] = m;
        }
        return Arrays.copyOfRange(result, 0, k);
    }

}


public class Main {

    public static void main(String[] args) {

        // creating and initializing three Movie objects
        Movie m1= new Movie("Casino Royale", "Eon Productions", "PG-13");
        Movie m2 = new Movie("Indiana Jones", "Raiders", "PG");
        Movie m3 = new Movie("Deadpool", "Fox", "R");
        Movie m4 = new Movie("Life Of Pi", "20th Century", "PG");

        // creating and initializing a Movie array
        Movie[] movies = {m1, m2, m3, m4};

        // calling the getPg() method
        Movie[] pgRatedMovies = m1.getPg(movies);
        for(Movie m: pgRatedMovies){
            System.out.println(m.getTitle());
        }

    }
}
