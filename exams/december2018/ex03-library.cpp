#include <iostream>
#include "ex03-library.h"

//Do not modify
MovieEvaluations::MovieEvaluations() {
  movies.insert("The Godfather");
  movieToEvaluation["The Godfather"]=10;
}

//Do not modify
bool MovieEvaluations::hasEvaluation(string movie){
  if(movies.find(movie) != movies.end()){
    //I have an evaluation for the movie
    return true;
  }
  else{
    return false;
  }
}

//Exercise 3 (a) Check and correct if necessary
void MovieEvaluations::print(){
  cout << "I have the following evaluations:"<<endl;
  for (map<string,double>::iterator it=movieToEvaluation.begin(); it!=movieToEvaluation.end(); ++it){
      cout << ' '<< "movie " << it->second  << " has evaluation " << it->first << endl;
  }
}

//Exercise 3 (b) Implement this function
bool MovieEvaluations::addEvaluation(string movie,double evaluation) {
  //Put your code here
}

//Exercise 3 (c) Implement this function
bool MovieEvaluations::updateEvaluation(string movie,double newEvaluation) {
  //Put your code here
}

//Exercise 3 (d) Implement this function
string MovieEvaluations::computeVerboseEvaluation(string movie) {
  //Put your code here
}