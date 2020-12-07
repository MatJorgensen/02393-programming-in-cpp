#include <iostream>

#include "ex03-library.h"

//Do not modify
MovieEvaluations::MovieEvaluations() {
    movies.insert("The Godfather");
    movieToEvaluation["The Godfather"] = 10;
}

//Do not modify
bool MovieEvaluations::hasEvaluation(string movie) {
    if (movies.find(movie) != movies.end()) {
        //I have an evaluation for the movie
        return true;
    } else {
        return false;
    }
}

//Exercise 3 (a) Check and correct if necessary
void MovieEvaluations::print() {
	map<string, double>::iterator itr;
    cout << "I have the following evaluations:" << endl;
    for (itr = movieToEvaluation.begin(); itr != movieToEvaluation.end(); itr++) {
        cout << " movie " << itr->first << " has evaluation " << itr->second << endl;
    }
}

//Exercise 3 (b) Implement this function
bool MovieEvaluations::addEvaluation(string movie, double evaluation) {
    if (hasEvaluation(movie)) {
		return false;
	} else if (evaluation < 0 || evaluation > 10) {
		return false;
	} else {
		movies.insert(movie);
		movieToEvaluation[movie] = evaluation;
		return true;
	}
}

//Exercise 3 (c) Implement this function
bool MovieEvaluations::updateEvaluation(string movie, double newEvaluation) {
    if (!hasEvaluation(movie)) {
		return false;
	} else if (newEvaluation < 0 || newEvaluation > 10) {
		return false;
	} else {
		movies.insert(movie);
		movieToEvaluation[movie] = newEvaluation;
		return true;
	}
}

//Exercise 3 (d) Implement this function
string MovieEvaluations::computeVerboseEvaluation(string movie) {
	if (!hasEvaluation(movie))
		return "not evaluated";

	double evaluation = movieToEvaluation[movie];
	
    if (0.0 <= evaluation && evaluation <= 2.5)
		return "very bad";
	else if (2.5 < evaluation && evaluation <= 5.0)
		return "bad";
	else if (5.0 < evaluation && evaluation <= 7.5)
		return "good";
	else 
		return "very good";
}
