#include "stepping.hh"

SteppingAction::SteppingAction(EventAction* eventAction)
{
	fEventAction = eventAction;
}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step *step)
{
	G4LogicalVolume *volume = step -> GetPreStepPoint() -> GetTouchableHandle() -> GetVolume() -> GetLogicalVolume();

	const MuonDetectorConstruction *detectorConstruction = static_cast<const MuonDetectorConstruction*> (G4RunManager::GetRunManager() -> GetUserDetectorConstruction());

	G4LogicalVolume *fScoringVolume = detectorConstruction -> GetScoringVolume();

	if(volume != fScoringVolume)
		return;	

	G4double edep = step -> GetTotalEnergyDeposit();
	/*
	if (edep != 0) {
		G4cout << "step: " << edep << G4endl;
	}
	*/
	fEventAction -> AddEdep(edep);
}
