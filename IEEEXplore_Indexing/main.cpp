#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>

using namespace std;

bool cmp(const pair<string, int>& a,
         const pair<string, int>& b)
{
    return (a.second > b.second);
}

char upperToLower(char c){
    if(c > 64 && c < 91)
        c += 32;
    return c;
}

bool isLetter(char c){
    if((c > 96 && c < 123) || c==39)
        return true;
    return false;
}

bool isPunctuation(char c) {
    if (c==44 || c==46 || c==63 || c==33)
        return true;
    return false;
}

int main() {
    char c;
    string word;
    int score=0, counter=0;
    vector<string> stopWords;
    map<string, int> indexTerms;
    vector<string> ans;

    c = getchar();
    while(c != '\n'){
        c = upperToLower(c);
        if(isLetter(c)){
            word.push_back(c);
        }
        else{
            stopWords.push_back(word);
            word.clear();
        }
        c = getchar();
    }
    stopWords.push_back(word);
    word.clear();

    c = getchar();
    while(c != '\n'){
    	c = upperToLower(c);
    	if(isLetter(c))
    		word.push_back(c);
    	else{
    		indexTerms.insert(pair<string, int>(word, 0));
    		word.clear();
    	}
    	c = getchar();
    }
    indexTerms.insert(pair<string, int>(word, 0));
    word.clear();

    c = getchar();
    while(c != EOF){
    	c = upperToLower(c);
    	if(c == 60){
    	    c = getchar();

    	    if(indexTerms.find(word) != indexTerms.end() && score!=0){
    			indexTerms.find(word)->second += score;
    			counter++;
    		}
    		else if (score!=0){
    			if(word.length() >= 4 && find(stopWords.begin(), stopWords.end(), word) == stopWords.end())
    				counter++;
    		}
    		word.clear();

    		while(c != 62){
    			word.push_back(c);
    			c = getchar();
    		}
    		if (word == "title") score = 5;
    		if (word == "abstract") score = 3;
    		if (word == "body") score = 1;
    		if ((word == "/title") || (word == "/abstract") || (word == "/body")) score = 0;
 			word.clear();
    	}
    	else if(isLetter(c) && score!=0){
    		word.push_back(c);
    	}
    	else if (score!=0 && !isPunctuation(c)){
    		if(indexTerms.find(word) != indexTerms.end()){
    			indexTerms.find(word)->second += score;
    			counter++;
    		}
    		else{
    			if(word.length() >= 4 && find(stopWords.begin(), stopWords.end(), word) == stopWords.end())
    				counter++;
    		}
    		word.clear();
    	}

    	c = getchar();
    }

    vector<pair<string, int>> vec;
    map<string, int> :: iterator it2;
    for (it2=indexTerms.begin(); it2!=indexTerms.end(); it2++)
      {
        vec.push_back(make_pair(it2->first, it2->second));
      }

	sort(vec.begin(), vec.end(), cmp);

	vector<pair<string, int>>::iterator it = vec.begin();
	vector<pair<string, int>>::iterator itHelp = it;

	int cnt = 0;
	//ans.push_back(it->first);
	while(cnt < 3 && it!=vec.end()){
		ans.push_back(get<0>(*it));
		cnt++;
		itHelp++;
		while((itHelp != vec.end()) && (get<1>(*it) == get<1>(*itHelp))){
			it++;
			ans.push_back(get<0>(*it));
			itHelp++;
			cnt++;
		}
		sort(ans.begin(), ans.end());
		for(string s : ans){
			float temp = indexTerms.find(s)->second;
			cout << s << ": " << fixed<<setprecision(8)<<temp/counter*100 << endl;
		}
		ans.clear();
		it++;
	}

    return 0;
}
