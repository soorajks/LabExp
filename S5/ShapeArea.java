import java.io.*;

class shape{
 int dim1,dim2;
 shape(int d1,int d2)
 {
        dim1 = d1;
        dim2 = d2;
        System.out.println(" Creating a Shape \n");
 }
}

class rectangle extends shape {
 rectangle(int l, int b)
 {
        super(l,b);
        System.out.println(" Creating a rectangle with sides "+l+" and "+b);
 }
 void rectprop()
 {
        System.out.println("\n\tRectangle properties");
        System.out.println("\t----------------------");
        System.out.println("\tArea = length * breadth");
	System.out.println("\tPerimeter = 2 * (length + breadth)");
 }
 int area(int l,int b)
 {
        return l*b;
 }
 int perimeter(int l,int b)
 {
	return 2*(l+b);
 }
}

class square extends rectangle {
 square(int s)
 {
	super(s,s);
	System.out.println(" \nCreating a square with side "+s);
 }
 void sqprop()
 {
	System.out.println("\n\tSquare properties " );
 	System.out.println("\t-------------------");
	System.out.println("\tsquare has all side equal");
	System.out.println("\tArea = side * side");
	System.out.println("\tPerimeter = 4 * side ");
 }
}

class ellipse extends shape {
 ellipse(int a,int b)
 {
	super(a,b);
	System.out.println("Creating an Ellipse with ");
	System.out.println("\tMajor axis = "+a);
	System.out.println("\tMinor axis = "+b);
 }
 void elprop()
 {
	System.out.println("\n\tEllipse properties");
	System.out.println("\t-------------------");
	System.out.println("\tArea = 3.14 * major axis * minor axis");
	System.out.println("\tPerimeter = 2*3.14*sqrt((a*a+b*b)/2)");
 }

 double area(int a,int b)
 {
	return 3.14*a*b;
 }
 double perimeter(int a,int b)
 {
	return 2*Math.PI*Math.sqrt(.5*(a*a+b*b));
 }
}


class circle extends ellipse {
 circle(int r)
 {
	super(r,r);
	System.out.println(" \nCreating a Circle with radius "+r);
 }
 void circleprop()
 {
	System.out.println("\n\tCircle properties");
	System.out.println("\t------------------");
	System.out.println("\tCircle is an ellipse with Major axis = Minor axis");
	System.out.println("\tArea = 3.14 * r * r");
	System.out.println("\tPerimeter = 2 * 3.14 * r");
 }
}


class ShapeArea{
 public static void main(String[] args)
 {
 InputStreamReader in = new InputStreamReader(System.in);
 BufferedReader br = new BufferedReader(in);
 int l=0,b=0,area=0,choice=0,peri=0;
 String ch = new String();
 double area1 = 0.0,peri1 = 0.0;
 do{
 try{
 System.out.println("\n\n\t----------MENU----------\n\t1.Rectangle\n\t2.Square\n\t3.Ellipse\n\t4.Circle\n\t5.Exit");
 System.out.println("Enter your Choice : ");
 ch = br.readLine();
 choice = Integer.parseInt(ch);
 switch(choice)
 {
 case 1 : System.out.println("Enter length and breadth");
         l=Integer.parseInt(br.readLine());
         b=Integer.parseInt(br.readLine());
         rectangle r = new rectangle(l,b);
         r.rectprop();
         area = r.area(l,b);
         peri = r.perimeter(l,b);
         System.out.println("\n\tArea = "+area+"\n\tPerimeter = "+peri);
         break;
 case 2 :System.out.println("Enter the side : ");
	 l=Integer.parseInt(br.readLine());
	 square s = new square(l);
	 s.sqprop();
	 area = s.area(l,l);
	 peri = s.perimeter(l,l);
	 System.out.println("\n\tArea = "+area+"\n\tPerimeter = "+peri);
	 break;
 case 3 :System.out.println("Enter a and b ");
         l=Integer.parseInt(br.readLine());
         b=Integer.parseInt(br.readLine());
	 ellipse e = new ellipse(l,b);
	 e.elprop();
	 area1 = e.area(l,b);
	 peri1 = e.perimeter(l,b);
	 System.out.println("\n\tArea = "+area1+"\n\tPerimeter = "+peri1);
	 break;
 case 4 :System.out.println("Enter the radius : ");
	 l=Integer.parseInt(br.readLine());
	 circle c = new circle(l);
	 c.circleprop();
	 area1 = c.area(l,l);
	 peri1 = c.perimeter(l,l);
	 System.out.println("\n\tArea = "+area1+"\n\tPerimeter = "+peri1);
	 break;
 case 5 :break;
 }
}
 catch(IOException e)
 {
	System.out.println(e);
	System.exit(1);
 }
 if(choice !=1 && choice !=2 && choice !=3 && choice !=4 && choice !=5)
 {
 	System.out.println("invalid Choice !!!");
 }
}while(choice!=5);
}
}
