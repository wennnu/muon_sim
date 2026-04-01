#include "run.hh"

RunAction::RunAction()
{}

RunAction::~RunAction()
{}

void RunAction::BeginOfRunAction(const G4Run*);
{
	G4AnalysisManager *analyzer = G4AnalysisManager::Instance();

	analyzer -> OpenFile("muon_output.root");
}

void RunAction::EndOfRunAction(const G4Run*);
{
	G4AnalysisManager *analyzer = G4AnalysisManager::Instance();

	analyzer -> Write();
	analyzier -> CloseFile();
}


