import java.io.*;

class lock{}
class Rw extends Thread
{
	String type;
	static boolean writing=false;
	static int nreaders=0;
	int id;
	static int resourse,i;
	static lock L=new lock();
	Rw(String str,int num)
	{
		type=str;
		id=num;
	}
	void aqrReadLock()
	{
		synchronized(L)
		{
			while(writing)
				try
				{
					L.wait();
				}
				catch(InterruptedException e) {}
			++nreaders;
		}
	}
	void rlsReadLock()
	{
		synchronized(L)
		{
			--nreaders;
			if(nreaders==0)
				L.notifyAll();
		}
	}
	void aqrWriteLock()
	{
		synchronized(L)
		{
			while(writing||(nreaders>0))
				try
				{
					L.wait();
				}
				catch(InterruptedException e) {}
				writing=true;
		}
	}
	void rlsWriteLock()
	{
		synchronized(L)
		{
			writing=false;
			L.notifyAll();
		}
	}
	void read()
	{
		for(;;)
		{
			aqrReadLock();
			System.out.println("\tReader"+id+" reads "+resourse);
			rlsReadLock();
			try
			{
				Thread.sleep(1000);
			}
			catch(InterruptedException e) {}
		}
	}
	void write()
	{
		for(;;)
		{
			aqrWriteLock();
			System.out.println("Writer"+id+" writes "+ ++resourse);
			rlsWriteLock();
			try
			{
				Thread.sleep(1000);
			}
			catch(InterruptedException e) {}
		}
	}
	public void run()
	{
		if(type.equals("Reader"))
			read();
		else write();
	}
}
class main
{
	public static void main(String args[])
	{
		int i=0;
		Rw[] rw=new Rw[6];
		while(i<3)
			rw[i]=new Rw("Writer",i++);
		while(i<6)
			rw[i]=new Rw("Reader",i++ -3);
		i=0;
		while(i<6)
			rw[i++].start();
	}
}
	
	
