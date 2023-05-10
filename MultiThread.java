import java.util.*;

class Movie extends Thread{
    int ticket =3,i;
    int[] p =new int[3];
    Movie(int[] x){
        for(i=0;i<3;i++){
            p[i]=x[i];
        }
    }
    public synchronized void run(){
        if(p[Integer.valueOf(Thread.currentThread().getName()) -1]<= ticket){
            System.out.println(p[Integer.valueOf(Thread.currentThread().getName())-1]+"-Tickets booked for"+Thread.currentThread().getName());

            try{
                Thread.sleep(100);
            }catch (Exception e){
                System.out.println("error detected");
            }
            ticket = ticket- p[Integer.valueOf(Thread.currentThread().getName())-1];
        }
        else{
            System.out.println("can not book ticket for "+ Thread.currentThread().getName());
        }
    }
}

public class MultiThread{
    public static void main(String args[]) {
        int[] t = new int[3];
        int i;
        Scanner sc = new Scanner(System.in);

        for(i=0;i<3;i++){
            System.out.println("enter the number of tickets for person"+(i+1));
            t[i]=sc.nextInt();    
        }
        Movie m = new Movie(t);
        Thread t1 = new Thread(m);
        Thread t2 = new Thread(m);
        Thread t3 = new Thread(m);
        t1.setName("1");
        t2.setName("2");
        t3.setName("3");
        t1.start();
        t2.start();
        t3.start();
    }
}