#include "string_ext.h"


// dismembers the string in "words" that have a space between them, easier to process the input then
std::vector<std::string> dismemberString( std::string words )  	
{
	std::vector< std::string > wordVec;
	wordVec.clear();
	std::string word;
	word.clear();
	for( int x = 0; x < words.size(); x++ )
	{
		if( words[x] != ' ' )
			word.push_back( words[x] );
		else
		{
			wordVec.push_back( word );
			word.clear();
		}
	}
	wordVec.push_back( word ); // the string doesn't end to space ( hopeful, needs some work here )
	return wordVec;
}
