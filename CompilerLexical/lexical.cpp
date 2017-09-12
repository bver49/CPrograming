#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

int exist(string word);					//找尋要分析的內容是否有包含operator或是special符號 有則回傳在分析的字串中最前面的特殊符號的index,否則回傳-1
int two(string word);					//確認特殊符號是否為兩個字元 如果是回傳1,否則回傳0
string checktype(string word);         //用來分析傳入的內容的形態 最終結果會回傳string


int main(int argc, char *argv[]) 
{
	ifstream fin(argv[1]);              	//讀取指定名稱的檔案
	ofstream fout("token.txt");				//輸出的檔案為token.txt
	int nline = 0;                          //計算行數的變數

	if(fin.eof()) 							//如果找不到指定的檔案
	cout << "Error:Can't find file!" << endl;    	//輸出error
	
	else 
	{
		string line;                      				//用來儲存讀取的檔案中每一行字串的變數

		while(getline(fin, line))        					//一行一行讀取檔案中的內容 並存到line中 直到讀不到內容就結束
		{			
		
			nline++;                           				//行數+1
			istringstream finw(line);       				//將line中的內容 以空白為分隔符 分割成一個一個字串
			string analysis = "", output = "", left = "";  		//analysis儲存待分析的內容 ouput儲存要輸出到檔案的內容 left儲存剩下未分析的內容
			int index = 0;                         				//記錄字串的index

			
			fout << "Line " << nline << ":" << endl;       		 //先輸出目前的行數到檔案中

			while(finw >> analysis)                   		//將分割好的字串一個一個傳入analysis
			{			
				if(analysis[0]=='/'&& analysis[1]=='/')   		//如果字串第一跟第二個內容皆為 / 代表這是註解,則跳出
				break;
				

				while(analysis != "")                     		//如果待分析的內容不是空的則進入while
				{
					if(exist(analysis)!= -1)               		//檢查待分析的內容 是否包含特殊符號 如果有則進入if
					{			
						index=exist(analysis);             		//確認最前面的特殊符號的位置
						left = analysis.substr(index);     		//剩下未分析的內容變成該符號到結尾的內容
						if(index != 0)                     		//如果特殊符號不是在最一開始
						analysis = analysis.substr(0,index);      //待分析的內容變為從頭,然後取到特殊符號之前
						
						else 
						{
							if(two(analysis.substr(0,2))==0)  //如果該特殊符號不是兩個字元 ex:==或者&&
							{
								left = analysis.substr(index+1);   //未分析的內容變成特殊符號以後的內容
								analysis = analysis.substr(0,1);   //分析的內容變成從頭取一個字元 ex:=或者+
							}
							else                                	//如果該特殊符號是兩個字元的內容
							{
								left = analysis.substr(index+2);   //為分析的內容變為特殊符號以後一個字元的內容
								analysis = analysis.substr(0,2);	//分析的內容為從頭取兩個字元
							}
						}
					}

					output+=checktype(analysis);                 //將分析的結果加到要輸出的字串上
					fout<<output<<analysis<<endl;               //將結果輸出到檔案中

					output="";                                  //清空要輸出的內容
					index=0;									//將編號歸零
					analysis=left;                             //待分析的內容變成還未分析的內容
					left="";								   //清空未分析的內容
				}
			}
		}

		fin.close();                                      //關閉輸入檔案
		fout.close();										//關閉輸出檔案
	}
	return 0;
}

int exist(string word) 
{
	string temp[] = {"(",")","[","]","{","}",";",",","==","!=","<",">","<=",">=","&&","||","=","!","+","-","*","/","++","--","+=","-=","*=","/="};  //定義特殊符號
 	int pos=-1;            													//記錄特殊符號的位置的變數 初始為-1
	for(int i = 0; i < (sizeof(temp) / sizeof(temp[0])); i++) 
	{

		if(word.find(temp[i])!= string::npos)                       //如果找到一個特殊符號
		{
			pos=word.find(temp[i]);                               //先將pos指定為他的位置 然後跳出
			break;
		}
		
	}
	if (pos>-1)                                                  //如果前面有找到一個特殊符號則進入if
	for(int i = 0; i < (sizeof(temp) / sizeof(temp[0])); i++) 
	{

		if(word.find(temp[i])!= string::npos && pos>word.find(temp[i]))       //檢查是否有比這個特殊符號 位置要在更前面的特殊符號
		{
			pos=word.find(temp[i]);												//如果有則將pos指定為他的位置
		}
		
	}


	return pos;                               										//回傳最前面的特殊符號的位置
}

int two(string word)
{
	string temp[] = {"==","!=","<=",">=","&&","||","++","--","+=","-=","*=","/="};     //定義兩個字元的特殊符號
	for(int i = 0; i < (sizeof(temp) / sizeof(temp[0])); i++)                       	//如果是兩個字元的特殊符號 回傳1
		if(word.find(temp[i])!= string::npos)                     
			return 1;
	
	return 0;        								                                 //如果不是兩個字元的特殊符號 回傳0
}

string checktype(string word)
{
		int length=word.length();        //計算傳入的字串長度

		string keyword[] = {"int","char","float","double","return","break","print","if","else","while","break","for"};  //定義keyword
		for(int i = 0; i < (sizeof(keyword)/sizeof(keyword[0]));i++)         //如果分析的內容有包含keyword
			if(word == keyword[i]) 
				return "<Keyword>     : ";                                  //回傳結果為keyword

		string Operator[] = {"==","!=","<",">","<=",">=","&&","||","=","!","+","-","*","/","++","--","+=","-=","*=","/="};  //定義operator
		for(int i = 0; i < (sizeof(Operator)/sizeof(Operator[0]));i++)       //如果分析的內容有包含operator
			if(word == Operator[i]) 
				return "<Operator>    : "; 									 //回傳結果為operator

		string special[] = {"(",")","[","]","{","}",";",","};               //定義special的內容
		for(int i = 0; i < (sizeof(special)/sizeof(special[0])); i++)       //如果分析的內容有包含special
			if(word == special[i])
				return "<Special>     : ";									//回傳結果為special

		string b=word.substr(0,1);                                         //將字串開頭的內容指定給b
		string e=word.substr(length-1,1);								  //將字串結尾的內容指定給e
		if((b== "'" && e == "'")||(b== "\"" && e == "\"")) 										//如果開頭跟結尾都是'符號或是" 代表他是char
			return "<Char>        : ";									//回傳結果為char

		string num[]={"0","1","2","3","4","5","6","7","8","9"};        //定義num
		int cc=0,nc=0;                                                   //cc用來計算小數點個數  nc用來記錄數字個數 初始皆為0
		if(word[0]=='0')                                                //如果開頭是0之後的內容又是數字 ex:05
			for(int i=0;i<(sizeof(num)/sizeof(num[0]));i++)             
				if(word.substr(1,1)==num[i])                       
					return "<Error>       : ";							 //回傳結果為error
		for(int i=0;i<length;i++)                                        //計算小數點個數
			if(word[i]=='.')
				cc++;
		if(cc>1)                    									//如果小數點個數大於1
			return "<Error>       : ";									//回傳結果為error
		for(int i=0;i<length;i++)										//如果分析的內容中有包含num
			for(int j=0;j<(sizeof(num)/sizeof(num[0]));j++)
				if(word.substr(i,1)==num[j])
				{
					nc++;        											//nc+1
					break;
				}
		if((nc+cc)==length) 												//如果小數點個數+數字個數=字串長度 代表他是數字
			return "<Number>      : ";										//回傳結果為number

		for(int i=0;i<(sizeof(num)/sizeof(num[0]));i++)						//已檢查過內容不是數字形態 但開頭卻是數字 ex:3abc
			if(word.substr(0,1)==num[i])
				return "<Error>       : ";									//回傳結果error
		if(word[0]=='.')													//如果字串開頭為. ex: .sd
				return "<Error>       : ";									//回傳結果error
		
		return "<Identifier>  : ";											//如果字串都不是以上的形態也都沒有error 則回傳Identifier

}
