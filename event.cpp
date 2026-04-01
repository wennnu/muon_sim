#include "event.hh"

EventAction::EventAction(RunAction*)
{
	fEdep = 0;
}

EventAction::~EventAction()
{}


void EventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
	G4cout << "Energy deposited: " << fEdep << G4endl;

	G4AnalysisManager *analyzer = G4AnalysisManager::Instance();
	analyzer -> FillNtupleDColumn(0, fEdep);
	analyzer -> AddNtupleRow(0);
}
