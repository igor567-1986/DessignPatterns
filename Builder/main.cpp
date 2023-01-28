#include<iostream>
using namespace std;
 
//Product
class Computer
{
	std::string type;
	std::string cp;
	std::string ram;
	std::string video;
	std::string disk;
	std::string power;
	bool on;
public:
	void set_type(const std::string& type)
	{
		this->type = type;
	}
	void set_cpu(const std::string& cp)
	{
		this->cp = cp;
	}
	void set_ram(const std::string& ram)
	{
		this->ram= ram;
	}
	void set_video(const std::string& video)
	{
		this->video = video;
	}
	void set_disk(const std::string& disk)
	{
		this->disk = disk;
	}
	void set_power(const std::string& power)
	{
		this->power = power;
	}
	
	/*Computer(const std::string& cp, const std::string& ram, const std::string& video, const std::string& disk, const std::string& power)
		:cp(cp), ram(ram), video(video), disk(disk), power(power)
	{
		on - false;
		cout << "CConstructor:\t" << this << endl;
	}*/
	Computer()
	{
		cout << "CompConructor:\t" << this << endl;
		on = false;
	}
	~Computer()
	{
		cout << "CompDestructor:\t" << this << endl;
	}
	void power_button()
	{
		on = on ? false : true;
	}
	virtual void info()const
	{
		cout<< "\n----------------------------------\n";
		if (on)
		{
			cout << "CPU: " << cp << ", ";
			cout << " RAM: " << ram << ", ";
			cout << "Video: " << video << ", ";
			cout << " DISK: " << disk << ", ";
			cout << "POWER: " << power << ", ";
		}
		else
		{
			cout << "Please turn me on" << endl;
		}
		cout << "\n----------------------------------\n";
	}
};

//AbstractB builder

class ComputerBuilder
{
protected:
	Computer* computer;
public:
	ComputerBuilder()
	{
		this->computer = new Computer;
	}
	virtual ~ComputerBuilder()
	{
		delete this->computer;
	}
	Computer* get_computer()const
	{
		return computer;
	}
	virtual void set_type() = 0;
	virtual void set_cpu() = 0;
	virtual void set_ram() = 0;
	virtual void set_video() = 0;
	virtual void set_disk() = 0;
	virtual void set_power() = 0;
};
///////////////////////////////////////////
 // ConcreteBuilders
class CheapComputerBuilder :public ComputerBuilder
{
public:
	~CheapComputerBuilder()	{}
	void set_type()
	{
		computer->set_type("CheapComputer");
	}
	void set_cpu()
	{
		computer->set_cpu("Intel Celeron 7300");
	}
	void set_ram()
	{
		computer->set_ram("SiliconPower 4GB");
	}
	void set_video()
	{
		computer->set_video("Intel UHD Grafics");
	}
	void set_disk()
	{
		computer->set_disk("Kingston ssd Now 128 GB");
	}
	void set_power()
	{
		computer->set_power("Chiefic 400W");
	}
};
class OfficeComputerBuilder :public ComputerBuilder
{
public:
	~OfficeComputerBuilder(){} 
	void set_type()
	{
		computer->set_type("OfficeComputer");
	}
	void set_cpu()
	{
		computer->set_cpu("Intel Core i3 13100");
	}
	void set_ram()
	{
		computer->set_ram("Kingston DDR-4 3200 8GB");
	}
	void set_video()
	{
		computer->set_video("Intel UHD Grafics 730");
	}
	void set_disk()
	{
		computer->set_disk("1Tb Samsung 750evo 512GB");
	}
	void set_power()
	{
		computer->set_power("Chiefic 500W Silver");
	}
};
class GameComputerBuilder :public ComputerBuilder
{
public:
	~GameComputerBuilder() {}
	void set_type()
	{
		computer->set_type("GameComputer");
	}
	void set_cpu()
	{
		computer->set_cpu("Intel Core i7 13700");
	}
	void set_ram()
	{
		computer->set_ram("Kingston DDR-5 5600 32 GB");
	}
	void set_video()
	{
		computer->set_video("nVideo GeForce RTX 4090");
	}
	void set_disk()
	{
		computer->set_disk("2TB Samsung  850 Pro M.2");
	}
	void set_power()
	{
		computer->set_power("Chiefic 1000W Platinum");
	}
};

class Sysadmin
{
	ComputerBuilder* builder;
public:
	Sysadmin() :builder(nullptr){}
	void assembly_computer(ComputerBuilder* builder)
	{
		this->builder = builder;
		builder->set_type();
		builder->set_cpu();
		builder->set_ram();
		builder->set_video();
		builder->set_disk();
		builder->set_power();
	}
	void turn_of_the_computer()
	{
		if (builder)
		{
			builder->get_computer()->power_button();
			builder->get_computer()->info();
		}
		else
		{
			cout << "Средства не были выделены:-(" << endl;
		}

	}
};



void main()
{
	setlocale(LC_ALL, "");
	//Computer comp("Core i5 12400", "Kingston 8GB", "Intel HD Graphics", "Samsung 870 Evo 500 GB", "Chieftec 500 Gold");
	//comp.info();

	//CheapComputer comp("Intel Celeron", "Kingston 4GB", "Intel HD Graphics", "Kingston SSD 128GB", "Chieftec 400");
	//comp.info();

	Sysadmin nice_guy;
	CheapComputerBuilder computer_for_director;
	nice_guy.assembly_computer(&computer_for_director);
	nice_guy.turn_of_the_computer();
	computer_for_director.get_computer()->power_button();
	computer_for_director.get_computer()->info();

	OfficeComputerBuilder computer_for_bookkeeper;
	nice_guy.assembly_computer(&computer_for_bookkeeper);
	nice_guy.turn_of_the_computer();

	GameComputerBuilder computer_for_sysadmin;
	nice_guy.assembly_computer(&computer_for_sysadmin);
	nice_guy.turn_of_the_computer();
}