/*
	Name: ANTHinsyOOP oR ANTHinsyOOP.hpp
	Copyright: ANT Technoloy Training Center
	Author: Mr. Uon Hinsy ( FB: Hinsy Lasong , Telegram: @HinsyLasong )
	Date: 09/08/24 09:08PM
	Description: this header file describe about create own input methods, C++ File I/O and others design console as namespace & C++ OOP Style
*/
#ifndef ____INC_ANTHINSYOOP_HPP____ 
#define ____INC_ANTHINSYOOP_HPP____ 
//////////////////////////////////////////////////////////////////////////////////
#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif
//------------------------------------
#include<windows.h>
#include<cstdlib>// Covert char array to number: atoi, atof, atod...
#include<string>// Covert std::string to number: stoi, stof, stod...
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cstring>// strlen, strcmp, strcpy, strcnpy,...
#include<cctype>
#include<ctime>
#include<cstdio>
#include<conio.h>
#include<iomanip>
#include <sys/stat.h> 
#include <regex> // Regular Expression
using namespace std;
//------------------------------------------------------------------------------------------------------------
namespace ANTHinsyOOP /* Start of Namespace */
{
	class DLLIMPORT HConsole {
		public:
			HConsole() = default;
			virtual ~HConsole() = default;
			static void setcolor(DWORD color_code);
			static void gotoxy(int x, int y);
			static void delay(int milliseconds);
			static void setcursor(bool visible, DWORD size);
			static void cls();
			static void drawBoxDoubleLine(int x, int y, int w, int h, int color = 7);
			static void drawBoxSingleLine(int x, int y, int w, int h, int color = 7);
			static void drawBoxSingleLineWithBG(int x, int y, int w, int h, int color);
			static void drawBoxDoubleLineWithBG(int x, int y, int w, int h, int color);
			static void HLine(int x, int y, int w, int color = 7, int line = 196);//widht
			static void VLine(int x, int y, int h, int color = 7, int line = 179);//Height
			static void clearBox(int x, int y, int w, int h, int color = 7);
			static string formatCurrency(const long double&  currency, const unsigned int& precision = 6);
			static long double eraseFormatCurrency(const string&  currency);
	};
	//------------------------------------
	class DLLIMPORT HDate {
		protected:
			static bool isValidDate(char* date);
			static bool isCurrentDate(char* date);
			static bool isValidDate(string& date);
			static bool isCurrentDate(string& date);
		public:
			HDate() = default;
			virtual ~HDate() = default;
			
	};
	//------------------------------------
	class DLLIMPORT Hinput {
		protected:
			// #              Overloading
			// Char Array 
			static char* inputAll(char* charArray);
			static char* inputNumber(char* charArray);
			static char* inputLetter(char* charArray);
			static char* inputPasswordMask(char* charArray);
			static char* input4Tel(char* charArray);
			static char* inputUNumber(char* charArray);
			static char* inputEmail(char* charArray);
			static char* inputDate(char* charArray);
			static char* inputDate(char* charArray, char sign);
			
		    //  std::string 
		    static string inputAll(string&  std_string);
		    static string inputNumber(string&  std_string);
		    static string inputLetter(string&  std_string);
			static string inputPasswordMask(string&  std_string);
			static string input4Tel(string&  std_string);
			static string inputUNumber(string&  std_string);
			static string inputEmail(string&  std_string);
			static string inputDate(string&  std_string);
			static string inputDate(string&  std_string, char sign);
			//#                 
			// Char Array
			static char* inputAll(char* charArray, UINT16 size);
			static char* inputNumber(char* charArray, UINT16 size);
			static char* inputLetter(char* charArray, UINT16 size);
			static char* inputPasswordMask(char* charArray, UINT16 size);
			static char* input4Tel(char* charArray, UINT16 size);
			static char* inputUNumber(char* charArray,  UINT16 size);
			static char* inputEmail(char* charArray,  UINT16 size);
			static char* inputPasswordMaskMin8(char* charArray, UINT16 size);
			
			
		    //  std::string
		    static string inputAll(string&  std_string, UINT16 size);
		    static string inputNumber(string&  std_string, UINT16 size);
		    static string inputLetter(string&  std_string, UINT16 size);
			static string inputPasswordMask(string&  std_string, UINT16 size);
			static string input4Tel(string&  std_string, UINT16 size);
			static string inputUNumber(string&  std_string,  UINT16 size);
			static string inputEmail(string&  std_string,  UINT16 size);
			static string inputPasswordMaskMin8(string&  std_string, UINT16 size);
		public:
			Hinput() = default;
			virtual ~Hinput() = default;			
	};
	//------------------------------------
	class DLLIMPORT HLVInput: private Hinput, private HDate
	{
		public:
			//                 Overriding
			// Char Array
			static char* inputAll(char* charArray);
			static char* inputNumber(char* charArray);
			static char* inputLetter(char* charArray);
			static char* inputPasswordMask(char* charArray);
			static char* input4Tel(char* charArray);
			static char* inputUNumber(char* charArray);
			static char* inputEmail(char* charArray);
			//                 Overloading
			static char* inputDate(char* charArray, bool isAfterCurrentDate = false);//format DD-MM-YYYY or DD/MM/YYYY or DD.MM.YYYY
			static char* inputDate(char* charArray, char sign, bool isAfterCurrentDate = false);//format DD-MM-YYYY or DD/MM/YYYY or DD.MM.YYYY
			//                 Overriding
		    //  std::string
		    static string inputAll(string&  std_string);
		    static string inputNumber(string&  std_string);
		    static string inputLetter(string&  std_string);
			static string inputPasswordMask(string&  std_string);
			static string input4Tel(string&  std_string);
			static string inputUNumber(string&  charArray);
			static string inputEmail(string&  charArray);
			//                 Overloading
			static string inputDate(string&  std_string, bool isAfterCurrentDate = false);//format DD-MM-YYYY or DD/MM/YYYY or DD.MM.YYYY
			static string inputDate(string&  std_string, char sign, bool isAfterCurrentDate = false);//format DD-MM-YYYY or DD/MM/YYYY or DD.MM.YYYY
			
			//                 Overriding
			//#                 
			// Char Array
			static char* inputAll(char* charArray, UINT16 size);
			static char* inputNumber(char* charArray, UINT16 size);
			static char* inputLetter(char* charArray, UINT16 size);
			static char* inputPasswordMask(char* charArray, UINT16 size);
			static char* input4Tel(char* charArray, UINT16 size);
			static char* inputUNumber(char* charArray,  UINT16 size);
			static char* inputEmail(char* charArray,  UINT16 size);
		    static char* inputPasswordMaskMin8(char* charArray, UINT16 size);//Password minimum length should be 8. At least one uppercase letter, one lowercase letter, one digits, and one special character
			//  std::string
		    static string inputAll(string&  std_string, UINT16 size);
		    static string inputNumber(string&  std_string, UINT16 size);
		    static string inputLetter(string&  std_string, UINT16 size);
			static string inputPasswordMask(string&  std_string, UINT16 size);
			static string input4Tel(string&  std_string, UINT16 size);
			static string inputUNumber(string&  std_string,  UINT16 size);
			static string inputEmail(string&  std_string,  UINT16 size);
			static string inputPasswordMaskMin8(string&  std_string, UINT16 size);//Password minimum length should be 8. At least one uppercase letter, one lowercase letter, one digits, and one special character		
			// Add New Feature 15-July-2025            
			static char* inputNumber(char* charArray, UINT16 size, bool isDecimalPoint);// false for integral, true for double or float
			static char* inputUNumber(char* charArray,  UINT16 size, bool isDecimalPoint);// false for integral, true for double or float
			static string inputNumber(string&  std_string, UINT16 size, bool isDecimalPoint);// false for integral, true for double or float
			static string inputUNumber(string&  std_string,  UINT16 size, bool isDecimalPoint);// false for integral, true for double or float
	};
	//------------------------------------
	class DLLIMPORT DisableWindowsConsole
    {
        public:
        	DisableWindowsConsole() = default;
			virtual ~DisableWindowsConsole() = default;
            static void DisableButtonMaximized();
            static void DisableButtonMinimized();
			static void DisableButtonClose();

    }; 
	//------------------------------------
	class DLLIMPORT Hinsy: public HConsole, public HLVInput, public DisableWindowsConsole{
		public:
			static void setFont(UINT hFontSize, UINT fontWeight = FW_BOLD, const WCHAR* fontName = L"Consolas", bool bMaximumWindow = false);
			static void setFullScreenHaveScroll(UINT height = 9001, UINT width = 700);
			static void setFullScreenNoScroll();
			static void setFixedScreenConsole(UINT width, UINT height);
			static void DisableScreenResize();
				
	};
	// Add: 05-Aug-2025
	class DLLIMPORT HNewFeature: public Hinsy {
		public:
			static void Clear();
			static void ClearXY(int x, int y, int lengthToClear);
            static void DrawBoxBG(int x, int y, int w, int h, int BgColor = 150);
			static void ShowMenu(int x, int y, string menus[], int sizeMenus, int color = 3, int indexShowSymbol = 0, string textSymbol = "==> ");	
	};
	//------------------------------------
	class DLLIMPORT H: public HNewFeature {
		public:
			static void setConsoleTitle(LPCTSTR  title); // Assign value by function  TEXT("")  ignore warning
			static void foreColor(DWORD color_code);
	};
	//------------------------------------
	template<class DF>class DLLIMPORT HFile {
		public:
			HFile() = default;
			virtual ~HFile() = default;
			static vector<DF>& readFBin(const string& fileName, const string& subFolder = "Sub_Data", const string& mainFolder = "App_Data");
			static void writeFBin(DF& data, const string& fileName, const string& subFolder = "Sub_Data", const string& mainFolder = "App_Data");
			static void writeFBin(vector<DF>& vData, const string& fileName, const string& subFolder = "Sub_Data", const string& mainFolder = "App_Data");
	};
	//------------------------------------
	template<typename DF>class DLLIMPORT HAutoID {
		protected:
			int autoID;
		public:
			HAutoID() = default;
			virtual ~HAutoID() = default;
			int findHighestIDNumber(const string& fileName, const string& subFolder = "Sub_Data", const string& mainFolder = "App_Data");
	
	};
	
}/* end of Namespace */
//------------------------------------------------------------------------------------------------------------
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	template<class DF>vector<DF>& ANTHinsyOOP::HFile<DF>::readFBin(const string& fileName, const string& subFolder, const string& mainFolder)
	{
		string path = mainFolder + "/" + subFolder + "/" + fileName;
		
		fstream file(path, ios::in | ios::binary);
		vector<DF> vData; DF tempData; 
	
	    if (file.is_open())
	    {
	        vData.clear();
	        while(file.read((char*)&tempData, sizeof(DF)))
	        {
	            vData.push_back(tempData);
	        }
	    }
	    else cout << "\n\n\t\t\t File  was not found!\n";
	       
	    // close file stream
	    file.close();
	  
	    return vData;
	}
	template<class DF>void ANTHinsyOOP::HFile<DF>::writeFBin(DF& data, const string& fileName, const string& subFolder,  const string& mainFolder)
	{
	    // Structure which would store the meta data
	    struct stat sb; 
		string sub_dir = mainFolder + "/" + subFolder + "/";
	  
	    if(stat(mainFolder.c_str(), &sb) != 0)
	    {
	    	//cout << "\nThe Main Path is not exist!!";
	    	// Create Main Folder
	    	mkdir(mainFolder.c_str());
	    	
	    	if(stat(sub_dir.c_str(), &sb) != 0)
	    	{
	    		//cout << "\n\tThe Sub Path is not exist!!";
	    		// Create Sub Folder
	    		mkdir(sub_dir.c_str());
			}
		} 
		else
		{
			//cout << "\nThe Main Path is exist!!";
			if(stat(sub_dir.c_str(), &sb) != 0)
	    	{
	    		//cout << "\n\tThe Sub Path is not exist!!";
	    		// Create Sub Folder
	    		mkdir(sub_dir.c_str());
			}
		}	
		string path = mainFolder + "/" + subFolder + "/" + fileName; 
		fstream file(path, ios::out | ios::app | ios::binary);
		
		if (file.is_open())
		{
			file.write((char*)&data, sizeof(DF));
		}
	    else cout << "\n\n\t\t\t File  was not found!\n";
	       
	    // close file stream
	    file.close();	
	}
	template<class DF>void ANTHinsyOOP::HFile<DF>::writeFBin(vector<DF>& vData, const string& fileName,  const string& subFolder, const string& mainFolder)
	{
		    // Structure which would store the meta data
	    struct stat sb; 
		string sub_dir = mainFolder + "/" + subFolder + "/";
	  
	    if(stat(mainFolder.c_str(), &sb) != 0)
	    {
	    	//cout << "\nThe Main Path is not exist!!";
	    	// Create Main Folder
	    	mkdir(mainFolder.c_str());
	    	
	    	if(stat(sub_dir.c_str(), &sb) != 0)
	    	{
	    		//cout << "\n\tThe Sub Path is not exist!!";
	    		// Create Sub Folder
	    		mkdir(sub_dir.c_str());
			}
		} 
		else
		{
			//cout << "\nThe Main Path is exist!!";
			if(stat(sub_dir.c_str(), &sb) != 0)
	    	{
	    		//cout << "\n\tThe Sub Path is not exist!!";
	    		// Create Sub Folder
	    		mkdir(sub_dir.c_str());
			}
		}
		string path = mainFolder + "/" + subFolder + "/" + fileName; 
		fstream file(path, ios::out | ios::binary);
		
		if (file.is_open())
		{
			for(int i = 0; i<vData.size(); i++)
			{
				file.write((char*)&vData[i], sizeof(DF));
			}
			
		}
		else cout << "\n\n\t\t\t File  was not found!\n";
	       
	    // close file stream
	    file.close();		
	}
	
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template<typename DF>int ANTHinsyOOP::HAutoID<DF>::findHighestIDNumber(const string& fileName, const string& subFolder, const string& mainFolder)
{
	string path = mainFolder + "/" + subFolder + "/" + fileName;
	DF tempData;
    int highestIDNumber = 0;
    
    ifstream file(path, ios::in | ios::binary);

    if (!file.is_open()) highestIDNumber = 0;
    
    while(file.read((char*)&tempData, sizeof(DF)))
	{
        if(tempData.autoID > highestIDNumber) 
		{
            highestIDNumber = tempData.autoID;
        }
    }
	// close file stream
    file.close();

    return highestIDNumber;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//----------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
#endif/* end of Header File ANTHinsyOOP oR ANTHinsyOOP.hpp */
