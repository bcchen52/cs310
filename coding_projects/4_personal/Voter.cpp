#include "Voter.h"

Voter::Voter(string firstname, string lastname, unsigned int voterage) {
	first = firstname;
	last = lastname;
	age = voterage;
	likelihood = 75;
    strength = 75;
	impact = 1;
	next = nullptr;
	prev = nullptr;
	voted = false;
	position = 0;
}

Voter::Voter() {
	first = "";
	last = "";
	age = 0;
	likelihood = 75;
    strength = 75;
	impact = 1;
	next = nullptr;
	prev = nullptr;
	voted = false;
	position = 0;
}

Voter::Voter(const Voter& origObject){
	first = origObject.first;
	last = origObject.last;
	age = origObject.age;
	likelihood = origObject.likelihood;
    strength = origObject.strength;
	impact = origObject.impact;
	next = nullptr;
	prev = nullptr;
	voted = origObject.voted;
	position = 0;
}

void Voter::show() {
	cout << first << " " << last << ", age " << age;
}

void Voter::name(){
	cout << first << " " << last ;
}

void Voter::show_full(){
	cout << first << " " << last << " (" << age << "): strength of support: " << strength << ", likelihood: " << likelihood << ", impact: " << impact;
}

void Voter::vote() {
	voted = true;
}

bool Voter::get_voted(){
	return voted;
}

bool Voter::operator==(const Voter& other) const {
	return (first == other.first) && 
        (last == other.last); 
}

bool Voter::operator!=(const Voter& other) const {
    return !(*this == other);
}

bool Voter::operator<(const Voter& other) const {
	if(first != other.first){
		return first < other.first;
	} else {
		return last < other.last;
	} 
}

bool Voter::impactCompare(const Voter& other)  {
	if(likelihood * strength != other.likelihood*other.strength){
		return likelihood * strength < other.likelihood*other.strength;
	} 
	return *this < other;
}

bool Voter::ageCompare(const Voter& other) {
	if(age != other.age){
		return age < other.age;
	} 
	return *this < other;
}

//prob not using this
void Voter::updateImpact(){
	impact = strength / likelihood;
}
      
void Voter::updateStrength(double added_strength){
	strength += added_strength;
	updateImpact();
}
      
void Voter::updateLikelihood(double reduced_likelihood){
	likelihood = likelihood * (100 - reduced_likelihood);
	updateImpact();
}

int Voter::get_position(){
	return position;
}

void Voter::set_position(int pos){
	position = pos;
}

std::ostream& operator<<(std::ostream& os, const Voter& voter){
	os << voter.last << ", " << voter.first << ", " << voter.age;
	return os;
}

