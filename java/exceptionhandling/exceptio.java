package exc;
public class exception {
    public static void main(String args[]){
        int a;
        int b=0;
        try {

           
        if(b==0){
            
            throw  new invalid("Invalidd Number");
        }
        a=5/b;
        }catch(invalid e){
            System.err.println("Error Occured");
            System.out.println(e.getMessage());
        }
    }
}
