#include <iostream>
#include <pthread.h>

using namespace std;

/**
	1>lan hans shi: yan chi shi li hua. 
	2> xian cheng bu an quan 
*/

class singleton 
{
	protected:
		singleton()
		{
			cout<<"singleton structor"<<endl;
		}

	private:
		static singleton* p;
	public:
		static singleton* instance();
};

singleton* singleton::p = NULL;

singleton* singleton::instance()
{
	if(p == NULL)
	{
		p = new singleton();
	}
	cout<<"singleton instance"<<endl;
	return p;
}

/**
	1> xian chen an quan  lan han shi 
*/

/*
class singleton_safe
{
protected:
	singleton_safe()
	{
		pthread_mutex_init(&mutex);
		cout<<"singleton_safe structor"<<endl;
	}

private:
	static singleton_safe* p;

public:
	static pthread_mutex_t mutex;
	static  singleton_safe* instance();
	~singleton_safe();
	
};

pthread_mutex_t singleton_safe::mutex;
singleton_safe* singleton_safe::p = NULL;
singleton_safe* singleton_safe::instance()
{
	if(p == NULL)
	{
		pthread_mutex_lock(&mutex);
		if(p ==NULL)
		{
			p = new	singleton_safe();
		}
		pthread_mutex_unlock(&mutex);
	}
	cout<<"singleton_safe instance"<<endl;
	return p;
}
*/

/**
	3> jing tai bian liang  shi xiang
*/
/*
class singleton_static_var
{
protected:
	singleton_static_var()
	{
		pthread_mutex_init(&mutex);
		cout<<"singleton_static_var structor"<<endl;
	}
public:
	static pthread_mutex_t mutex;
	static singleton_static_var* instance(); 
	int a;
};

pthread_mutex_t singleton_static_var::mutex;
singleton_static_var* singleton_static_var::instance()
{
	pthread_mutex_lock(&mutex);
	static singleton_static_var obj;
	pthread_mutex_unlock(&mutex);
	cout<<"singleton_static_var instance"<<endl;
	return &obj;
}

*/

/**
	4> lan han shi
*/
class singleton_lanhan
{
protected:
	singleton_lanhan()
	{
		cout<<"singleton_lanhan structor"<<endl;
	}
private:
	static singleton_lanhan* p;
public:
	static singleton_lanhan* instance();
	~singleton_lanhan();
	
};

singleton_lanhan* singleton_lanhan::p = new singleton_lanhan;
singleton_lanhan* singleton_lanhan::instance()
{
	cout<<"singleton_lanhan instance"<<endl;
	return p;
}


int main(int argc, char const *argv[])
{
	/* code */
	singleton* single = singleton::instance();
	//singleton_safe single_safe;
	//singleton_static_var single_var;
	singleton_lanhan* single_lanhan = singleton_lanhan::instance();

	return 0;
}

/**
OUTPUT:
	singleton_lanhan structor
	singleton structor
	singleton instance
	singleton_lanhan instance
*/
