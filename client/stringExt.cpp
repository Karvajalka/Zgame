#include "stringExt.h"

std::vector<std::string> dismemberString( std::string words )  	
{
	/*
	 * This function dismembers the string into parts that are separated
	 * by space(s). It just reads it until it finds a space and then 
	 * pushes the letters before that into the wordvector. This helps
	 * with processing the input
	 */
	std::vector< std::string > wordVec;
	wordVec.clear();
	std::string word;
	word.clear();
	for( int x = 0; x < words.size(); x++ )
	{
		if( words[x] != ' ' )
			word.push_back( words[x] );
		else if( word.size() > 0 )
		{
			wordVec.push_back( word );
			word.clear();
		}
	}
	if( word.size() > 0 ) //making sure the string didn't end to space(s)
		wordVec.push_back( word );
	return wordVec;
}
