#include "Datast.h"
Flight::Datast::Datast()
{
	alpha = 0;
	CL = CD = Cm = 0;
	CLa = CDa = Cma = 0;
	CYb = Clb = Cnb = 0;
	CYp = Clp = Cnp = 0;
	CLq = Cmq = 0;
	CYr = Clr = Cnr = 0;
	Cmadot = 0;
}

Flight::Datast::Datast(std::string input)
{
	Readfromavloutput(input);
}

void Flight::Datast::Readfromavloutput(std::string input)
{
	std::ifstream file;
	std::string str,temp;
	file.open(input);
	while (getline(file,str))
	{
		if (str.find("Alpha = ") != std::string::npos)
		{
			temp.assign(str,str.find("Alpha =") + 7,10);
			std::stringstream iss(temp);
			iss >> alpha; 
			//std::cout << alpha << std::endl;
		}
		if ((str.find("elevator") != std::string::npos)&&(str.find("=")!=std::string::npos))
		{
			temp.assign(str, str.find("=") + 3,10);
			std::stringstream iss(temp);
			iss >> elevator;
			//std::cout << elevator << std::endl;
		}
		if (str.find("CLtot =") != std::string::npos)
		{
			temp.assign(str, str.find("CLtot =") + 7,10);
			std::stringstream iss(temp);
			iss >> CL;
			//std::cout << CL << std::endl;
		}
		if (str.find("CDtot =") != std::string::npos)
		{
			temp.assign(str, str.find("CDtot =") + 7, 10);
			std::stringstream iss(temp);
			iss >> CD;
			//std::cout << CD << std::endl;
		}
		if (str.find("Cmtot =") != std::string::npos)
		{
			temp.assign(str, str.find("Cmtot =") + 7,10);
			std::stringstream iss(temp);
			iss >> Cm;
			//std::cout << Cm << std::endl;
		}
		if (str.find("CLa =") != std::string::npos)
		{
			temp.assign(str, str.find("CLa =") + 5, 11);
			std::stringstream iss(temp);
			iss >> CLa;
			//std::cout << CLa << std::endl;
		}
		if (str.find("Cma =") != std::string::npos)
		{
			temp.assign(str, str.find("Cma =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Cma;
			//std::cout << Cma << std::endl;
		}
		if (str.find("CYb =") != std::string::npos)
		{
			temp.assign(str, str.find("CYb =") + 5, 11);
			std::stringstream iss(temp);
			iss >> CYb;
			//std::cout << CYb << std::endl;
		}
		if (str.find("Clb =") != std::string::npos)
		{
			temp.assign(str, str.find("Clb =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Clb;
			//std::cout << Clb << std::endl;
		}
		if ((str.find("Cnb =") != std::string::npos) && (str.find("Cna =") != std::string::npos))
		{
			temp.assign(str, str.find("Cnb =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Cnb;
		//	std::cout << Cnb << std::endl;
		}
		if (str.find("CYp =") != std::string::npos)
		{
			temp.assign(str, str.find("CYp =") + 5, 11);
			std::stringstream iss(temp);
			iss >> CYp;
			//std::cout << CYp << std::endl;
		}
		if (str.find("Clp =") != std::string::npos)
		{
			temp.assign(str, str.find("Clp =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Clp;
			//std::cout << Clp << std::endl;
		}
		if (str.find("Cnp =") != std::string::npos)
		{
			temp.assign(str, str.find("Cnp =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Cnp;
			//std::cout << Cnp << std::endl;
		}
		if (str.find("CYr =") != std::string::npos)
		{
			temp.assign(str, str.find("CYr =") + 5, 11);
			std::stringstream iss(temp);
			iss >> CYr;
			//std::cout << CYr << std::endl;
		}
		if (str.find("Clr =") != std::string::npos)
		{
			temp.assign(str, str.find("Clr =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Clr;
			//std::cout << Clr << std::endl;
		}
		if (str.find("Cnr =") != std::string::npos)
		{
			temp.assign(str, str.find("Cnr =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Cnr;
			//std::cout << Cnr << std::endl;
		}
		if (str.find("CLq =") != std::string::npos)
		{
			temp.assign(str, str.find("CLq =") + 5, 11);
			std::stringstream iss(temp);
			iss >> CLq;
			//std::cout << CLq << std::endl;
		}
		if (str.find("Cmq =") != std::string::npos)
		{
			temp.assign(str, str.find("Cmq =") + 5, 11);
			std::stringstream iss(temp);
			iss >> Cmq;
			//std::cout << Cmq << std::endl;
		}
		
	}
	file.close();
}
	/*f
		if contains(update, 'CLa =')
			datast.CLa = str2num(update(strfind(update, 'CLa =') + 5:strfind(update, 'CLa =') + 15));
	end
		if contains(update, 'Cma =')
			datast.Cma = str2num(update(strfind(update, 'Cma =') + 5:strfind(update, 'Cma =') + 15));
	end
		if contains(update, 'CYb =')
			datast.CYb = str2num(update(strfind(update, 'CYb =') + 5:end));
	end
		if contains(update, 'Clb =')
			datast.Clb = str2num(update(strfind(update, 'Clb =') + 5:end));
	end
		if contains(update, 'Cnb =')
			if contains(update, 'Cna = ')
				datast.Cnb = str2num(update(strfind(update, 'Cnb =') + 5:end));
	end
		end
		if contains(update, 'CYp =')
			datast.CYp = str2num(update(strfind(update, 'CYp =') + 5:strfind(update, 'CYp =') + 15));
	end
		if contains(update, 'Clp =')
			datast.Clp = str2num(update(strfind(update, 'Clp =') + 5:strfind(update, 'Clp =') + 15));
	end
		if contains(update, 'Cnp =')
			datast.Cnp = str2num(update(strfind(update, 'Cnp =') + 5:strfind(update, 'Cnp =') + 15));
	end
		if contains(update, 'CLq =')
			datast.CLq = str2num(update(strfind(update, 'CLq =') + 5:strfind(update, 'CLq =') + 15));
	end
		if contains(update, 'Cmq =')
			datast.Cmq = str2num(update(strfind(update, 'Cmq =') + 5:strfind(update, 'Cmq =') + 15));
	end
		if contains(update, 'CYr =')
			datast.CYr = str2num(update(strfind(update, 'CYr =') + 5:end));
	end
		if contains(update, 'Clr =')
			datast.Clr = str2num(update(strfind(update, 'Clr =') + 5:end));
	end
		if contains(update, 'Cnr =')
			datast.Cnr = str2num(update(strfind(update, 'Cnr =') + 5:end));
	end
		% d1Îª¸±Òí
		% if contains(update, 'Cld1 =')
		% datast.Cld1 = str2num(update(strfind(update, 'Cld1 =') + 6:strfind(update, 'Cld1 =') + 17));
	% end
		% if contains(update, 'Cnd1 =')
		% datast.Cnd1 = str2num(update(strfind(update, 'Cnd1 =') + 6:strfind(update, 'Cnd1 =') + 17));
	% end
		% d2ÎªÉý½µ¶æ
		if contains(update, 'CLd1 =')
			datast.CLd1 = str2num(update(strfind(update, 'CLd1 =') + 7:strfind(update, 'CLd1 =') + 16));
	end
		if contains(update, 'Cmd1 =')
			datast.Cmd1 = str2num(update(strfind(update, 'Cmd1 =') + 7:strfind(update, 'Cmd1 =') + 16));
	end
		end
		fclose(fid);
	end

}*/

bool Flight::Datast::Readfromkeyboard()
{
	double temp;
	std::cerr << "alpha" << std::endl;
	std::cin >> temp ;
	Set_alpha(temp);
	std::cerr << "CL" << std::endl;
	std::cin >> temp;
	Set_CL(temp);
	std::cerr << "CD" << std::endl;
	std::cin >> temp;
	Set_CD(temp);
	std::cerr << "Cm" << std::endl;
	std::cin >> temp;
	Set_Cm(temp);
	std::cerr << "CLa" << std::endl;
	std::cin >> temp;
	Set_CLa(temp);
	std::cerr << "CDa" << std::endl;
	std::cin >> temp;
	Set_CDa(temp);
	std::cerr << "Cma" << std::endl;
	std::cin >> temp;
	Set_Cma(temp);
	std::cerr << "CYb" << std::endl;
	std::cin >> temp;
	Set_CYb(temp);
	std::cerr << "Clb" << std::endl;
	std::cin >> temp;
	Set_Clb(temp);
	std::cerr << "Cnb" << std::endl;
	std::cin >> temp;
	Set_Cnb(temp);
	std::cerr << "CYp" << std::endl;
	std::cin >> temp;
	Set_CYp(temp);
	std::cerr << "Clp" << std::endl;	
	std::cin >> temp;
	Set_Clp(temp);
	std::cerr << "Cnp" << std::endl;
	std::cin >> temp;
	Set_Cnp(temp);
	std::cerr << "CLq" << std::endl;
	std::cin >> temp;
	Set_CLq(temp);
	std::cerr << "Cmq" << std::endl;
	std::cin >> temp;
	Set_Cmq(temp);
	std::cerr << "CYr" << std::endl;
	std::cin >> temp;
	Set_CYr(temp);
	std::cerr << "Clr" << std::endl;
	std::cin >> temp;
	Set_Clr(temp);
	std::cerr << "Cnr" << std::endl;
	std::cin >> temp;
	Set_Cnr(temp);
	std::cerr << "Cmadot" << std::endl;
	std::cin >> temp ;
	Set_Cmadot(temp);
	return true;
}
