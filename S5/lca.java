import java.lang.Thread;
import java.io.*;
class Node
{
 int dat,depth;
 Node left,right;
 Node(int d)
 {
   dat=d;
   left=right=null;
  }
}
class Q
{      Node a[];
  int top;
  Q()
  {
   a=new Node[100];
   top=0;
  }
  void push(Node p)
  {
    a[top]=p;
    top++;
  }
  int firstindex(int p)
  {
   for(int i=0;i<top;i++)
   {
     if(p==a[i].dat)
       return i;
   }
   return -1;
  }
  Node rangemin(int i,int j)
  {
    int min=i;
    for(int k=i+1;k<j;k++)
    {
    if(a[k].depth<a[min].depth)
       min=k;
    }
    return a[min];
  }
  void showall()
  {
    for(int i=0;i<top;i++)
    System.out.println(a[i].dat+":"+a[i].depth);
  }
}



class ParQ extends Thread
{
  int begin,end;
  Node min;
  Q a;
  ParQ(Q b,int i,int j)
  {
    a=b;
    if(i<j)
    {
    begin=i;
    end=j;
    }
    else
    { 
    begin=j;
    end=i;
    }
  }
  public void run()
  {
  min=a.rangemin(begin,end);
  System.out.println("LCA is "+ min.dat);
  }
}


class BST extends Thread
{
  Node h;
  static Q q=new Q();
  BST(Node i,int d)
  {
    h=i;
    if(h!=null)
     h.depth=d;
  }
  Node append_1(Node h, Node n)
  {
    if(h==null)
       return n;
    if(n.dat<h.dat)
       h.left=append_1(h.left,n);
    else
       h.right=append_1(h.right,n);
    return h;
  }
  
  void append(Node n)
  {
  h=append_1(h,n);
  }
  
  void euler_1(Node h)
  {
   if(h!=null)
      q.push(h);
   if(h.left!=null)
   {
     BST b=new BST(h.left,h.depth+1);
     b.start();
     try
     {
      b.join();
     }
     catch(InterruptedException e)
     {
      e.printStackTrace();
     }
     q.push(h);
   }
   if(h.right!=null)
   {
     BST b=new BST(h.right,h.depth+1);
     b.start();
     try
     {
       b.join();
     }
     catch(InterruptedException e)
     {
       e.printStackTrace();
     }
     q.push(h);
   }
 }
 void euler()
 {
   euler_1(h);
 }
 public void run()
 {
    euler_1(h);
 }
}


public class lca
{
  public static void main(String args[])
  {
    BST b=new BST(null,0);
    DataInputStream rd;
    rd=new DataInputStream(System.in);
    int choice=1,n1,n2,ch;
    
    do
    {
      int n;
      System.out.print("enter the node:");
      try
      { n=Integer.parseInt(rd.readLine()); }
      catch(IOException e)
      {
        n=0;
        e.printStackTrace();
      }
      b.append(new Node(n));
      System.out.print("insert more?(0/1);");
      try
      {choice=Integer.parseInt(rd.readLine());}
      catch(IOException e)
      {
        n=1;
        e.printStackTrace();
      }
    }while(choice==1);
    b.euler();
    b.q.showall();
    do
    {
      System.out.println("\n enter two nodes:");
      try
      {
        n1=Integer.parseInt(rd.readLine());
        n2=Integer.parseInt(rd.readLine());
      }
      catch(IOException e)
      {
        n1=n2=0;
        e.printStackTrace();
      }
      int i=b.q.firstindex(n1);
      int j=b.q.firstindex(n2);
      ParQ q=new ParQ(b.q,i,j);
      q.start();
      System.out.println("Do you want to continue(0/1):");
      try
      {ch=Integer.parseInt(rd.readLine());}
      catch(IOException e)
      {
        ch=0;
      }
     }while(ch==1);
   }
}  

