#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.hh"
#include "physicslist.hh"
#include "action.hh"

int main(int argc, char** argv)
{
	// G4RunManager contals the flow of the program
	// and manages the event loop(s) within a run
	// also responsible for managing initialization
	// procedures, including methods in the user
	// initialization classes
	G4RunManager *runManager = new G4RunManager();
	runManager -> SetUserInitialization(new MuonDetectorConstruction());
	runManager -> SetUserInitialization(new PhysicsList());
	runManager -> SetUserInitialization(new ActionInitialization());

	runManager -> Initialize();

	G4UIExecutive *ui = new G4UIExecutive(argc, argv);

	G4VisManager *visManager = new G4VisExecutive();
	visManager -> Initialize();

	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	
	UImanager -> ApplyCommand("/vis/open OGL");
	UImanager -> ApplyCommand("/vis/drawVolume");
	UImanager -> ApplyCommand("/vis/viewer/set/defaultColour .3. 4. 5");
	UImanager -> ApplyCommand("/vis/viewer/set/background .5 .8 .5");
	UImanager -> ApplyCommand("/vis/scene/add/trajectories smooth");
	UImanager -> ApplyCommand("/vis/scene/endOfEventAction accumulate");
	UImanager -> ApplyCommand("/vis/scene/add/axes 0 0 0 1 m");
	UImanager -> ApplyCommand("/vis/geometry/set/colour PlasticScintillator 1 0 1");
	UImanager -> ApplyCommand("/vis/geometry/set/forceSolid PlasticScintillator");
	UImanager -> ApplyCommand("/vis/geometry/set/colour AluminumBox 0.5 0 1");
	UImanager -> ApplyCommand("/vis/viewer/centreAndZoomInOn AlBox");
	ui -> SessionStart();
	
	return 0;
}
