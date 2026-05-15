#include "detector.hh"

SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

SensitiveDetector::~SensitiveDetector()
{}

G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *R0hist)
{
	G4Track *track = aStep -> GetTrack();

	//track -> SetTrackStatus(fStopAndKill);

	G4StepPoint *preStep = aStep -> GetPreStepPoint();
	G4StepPoint *postStep = aStep -> GetPostStepPoint();

	// get photon position information
	//G4ThreeVector posPhoton =  preStep -> GetPosition();

	G4int event = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
	//G4AnalysisManager *analyzer = new G4AnalysisManager::Instance();

	return true;
}


