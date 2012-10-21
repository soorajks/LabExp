import java.io.*;
class complex
{
	double re,im;
	complex(double r,double i)
	{
		re=r;
		im=i;
	}
	complex add(complex p)
	{
		complex q=new complex(0,0);
		q.re=re+p.re;
		q.im=im+p.im;
		return q;
	}
	complex mul(double s)
	{
		complex q=new complex(0,0);                      
		q.re=re*s;
		q.im=im*s;
		return q;
	}
	void display()
	{
		System.out.print(re+"+i"+im);
	}
}
abstract class basevector
{
	double rvector[];
	complex cvector[];
	DataInputStream rd;
	{
		rd=new DataInputStream(System.in);
	}
	public abstract basevector add(basevector p);
	public abstract void showvector();
	public abstract basevector scalarmul(double a);
	public abstract void readvector();
}
class realvector extends basevector
{
	private int i,n;                             
	realvector(int j)
	{
		super();
		rvector=new double[10];
		n=j;
		for(i=0;i<n;i++)
			rvector[i]=0;
	}
	public void readvector()
	{
		for(i=0;i<n;i++)
		{
			System.out.println("Enter component "+(i+1)+" : ");
			try
			{
				rvector[i]=Integer.parseInt(rd.readLine());
			}
			catch(IOException e)
			{
				rvector[i]=0;
			}
		}
	}
	public basevector add(basevector p)
	{  realvector q=new realvector(n);
		for(i=0;i<n;i++)
			q.rvector[i]=rvector[i]+p.rvector[i];
		return q;
	}
	public basevector scalarmul(double a)
	{ realvector q= new realvector(n);
		for(i=0;i<n;i++)
			q.rvector[i]=rvector[i]*a;
                return q;
	}
	public void showvector()
	{
		System.out.print("(");
		for(i=0;i<n;i++)
		{
			System.out.print(rvector[i]);
			if(i!=(n-1))
				System.out.print(",");
		}
		System.out.print(")");
	}
}
class cvector extends basevector
{
	private int i,j,n;
	int r,im;
	cvector(int k)
	{
		super();
		cvector=new complex[10];
		n=k;
		for(i=0;i<n;i++)
			cvector[i]=new complex(0,0);
	}
	public void readvector()
	{
		for(i=0;i<n;i++)
		{
			System.out.println("Enter component "+(i+1)+" : ");
			try
			{
				r=Integer.parseInt(rd.readLine());
				im=Integer.parseInt(rd.readLine());
			}
			catch(IOException e)
			{
				r=0;
				im=0;
			}
			cvector[i]=new complex(r,im);
		}
	}
	public basevector add(basevector p)
	{
		cvector c=new cvector(n);
		for(i=0;i<n;i++)
			c.cvector[i]=cvector[i].add(p.cvector[i]);
		return c;
	}
	public basevector scalarmul(double a)
	{
                cvector c=new cvector(n);
		for(i=0;i<n;i++)
			c.cvector[i]=cvector[i].mul(a);
                return c;
	}
	public void showvector()
	{
		System.out.print("(");
		for(i=0;i<n;i++)
		{
			cvector[i].display();
			System.out.print(",");
		}

		System.out.print(")");
	}
}class vector
{
	public static void main(String args[])throws NumberFormatException,IOException
	{
		DataInputStream rd=new DataInputStream(System.in);
		int ch1,ch2,n;
		double r,im;
		basevector r1,r2, r3;
		while(true)
		{
			System.out.println("MENU\n1.Real Vector\n2.Complex Vector\n3.Exit\nEnter your choice : ");
			ch1=Integer.parseInt(rd.readLine());
			switch(ch1)
			{
				case 1:
					System.out.println("Enter the dimension : ");
					n=Integer.parseInt(rd.readLine());
					r1=new realvector(n);
					r1.readvector();
					a:
					while(true)
					{
						System.out.println("\n1.Add\n2.Scalar Multiplication\n3.Display\n4.Back\nEnter your choice : ");
						ch2=Integer.parseInt(rd.readLine());
						switch(ch2)
						{
							case 1:
								System.out.println("Enter a vector of dimension "+n+" : ");
								r2=new realvector(n);
								r2.readvector();
								r3=r1.add(r2);
								r3.showvector();
								break;
							case 2:
								System.out.println("Enter a scalar :  ");
								r=Integer.parseInt(rd.readLine());
								r3=r1.scalarmul(r);
								r3.showvector();
								break;
							case 3:
								r1.showvector();
								break;
							case 4:
								break a;
						}
					}
					break;
				case 2:
					System.out.println("Enter the dimension : ");
					n=Integer.parseInt(rd.readLine());
					r1=new cvector(n);
					r1.readvector();
					b:
					while(true)
					{
						System.out.println("\n1.Add\n2.Scalar Multiplication\n3.Display\n4.Back\nEnter your choice : ");
						ch2=Integer.parseInt(rd.readLine());
						switch(ch2)
						{
							case 1:
								System.out.println("Enter a vector of dimension "+n+" : ");
								r2=new cvector(n);
								r2.readvector();
								r3=r1.add(r2);
								r3.showvector();
								break;
							case 2:
								System.out.println("Enter a scalar : ");
								r=Integer.parseInt(rd.readLine());
								r3=r1.scalarmul(r);
								r3.showvector();
								break;
							case 3:
								r1.showvector();
								break;
							case 4:
								break b;
						}
					}
					break;
				case 3:
					System.exit(0);
			}
		}
	}
}
