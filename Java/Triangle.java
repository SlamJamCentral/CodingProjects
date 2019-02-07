import java.util.Scanner;

public class Triangle{
  public static void main(String[] args){
    boolean repeat = false;
    do{
      double sideA = 0, sideB = 0, sideC = 0, sideH = 0, sideX = 0, sideY = 0;
      String givenInput = "";

      Scanner scanDude = new Scanner(System.in);

      System.out.println("\nWhat two sides are your givens?");
      System.out.println("If the sides are correct but the input doesn't go through,\ntry rearranging the letters or make sure the letters are in the same case");
      System.out.println("\nA = side a\nB = side b\nC = side c\nH = side h\nX = side a prime\nY = side b prime");
      givenInput = scanDude.nextLine();

      switch(givenInput){
        case "ab":
        case "AB":
          repeat = false;
          System.out.println("What is side A?");
          sideA = scanDude.nextDouble();
          System.out.println("What is side B?");
          sideB = scanDude.nextDouble();

          sideC = Math.pow(Math.pow(sideA, 2) + Math.pow(sideB, 2), 0.5);
          sideX = (Math.pow(sideA, 2))/ sideC;
          sideY = (Math.pow(sideB, 2))/ sideC;
          sideH = Math.pow((sideX * sideY), 0.5);

          break;

        case "ah":
        case "AH":
          repeat = false;
          System.out.println("What is side A?");
          sideA = scanDude.nextDouble();
          System.out.println("What is side H?");
          sideH = scanDude.nextDouble();

          break;

        case "ax":
        case "AX":
          repeat = false;
          System.out.println("What is side A?");
          sideA = scanDude.nextDouble();
          System.out.println("What is side X?");
          sideX = scanDude.nextDouble();
          break;

        case "ay":
        case "AY":
          repeat = false;
          System.out.println("What is side A?");
          sideA = scanDude.nextDouble();
          System.out.println("What is side Y?");
          sideY = scanDude.nextDouble();
          break;

        case "ac":
        case "AC":
          repeat = false;
          System.out.println("What is side A?");
          sideA = scanDude.nextDouble();
          System.out.println("What is side C?");
          sideC = scanDude.nextDouble();
          break;

        case "bh":
        case "BH":
          repeat = false;
          System.out.println("What is side B?");
          sideB = scanDude.nextDouble();
          System.out.println("What is side H?");
          sideH = scanDude.nextDouble();
          break;

        case "bx":
        case "BX":
          repeat = false;
          System.out.println("What is side B?");
          sideB = scanDude.nextDouble();
          System.out.println("What is side X?");
          sideX = scanDude.nextDouble();
          break;

        case "by":
        case "BY":
          repeat = false;
          System.out.println("What is side B?");
          sideB = scanDude.nextDouble();
          System.out.println("What is side Y?");
          sideY = scanDude.nextDouble();
          break;

        case "bc":
        case "BC":
          repeat = false;
          System.out.println("What is side B?");
          sideB = scanDude.nextDouble();
          System.out.println("What is side C?");
          sideC = scanDude.nextDouble();
          break;

        case "hx":
        case "HX":
          repeat = false;
          System.out.println("What is side H?");
          sideH = scanDude.nextDouble();
          System.out.println("What is side X?");
          sideX = scanDude.nextDouble();
          break;

        case "hy":
        case "HY":
          repeat = false;
          System.out.println("What is side H?");
          sideH = scanDude.nextDouble();
          System.out.println("What is side Y?");
          sideY = scanDude.nextDouble();
          break;

        case "hc":
        case "HC":
          repeat = false;
          System.out.println("What is side H?");
          sideH = scanDude.nextDouble();
          System.out.println("What is side C?");
          sideC = scanDude.nextDouble();
          break;

        case "xy":
        case "XY":
          repeat = false;
          System.out.println("What is side X?");
          sideX = scanDude.nextDouble();
          System.out.println("What is side Y?");
          sideY = scanDude.nextDouble();
          break;

        case "xc":
        case "XC":
          repeat = false;
          System.out.println("What is side X?");
          sideX = scanDude.nextDouble();
          System.out.println("What is side C?");
          sideC = scanDude.nextDouble();
          break;

        case "yc":
        case "YC":
          repeat = false;
          System.out.println("What is side Y?");
          sideY = scanDude.nextDouble();
          System.out.println("What is side C?");
          sideC = scanDude.nextDouble();
          break;

        default:
          repeat = true;
          break;
      }

      System.out.println("Side A: " + sideA);
      System.out.println("Side B: " + sideB);
      System.out.println("Side C: " + sideC);
      System.out.println("Side H: " + sideH);
      System.out.println("Side X: " + sideX);
      System.out.println("Side Y: " + sideY);

    }while(repeat);
  }
}
