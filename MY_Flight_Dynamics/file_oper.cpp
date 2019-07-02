#include "file_oper.h"

void file_oper::build_file(string filename)
{
	const char* p = filename.c_str();	
	this->file = fopen(p,"r+");
	this->ofile.open(filename);
}

void file_oper::finish_file(void)
{
	this->ofile.close();	
}

void file_oper::writefile(string str, int movement)
{
	this->ofile.seekp(movement, ios::cur);	
	this->writefile(str);
}

void file_oper::writefile(string str)
{
	const char* p = str.c_str();
	this->ofile << p << std::endl;
}

void file_oper::build_run(string filepath,var v)
{
	string str = filepath;
	str.append("\\test.run");
	v.fresh_var();
	this->build_file(str);
	///
	//
	str = "";
	this->writefile(str);
	//-------------------------------------------- -
	str = "--------------------------------------------";
	this->writefile(str);
	//	Run case  1:  
	str = "Run case  1:  ";
	str.append(v.get_name());
	this->writefile(str);
	//
	str = "";
	this->writefile(str);
	//alpha->alpha = 2.0000
	str = "alpha->alpha = ";
	str.append(to_string(v.get_alpha()));
	this->writefile(str);
	//beta->beta = 0.00000
	str = "beta->beta = ";
	str.append(to_string(v.get_beta()));
	this->writefile(str);
	//pb / 2V->pb / 2V = 0.00000
	str = "pb / 2V->pb / 2V = 0.00000";
	this->writefile(str);
	//qc / 2V->qc / 2V = 0.00000
	str = "qc / 2V->qc / 2V = 0.00000";
	this->writefile(str);
	//rb / 2V->rb / 2V = 0.00000
	str = "rb / 2V->rb / 2V = 0.00000";
	this->writefile(str);
	//
	str = "";
	this->writefile(str);
	//alpha = 0     deg
	str = "alpha = ";
	str.append(to_string(v.get_alpha()));
	str.append("     deg");
	this->writefile(str);
	//beta = 0.00000     deg
	str = "beta = ";
	str.append(to_string(v.get_beta()));
	str.append("     deg");
	this->writefile(str);
	//pb / 2V = 0.00000
	str = "pb / 2V = 0.00000";
	this->writefile(str);
	//qc / 2V = 0.00000
	str = "qc / 2V = 0.00000";
	this->writefile(str);
	//rb / 2V = 0.00000
	str = "rb / 2V = 0.00000";
	this->writefile(str);
	//CL = 0.00000
	str = "CL = 0.00000";
	this->writefile(str);
	//CDo = 0.02000000
	str = "CDo = ";
	str.append(to_string(v.get_CDo()));
	this->writefile(str);
	//bank = 0.00000     deg
	str = "bank = 0.00000     deg";
	this->writefile(str);
	//elevation = 0.00000     deg
	str = "elevation = 0.00000     deg";
	this->writefile(str);
	//heading = 0.00000     deg
	str = "heading = 0.00000     deg";
	this->writefile(str);
	//	Mach = 0.1
	str = "Mach = ";
	str.append(to_string(v.get_mach()));
	this->writefile(str);
	//	velocity = 10     Lunit / Tunit
	str = "velocity = ";
	str.append(to_string(v.get_velocity()));
	str.append("     Lunit / Tunit");
	this->writefile(str);
	//	density = 1.12     Munit / Lunit ^ 3
	str = "density = ";
	str.append(to_string(v.get_density()));
	str.append("Munit / Lunit ^ 3");
	this->writefile(str);
	//	grav.acc. = 9.8000     Lunit / Tunit ^ 2
	str = "grav.acc. = ";
	str.append(to_string(v.get_gravity()));
	str.append("     Lunit / Tunit ^ 2");
	this->writefile(str);
	//	turn_rad. = 0.00000     Lunit
	str = "turn_rad. = 0.00000     Lunit";
	this->writefile(str);
	//	load_fac. = 0.00000
	str = "load_fac. = 0.00000";
	this->writefile(str);
	//	X_cg = 0.313     Lunit
	str = "X_cg = ";
	str.append(to_string(v.get_Xref()));
	str.append("     Lunit");
	this->writefile(str);
	//	Y_cg = 0.00000000     Lunit
	str = "Y_cg = ";
	str.append(to_string(v.get_Yref()));
	str.append("     Lunit");
	this->writefile(str);
	//	Z_cg = 0.23900     Lunit
	str = "Z_cg = ";
	str.append(to_string(v.get_Zref()));
	str.append("     Lunit");
	this->writefile(str);
	//	mass = 3.80000000     Munit
	str = "mass = ";
	str.append(to_string(v.get_mass()));
	str.append("     Munit");
	this->writefile(str);
	//	Ixx = 6950.5700     Munit - Lunit ^ 2
	str = "Ixx = ";
	str.append(to_string(v.get_Ixx()));
	str.append("     Munit - Lunit ^ 2");
	this->writefile(str);
	//	Iyy = 5201.04800     Munit - Lunit ^ 2
	str = "Iyy = ";
	str.append(to_string(v.get_Iyy()));
	str.append("     Munit - Lunit ^ 2");
	this->writefile(str);
	//	Izz = 11616.5900     Munit - Lunit ^ 2
	str = "Izz = ";
	str.append(to_string(v.get_Izz()));
	str.append("     Munit - Lunit ^ 2");
	this->writefile(str);
	//	Ixy = 0.0000 Munit - Lunit ^ 2
	str = "Ixy = ";
	str.append(to_string(v.get_Ixy()));
	str.append("     Munit - Lunit ^ 2");
	this->writefile(str);
	//	Iyz = 0.000 Munit - Lunit ^ 2
	str = "Iyz = ";
	str.append(to_string(v.get_Iyz()));
	str.append("     Munit - Lunit ^ 2");
	this->writefile(str);
	//	Izx = -897.0030     Munit - Lunit ^ 2
	str = "Izx = ";
	str.append(to_string(v.get_Izx()));
	str.append("     Munit - Lunit ^ 2");
	this->writefile(str);
	//	visc CL_a = 0.00000
	str = "visc CL_a = 0.00000";
	this->writefile(str);
	//	visc CL_u = 0.00000
	str = "visc CL_u = 0.00000";
	this->writefile(str);
	//	visc CM_a = 0.00000
	str = "visc CM_a = 0.00000";
	this->writefile(str);
	//	visc CM_u = 0.00000
	str = "visc CM_u = 0.00000";
	this->writefile(str);
		
	///
	this->finish_file();
}

void file_oper::build_avl(string filepath)
{
}

FILE* file_oper::get_file_point(void)
{
	return file;
}
