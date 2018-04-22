//This C++ programe checks the sentence acording to the english grammer


#include"std_lib_facilities.h"

vector<string> verb{ "rules", "fly", "swim" };
vector<string> noun{ "birds", "fish","C++" };
vector<string> conjuction{ "and","or","but" };


//takes string and i which tells the starting point
//return the word
//this fucntion returns the word
string give_word(string t, unsigned int i)
{
	string  word;
	while (i < t.size() && t[i] != 32) //till the last and if presence of 
	{
			word.push_back(t[i]);
			i++;
	}
	return word;
}

//----------------------------------------------------

//it checks if a word is noun or not
//it takes set of noun and a word
//it return ture if word is  noun else false
bool check_noun(vector<string> &noun, string temp)
{
	for (string x : noun)
		if (x == temp)return true;

	cout << "\nnot OK\n";
	return false;
}

//----------------------------------------------------

//it takes a word 
//return true or false
//if the word is a verb then it is ture else it returns false
bool check_verb(vector<string> &verb, string temp)
{
	for (string x : verb)
		if (x == temp)return true;

	cout << "\nnot OK\n";
	return false;
}

//----------------------------------------------------

//it takes a word and set of conjuction
//it returns true if it is a conjuction else false
bool check_conjunction(vector<string> &conjuction, string temp)
{
	for (string x : conjuction)
		if (x == temp)return true;

	cout << "\nnot OK\n";
	return false;
}

//----------------------------------------------------

//it takes a word if it is a full stop 
//it returns ture 
//else false
bool check_full_stop(string temp)
{
	if (temp == ".")return true;

	else return	false;
}

//----------------------------------------------------

//takes a string and position of last space seen in the sentence
//prints yes or no
//noun -> verb -> . -> OK / conjuction -> repeate the procees / not OK
void sentence(string t, int previous_space = 0)
{
 
	string word = give_word(t, previous_space);

	if (check_noun(noun, word))//if noun found then check for verb
	{
		previous_space += word.size()+1;
		word = give_word(t,previous_space);

		if (check_verb(verb, word)) //if verb found check for . or conjuction
		{
			previous_space += word.size() + 1; 
			word = give_word(t, previous_space);
			if (check_full_stop(word)) //if . found then ends
			{
				cout << "\nOK\n";
			}
			else if (check_conjunction(conjuction, word )) //if conjuction found then check for next words
			{
				previous_space += word.size() + 1;
				sentence(t, previous_space);
			}
			else
			{
				cout << "\nnot OK\n";
			}
		}
	}
}
//-------------------------------------------------


int main()
{
	try
	{
		cout << "\tEnter a sentence:"
			<< "\n\tSet of verb = \"rules\", \"fly\", \"swim\""
			<< "\n\tSet of noun = \"birds\", \"fish\",\"C++\""
			<< "\n\tSet of conjuction = \"and\",\" or \",\"but\"\n";

		string t; 
		getline(cin, t);
		sentence(t); //takes whole string
		keep_window_open();
		return 0;
	}
	catch (out_of_range)
	{
		cerr << "\nOUT of range\n";
		keep_window_open();
		return 1;
	}
}