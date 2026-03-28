#include "action.hh"

ActionInitialization::ActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::Build() const
{
	// create particles
	PrimaryGenerator *generator = new PrimaryGenerator();
	SetUserAction(generator);
}

