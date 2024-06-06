#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
class admission{
	protected:
		string name;
		string fname;
		string gender;
		string address;
		string pnumber;
		string password;
		int age;
		string CNIC;
		string date;
		string collegename;
		int marks;
		int passing;
		string sname;
		string spnumber;
		string spassword;
		int sage;
		string sCNIC;
		int smarks;
		int spassing;
		int choice;
		long random;
		long srandom;
		char choic;
		public:
			void home();
			void menu();
			void form();
			void status();
			void test();
			void paper();
			void show();
			void admin();
			void admins();
			void privious();
			void nextmenu();
			void showresult();
			void findmerit();
};
void admission::home(){
	system("cls");
	cout<<"\n\n";
	cout<<"\t 1: Work as an Admin "<<endl;
	cout<<"\t 2: Open as Student "<<"\n\t ";
	cin>>choice;
	if(choice==1){
		cout<<"\t This is not working right now || Sorry "<<endl;
		system("pause");
		home();
	}
	else if(choice==2){
		menu();
	}
}
//this is all about the admin informations
void admission::admin(){
	system("cls");
	cout<<"\n\n";
	cout<<"\t 1: Add new Admin "<<endl;
	cout<<"\t 2: Privious Admin "<<endl;
	cout<<"\t ";
	cin>>choice;
	if(choice==1){
		admins();
	}
	else if(choice==2){
		privious();
	}
}
void admission::admins(){
	cin.ignore();
	system("cls");
	cout<<"\n\n";
	cout<<"\t Enter the CNIC : ";
	getline(cin,CNIC);
	cout<<"\n";
	cout<<"\t Enter the password : ";
	getline(cin,password);
	cout<<"\n";
	string filetype=CNIC+".txt";
	ofstream offsfile;
	ifstream iffsfile;
	iffsfile.open(filetype.c_str());
	string existingUsername;
    while(iffsfile>>existingUsername){
        if(CNIC==existingUsername){
            cout<<"\t Admin already exists"<<"\n\n";
            cout<<"\t ";
            system("pause");
            iffsfile.close();
            admin();
        }
    }
	offsfile.open(filetype.c_str());
	if(!offsfile){
		cout<<"\t File not Found "<<"\n\t ";
		system("pause");
		admin();
	}
	offsfile<<CNIC<<endl;
	offsfile<<password<<endl;
	offsfile.close();
	admin();
}
void admission::privious(){
	cin.ignore();
	system("cls");
	cout<<"\n\n";
	cout<<"\t Enter your CNIC : ";
	getline(cin,CNIC);
	cout<<"\n ";
	cout<<"\t Enter your password : ";
	getline(cin,password);
	ifstream iffsfile;
	string typefile=CNIC+".txt";
	iffsfile.open(typefile.c_str());
	if(!iffsfile){
		cout<<"\t File not Found "<<"\n\t ";
		system("pause");
		admin();
	}
	iffsfile>>sCNIC;
	iffsfile>>spassword;
	if(CNIC==sCNIC&&password==spassword){
		cout<<"\t Login Successful "<<endl;
		iffsfile.close();
		cout<<"\t ";
		system("pause");
		nextmenu();
	}
}
void admission::nextmenu(){
	system("cls");
	cout<<"\n\n";
	cout<<"\t 1: Show All Students Result "<<endl;
	cout<<"\t 2: Find Student Merit "<<endl;
	cout<<"\t ";
	cin>>choice;
	switch(choice){
		case 1:
			showresult();
			break;
			case 2:
				findmerit();
				break;
				default:
					cout<<"\t Enter a valid input "<<endl;
					break;
	}
	nextmenu();
}
void admission::showresult(){
	cin.ignore();
	system("cls");
	cout<<"\n\n";
	ifstream meritfile;
	meritfile.open("merit.txt");
	string meritlist;
	while(getline(meritfile,meritlist)){
		cout<<"\t "<<meritlist<<endl;
	}
	meritfile.close();
	cout<<"\t ";
	system("pause");
}
void admission::findmerit(){
	cin.ignore();
	system("cls");
	cout<<"\n\n";
	cout<<"\t Enter the CNIC of Student : ";
	getline(cin,CNIC);
	string studentlist;
	ifstream findmeritstudent;
	findmeritstudent.open("merit.txt");
	while(getline(findmeritstudent,studentlist)){
		if(studentlist.find(CNIC)!=string::npos){
			cout<<"\t "<<studentlist<<endl;
		}
	}
	findmeritstudent.close();
	cout<<"\t ";
	system("pause");
}
//main menu of our project
//this is all about the student informations and merits etc
void admission::menu(){
	system("cls");
	cout<<"\n\n";
	cout<<"\t 1: Register Yourself "<<endl;
	cout<<"\t 2: Check Your Application Status "<<endl;
	cout<<"\t 3: Start Test "<<endl;
	cout<<"\t 4: Check Your Position Merit "<<endl;
	cout<<"\t 5: Exit Program "<<endl;
	cout<<"\t ";
	cin>>choice;
	switch(choice){
		case 1:
			form();
			break;
			case 2:
				status();
				cout<<"\t ";
				system("pause");
				break;
				case 3:
					test();
					case 4:
						show();
						break;
						case 5:
							exit(0);
							break;
							default:
								cout<<"\t ";
								system("pause");
								cout<<"Enter a valid input "<<endl;
								break;
	}
	menu();
}
//fill the form by user as online
void admission::form(){
	system("cls");
	cin.ignore();
	cout<<"\n\n";
	cout<<"\t Enter your Name : ";
	getline(cin,name);
	cout<<"\n ";
	cout<<"\t Enter your Father Name : ";
	getline(cin,fname);
	cout<<"\n";
	cout<<"\t Enter your Gender : ";
	getline(cin,gender);
	cout<<"\n";
	cout<<"\t Enter your Address : ";
	getline(cin,address);
	cout<<"\n";
	cout<<"\t Enter your Age : ";
	cin>>age;
	cin.ignore();
	label3:
	cout<<"\n";
	cout<<"\t Enter your CNIC : ";
	getline(cin,CNIC);
	if(CNIC.length()<13||CNIC.length()>13){
		cout<<"\n";
		cout<<"\t CNIC Is Not Correct "<<endl;
		goto label3;
	}
	string filetype=CNIC+".txt";
	ifstream iffsfile;
	iffsfile.open(filetype.c_str());
	string existingUsername;
    while(iffsfile>>existingUsername){
        if(CNIC==existingUsername){
            cout<<"\n";
            cout<<"\t Student already exists"<<"\n\n";
            iffsfile.close();
            goto label3;
        }
    }
	label2:
	cout<<"\n";
	cout<<"\t Enter your Password : ";
	getline(cin,password);
	if(password.length()>8||password.length()<8){
		cout<<"\n";
		cout<<"\t Password Is Not Strong"<<endl;
		goto label2;
	}
	if(password.find(' ')!=string::npos){
		cout<<"\n";
    	cout<<"\t Password Is Not Strong "<<endl;
    	goto label2;
	}
	bool hasdigit=false;
	bool hasalpha=false;
	for(size_t i=0;i<password.length();i++){
    	if(isdigit(password[i])){
        	hasdigit=true;
    	}
		else if(isalpha(password[i])){
        	hasalpha=true;
    	}
	}
	if (!hasdigit||!hasalpha){
		cout<<"\n";
	    cout<<"\t Password Is Not Strong"<<endl;
	    goto label2;
	}
	label1:
	cout<<"\n";
	cout<<"\t Enter your Phone Number : ";
	getline(cin,pnumber);
	cout<<"\n";
	if(pnumber.length()<11||pnumber.length()>11){
		cout<<"\t Phone Number Length Is Not 11"<<endl;
		goto label1;
	}
	cout<<"\t Enter your Date Of Birth : ";
	getline(cin,date);
	cout<<"\n";
	cout<<"\t Enter your College Name : ";
	getline(cin,collegename);
	cout<<"\n";
	cout<<"\t Enter your Marks in FSc : ";
	cin>>marks;
	cout<<"\n";
	cout<<"\t Enter your Passing Year : ";
	cin>>passing;
	cout<<"\n";
	random=rand()%123456+marks+age+passing+236514;
	cout<<"\t Your Login Number : "<<random<<endl;
	cout<<"\n";
	cout<<"\t You want to submit your application (y/n) ";
	cin>>choic;
	cout<<"\n";
	if(choic=='y'||choic=='Y'){
//Apprrove or not
	cout<<"\t Registration Successful "<<"\n\n";
	cout<<"\t Wait For Approving Your Application "<<endl;
//	file opening
	ofstream outfile;
	string filename=CNIC+".txt";
	outfile.open(filename.c_str());
	outfile<<CNIC<<endl;
	outfile<<password<<endl;
	outfile<<name<<endl;
	outfile<<fname<<endl;
	outfile<<gender<<endl;
	outfile<<address<<endl;
	outfile<<age<<endl;
	if(age<17){
		outfile<<"Age Issue ---------"<<endl;
	}
	outfile<<pnumber<<endl;
	outfile<<random<<endl;
	outfile<<date<<endl;
	outfile<<collegename<<endl;
	outfile<<marks<<endl;
	if(marks<950){
		outfile<<"Marks Issue ---------"<<endl;
	}
	outfile<<passing<<endl;
	if(passing<2018||passing>2022){
		outfile<<"passing Year Issue ---------"<<endl;
	}
	outfile.close();
	cout<<"\n\t ";
	system("pause");
}
	else{
		cout<<"\t Your application are cleared "<<endl;
	cout<<"\n\t ";
	system("pause");
	}	
}
//Next Function is checking status
void admission::status(){
	system("cls");
	cin.ignore();
	cout<<"\n\n";
	cout<<"\t Enter your CNIC : ";
	getline(cin,CNIC);
	cout<<"\n";
	string file=CNIC+".txt";
	ifstream infile;
	infile.open(file.c_str());
	if(!infile){
		cout<<"\t File Not Found"<<endl;
		cout<<"\t ";
		system("pause");
		menu();
	}
	cout<<"\t File Found "<<endl;
	string line;
	while(getline(infile,line)){
		cout<<"\t "<<line<<endl;
	}
	infile.close();
	infile.open(file.c_str());
	string searchString = "---------"; // Replace with the string you want to find
    string innline;
    int lineNumber = 1;
    bool stringfound=false;
    while(getline(infile,innline)){
        if(innline.find(searchString)!=string::npos){
            cout<<"\t String'"<<searchString<<"' found at line "<<lineNumber<<endl;
            stringfound=true;
            break;
        }
        lineNumber++;
    }
    infile.close();
    if(stringfound){
    	cout<<"\t Your file is deleted "<<endl;
    	remove(file.c_str());
	}
	else{
		cout<<"\t Your Application Is Approved "<<endl;
	}
}
//conduct the test of selected student who are submit their form
void admission::test(){
	system("cls");
	int count=0;
	int add=0;
	int countt=0;
	int sum=0;
	int plus=0;
	int total=0;
	cin.ignore();
	cout<<"\n\n";
	cout<<"\t Enter your CNIC : ";
	getline(cin,CNIC);
	cout<<"\n";
	cout<<"\t Enter your Password : ";
	getline(cin,password);
	string filena=CNIC+".txt";
	ifstream infile;
	infile.open(filena.c_str());
	if(!infile){
		cout<<"\t File not Found "<<"\n\t ";
		system("pause");
		menu();
	}
	ifstream ifile;
	ifile.open("test.txt");
	string iline;
	bool found=false;
	while(getline(ifile,iline)){
		if(iline.find(CNIC)!=string::npos){
			cout<<"\n";
			cout<<"\t You already take that quiz "<<endl;
			ifile.close();
			cout<<"\t ";
			system("pause");
			menu();
		}
	}
	infile>>sCNIC;
	infile>>spassword;
	if(CNIC==sCNIC&&password==spassword){
		cout<<"\t File Found "<<endl;
		infile.close();
//if user not first check their status
		ifstream ifi;
		ifi.open(filena.c_str());
		string found= "---------";
	    string ine;
	    bool stringfound=false;
	    while(getline(ifi,ine)){
	        if(ine.find(found)!=string::npos){
	            cout<<"File having issue found"<<endl;
	            stringfound=true;
	            break;
	        }
	    }
	    ifi.close();
	    if(stringfound){
	    	cout<<"\t Your file is deleted "<<endl;
	    	remove(filena.c_str());
	    	cout<<"\t ";
	    	system("pause");
	    	menu();
		}
		cout<<"\t ";
		system("pause");
	//next function like joint
		system("cls");
		cout<<"\n\n";
		cout<<"\t Your paper is about MATHS,PHYSICS,CHEMISTRY,ENGLISH,PROGRAMMING questions "<<"\n\n";
		cout<<"\t 1: Start Paper"<<endl;
		cout<<"\t 2: Go Back"<<endl;
		cout<<"\t ";
		cin>>choice;
		if(choice==1){
			ofstream ofile;
			ofile.open("test.txt",ios::app);
			if(!ofile){
				system("pause");
				cout<<"\t File not Found "<<endl;
				menu();
			}
			ofile<<CNIC<<endl;
			ofile<<password<<endl;
			ofile.close();
			system("cls");
			cin.ignore();
			cout<<"\n\n";
			cout<<"\t Your First Paper Is MATHS "<<"\n\n";
		//1st M
			cout<<"\t 1: What is the derivative of f(x) = 3x^4 - 8x^2 + 2x + 7?  a"<<"\n\n";
			cout<<"\t a) 12x^3 - 16x + 2 \t\t b) 12x^3 - 16x^2 + 2"<<"\n\n";
			cout<<"\t c) 12x^3 - 16x + 2x + 7 \t d) 12x^3 - 16x^2 + 2x + 7"<<"\n\n\t ";
			cin>>choic;
			if(choic=='a'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//2nd M
			cout<<"\t 2: Which of the following is the Maclaurin series representation for e^x? d"<<"\n\n";
			cout<<"\t a) 1 + x + (x^2)/2! + (x^3)/3! + ... \t b) 1 + x + (x^2)/2! + (x^3)/3! + ..."<<"\n\n";
			cout<<"\t c) 1 + x + (x^2)/2! + (x^3)/3! + ... \t d) 1 + x + (x^2)/2! + (x^3)/3! + ..."<<"\n\n\t ";
			cin>>choic;
			if(choic=='d'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//3rd M
			cout<<"\t 3: In a right-angled triangle, the tangent of an angle is equal to 3/4.\n";
			cout<<"\t What is the value of the sine of the same angle? c"<<"\n\n";
			cout<<"\t a) 3/4 \t b) 4/3"<<"\n\n";
			cout<<"\t c) 3/5 \t d) 4/5"<<"\n\n\t ";
			cin>>choic;
			if(choic=='c'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//4th M
			cout<<"\t 4: What is the integral of ?(5x^3 + 2x^2 - 4x + 7) dx? a"<<"\n\n";
			cout<<"\t a) (5/4)x^4 + (2/3)x^3 - 2x^2 + 7x + C \t b) (5/4)x^4 + (2/3)x^3 - 2x + 7x + C"<<"\n\n";
			cout<<"\t c) (5/4)x^4 + (2/3)x^3 - 2x^2 + 7 + C \t\t d) (5/4)x^4 + (2/3)x^3 - 2x^2 + 7x + C"<<"\n\n\t ";
			cin>>choic;
			if(choic=='a'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//5th M
			cout<<"\t 5: What is the value of lim(x?8) (2x^3 - 5x^2 + 3) / (4x^3 - x + 2)? a"<<"\n\n";
			cout<<"\t a) 1/2 \t b) 2"<<"\n\n";
			cout<<"\t c) 4 \t\t d) Does not exist"<<"\n\n\t ";
			cin>>choic;
			if(choic=='a'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//6th M
			cout<<"\t 6: A particle moves along a straight line according to the equation x(t) = 4t^3 - 3t^2 + 2t + 1.\n";
			cout<<"\t What is its velocity at t = 2? c"<<"\n\n";
			cout<<"\t a) 40 \t\t  b) 48"<<"\n\n";
			cout<<"\t c) 52 \t\t  d) 56"<<"\n\n\t ";
			cin>>choic;
			if(choic=='c'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//7th M
			cout<<"\t 7: The graph of a function f(x) passes through the point (2, 5) and has a slope of 3 at that point.\n";
			cout<<"\t What is the equation of the tangent line at x = 2? b"<<"\n\n";
			cout<<"\t a) y = 3x + 2 \t b) y = 3x + 5"<<"\n\n";
			cout<<"\t c) y = 5x + 2 \t d) y = 5x + 3"<<"\n\n\t ";
			cin>>choic;
			if(choic=='b'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//8th M
			cout<<"\t 8: What is the complex conjugate of the number 4 - 2i? a"<<"\n\n";
			cout<<"\t a) 4 + 2i \t b) -4 - 2i"<<"\n\n";
			cout<<"\t c) -4 + 2i \t d) 2 - 4i"<<"\n\n\t ";
			cin>>choic;
			if(choic=='a'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//9th M
			cout<<"\t 9: Solve the equation log2(x^2 + 3x) = 4. d"<<"\n\n";
			cout<<"\t a) x = 1 \t b) x = -5"<<"\n\n";
			cout<<"\t c) x = 4 \t d) x = -3"<<"\n\n\t ";
			cin>>choic;
			if(choic=='d'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//10th M
			cout<<"\t 10: A box contains 5 red balls and 3 blue balls. If two balls are selected at random without replacement,\n";
			cout<<"\t what is the probability that both balls are red? b"<<"\n\n";
			cout<<"\t a) 1/14 \t b) 5/14"<<"\n\n";
			cout<<"\t c) 5/12 \t d) 2/3"<<"\n\n\t ";
			cin>>choic;
			if(choic=='b'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//11th M
			cout<<"\t 11: If f(x) = x^3 - 5x^2 + 8x + 2, what is the sum of the x-intercepts of the graph of f(x)? a"<<"\n\n";
			cout<<"\t a) 5 \t\t  b) 8"<<"\n\n";
			cout<<"\t c) -8 \t\t  d) -2"<<"\n\n\t ";
			cin>>choic;
			if(choic=='a'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//12th M
			cout<<"\t 12: The parametric equations x = t^2 + 3 and y = t - 1 represent a curve.\n";
			cout<<"\t What is the equation of the tangent line to the curve at the point (4, 2)? b"<<"\n\n";
			cout<<"\t a) y = -x + 6 \t b) y = x - 2"<<"\n\n";
			cout<<"\t c) y = 2x - 7 \t d) y = 3x - 10"<<"\n\n\t ";
			cin>>choic;
			if(choic=='b'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//13th M
			cout<<"\t 13: Find the value of ? in the equation 3cos(2? - p/4) = v2. a"<<"\n\n";
			cout<<"\t a) p/12 \t b) 3p/4"<<"\n\n";
			cout<<"\t c) 5p/4 \t d) 7p/12"<<"\n\n\t ";
			cin>>choic;
			if(choic=='a'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//14th M
			cout<<"\t 14: What is the area enclosed by the curves y = 2x^2 and y = x + 1? b"<<"\n\n";
			cout<<"\t a) 1/3 square units \t b) 1/2 square units"<<"\n\n";
			cout<<"\t c) 1 square unit \t d) 3 square units"<<"\n\n\t ";
			cin>>choic;
			if(choic=='b'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//15th M
			cout<<"\t 15: The vectors u = (2, -1) and v = (-3, 4) are given. What is the magnitude of u + v? b"<<"\n\n";
			cout<<"\t a) v2 \t\t  b) v5"<<"\n\n";
			cout<<"\t c) 2v2 \t d) 5v2"<<"\n\n\t ";
			cin>>choic;
			if(choic=='b'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//16th M
			cout<<"\t 16: Solve the equation sin^2(x) - 3sin(x) + 2 = 0 for 0 = x = 2p. c"<<"\n\n";
			cout<<"\t a) x = p/2 or 3p/2 \t b) x = p/4 or 3p/4"<<"\n\n";
			cout<<"\t c) x = p/6 or 5p/6 \t d) x = 0 or p"<<"\n\n\t ";
			cin>>choic;
			if(choic=='c'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//17th M
			cout<<"\t 17: A population grows according to the function P(t) = 500(1 + 0.02)^t, where t represents time in years.\n";
			cout<<"\t If the initial population is 500, what is the population after 10 years? c"<<"\n\n";
			cout<<"\t a) 510 \t b) 550"<<"\n\n";
			cout<<"\t c) 605 \t d) 650"<<"\n\n\t ";
			cin>>choic;
			if(choic=='c'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//18th M
			cout<<"\t 18: What is the determinant of the matrix [3 5; 2 4]? b"<<"\n\n";
			cout<<"\t a) -2 \t b) 2"<<"\n\n";
			cout<<"\t c) 8 \t d) 12"<<"\n\n\t ";
			cin>>choic;
			if(choic=='b'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//19th M
			cout<<"\t 19: If f(x) = x^3 - 2x^2 + 3x - 4 and g(x) = 2x + 1, what is the value of (f ° g)(-1)? d"<<"\n\n";
			cout<<"\t a) -2 \t b) -6"<<"\n\n";
			cout<<"\t c) -8 \t d) -10"<<"\n\n\t ";
			cin>>choic;
			if(choic=='d'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
		//20th M
			cout<<"\t 20: A right circular cone has a height of 12 cm and a slant height of 15 cm.\n";
			cout<<"\t What is the volume of the cone? b"<<"\n\n";
			cout<<"\t a) 180p cm³ \t b) 360p cm³"<<"\n\n";
			cout<<"\t c) 540p cm³ \t d) 720p cm³"<<"\n\n\t ";
			cin>>choic;
			if(choic=='b'){
				count++;
			}
			system("cls");
			cout<<"\n\n";
			cout<<"\t 1: Start next Subject paper "<<endl;
			cout<<"\t 2: End Paper "<<endl;
			cout<<"\t ";
			cin>>choice;
			if(choice==1){
				system("cls");
				cin.ignore();
				cout<<"\n\n";
				cout<<"\t Your Second Paper Is Physics "<<"\n\n";
		//1st P
				cout<<"\t 1: Which of the following best describes the law of conservation of energy? c"<<"\n\n";
				cout<<"\t a) Energy can be created but not destroyed. \t b) Energy can be destroyed but not created."<<"\n\n";
				cout<<"\t c) Energy cannot be created or destroyed. \t d) Energy can be both created and destroyed."<<"\n\n\t ";
				cin>>choic;
				if(choic=='c'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//2nd P
				cout<<"\t 2: Which of the following formulas represents Ohm's law? a"<<"\n\n";
				cout<<"\t a) V = IR \t b) P = VI"<<"\n\n";
				cout<<"\t c) F = ma \t d) W = mg"<<"\n\n\t ";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//3rd P
				cout<<"\t 3: When light travels from a medium with a higher refractive index to a medium with a lower\n";
				cout<<"\t refractive index, what happens to the speed and direction of the light? c"<<"\n\n";
				cout<<"\t a) Speed and direction increase. \t \t b) Speed and direction decrease."<<"\n\n";
				cout<<"\t c) Speed increases, direction stays the same. \t d) Speed decreases, direction changes."<<"\n\n\t ";
				cin>>choic;
				if(choic=='c'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//4th P
				cout<<"\t 4: Which of the following best describes the principle of superposition? b"<<"\n\n";
				cout<<"\t a) The total energy of an isolated system remains constant."<<"\n\n";
				cout<<"\t b) The displacement of a medium caused by two or more waves is the algebraic sum of their "<<"\n\n";
				cout<<"\t c) The frequency of a wave increases as the wavelength decreases."<<"\n\n";
				cout<<"\t d) The intensity of a wave decreases as the distance from the source increases."<<"\n\n\t ";
				cin>>choic;
				if(choic=='b'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//5th P
				cout<<"\t 5: Which of the following is an example of a vector quantity? d"<<"\n\n";
				cout<<"\t a) Temperature \t b) Speed"<<"\n\n";
				cout<<"\t c) Mass \t\t  d) Force"<<"\n\n\t ";
				cin>>choic;
				if(choic=='d'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//6th P
				cout<<"\t 6: Which of the following is true about the first law of thermodynamics? b"<<"\n\n";
				cout<<"\t a) Energy flows from a colder object to a hotter object."<<"\n\n";
				cout<<"\t b) The total energy of an isolated system remains constant."<<"\n\n";
				cout<<"\t c) Entropy of a system always decreases."<<"\n\n";
				cout<<"\t d) Work done by a system is always equal to the heat absorbed by the system."<<"\n\n\t ";
				cin>>choic;
				if(choic=='b'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//7th P
				cout<<"\t 7: Which of the following formulas represents the relationship between power, force, and velocity? b"<<"\n\n";
				cout<<"\t a) P = Fd \t b) P = Fv"<<"\n\n";
				cout<<"\t c) P = F/t \t d) P = Fv/t"<<"\n\n\t ";
				cin>>choic;
				if(choic=='b'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//8th P
				cout<<"\t 8: In which of the following situations would the use of a concave lens be appropriate? a"<<"\n\n";
				cout<<"\t a) Correcting nearsightedness \t \t b) Correcting farsightedness"<<"\n\n";
				cout<<"\t c) Creating a magnifying glass \t d) Correcting astigmatism"<<"\n\n\t ";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//9th P
				cout<<"\t 9: Which of the following best describes the relationship between frequency and\n";
				cout<<"\t wavelength of a wave? a"<<"\n\n";
				cout<<"\t a) They are inversely proportional. \t b) They are directly proportional."<<"\n\n";
				cout<<"\t c) They are unrelated. \t\t d) They are inversely proportional to the square root."<<"\n\n\t ";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//10th P
				cout<<"\t 10: Which of the following quantities is conserved in elastic collisions? a"<<"\n\n";
				cout<<"\t a) Momentum \t\t b) Kinetic energy"<<"\n\n";
				cout<<"\t c) Potential energy \t d) Total energy"<<"\n\n\t ";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//11st P
				cout<<"\t 11: Which of the following statements about electric field lines is true? a"<<"\n\n";
				cout<<"\t a) They always point in the direction of the electric field."<<"\n\n";
				cout<<"\t b) They always point in the direction opposite to the electric field."<<"\n\n";
				cout<<"\t c) They form closed loops around a positive charge."<<"\n\n";
				cout<<"\t d) They form closed loops around a negative charge."<<"\n\n\t ";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//12nd P
				cout<<"\t 12: What is the SI unit of electric charge? c"<<"\n\n";
				cout<<"\t a) Ampere \t b) Volt"<<"\n\n";
				cout<<"\t c) Coulomb \t d) Ohm"<<"\n\n\t ";
				cin>>choic;
				if(choic=='c'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//13rd P
				cout<<"\t 13: According to the law of reflection, the angle of incidence is equal to the angle of _____. d"<<"\n\n";
				cout<<"\t a) Absorption \t b) Diffraction"<<"\n\n";
				cout<<"\t c) Refraction \t d) Reflection"<<"\n\n\t ";
				cin>>choic;
				if(choic=='d'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//14th P
				cout<<"\t 14: Which of the following statements about gravitational potential energy is correct? a"<<"\n\n";
				cout<<"\t a) It depends on the mass and height of an object."<<"\n\n";
				cout<<"\t b) It depends on the mass and velocity of an object."<<"\n\n";
				cout<<"\t c) It depends on the volume and density of an object."<<"\n\n";
				cout<<"\t d) It depends on the temperature and pressure of an object."<<"\n\n\t ";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//15th P
				cout<<"\t 15: Which of the following formulas represents the relationship between acceleration,\n";
				cout<<"\t initial velocity, final velocity, and displacement? c"<<"\n\n";
				cout<<"\t a) v = u + at \t\t b) s = ut + (1/2)at^2"<<"\n\n";
				cout<<"\t c) v^2 = u^2 + 2as \t d) s = vt - (1/2)at^2"<<"\n\n\t ";
				cin>>choic;
				if(choic=='c'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//16th P
				cout<<"\t 16: Which of the following best describes the behavior of gases at absolute zero temperature? d"<<"\n\n";
				cout<<"\t a) They become solids. \t\t  b) They become liquids."<<"\n\n";
				cout<<"\t c) They become superconductors. \t d) They approach zero volume and pressure."<<"\n\n\t ";
				cin>>choic;
				if(choic=='d'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//17th P
				cout<<"\t 17: Which of the following statements about nuclear fusion is true? a"<<"\n\n";
				cout<<"\t a) It releases energy by combining light atomic nuclei."<<"\n\n";
				cout<<"\t b) It releases energy by splitting heavy atomic nuclei."<<"\n\n";
				cout<<"\t c) It releases energy by the process of radioactive decay."<<"\n\n";
				cout<<"\t d) It releases energy by transforming protons into neutrons."<<"\n\n\t ";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//18th P
				cout<<"\t 18: The phenomenon of electromagnetic induction is based on the relationship between _____. c"<<"\n\n";
				cout<<"\t a) Current and resistance \t\t         b) Force and acceleration"<<"\n\n";
				cout<<"\t c) Magnetic field and electric current \t d) Energy and power"<<"\n\n\t ";
				cin>>choic;
				if(choic=='c'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//19th P
				cout<<"\t 19: Which of the following statements about special relativity is true? a"<<"\n\n";
				cout<<"\t a) The laws of physics are the same for all observers in uniform motion."<<"\n\n";
				cout<<"\t b) The speed of light is not constant in a vacuum."<<"\n\n";
				cout<<"\t c) Time is absolute and does not depend on the observer's frame of reference."<<"\n\n";
				cout<<"\t d) Mass increases with velocity according to the equation m = m0(1 - v^2/c^2)^(-1/2)."<<"\n\n";
				cin>>choic;
				if(choic=='a'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
		//20th P
				cout<<"\t 20: Which of the following best describes the behavior of sound waves in a vacuum? b"<<"\n\n";
				cout<<"\t a) They travel faster than in a medium. \t         b) They cannot travel because they require a medium."<<"\n\n";
				cout<<"\t c) They travel at the same speed as in a medium. \t d) They travel slower than in a medium."<<"\n\n\t ";
				cin>>choic;
				if(choic=='b'){
					add++;
				}
				system("cls");
				cout<<"\n\n";
				cout<<"\t 1: Start next Subject paper (CHEMISTRY)"<<endl;
				cout<<"\t 2: End Paper "<<endl;
				cout<<"\t ";
				cin>>choice;
				if(choice==1){
					system("cls");
					cin.ignore();
					cout<<"\n\n";
		//1st C
					cout<<"\t 1: Which of the following is the correct electron configuration for a neutral oxygen atom? a"<<"\n\n";
					cout<<"\t a) 1s^2 2s^2 2p^6 \t b) 1s^2 2s^2 2p^4"<<"\n\n";
					cout<<"\t c) 1s^2 2s^2 2p^3 \t d) 1s^2 2s^2 2p^2"<<"\n\n\t ";
					cin>>choic;
					if(choic=='a'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//2nd C
					cout<<"\t 2: Which of the following elements has the highest electronegativity? d"<<"\n\n";
					cout<<"\t a) Sodium (Na) \t b) Oxygen (O)"<<"\n\n";
					cout<<"\t c) Carbon (C) \t\t d) Fluorine (F)"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//3rd C
					cout<<"\t 3: Which of the following is an example of an exothermic reaction? a"<<"\n\n";
					cout<<"\t a) Combustion of methane \t b) Photosynthesis"<<"\n\n";
					cout<<"\t c) Dissolving salt in water \t d) Electrolysis of water"<<"\n\n\t ";
					cin>>choic;
					if(choic=='a'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//4th C
					cout<<"\t 4: What is the molar mass of glucose (C6H12O6)? a"<<"\n\n";
					cout<<"\t a) 180 g/mol \t b) 342 g/mol"<<"\n\n";
					cout<<"\t c) 90 g/mol \t d) 720 g/mol"<<"\n\n\t ";
					cin>>choic;
					if(choic=='a'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//5th C
					cout<<"\t 5: Which of the following types of bonding involves the sharing of electrons? c"<<"\n\n";
					cout<<"\t a) Ionic bonding \t b) Metallic bonding"<<"\n\n";
					cout<<"\t c) Covalent bonding \t d) Hydrogen bonding"<<"\n\n\t ";
					cin>>choic;
					if(choic=='c'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//6th C
					cout<<"\t 6: What is the pH value of a solution with a hydrogen ion concentration of 1 x 10^-8 M? c"<<"\n\n";
					cout<<"\t a) 2 \t b) 6"<<"\n\n";
					cout<<"\t c) 8 \t d) 12"<<"\n\n\t ";
					cin>>choic;
					if(choic=='c'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//7th C
					cout<<"\t 7: Which of the following is a reducing agent? d"<<"\n\n";
					cout<<"\t a) Oxidizing agent \t b) Catalyst"<<"\n\n";
					cout<<"\t c) Base \t\t  d) Element undergoing oxidation"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//8th C
					cout<<"\t 8: Which of the following is an example of an endothermic process? c"<<"\n\n";
					cout<<"\t a) Freezing of water \t\t  b) Rusting of iron"<<"\n\n";
					cout<<"\t c) Melting of wax \t  d) Combustion of gasoline"<<"\n\n\t ";
					cin>>choic;
					if(choic=='c'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//9th C
					cout<<"\t 9: Which of the following is the correct Lewis structure for carbon dioxide (CO2)? a"<<"\n\n";
					cout<<"\t a) O=C=O \t b) C=O"<<"\n\n";
					cout<<"\t c) O=C-O \t d) O-C=O"<<"\n\n\t ";
					cin>>choic;
					if(choic=='a'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//10th C
					cout<<"\t 10: Which of the following is an example of a heterogeneous mixture? d"<<"\n\n";
					cout<<"\t a) Saltwater \t b) Air"<<"\n\n";
					cout<<"\t c) Vinegar \t d) Sand and water"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//11st C
					cout<<"\t 11: Which of the following is the correct balanced equation for the reaction\n";
					cout<<"\t between sodium hydroxide (NaOH) and hydrochloric acid (HCl)? a"<<"\n\n";
					cout<<"\t a) NaOH + HCl -> NaCl + H2O \t b) NaOH + HCl -> NaCl + H2"<<"\n\n";
					cout<<"\t c) NaOH + HCl -> Na2Cl2 + H2O \t d) NaOH + HCl -> Na2CO3 + H2O"<<"\n\n\t ";
					cin>>choic;
					if(choic=='a'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//12nd C
					cout<<"\t 12: What is the oxidation state of chlorine in HClO4? d"<<"\n\n";
					cout<<"\t a) -1 \t b) 0"<<"\n\n";
					cout<<"\t c) +1 \t d) +7"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//13rd C
					cout<<"\t 13: Which of the following elements has the highest ionization energy? d"<<"\n\n";
					cout<<"\t a) Sodium (Na) \t b) Oxygen (O)"<<"\n\n";
					cout<<"\t c) Carbon (C) \t\t  d) Fluorine (F)"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//14th C
					cout<<"\t 14: Which of the following compounds is an example of an organic acid? d"<<"\n\n";
					cout<<"\t a) Sodium chloride (NaCl) \t b) Glucose (C6H12O6)"<<"\n\n";
					cout<<"\t c) Ethanol (C2H5OH) \t\t d) Acetic acid (CH3COOH)"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//15th C
					cout<<"\t 15: What is the product of the complete combustion of a hydrocarbon fuel? a"<<"\n\n";
					cout<<"\t a) Carbon dioxide (CO2) and water (H2O)"<<"\n\n";
					cout<<"\t b) Carbon monoxide (CO) and water (H2O)"<<"\n\n";
					cout<<"\t c) Methane (CH4)"<<"\n\n";
					cout<<"\t d) Oxygen gas (O2)"<<"\n\n\t ";
					cin>>choic;
					if(choic=='a'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//16 C
					cout<<"\t 16: Which of the following is the correct formula for sodium carbonate? b"<<"\n\n";
					cout<<"\t a) NaCO \t b) Na2CO3"<<"\n\n";
					cout<<"\t c) NaCO3 \t d) Na2(CO3)2"<<"\n\n\t ";
					cin>>choic;
					if(choic=='b'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//17th C
					cout<<"\t 17: What is the chemical formula for potassium permanganate? a"<<"\n\n";
					cout<<"\t a) KMnO4 \t b) K2MnO4"<<"\n\n";
					cout<<"\t c) KMnO3 \t d) K(MnO4)2"<<"\n\n\t ";
					cin>>choic;
					if(choic=='a'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//18th C
					cout<<"\t 18: Which of the following is an example of an isotope? d"<<"\n\n";
					cout<<"\t a) Oxygen-16 (16O) \t b) Oxygen-17 (17O)"<<"\n\n";
					cout<<"\t c) Oxygen-18 (18O) \t d) All of the above"<<"\n\n\t ";
					cin>>choic;
					if(choic=='c'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//19th C
					cout<<"\t 19: Which of the following elements is a halogen? d"<<"\n\n";
					cout<<"\t a) Sodium (Na) \t b) Oxygen (O)"<<"\n\n";
					cout<<"\t c) Carbon (C) \t\t d) Chlorine (Cl)"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
		//20th C
					cout<<"\t 20: Which of the following is an example of a redox reaction? d"<<"\n\n";
					cout<<"\t a) AgNO3 + NaCl -> AgCl + NaNO3 \t b) H2O -> H2 + O2"<<"\n\n";
					cout<<"\t c) NH3 + HCl -> NH4Cl \t d) H2SO4 + 2NaOH -> Na2SO4 + 2H2O"<<"\n\n\t ";
					cin>>choic;
					if(choic=='d'){
						countt++;
					}
					system("cls");
					cout<<"\n\n";
					cout<<"\t 1: Start next Subject paper (ENGLISH)"<<endl;
					cout<<"\t 2: End Paper "<<endl;
					cout<<"\t ";
					cin>>choice;
					if(choice==1){
						system("cls");
						cout<<"\n\n";
		//1st E
						cout<<"\t 1: What is the correct definition of an allegory? b"<<"\n\n";
						cout<<"\t a) A figure of speech that involves an implied comparison between two unrelated things"<<"\n\n";
						cout<<"\t b) A narrative or poem in which characters, events, and settings represent abstract ideas or moral qualities"<<"\n\n";
						cout<<"\t c) The repetition of similar sounds at the beginning of words or stressed syllables"<<"\n\n";
						cout<<"\t d) The use of words to convey a meaning that is the opposite of their literal meaning"<<"\n\n\t ";
						cin>>choic;
						if(choic=='b'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//2nd E
						cout<<"\t 2: Which of the following literary devices is used to create a contrast between two\n";
						cout<<"\t opposite ideas using parallel grammatical structures? d"<<"\n\n";
						cout<<"\t a) Metaphor \t b) Simile"<<"\n\n";
						cout<<"\t c) Oxymoron \t d) Antithesis"<<"\n\n\t ";
						cin>>choic;
						if(choic=='d'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//3rd E
						cout<<"\t 3: In which type of point of view does the narrator refer to themselves as\n";
						cout<<"\t 'I' and have access to their own thoughts and feelings? a"<<"\n\n";
						cout<<"\t a) First-person \t\t  b) Second-person"<<"\n\n";
						cout<<"\t c) Third-person limited \t d) Third-person omniscient"<<"\n\n\t ";
						cin>>choic;
						if(choic=='a'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//4th E
						cout<<"\t 4: What is the correct definition of foreshadowing in literature? c"<<"\n\n";
						cout<<"\t a) The use of vivid or descriptive language to create sensory experiences for the reader"<<"\n\n";
						cout<<"\t b) The emotional atmosphere created by a literary work"<<"\n\n";
						cout<<"\t c) Clues or hints about events that will occur later in the story"<<"\n\n";
						cout<<"\t d) The repetition of consonant sounds at the beginning of words or stressed syllables"<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//5th E
						cout<<"\t 5: Which of the following is an example of a tragic flaw in a character? c"<<"\n\n";
						cout<<"\t a) The use of irony to convey a meaning that is the opposite of the literal meaning"<<"\n\n";
						cout<<"\t b) The tendency of a character to speak their thoughts aloud, revealing their innermost feelings"<<"\n\n";
						cout<<"\t c) A character's excessive pride or hubris, leading to their downfall"<<"\n\n";
						cout<<"\t d) The use of words that imitate the sounds they describe"<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//6th E
						cout<<"\t 6: What is the correct definition of a sonnet in poetry? b"<<"\n\n";
						cout<<"\t a) A type of poem that tells a story and often has a musical quality"<<"\n\n";
						cout<<"\t b) A type of poem with 14 lines and a specific rhyme scheme and meter"<<"\n\n";
						cout<<"\t c) A figure of speech that involves an implied comparison between two unrelated things"<<"\n\n";
						cout<<"\t d) A type of poem that expresses the speaker's personal thoughts and feelings"<<"\n\n\t ";
						cin>>choic;
						if(choic=='b'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//7th E
						cout<<"\t 7: Which of the following best describes a bildungsroman? c"<<"\n\n";
						cout<<"\t a) A work of literature that criticizes or ridicules human vices or follies through humor or wit"<<"\n\n";
						cout<<"\t b) A narrative that focuses on the physical and sensory details of a scene or setting"<<"\n\n";
						cout<<"\t c) A type of novel that focuses on the moral and psychological growth of the main character"<<"\n\n";
						cout<<"\t d) A type of poetry that has a fixed structure and often uses elaborate metaphors or conceits"<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//8th E
						cout<<"\t 8: What is the correct definition of a motif in literature? a"<<"\n\n";
						cout<<"\t a) A recurrent image, idea, or symbol that develops or reinforces a theme"<<"\n\n";
						cout<<"\t b) A comparison between two unlike things using 'like' or 'as'"<<"\n\n";
						cout<<"\t c) A type of poem that expresses intense emotions or thoughts"<<"\n\n";
						cout<<"\t d) The rhythmical pattern of stressed and unstressed syllables in a poem"<<"\n\n\t ";
						cin>>choic;
						if(choic=='a'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//9th E
						cout<<"\t 9: Which of the following is an example of verbal irony? a"<<"\n\n";
						cout<<"\t a) A character says the opposite of what they mean, intending to deceive or mock"<<"\n\n";
						cout<<"\t b) The use of words that imitate the sounds they describe"<<"\n\n";
						cout<<"\t c) The use of vivid or descriptive language to create sensory experiences for the reader"<<"\n\n";
						cout<<"\t d) The repetition of similar sounds at the beginning of words or stressed syllables"<<"\n\n\t ";
						cin>>choic;
						if(choic=='a'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//10th E
						cout<<"\t 10: What is the correct definition of a soliloquy in drama? a"<<"\n\n";
						cout<<"\t a) A long speech by a character alone on stage, revealing their thoughts and feelings"<<"\n\n";
						cout<<"\t b) The emotional atmosphere created by a literary work"<<"\n\n";
						cout<<"\t c) A comparison between two unlike things using 'like' or 'as'"<<"\n\n";
						cout<<"\t d) A type of play that portrays humorous or satirical situations and characters"<<"\n\n\t ";
						cin>>choic;
						if(choic=='a'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//11th E
						cout<<"\t 11: Which of the following is an example of a hyperbole? c"<<"\n\n";
						cout<<"\t a) It is the east, and Juliet is the sun. - Romeo and Juliet by William Shakespeare"<<"\n\n";
						cout<<"\t b) My love is like a red, red rose. - A Red, Red Rose by Robert Burns"<<"\n\n";
						cout<<"\t c) I'm so hungry, I could eat a horse."<<"\n\n";
						cout<<"\t d) Shall I compare thee to a summer's day? - Sonnet 18 by William Shakespeare"<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//12th E
						cout<<"\t 12: What is the correct definition of alliteration in poetry? b"<<"\n\n";
						cout<<"\t a) The use of words that imitate the sounds they describe"<<"\n\n";
						cout<<"\t b) The repetition of similar sounds at the beginning of words or stressed syllables"<<"\n\n";
						cout<<"\t c) The emotional atmosphere created by a literary work"<<"\n\n";
						cout<<"\t d) The rhythmical pattern of stressed and unstressed syllables in a poem"<<"\n\n\t ";
						cin>>choic;
						if(choic=='b'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//13th E
						cout<<"\t 13: Which of the following is an example of a metaphor? c"<<"\n\n";
						cout<<"\t a) Time is money. \t b) The wind howled through the night."<<"\n\n";
						cout<<"\t c) Love is a rose. \t d) The stars danced in the sky."<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//14th E
						cout<<"\t 14: What is the correct definition of a tragic hero in literature? c"<<"\n\n";
						cout<<"\t a) A character who serves as a contrast to another character, often highlighting their traits"<<"\n\n";
						cout<<"\t b) A character who undergoes a significant internal change or transformation"<<"\n\n";
						cout<<"\t c) A character who is admired for their noble qualities but has a tragic flaw leading to their downfall"<<"\n\n";
						cout<<"\t d) A character who is depicted as foolish or ridiculous, often for comic effect"<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//15th E
						cout<<"\t 15: Which of the following literary movements emphasized the power of the\n";
						cout<<"\t individual and celebrated imagination and emotion? a"<<"\n\n";
						cout<<"\t a) Romanticism \t b) Realism"<<"\n\n";
						cout<<"\t c) Modernism \t\t  d) Transcendentalism"<<"\n\n\t ";
						cin>>choic;
						if(choic=='a'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//16th E
						cout<<"\t 16: What is the correct definition of a simile in literature? a"<<"\n\n";
						cout<<"\t a) A figure of speech that involves an implied comparison between two unrelated things"<<"\n\n";
						cout<<"\t b) The emotional atmosphere created by a literary work"<<"\n\n";
						cout<<"\t c) The repetition of similar sounds at the beginning of words or stressed syllables"<<"\n\n";
						cout<<"\t d) The rhythmical pattern of stressed and unstressed syllables in a poem"<<"\n\n\t ";
						cin>>choic;
						if(choic=='a'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//17th E
						cout<<"\t 17: Which of the following literary devices is used to create a sense of rhythm and musicality in poetry? a"<<"\n\n";
						cout<<"\t a) Alliteration \t b) Symbolism"<<"\n\n";
						cout<<"\t c) Foreshadowing \t d) Personification"<<"\n\n\t ";
						cin>>choic;
						if(choic=='a'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//18th E
						cout<<"\t 18: What is the correct definition of an archetype in literature? b"<<"\n\n";
						cout<<"\t a) A narrative device that creates suspense or tension"<<"\n\n";
						cout<<"\t b) A character or symbol that represents a universal pattern or recurring theme"<<"\n\n";
						cout<<"\t c) The repetition of similar sounds at the end of words or stressed syllables"<<"\n\n";
						cout<<"\t d) The emotional atmosphere created by a literary work"<<"\n\n\t ";
						cin>>choic;
						if(choic=='b'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//19th E
						cout<<"\t 19: Which of the following best describes the purpose of a thesis statement in an essay? c"<<"\n\n";
						cout<<"\t a) To provide a summary of the main points of the essay"<<"\n\n";
						cout<<"\t b) To introduce a counterargument and refute it"<<"\n\n";
						cout<<"\t c) To present the main argument or claim of the essay"<<"\n\n";
						cout<<"\t d) To offer a concluding statement or final thought"<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
		//20th E
						cout<<"\t 20: What is the correct definition of dramatic irony? c"<<"\n\n";
						cout<<"\t a) The use of words that imitate the sounds they describe"<<"\n\n";
						cout<<"\t b) The repetition of consonant sounds at the end of words or stressed syllables"<<"\n\n";
						cout<<"\t c) A contrast between what the audience knows and what a character believes or expects"<<"\n\n";
						cout<<"\t d) The emotional atmosphere created by a literary work"<<"\n\n\t ";
						cin>>choic;
						if(choic=='c'){
							sum++;
						}
						system("cls");
						cout<<"\n\n";
						cout<<"\t 1: Start next Subject paper (OOP)"<<endl;
						cout<<"\t 2: End Paper "<<endl;
						cout<<"\t ";
						cin>>choice;
						if(choice==1){
							system("cls");
							cout<<"\n\n";
		//1st O
							cout<<"\t 1: What is the output of the following code snippet? a"<<"\n\n";
							cout<<"\t #include <iostream>"<<"\n\n";
							cout<<"\t int main() {"<<"\n\n";
							cout<<"\t int x = 5;"<<"\n\n";
						    cout<<"\t int y = x++;"<<"\n\n";
							cout<<"\t std::cout << y << std::endl;"<<"\n\n";
							cout<<"\t return 0;"<<"\n\n";
							cout<<"\t }"<<"\n\n";
							cout<<"\t a) 4 \t\t b) 5"<<"\n\n";
							cout<<"\t c) 6 \t\t d) Undefined behavior"<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//2nd O
							cout<<"\t 2 Which of the following is a correct way to dynamically allocate an array of integers in C++? b"<<"\n\n";
							cout<<"\t a) int arr[10]; \t\t  b) int* arr = new int[10];"<<"\n\n";
							cout<<"\t c) int* arr = new int; \t d) int* arr = malloc(10 * sizeof(int));"<<"\n\n\t ";
							cin>>choic;
							if(choic=='b'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//3rd O
							cout<<"\t 3: What is the purpose of the const keyword in C++? a"<<"\n\n";
							cout<<"\t a) It declares a variable whose value cannot be modified."<<"\n\n";
							cout<<"\t b) It declares a variable whose value can be modified."<<"\n\n";
							cout<<"\t c) It indicates that a function will not modify the object it is called on."<<"\n\n";
							cout<<"\t d) It is used to define constant expressions."<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//4th O
							cout<<"\t 4: What is the correct way to access the second element of a C++ array arr? c"<<"\n\n";
							cout<<"\t a) arr(1); \t b) arr[2];"<<"\n\n";
							cout<<"\t c) arr[1]; \t d) arr.2;"<<"\n\n\t ";
							cin>>choic;
							if(choic=='c'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//5th O
							cout<<"\t 5: What is the output of the following code snippet? b"<<"\n\n";
							cout<<"\t #include <iostream>"<<"\n\n";
							cout<<"\t int main() {"<<"\n\n";
							cout<<"\t     int x = 10;"<<"\n\n";
							cout<<"\t     int& ref = x;"<<"\n\n";
							cout<<"\t     ref = 5;"<<"\n\n";
							cout<<"\t     std::cout << x << std::endl;"<<"\n\n";
							cout<<"\t     return 0;"<<"\n\n";
							cout<<"\t }"<<"\n\n";
							cout<<"\t a) 10 \t\t b) 5"<<"\n\n";
							cout<<"\t c) 15 \t\t d) Compilation error"<<"\n\n\t ";
							cin>>choic;
							if(choic=='b'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//6th O
							cout<<"\t 6: What does the endl manipulator do in C++? d"<<"\n\n";
							cout<<"\t a) It moves the cursor to the next line. \t b) It inserts a newline character."<<"\n\n";
							cout<<"\t c) It flushes the output buffer. \t\t d) All of the above."<<"\n\n\t ";
							cin>>choic;
							if(choic=='d'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//7th O
							cout<<"\t 7: Which of the following is NOT a valid data type in C++? b"<<"\n\n";
							cout<<"\t a) long long \t\t  b) boolean"<<"\n\n";
							cout<<"\t c) float \t\t d) char"<<"\n\n\t ";
							cin>>choic;
							if(choic=='b'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//8th O
							cout<<"\t 8: What is the correct way to declare a pure virtual function in C++? a"<<"\n\n";
							cout<<"\t a) virtual void myFunction() = 0; \t b) pure virtual void myFunction();"<<"\n\n";
							cout<<"\t c) virtual void myFunction() pure; \t d) void myFunction() = pure virtual;"<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//9th O
							cout<<"\t 9: What is the output of the following code snippet? a"<<"\n\n";
							cout<<"\t #include <iostream>"<<"\n\n";
							cout<<"\t int main() {"<<"\n\n";
							cout<<"\t     int x = 5;"<<"\n\n";
							cout<<"\t     int* ptr = &x;"<<"\n\n";
							cout<<"\t     std::cout << *ptr << std::endl;"<<"\n\n";
							cout<<"\t     return 0;"<<"\n\n";
							cout<<"\t }"<<"\n\n";
							cout<<"\t a) 5 \t\t\t  b) 0"<<"\n\n";
							cout<<"\t c) Garbage value \t d) Compilation error"<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//10th O
							cout<<"\t 10: Which of the following operators is used to allocate memory for a class object on the heap? a"<<"\n\n";
							cout<<"\t a) new \t\t b) malloc"<<"\n\n";
							cout<<"\t c) alloc \t\t d) allocate"<<"\n\n";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//11st O
							cout<<"\t 11: What is the correct way to define a constant member function in a C++ class? c"<<"\n\n";
							cout<<"\t a) const void myFunction() { } \t b) void const myFunction() { }"<<"\n\n";
							cout<<"\t c) void myFunction() const { } \t d) const myFunction() { }"<<"\n\n\t ";
							cin>>choic;
							if(choic=='c'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//12nd O
							cout<<"\t 12: What does the sizeof operator return in C++? d"<<"\n\n";
							cout<<"\t a) The size of a variable in bytes. \t b) The size of a class in bytes."<<"\n\n";
							cout<<"\t c) The size of a data type in bytes. \t d) All of the above."<<"\n\n\t ";
							cin>>choic;
							if(choic=='d'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//13rd O
							cout<<"\t 13: What is the correct syntax for defining a template class in C++? a"<<"\n\n";
							cout<<"\t a) template<typename T> class MyClass { }"<<"\n\n";
							cout<<"\t b) template<class T> class MyClass { }"<<"\n\n";
							cout<<"\t c) class template<typename T> MyClass { }"<<"\n\n";
							cout<<"\t d) class<typename T> template MyClass { }"<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//14th O
							cout<<"\t 14: What is the correct way to open a file named 'data.txt' in C++ for writing? a"<<"\n\n";
							cout<<"\t a) fstream file('data.txt', ios::out);"<<"\n\n";
							cout<<"\t b) ifstream file(data.txt);"<<"\n\n";
							cout<<"\t c) ofstream file(data.txt);"<<"\n\n";
							cout<<"\t d) file.open(data.txt);"<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//15th O
							cout<<"\t 15: What is the output of the following code snippet? a"<<"\n\n";
							cout<<"\t #include <iostream>"<<"\n\n";
							cout<<"\t using namespace std;"<<"\n\n";
							cout<<"\t int main() {"<<"\n\n";
							cout<<"\t     int arr[5] = {1, 2, 3, 4, 5};"<<"\n\n";
							cout<<"\t     int* ptr = arr;"<<"\n\n";
							cout<<"\t     cout << *ptr++ << endl;"<<"\n\n";
							cout<<"\t     return 0;"<<"\n\n";
							cout<<"\t }"<<"\n\n";
							cout<<"\t a) 1 \t\t b) 2"<<"\n\n";
							cout<<"\t c) 5 \t\td) Compilation error"<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//16th O
							cout<<"\t 16: Which of the following is NOT a valid way to pass arguments to a C++ function? d"<<"\n\n";
							cout<<"\t a) Pass by value \t b) Pass by reference"<<"\n\n";
							cout<<"\t c) Pass by pointer \t d) Pass by constant reference"<<"\n\n\t ";
							cin>>choic;
							if(choic=='d'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//17th O
							cout<<"\t 17: What is the correct way to declare a friend function of a C++ class? c"<<"\n\n";
							cout<<"\t a) friend myFunction(); \t b) void friend myFunction();"<<"\n\n";
							cout<<"\t c) friend void myFunction(); \t d) myFunction() friend;"<<"\n\n\t ";
							cin>>choic;
							if(choic=='c'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//18th O
							cout<<"\t 18: What is the correct way to include a header file named myheader.h in a C++ program? c"<<"\n\n";
							cout<<"\t a) include myheader.h \t b) #include <myheader.h>"<<"\n\n";
							cout<<"\t c) #include myheader \t d) include <myheader.h>"<<"\n\n\t ";
							cin>>choic;
							if(choic=='c'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//19th O
							cout<<"\t 19: What is the output of the following code snippet? c"<<"\n\n";
							cout<<"\t #include <iostream>"<<"\n\n";
							cout<<"\t using namespace std;"<<"\n\n";
							cout<<"\t int add(int x, int y) {"<<"\n\n";
							cout<<"\t     return x + y;"<<"\n\n";
							cout<<"\t }"<<"\n\n";
							cout<<"\t int main() {"<<"\n\n";
							cout<<"\t     cout << add(5, 3) << endl;"<<"\n\n";
							cout<<"\t     return 0;"<<"\n\n";
							cout<<"\t }"<<"\n\n";
							cout<<"\t a) 5 \t\t b) 3"<<"\n\n";
							cout<<"\t c) 8 \t\t d) Compilation error"<<"\n\n\t ";
							cin>>choic;
							if(choic=='c'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
		//20th O
							cout<<"\t 20: Which of the following is a correct way to define a constructor in a C++ class named 'MyClass'? a"<<"\n\n";
							cout<<"\t a) MyClass() { } \t\t b) void MyClass() { }"<<"\n\n";
							cout<<"\t c) MyClass::MyClass() { } \t d) constructor MyClass() { }"<<"\n\n\t ";
							cin>>choic;
							if(choic=='a'){
								plus++;
							}
							system("cls");
							cout<<"\n\n";
							total=count+add+countt+sum+plus;
							cout<<"\t your total points in MATHS are : "<<count<<endl;
							cout<<"\t Your total points in PHYSICS are : "<<add<<endl;
							cout<<"\t your points in CHEMISTRY are : "<<countt<<endl;
							cout<<"\t your total points in ENGLISH are : "<<sum<<endl;
							cout<<"\t your total points in OOP are : "<<plus<<endl;
							cout<<"\t Total points of "<<CNIC<<" are : "<<total<<endl;
							cout<<"\t Now your paper is over "<<"\n\t ";
							ofstream write;
							write.open("merit.txt",ios::app);
							write<<CNIC<<" are :"<<" Maths :"<<count<<" Physics :"<<add<<" Chemistry : "<<countt<<" English : "<<sum<<" OOP : "<<plus<<" Total : "<<total<<endl;
							write.close();
							system("pause");
							menu();							
						}
		//this else is ask for start of oop paper
						else{
							total=count+add+countt+sum;
							cout<<"\t your total points in MATHS are : "<<count<<endl;
							cout<<"\t Your total points in PHYSICS are : "<<add<<endl;
							cout<<"\t your points in CHEMISTRY are : "<<countt<<endl;
							cout<<"\t your total points in ENGLISH are : "<<sum<<endl;
							cout<<"\t Total points of "<<CNIC<<" are : "<<total<<endl;
							cout<<"\t Now your paper is over "<<"\n\t ";
							ofstream write;
							write.open("merit.txt",ios::app);
							write<<CNIC<<" are :"<<" Maths :"<<count<<" Physics :"<<add<<" Chemistry : "<<countt<<" English : "<<sum<<" OOP : "<<plus<<" Total : "<<total<<endl;
							write.close();
							system("pause");
							menu();
						}	
					}	
		//this else is ask st the start of english test
					else{
						total=count+add+countt;
						cout<<"\t your total points in MATHS are : "<<count<<endl;
						cout<<"\t Your total points in PHYSICS are : "<<add<<endl;
						cout<<"\t your points in CHEMISTRY are : "<<countt<<endl;
						cout<<"\t Total points of "<<CNIC<<" are : "<<total<<endl;
						cout<<"\t Now your paper is over "<<"\n\t ";
						ofstream write;
						write.open("merit.txt",ios::app);
						write<<CNIC<<" are :"<<" Maths :"<<count<<" Physics :"<<add<<" Chemistry : "<<countt<<" English : "<<sum<<" OOP : "<<plus<<" Total : "<<total<<endl;
						write.close();
						system("pause");
						menu();
					}
				}
		//this else is ask at the start of chemistry test 
				else{
					total=count+add;
					cout<<"\t your total points in MATHS are : "<<count<<endl;
					cout<<"\t Your total points in PHYSICS are : "<<add<<endl;
					cout<<"\t Total points of "<<CNIC<<" are : "<<total<<endl;
					cout<<"\t Now your paper is over "<<"\n\t ";
					ofstream write;
					write.open("merit.txt",ios::app);
					write<<CNIC<<" are :"<<" Maths :"<<count<<" Physics :"<<add<<" Chemistry : "<<countt<<" English : "<<sum<<" OOP : "<<plus<<" Total : "<<total<<endl;
					write.close();
					system("pause");
					menu();
				}
			}	
		//this else is for ask in starting of physics test
			else{
				total=count;
				cout<<"\t your total points in MATHS are : "<<count<<endl;
				cout<<"\t Total points of "<<CNIC<<" are : "<<total<<endl;
				cout<<"\t Now your paper is over "<<"\n\t ";
				ofstream write;
				write.open("merit.txt",ios::app);
				write<<CNIC<<" are :"<<" Maths :"<<count<<" Physics :"<<add<<" Chemistry : "<<countt<<" English : "<<sum<<" OOP : "<<plus<<" Total : "<<total<<endl;
				write.close();
				system("pause");
				menu();
			}
		}
	//this else is for first maths test if ka else hy
		else if(choice==2){
			menu();
		}
}	
//this is for inputs like user cnic and password not for paper else
	else{
		system("pause");
		cout<<"\t Wrong Inputs "<<endl;
		menu();
	}
}
void admission::show(){
	cin.ignore();
	system("cls");
	cout<<"\n\n";
	cout<<"\t Enter your CNIC : ";
	getline(cin,CNIC);
	cout<<"\n";
	ifstream find;
	find.open("merit.txt");
	string lists;
	while(getline(find,lists)){
		if(lists.find(CNIC)!=string::npos){
		cout<<"\t "<<lists<<endl;
			cout<<"\t Found"<<endl;
		}
	}
	find.close();
	cout<<"\t ";
	system("pause");
}
int main(){
	admission obj;
	system("color A");
	obj.home();
	return 0;
}
